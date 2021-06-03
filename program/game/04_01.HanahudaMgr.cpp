#include "DxLib.h"
#include "../library/t2klib.h"
#include "../support/Support.h"
#include "00.SceneMgr.h"
#include "02.Chapter.h"
#include "04_01.HanahudaMgr.h"
#include "04_99.Hanahuda_battle_Modules.h"
#include "04_99.Hanahuda_Card_Modules.h"
#include "04_99.Hanahuda_Score_Modules.h"
#include <time.h>

//BGM
static int BattleBGM = 0;

//花札の初期化クラス
Hanahuda_Card Card;

//プレイヤークラス
Player player;	//プレイヤー基本情報
Player enemy;	//敵の基本情報

//カードナンバー数える用
static int CardSel_NUM_ = 8;
static int NowSelect = 0;	//選択中の手札

//シーン遷移
static int GameScene_= Progress0;	//ゲーム内シーンは0から始まる

//プロトタイプ宣言
//ファイル内で必須の呼び出し関数。
//Mgr～とつく関数はこのファイル内の関数,一番下にある。そのほかの関数はすべてbattle_Modules.cppに集約
void Mgr_Player_Card_Placement();
void Mgr_Enemy_Card_Placement();

void Mgr_Player_Card_Move();
void Mgr_Enemy_Card_Move();

//-------------------------------------ここから管理用メイン関数------------------------------------------------
									
//初期化管理
void HanahudaMgr_Initialize() {
	
	player.MainScene_ = Progress0;
	
	//札の初期化	
	Card.Card_Modules_Initialize();	

	//自分・敵の札の最初のシャッフル
	player.Card_Moudules_First_Place(&player);
	enemy.Card_Moudules_First_Place(&enemy);

	//札を乱数でシャッフルする（すくみ・役共に）
	player.Card_Modules_YAKU_shuffle(&player, CardSel_NUM_);
	enemy.Card_Modules_YAKU_shuffle(&enemy, CardSel_NUM_);

	player.Card_Modules_3_shuffle(&player, CardSel_NUM_);
	enemy.Card_Modules_3_shuffle(&enemy, CardSel_NUM_);
		
	//BGM初期化
	BattleBGM = LoadSoundMem("sound/Battle_Stage_1.mp3");
	ChangeVolumeSoundMem(160,BattleBGM);
	PlaySoundMem(BattleBGM, DX_PLAYTYPE_LOOP);
	
	//乱数
	srand((unsigned int)time(0));
	
	//画像・座標・SE・フォント初期化処理
	player.Init_Battle(&player, &enemy, 1);
	
	//自分・敵の札の座標初期化
	for (int i = 0; i < 8; i++) {

		player.cpos_x[i] = 100 + (i * 100);
		player.cpos_y[i] = 750;

		enemy.cpos_x[i] = 200 + (i * 100);
		enemy.cpos_y[i] = 100;
	}

	//HPの初期化
	/*player.HP = 5000;
	enemy.HP = 1000;*/

	//敵の攻撃座標の更新
	enemy.AT_pos_x = 1200;
	enemy.AT_pos_y = -300;
}


//終了処理
void HanahudaMgr_Finalize() {
	
	Card.Card_Modules_Finalize();
	DeleteSoundMem(BattleBGM);

	player.Finalize_Battle(&player);
	enemy.Finalize_Battle(&enemy);	
}


//更新・計算管理
void HanahudaMgr_Update() {

	//背景表示
	DrawRotaGraph(512, 350, 1.0f, 0, player.Back_Image, true);
	player.System_Messeage(&player,&enemy);

	if (player.MainScene_ == Progress0) {	//開始合図

		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RETURN)) {	
	
			player.MainScene_ = Progress1;
		}
	}	
	else if (player.MainScene_ == Progress1) {	//自分カードの移動ターン		
		
		//【関数】攻撃・回復のメニュー表示
		player.Card_Modules_Menu(&player);
		
	}
	else if (player.MainScene_ == Progress2) {	//計算・攻撃処理1
		
		Mgr_Player_Card_Move();	//自分カードの移動関数

		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RETURN)) {	//出す札の決定する

			player.Moudules_Myplayer_YAKUScore_RETURN(&player);	//決定と共に自プレイヤーの役スコアの計算をする
			player.Game_Start = true; //札を3枚以上上げることを制御
			player.Count_3 = 4;	 //札を3枚以上上げることを制御
		}


		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_SPACE)) {	//次シーンへ移動

			Mgr_Enemy_Card_Move();								//シーン移動と同時に敵のカード計算を行う
			enemy.Moudules_Enemy_Card_Place(&player, &enemy);	///シーン移動と同時に敵のカード計算し、舞台に3枚出す（プレイヤーカードを計算して判断）
			enemy.Moudules_Enemy_YAKUScore_RETURN(&enemy);
			player.Moudules_All_Score_RETURN(&player, &enemy);	//3すくみ・役の点数を合算
			player.MainScene_ = Progress3;
		}
		

	}
	else if (player.MainScene_ == Progress3) {	//計算・攻撃処理2
	
		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_SPACE)) {	//次シーンへ移動
			player.MainScene_ = Progress4;
		}

		
	}
	else if (player.MainScene_ == Progress4) {	//計算・攻撃処理3
		
		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_SPACE)) {	//次シーンへ移動

			//自分の攻撃モーション初期化・時間があったらモジュールcppに移動
			player.Modules_Attack_init(&player, &enemy);

			player.Moudules_Player_Attack(&player, &enemy, 0);//自プレイヤーの攻撃処理(すくみ)
			enemy.Moudules_Enemy_Attack(&player, &enemy, 0);//敵の攻撃処理	
			player.MainScene_ = Progress5;
			//player.AT_Wait[0] = false;
		}

		
	}
	else if (player.MainScene_ == Progress5) {	//札シャッフル・初期化
		
		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_SPACE)) {	//次シーンへ移動

			player.Moudules_Player_Attack(&player, &enemy, 1);//自プレイヤーの攻撃処理(役)		
			enemy.Moudules_Enemy_Attack(&player, &enemy, 1);//敵の攻撃処理	

			//敵の攻撃モーション初期化・時間があったらモジュールcppに移動
			player.Modules_Attack_init(&player, &enemy);

			if (player.HP <= 0 || enemy.HP <= 0) {

				player.MainScene_ = Progress7;
			}
			else {
				player.MainScene_ = Progress6;
			}

		}
				
	}
	else if (player.MainScene_ == Progress6) {

		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RETURN)) { //Progress0に戻る

			player.Card_Moudules_YAKU_Reshaffle(&player, 8,1);
			enemy.Card_Moudules_YAKU_Reshaffle(&enemy, 8,2);

			player.MainScene_ = Progress0;
			player.Game_Start = false;
		}
		

	}
	else if (player.MainScene_ == Progress7) {
		//試合終了
	}
	else if (player.MainScene_ == Progress8) {
		player.Card_Modules_Recovery_Menu(&player);
	}
	else if (player.MainScene_ == Progress9) {
		//ヘルプ画面
	}
	else if (player.MainScene_ == Progress10) {
		//役一覧
	}
	else if (player.MainScene_ == Progress11) {
		//戻る画面の表示
		player.Card_Modules_Back_Menu(&player);
	}
	
}


//描画管理
void HanahudaMgr_Draw() {
		
	//プレイヤーHPバー
	player.HP_now =1.0f * ( (float)player.HP / 5000.0f);

	//enemyHPバー
	enemy.HP_now = 1.0f * ((float)enemy.HP / 5000.0f);

	//自分の手札を配置	
	Mgr_Player_Card_Placement();

	//敵の手札の配置
	Mgr_Enemy_Card_Placement();
	
	//HPバー
	DrawRotaGraph3(20, 700, 0, 0, player.HP_now, 0.5f, 0, player.HP_var, TRUE);
	DrawStringEx(20, 675, -1, "HP:%d / %d", player.HP, 5000);
	
	//HP・敵バー
	DrawRotaGraph3(700, 50, 0, 0, enemy.HP_now, 0.5f, 0, enemy.HP_var, TRUE);
	DrawStringEx(700, 25, -1, "HP:%d / %d", enemy.HP, 5000);

	//開始合図の関数
	player.Modules_Battle_Start(&player);
	
	//3すくみの攻撃モーション（SEと立ち絵と音楽の表示）・Progress3の時発動
	player.Modules_Attack_Motion(&player,&enemy,Progress4);

	//役の攻撃モーション
	player.Modules_Attack_Motion_YAKU(&player, &enemy, Progress5);

	//resurt結果の表示
	player.Modules_Result(&player, &enemy,2);

	//ヘルプ画面の表示
	player.Card_Modules_Help(&player, Progress9);

	//役一覧リストの表示
	player.Card_Modules_YakuList(&player, Progress10);
			
	/*DrawStringEx(50, 700, -1, "MY HP: %d", player.HP);
	DrawStringEx(50, 730, -1, "TotalScore: %d", player.TotalScore);
	DrawStringEx(50, 100, -1, "ENEMY HP: %d", enemy.HP);
	DrawStringEx(40, 130, -1, "TotalScore: %d", enemy.TotalScore);
	DrawStringEx(50, 250, -1, "ゲームシーンナンバー : %d", player.MainScene_);
	DrawStringEx(50, 400, -1, "AT_count: %d", player.AT_counter);*/

	//
	//DrawStringEx(800, 200, -1, "jan : %d", player.Jan);
	//DrawStringEx(800, 230, -1, "Feb : %d", player.Feb);
	//DrawStringEx(800, 260, -1, "Mar : %d", player.Mar);
	//DrawStringEx(800, 290, -1, "Apr : %d", player.Apr);
	//DrawStringEx(800, 310, -1, "may : %d", player.May);
	//DrawStringEx(800, 340, -1, "jun : %d", player.Jun);
	//DrawStringEx(800, 370, -1, "july : %d", player.Jul);
	//DrawStringEx(800, 400, -1, "aug : %d", player.Aug);
	//DrawStringEx(800, 430, -1, "sep : %d", player.Sep);
	//DrawStringEx(800, 460, -1, "oct : %d", player.Oct);
	//DrawStringEx(800, 490, -1, "nov : %d", player.Oct);
	//DrawStringEx(800, 520, -1, "dec : %d", player.Oct);

	/*DrawStringEx(50, 330, -1, "Ene_Sukim_3_Coun0:%d", enemy.Ene_Sukim_3_Count[0]);
	DrawStringEx(50, 360, -1, "Ene_Sukim_3_Coun1:%d", enemy.Ene_Sukim_3_Count[1]);
	DrawStringEx(50, 390, -1, "Ene_Sukim_3_Coun2:%d", enemy.Ene_Sukim_3_Count[2]);
	DrawStringEx(50, 410, -1, "enemy.Count_3:%d", enemy.Count_3);*/
	/*for (int i = 0; i < 8; i++) {

		DrawStringEx(50+(i*30),270, -1, " %d", player.YAKU_R[i]);

	}*/
	
}

//-------------------------------------ここから呼び出し用関数-------------------------------------------------

//描画・花札の配置関数
void Mgr_Player_Card_Placement() {	//自分の花札配置

	for (int i = 0; i < 8; i++) {
		if (player.Huda_UP[i] ) {			
			player.cpos_y[i] = 450;
		}		
		else if (i == NowSelect) {			
			player.cpos_x[i] = 100 + (i * 100);
			player.cpos_y[i] = 500;
		}
		else {
			player.cpos_x[i] = 100+(i *100);
			player.cpos_y[i] = 600;
		}

		//乱数入れ込み		
		player.cYaku_Num = player.YAKU_R[i];
		//player.cYaku_Num = 0;	//テスト
		player.c3_Num1 = player.Sukumi_R[i];
	
		DrawRotaGraph(player.cpos_x[i] , player.cpos_y[i], 1.0f, 0, Card.Card[player.uraomote][player.cYaku_Num][player.c3_Num1], true);
		//DrawRotaGraph(player.cpos_x[i] + (i * 100), player.cpos_y[i], 1.0f, 0, Card.Card[player.uraomote][0][0], true);
	}

}

void Mgr_Enemy_Card_Placement() {	//敵の花札配置

	for (int i = 0; i < 8; i++) {

		//乱数入れ込み		
		enemy.cYaku_Num = enemy.YAKU_R[i];	//テスト中		
		enemy.c3_Num1 = enemy.Sukumi_R[i];
			
		if (enemy.Huda_UP[i]) {
			enemy.cpos_y[i] = 300;
		}
		else {

			enemy.cpos_x[i] = 200 + (i * 100);
			enemy.cpos_y[i] = 150;
		}
		
		DrawRotaGraph(enemy.cpos_x[i], enemy.cpos_y[i], 1.0f, 0, Card.Card[enemy.uraomote][enemy.cYaku_Num][enemy.c3_Num1], true);		
	}

}


//自分のカードの移動処理
void Mgr_Player_Card_Move() {
	
	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RIGHT) && player.Game_Start == false) {	//右に移動

		NowSelect = (NowSelect + 1) % CardSel_NUM_;
	}

	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_LEFT) && player.Game_Start == false) {	//左に移動

		NowSelect = (NowSelect + (CardSel_NUM_ -1)) % CardSel_NUM_;
		for (int i = 0; i < 8; i++) {
	
			if (player.Huda_UP[i] ) {
				player.cpos_y[i] = 450;
			}
			else if (i == NowSelect) {
				player.cpos_y[i] = 500;
			}
			else {
				player.cpos_y[i] = 600;

			}			
		}

	}

	
	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_UP) && player.Game_Start == false) {	//舞台に出す札候補を決定する

		for (int i = 0; i < 8; i++) {

			if (i == NowSelect && player.Count_3 <3){

				int SelectNum_r = NowSelect;
				player.Count_3++;				
				player.Huda_UP[SelectNum_r] = true;
				player.UR_Storage[SelectNum_r] = eCard_Omote;
				player.YAKU1_Storage[SelectNum_r] = player.YAKU_R[SelectNum_r];
				//player.YAKU1_Storage[SelectNum_r] = 0;	//テスト
												
				if (player.Count_3 == 1) {
				
					player.SUKUMI_Storage[0] = player.Sukumi_R[SelectNum_r];
					player.cpos_x[SelectNum_r] = 400;

				}
				else if (player.Count_3 == 2) {

					player.SUKUMI_Storage[1] = player.Sukumi_R[SelectNum_r];
					player.cpos_x[SelectNum_r] = 500;

				}
				else if (player.Count_3 == 3) {

					player.SUKUMI_Storage[2] = player.Sukumi_R[SelectNum_r];
					player.cpos_x[SelectNum_r] = 600;

				}


			}

		}

	}

	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_DOWN) && player.Game_Start == false) {	//札を下げる

		for (int i = 0; i < 8; i++) {
			
			player.Count_3 = 0;
			player.Huda_UP[i] = false;
			player.UR_Storage[i] = eCard_Omote;
			player.YAKU1_Storage[i] = 99;
			player.SUKUMI_Storage[i] = 99;		
		}

		player.TotalScore = 0;
		player.Jan = 0;
		player.Feb = 0;
		player.Mar = 0;
		player.Apr = 0;
		player.May = 0;
		player.Jun = 0;
		player.Jul = 0;
		player.Aug = 0;
		player.Sep = 0;
		player.Oct = 0;
		player.Nov = 0;
		player.Dec = 0;
	
	}

}

//敵のカードの移動処理
void Mgr_Enemy_Card_Move() {
		
	for (int i = 0; i < 8; i++) {

		enemy.UR_Storage[i] = eCard_Omote;
		enemy.YAKU1_Storage[i] = enemy.YAKU_R[i];	
		enemy.SUKUMI_Storage[i] = enemy.Sukumi_R[i];		
	}
	
}







