#include "DxLib.h"
#include "../library/t2klib.h"
#include "../support/Support.h"
#include "00.SceneMgr.h"
#include "02.Chapter.h"
#include "04_03.HanahudaMgr.h"
#include "04_99.Hanahuda_battle_Modules.h"
#include "04_99.Hanahuda_Card_Modules.h"
#include "04_99.Hanahuda_Score_Modules.h"
#include <time.h>


//BGM
static int BattleBGM = 0;

//花札の初期化クラス
Hanahuda_Card Card3;

//プレイヤークラス
Player player3;	//プレイヤー基本情報
Player enemy3;	//敵の基本情報

//カードナンバー数える用
static int CardSel_NUM_ = 8;
static int NowSelect = 0;	//選択中の手札


//シーン遷移
static int GameScene_ = Progress0;	//ゲーム内シーンは0から始まる


//プロトタイプ宣言
//ファイル内で必須の呼び出し関数。
//Mgr～とつく関数はこのファイル内の関数,一番下にある。そのほかの関数はすべてbattle_Modules.cppに集約
void Mgr_Player_Card_Placement_3();
void Mgr_Enemy_Card_Placement_3();

void Mgr_Player_Card_Move_3();
void Mgr_Enemy_Card_Move_3();


//-------------------------------------ここから管理用メイン関数------------------------------------------------


//初期化管理
void HanahudaMgr_Initialize_3() {


	player3.MainScene_ = Progress0;

	//札の初期化	
	Card3.Card_Modules_Initialize();

	//BGM初期化
	BattleBGM = LoadSoundMem("sound/Battle_Stage_1.mp3");
	ChangeVolumeSoundMem(160, BattleBGM);
	PlaySoundMem(BattleBGM, DX_PLAYTYPE_LOOP);


	//乱数
	srand(time(0));

	//画像・座標・SE・フォント初期化処理
	player3.Init_Battle(&player3, &enemy3, 3);

	//自分・敵の札の最初のシャッフル
	player3.Card_Moudules_First_Place(&player3);
	enemy3.Card_Moudules_First_Place(&enemy3);


	//札を乱数でシャッフルする（すくみ・役共に）
	player3.Card_Modules_YAKU_shuffle(&player3, CardSel_NUM_);
	enemy3.Card_Modules_YAKU_shuffle(&enemy3, CardSel_NUM_);

	player3.Card_Modules_3_shuffle(&player3, CardSel_NUM_);
	enemy3.Card_Modules_3_shuffle(&enemy3, CardSel_NUM_);


	//自分・敵の札の座標初期化
	for (int i = 0; i < 8; i++) {

		player3.cpos_x[i] = 100 + (i * 100);
		player3.cpos_y[i] = 750;

		enemy3.cpos_x[i] = 200 + (i * 100);
		enemy3.cpos_y[i] = 100;

	}

	//HPの初期化
	/*player3.HP = 5000.0f;
	enemy3.HP = 5000.0f;*/

	//敵の攻撃座標の更新
	enemy3.AT_pos_x = 1200;
	enemy3.AT_pos_y = -300;


}


//終了処理
void HanahudaMgr_Finalize_3() {

	Card3.Card_Modules_Finalize();
	DeleteSoundMem(BattleBGM);

	player3.Finalize_Battle(&player3);
	enemy3.Finalize_Battle(&enemy3);


}


//更新・計算管理
void HanahudaMgr_Update_3() {


	//背景表示
	DrawRotaGraph(512, 350, 1.0f, 0, player3.Back_Image, true);
	player3.System_Messeage(&player3, &enemy3);

	if (player3.MainScene_ == Progress0) {	//開始合図

		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RETURN)) {

			player3.MainScene_ = Progress1;

		}

	}
	else if (player3.MainScene_ == Progress1) {	//自分カードの移動ターン


		//【関数】攻撃・回復のメニュー表示
		player3.Card_Modules_Menu(&player3);


	}
	else if (player3.MainScene_ == Progress2) {	//計算・攻撃処理1

		Mgr_Player_Card_Move_3();	//自分カードの移動関数


		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RETURN)) {	//出す札の決定する

			player3.Moudules_Myplayer_YAKUScore_RETURN(&player3);	//決定と共に自プレイヤーの役スコアの計算をする
			player3.Game_Start = true; //札を3枚以上上げることを制御
			player3.Count_3 = 4;	 //札を3枚以上上げることを制御

		}


		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_SPACE)) {	//次シーンへ移動

			Mgr_Enemy_Card_Move_3();								//シーン移動と同時に敵のカード計算を行う
			enemy3.Moudules_Enemy_Card_Place_3(&player3, &enemy3);	///シーン移動と同時に敵のカード計算し、舞台に3枚出す（プレイヤーカードを計算して判断）
			enemy3.Moudules_Enemy_YAKUScore_RETURN(&enemy3);
			player3.Moudules_All_Score_RETURN(&player3, &enemy3);	//3すくみ・役の点数を合算


			player3.MainScene_ = Progress3;
		}


	}
	else if (player3.MainScene_ == Progress3) {	//計算・攻撃処理2

		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_SPACE)) {	//次シーンへ移動

			player3.MainScene_ = Progress4;

		}


	}
	else if (player3.MainScene_ == Progress4) {	//計算・攻撃処理3

		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_SPACE)) {	//次シーンへ移動

			//自分の攻撃モーション初期化・時間があったらモジュールcppに移動
			player3.Modules_Attack_init(&player3, &enemy3);

			player3.Moudules_Player_Attack(&player3, &enemy3, 0);//自プレイヤーの攻撃処理(すくみ)
			enemy3.Moudules_Enemy_Attack(&player3, &enemy3, 0);//敵の攻撃処理	


			player3.MainScene_ = Progress5;
			//player3.AT_Wait[0] = false;

		}


	}
	else if (player3.MainScene_ == Progress5) {	//札シャッフル・初期化

		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_SPACE)) {	//次シーンへ移動


			player3.Moudules_Player_Attack(&player3, &enemy3, 1);//自プレイヤーの攻撃処理(役)		
			enemy3.Moudules_Enemy_Attack(&player3, &enemy3, 1);//敵の攻撃処理	

			//敵の攻撃モーション初期化・時間があったらモジュールcppに移動
			player3.Modules_Attack_init(&player3, &enemy3);

			if (player3.HP <= 0 || enemy3.HP <= 0) {

				player3.MainScene_ = Progress7;

			}
			else {

				player3.MainScene_ = Progress6;

			}


		}



	}
	else if (player3.MainScene_ == Progress6) {

		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RETURN)) { //Progress0に戻る

			player3.Card_Moudules_YAKU_Reshaffle(&player3, 8, 1);
			enemy3.Card_Moudules_YAKU_Reshaffle(&enemy3, 8, 4);

			player3.MainScene_ = Progress0;
			player3.Game_Start = false;
		}


	}
	else if (player3.MainScene_ == Progress7) {


		//試合終了


	}
	else if (player3.MainScene_ == Progress8) {


		player3.Card_Modules_Recovery_Menu(&player3);



	}
	else if (player3.MainScene_ == Progress9) {


		//ヘルプ画面


	}
	else if (player3.MainScene_ == Progress10) {


		//役一覧


	}
	else if (player3.MainScene_ == Progress11) {



		//戻る画面の表示
		player3.Card_Modules_Back_Menu(&player3);


	}




}


//描画管理
void HanahudaMgr_Draw_3() {

	//プレイヤーHPバー
	player3.HP_now = 1.0f * ((float)player3.HP / MAXHP_1);

	//enemyHPバー
	enemy3.HP_now = 1.0f * ((float)enemy3.HP / MAXHP_1);


	//自分の手札を配置	
	Mgr_Player_Card_Placement_3();

	//敵の手札の配置
	Mgr_Enemy_Card_Placement_3();

	//HPバー
	DrawRotaGraph3(20, 700, 0, 0, player3.HP_now, 0.5f, 0, player3.HP_var, TRUE);
	DrawStringEx(20, 675, -1, "HP:%d / %d", player3.HP, 5000);

	//HP・敵バー
	DrawRotaGraph3(700, 50, 0, 0, enemy3.HP_now, 0.5f, 0, enemy3.HP_var, TRUE);
	DrawStringEx(700, 25, -1, "HP:%d / %d", enemy3.HP, 5000);


	//開始合図の関数
	player3.Modules_Battle_Start(&player3);

	//3すくみの攻撃モーション（SEと立ち絵と音楽の表示）・Progress3の時発動
	player3.Modules_Attack_Motion(&player3, &enemy3, Progress4);


	//役の攻撃モーション
	player3.Modules_Attack_Motion_YAKU(&player3, &enemy3, Progress5);


	//resurt結果の表示
	player3.Modules_Result(&player3, &enemy3, 4);

	//ヘルプ画面の表示
	player3.Card_Modules_Help(&player3, Progress1);

	//役一覧リストの表示
	player3.Card_Modules_YakuList(&player3, Progress10);


	/*DrawStringEx(50, 700, -1, "MY HP: %d", player3.HP);
	DrawStringEx(50, 730, -1, "TotalScore: %d", player3.TotalScore);
	DrawStringEx(50, 100, -1, "ENEMY HP: %d", enemy3.HP);
	DrawStringEx(40, 130, -1, "TotalScore: %d", enemy3.TotalScore);
	DrawStringEx(50, 250, -1, "ゲームシーンナンバー : %d", player3.MainScene_);
	DrawStringEx(50, 400, -1, "AT_count: %d", player3.AT_counter);


	DrawStringEx(800, 200, -1, "jan : %d", enemy3.Jan);
	DrawStringEx(800, 230, -1, "Feb : %d", enemy3.Feb);
	DrawStringEx(800, 260, -1, "Mar : %d", enemy3.Mar);
	DrawStringEx(800, 290, -1, "Apr : %d", enemy3.Apr);
	DrawStringEx(800, 310, -1, "may : %d", enemy3.May);
	DrawStringEx(800, 340, -1, "jun : %d", enemy3.Jun);
	DrawStringEx(800, 370, -1, "july : %d",enemy3.Jul);
	DrawStringEx(800, 400, -1, "aug : %d", enemy3.Aug);
	DrawStringEx(800, 430, -1, "sep : %d", enemy3.Sep);
	DrawStringEx(800, 460, -1, "oct : %d", enemy3.Oct);
	DrawStringEx(800, 490, -1, "nov : %d", enemy3.Oct);
	DrawStringEx(800, 520, -1, "dec : %d", enemy3.Oct);*/


	/*DrawStringEx(50, 330, -1, "Ene_Sukim_3_Coun0:%d", enemy3.Ene_Sukim_3_Count[0]);
	DrawStringEx(50, 360, -1, "Ene_Sukim_3_Coun1:%d", enemy3.Ene_Sukim_3_Count[1]);
	DrawStringEx(50, 390, -1, "Ene_Sukim_3_Coun2:%d", enemy3.Ene_Sukim_3_Count[2]);
	DrawStringEx(50, 410, -1, "enemy3.Count_3:%d", enemy3.Count_3);*/


	/*for (int i = 0; i < 8; i++) {

		DrawStringEx(50 + (i * 30), 270, -1, " %d", enemy3.YAKU2_Storage[i]);

	}*/

}

//-------------------------------------ここから呼び出し用関数-------------------------------------------------

//描画・花札の配置関数
void Mgr_Player_Card_Placement_3() {	//自分の花札配置

	for (int i = 0; i < 8; i++) {


		if (player3.Huda_UP[i]) {

			player3.cpos_y[i] = 450;

		}
		else if (i == NowSelect) {


			player3.cpos_x[i] = 100 + (i * 100);
			player3.cpos_y[i] = 500;

		}
		else {

			player3.cpos_x[i] = 100 + (i * 100);
			player3.cpos_y[i] = 600;

		}

		//乱数入れ込み		
		player3.cYaku_Num = player3.YAKU_R[i];
		//player3.cYaku_Num = 0;	//テスト
		player3.c3_Num1 = player3.Sukumi_R[i];


		DrawRotaGraph(player3.cpos_x[i], player3.cpos_y[i], 1.0f, 0, Card3.Card[player3.uraomote][player3.cYaku_Num][player3.c3_Num1], true);
		//DrawRotaGraph(player3.cpos_x[i] + (i * 100), player3.cpos_y[i], 1.0f, 0, Card2.Card[player3.uraomote][0][0], true);

	}

}

void Mgr_Enemy_Card_Placement_3() {	//敵の花札配置

	for (int i = 0; i < 8; i++) {

		//乱数入れ込み		
		enemy3.cYaku_Num = enemy3.YAKU_R[i];	//テスト中		
		enemy3.c3_Num1 = enemy3.Sukumi_R[i];


		if (enemy3.Huda_UP[i]) {

			enemy3.cpos_y[i] = 300;

		}
		else {

			enemy3.cpos_x[i] = 200 + (i * 100);
			enemy3.cpos_y[i] = 150;

		}

		DrawRotaGraph(enemy3.cpos_x[i], enemy3.cpos_y[i], 1.0f, 0, Card3.Card[enemy3.uraomote][enemy3.cYaku_Num][enemy3.c3_Num1], true);

	}

}


//自分のカードの移動処理
void Mgr_Player_Card_Move_3() {

	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RIGHT) && player3.Game_Start == false) {	//右に移動

		NowSelect = (NowSelect + 1) % CardSel_NUM_;

	}

	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_LEFT) && player3.Game_Start == false) {	//左に移動

		NowSelect = (NowSelect + (CardSel_NUM_ - 1)) % CardSel_NUM_;

		for (int i = 0; i < 8; i++) {

			if (player3.Huda_UP[i]) {

				player3.cpos_y[i] = 450;

			}
			else if (i == NowSelect) {

				player3.cpos_y[i] = 500;

			}
			else {

				player3.cpos_y[i] = 600;

			}

		}

	}


	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_UP) && player3.Game_Start == false) {	//舞台に出す札候補を決定する

		for (int i = 0; i < 8; i++) {

			if (i == NowSelect && player3.Count_3 < 3) {

				int SelectNum_r = NowSelect;
				player3.Count_3++;
				player3.Huda_UP[SelectNum_r] = true;
				player3.UR_Storage[SelectNum_r] = eCard_Omote;
				player3.YAKU1_Storage[SelectNum_r] = player3.YAKU_R[SelectNum_r];
				//player3.YAKU1_Storage[SelectNum_r] = 0;	//テスト


				if (player3.Count_3 == 1) {

					player3.SUKUMI_Storage[0] = player3.Sukumi_R[SelectNum_r];
					player3.cpos_x[SelectNum_r] = 400;

				}
				else if (player3.Count_3 == 2) {

					player3.SUKUMI_Storage[1] = player3.Sukumi_R[SelectNum_r];
					player3.cpos_x[SelectNum_r] = 500;

				}
				else if (player3.Count_3 == 3) {

					player3.SUKUMI_Storage[2] = player3.Sukumi_R[SelectNum_r];
					player3.cpos_x[SelectNum_r] = 600;

				}


			}

		}

	}

	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_DOWN) && player3.Game_Start == false) {	//札を下げる

		for (int i = 0; i < 8; i++) {

			player3.Count_3 = 0;
			player3.Huda_UP[i] = false;
			player3.UR_Storage[i] = eCard_Omote;
			player3.YAKU1_Storage[i] = 99;
			player3.SUKUMI_Storage[i] = 99;

		}

		player3.TotalScore = 0;
		player3.Jan = 0;
		player3.Feb = 0;
		player3.Mar = 0;
		player3.Apr = 0;
		player3.May = 0;
		player3.Jun = 0;
		player3.Jul = 0;
		player3.Aug = 0;
		player3.Sep = 0;
		player3.Oct = 0;
		player3.Nov = 0;
		player3.Dec = 0;

	}


}

//敵のカードの移動処理
void Mgr_Enemy_Card_Move_3() {

	for (int i = 0; i < 8; i++) {

		enemy3.UR_Storage[i] = eCard_Omote;
		enemy3.YAKU1_Storage[i] = enemy3.YAKU_R[i];
		enemy3.SUKUMI_Storage[i] = enemy3.Sukumi_R[i];

	}


}







