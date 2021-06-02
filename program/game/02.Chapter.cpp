#include "DxLib.h"
#include "../library/t2klib.h"
#include "../support/Support.h"
#include "00.SceneMgr.h"
#include "02.Chapter.h"

//画像
static int BackImage;	//背景
static int CHAPTER_Lock_Image[5] = { 0 };	//チャプターロック用の画像
static int CHAPTER_Image_[5] = {0};	 //チャプター選択画像5枚
static int CHAPTER_Image_Select[5] = { 0 };	//チャプター選択時に光らせるための画像

static int GoBack_Title;	//タイトルに戻る専用の画像
static int backimage_ = 0;
static int Setumei_Box;

//BGMとSE
static int ENTER_SE;	//決定時SE
static int Title_BGM = 0;	//タイトルBGM・チャプターとコンフィグも同じ曲
static int Change_SE;	//シフトキー移動のSE


//制御用bool
static bool init = false;	//初期化用
static bool Finalize = false;	//	終了処理
static int MUSIC_STOP;

static bool CHAPTER_Select_b[5] = { 1,0,0,0,0 };	//チャプター選択中はブレンドモードで発光

//セーブデータ管理
save_deta_t save_data;
FILE* fp;
char* name = "sava_data.dat";

//チャプター解放制御
Chapter_Key Key;

//選択移動用変数
enum {
	eChapter_0,
	eChapter_1,
	eChapter_2,
	eChapter_3,
	eChapter_4,
	eChapter_Num,
};

static int NowSelect = eChapter_0;

//初期化
void Chapter_Initialize() {
		
		BackImage = LoadGraph("graphics/chapter_back.png"); //背景画像の初期化
		Setumei_Box = LoadGraph("graphics/wafuu1.png");
	
		//チャプター画像
		CHAPTER_Image_[0] = LoadGraph("graphics/Chapter_1.png");
		CHAPTER_Image_[1] = LoadGraph("graphics/Chapter_2.png");
		CHAPTER_Image_[2] = LoadGraph("graphics/Chapter_3.png");
		CHAPTER_Image_[3] = LoadGraph("graphics/Chapter_4.png");
		CHAPTER_Image_[4] = LoadGraph("graphics/Chapter_5.png");

		for (int i = 0; i < 5; i++) {	//選択時発光用画像
			CHAPTER_Image_Select[i] = LoadGraph("graphics/Chapter_1_select.png");
		}

		for (int i = 0; i < 5; i++) {	//アンロック用画像
			CHAPTER_Lock_Image[i] = LoadGraph("graphics/Chapter_1_lock.png");
		}

		//BGM
		ENTER_SE = LoadSoundMem("sound/DECISION_SE.mp3");
		Title_BGM = LoadSoundMem("sound/TITLE_CHAPTER_BGM.mp3");
		Change_SE = LoadSoundMem("sound/MOVE_CULSOL_SE.mp3");	

		PlaySoundMem(Title_BGM,DX_PLAYTYPE_LOOP);
		
		//ファイル内容からデータをロード
		if ((fp = fopen(name, "rb")) == NULL) {
			printf("ファイルオープンエラー");
		}
		else {
			//ファイルからデータを読み込む
			fread(&save_data, sizeof(save_deta_t), 1, fp);
			fclose(fp);	//解放						
			printf("chapter 1 = %d\n", save_data.s_Chapter_Unlock[1]);
			printf("chapter 1 = %d\n", save_data.s_Chapter_Unlock[2]);
			printf("chapter 1 = %d\n", save_data.s_Chapter_Unlock[3]);
			printf("chapter 1 = %d\n", save_data.s_Chapter_Unlock[4]);			
		}

		for (int i = 0; i < 5; i++) {

			if (save_data.s_Chapter_Unlock[i]) {
				Key.Chapter_Unlock[i] = true;
			}

		}
		
}

//終了処理
void Chapter_Finalize() {

		for (int i = 0; i < 5; i++) {
		DeleteGraph(CHAPTER_Image_[i]);
		DeleteGraph(CHAPTER_Image_Select[i]);
		DeleteGraph(CHAPTER_Lock_Image[i]);	
		}
		DeleteSoundMem(Title_BGM);
		DeleteGraph(BackImage);
		DeleteGraph(Title_BGM);
		DeleteGraph(Change_SE);
		DeleteGraph(ENTER_SE);	
}


//更新・計算処理

	//右に移動
void Chapter_Update() {

	DrawRotaGraph(512, 350, 1.0f, 0, backimage_, true);	
	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RIGHT)) {
					
		NowSelect = (NowSelect + 1) % eChapter_Num;
		PlaySoundMem(Change_SE, DX_PLAYTYPE_BACK);
		
		for(int i = 0; i < 5; i++) {	//選択中のチャプターを光らせる

			if (NowSelect == i) {
				CHAPTER_Select_b[i] = true;
			}
			else {
				CHAPTER_Select_b[i] = false;
			}
		}
	}

	//左に移動
	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_LEFT)) {
	
		NowSelect = (NowSelect + (eChapter_Num - 1)) % eChapter_Num;
		PlaySoundMem(Change_SE, DX_PLAYTYPE_BACK);
		
		for (int i = 0; i < 5; i++) {

			if (NowSelect == i) {
				CHAPTER_Select_b[i] = true;
			}
			else {
				CHAPTER_Select_b[i] = false;
			}
		}		
	}

	//選択中の番号をエンターしたら、そのシーンへ移行する。
	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RETURN)) {

		PlaySoundMem(ENTER_SE, DX_PLAYTYPE_BACK);
		switch (NowSelect)	
		{
		case eChapter_0:
				SceneMgr_ChangeScene(Novel_0);	//プロローグのため、常に解放
				DeleteSoundMem(Title_BGM);
				MUSIC_STOP = 0;
				Finalize = true;
				break;

		case eChapter_1:
			
			if (Key.Chapter_Unlock[eChapter_1]) {	//チャプター0読了で解放				
				SceneMgr_ChangeScene(Game_1);
				DeleteSoundMem(Title_BGM);
				MUSIC_STOP = 0;
				Finalize = true;
			}
				break;

		case eChapter_2:
			
			if (Key.Chapter_Unlock[eChapter_2]) {	//チャプター1読了で解放
				SceneMgr_ChangeScene(Novel_2);
				MUSIC_STOP = 0;
				Finalize = true;			
			}
				break;
			
		case eChapter_3:
			
			if (Key.Chapter_Unlock[eChapter_3]) {	//チャプター2読了で解放
				
				SceneMgr_ChangeScene(Novel_3);
				MUSIC_STOP = 0;
				Finalize = true;

			}			
				break;

		case eChapter_4:
			
			if (Key.Chapter_Unlock[eChapter_4]) {	//チャプター3読了で解放
				SceneMgr_ChangeScene(Novel_4);
				MUSIC_STOP = 0;
				Finalize = true;
			}			
				break;
		}
	}

	//バックスペースキーが押されたらタイトルへ移動
	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_BACK)) {
		SceneMgr_ChangeScene(Title);
		Finalize = true;
	}

}
//更新-チャプター制御解除用関数
void Chapter_Unlock(int *chapter_NUM) {		//条件クリア直後に呼び出し、該当チャプターへの制御解除する

	int Num = *chapter_NUM;

	for (int i = 0; i < 5; i++) {

		if (i== Num) {

			Key.Chapter_Unlock[i] = true;
			save_data.s_Chapter_Unlock[i] = true;

		}

	}
	
	if ((fp = fopen(name, "wb")) == NULL) {
		printf("ファイルオープンエラー\n");
	}
	else {
		fwrite(&save_data, sizeof(save_deta_t), 1, fp);
		fclose(fp);
	}

	
	
	




}


//描画
void Chapter_Draw() {

		int pos_x = 100;	//チャプター画像座標調整用
		int pos_y = 200;

		DrawRotaGraph(512, 384, 0.95f, 0, BackImage,true);	//背景画像
		DrawRotaGraph(512, 630, 1.0f, 0, Setumei_Box, true);	//背景画像
		

		
	for (int i = 0; i < 5; i++) {	//チャプター画像描画

		if (i % 2 != 0) {		//CHAPTER i が奇数だったら

			pos_y = 400;	//yの位置を調整

		}
		else {

			pos_y = 200;

		}

		//選択中である場合は光らせる
		if (CHAPTER_Select_b[i]) {	

			if (CHAPTER_Select_b[0]) {

				DrawStringEx(200, 600, -1, "◆◇始まりの章（シナリオのみ）◇◆");
				DrawStringEx(200, 630, -1, "←　→　移動でチャプターを選択できます。");
				DrawStringEx(200, 650, -1, "ENTERキーでその章に行きます。");
				DrawStringEx(200, 670, -1, "タイトルの戻る場合は、BackSpeceキーを押してください。");



			}

			if (CHAPTER_Select_b[1]) {

				DrawStringEx(200, 600, -1, "◆◇弐章（試合のみ）◇◆");
				DrawStringEx(200, 630, -1, "解放条件：『始まりの章』をクリア");
				DrawStringEx(200, 650, -1, "花札に勝利すると自動セーブがされます。");
				



			}

			if (CHAPTER_Select_b[2]) {

				DrawStringEx(200, 600, -1, "◆◇参章（シナリオ・花札）◇◆");
				DrawStringEx(200, 630, -1, "解放条件：『弐章』をクリア");
				DrawStringEx(200, 650, -1, "花札に勝利すると自動セーブがされます。");

				



			}

			if (CHAPTER_Select_b[3]) {

				DrawStringEx(200, 600, -1, "◆◇四章（シナリオ・花札）◇◆");
				DrawStringEx(200, 630, -1, "解放条件：『参章』をクリア");
				DrawStringEx(200, 650, -1, "花札に勝利すると自動セーブがされます。");



			}

			if (CHAPTER_Select_b[4]) {

				DrawStringEx(200, 600, -1, "◆◇最終章（シナリオ・花札）◇◆");
				DrawStringEx(200, 630, -1, "解放条件：『四章』をクリア");
				DrawStringEx(200, 650, -1, "花札に勝利すると自動セーブがされます。");



			}





				SetDrawBlendMode(DX_BLENDMODE_ADD, 120);
				DrawRotaGraph(pos_x + (i * 200), pos_y, 1.05f, 0, CHAPTER_Image_Select[i], true);


				
				


									
		}

		//	画像の表示
		if (Key.Chapter_Unlock[i]) {
			
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 250);
				DrawRotaGraph(pos_x + (i * 200), pos_y, 1.0f, 0, CHAPTER_Image_[i], true);
									
		}
		else {

		//アンロック画像			
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 250);
				DrawRotaGraph(pos_x + (i * 200), pos_y, 1.0f, 0, CHAPTER_Image_[i], true);

				DrawRotaGraph(pos_x + (i * 200), pos_y, 1.0f, 0, CHAPTER_Lock_Image[i], true);
			
		}
		
	
				
	}




}
