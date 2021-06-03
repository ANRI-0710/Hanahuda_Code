#include "DxLib.h"
#include "../library/t2klib.h"
#include "../support/Support.h"
#include "00.SceneMgr.h"
#include "01.TitleMgr.h"


static int BackImage;		//背景
static int ENTER_SE;	//決定時SE
static int Title_BGM;
static int Change_SE;	//シフトキー移動のSE
static int Title_Font_Meicho;

static int Title_Box =  0 ;

typedef enum {
	eTitle_start,
	eTitle_Config,
	eTitle_Num,

}eTitle;

static int NowSelect = eTitle_start;
static int MUSIC_STOP = 0;

//初期化
void Title_Initialize() {

  //BGMとSEの初期化
	 BackImage = LoadGraph("graphics/01_Title_back.png"); //背景画像の初期化
	 ENTER_SE = LoadSoundMem("sound/DECISION_SE.mp3");
	 Title_BGM = LoadSoundMem("sound/TITLE_CHAPTER_BGM.mp3");
	 Change_SE = LoadSoundMem("sound/MOVE_CULSOL_SE.mp3");
	 Title_Font_Meicho = CreateFontToHandle("ＭＳ 明朝", 30, 9, DX_FONTTYPE_NORMAL);
	 Title_Box = LoadGraph("graphics/wafuu_kaiwabox.png");		 
	 PlaySoundMem(Title_BGM,DX_PLAYTYPE_LOOP);
}
	
	
//終了処理
void Title_Finalize() {				
	DeleteSoundMem(Title_BGM);
	DeleteGraph(BackImage);
	DeleteGraph(Change_SE);
	DeleteGraph(ENTER_SE);
	DeleteGraph(Title_Box);
	//SetFontSize(15);
}

//更新
void Title_Update() {				
	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RETURN)) {
		switch (NowSelect)
		{
		case eTitle_start:
			SceneMgr_ChangeScene(Chapter);
			break;
		
		case eTitle_Config:
			SceneMgr_ChangeScene(Config);
			break;
		}
	}
}


//描画
void Title_Draw() {		
	DrawRotaGraph(512, 384, 1.0f, 0, BackImage, true);	
	DrawRotaGraph(650, 650, 0.6f, 0, Title_Box, true);	
	DrawStringToHandle(490, 640, "-START TO ENTER KEY-", GetColor(255, 255, 255), Title_Font_Meicho);	
}



