#include "DxLib.h"
#include "../library/t2klib.h"
#include "../support/Support.h"
#include "00.SceneMgr.h"
#include "01.TitleMgr.h"
#include "02.Chapter.h"
#include "03.Novel_1.h"
#include "03.Novel_2.h"
#include "03.Novel_3.h"
#include "03.Novel_4.h"
#include "03.Novel_5.h"
#include "04_01.HanahudaMgr.h"
#include "04_02.HanahudaMgr.h"
#include "04_03.HanahudaMgr.h"
#include "04_04.HanahudaMgr.h"

static eScene mNextScene = None;	//	次のシーンの管理変数
static eScene mScene = Title;	//	シーンの管理変数

static void SceneMgr_InitalizeModule(eScene scene);	//	指定モジュールの初期化処理を行う
static void SceneMgr_FinalizeModule(eScene scene);	//指定のモジュールの終了処理を行う


//初期化
void SceneMgr_Initialize() {

	SceneMgr_InitalizeModule(mScene);	//前シーンの終了処理するため、予約処理
}

//終了処理
void SceneMgr_Finalize() {

	SceneMgr_FinalizeModule(mScene);	//前シーンの終了処理するため、予約処理

}

//更新処理
void SceneMgr_Update() {

	if (mNextScene != None) {

		SceneMgr_FinalizeModule(mScene);	//現在のシーンの終了処理の実行・同時処理はできない
		mScene = mNextScene;	//次のシーンを現在のシーンに
		mNextScene = None; //次のシーン情報をクリア
		SceneMgr_InitalizeModule(mScene);	//移行したいシーンを初期化する

	}

	switch (mScene)	{	//シーンによって更新処理を分岐
		
	case Title:	//現在シーンがタイトルの場合
		Title_Update();	//各シーンの更新をする、以下省略
		break;
	case Chapter:
		Chapter_Update();
		break;
	case Novel_0:
		Novel_CH_1_Update();
		break;
	case Novel_1:
		//Novel_CH_1_Update();
		break;

	case Novel_2:
		Novel_CH_2_Update();
		break;

	case Novel_3:
		Novel_CH_3_Update();
		break;

	case Novel_4:
		Novel_CH_4_Update();
		break;

	case Novel_5:
		Novel_CH_5_Update();
		break;

	case Game_1:
		HanahudaMgr_Update();
		break;

	case Game_2:
		HanahudaMgr_Update_2();
		break;

	case Game_3:
		HanahudaMgr_Update_3();
		break;

	case Game_4:
		HanahudaMgr_Update_4();
		break;

	case Config:
		//Config_Update();
		break;		
	}

}

//描画処理
void SceneMgr_Draw() {

	switch (mScene) {	//シーンによって更新処理を分岐

	case Title:	//現在シーンがタイトルの場合
		Title_Draw();	//各シーンの更新をする、以下省略
		break;
	case Chapter:
		Chapter_Draw();
		break;
	case Novel_0:	//ノベル0話（プロローグ）
		Novel_CH_1_Draw();
		break;
	
	case Novel_1:
		//Novel_CH_1_Draw();
		break;

	case Novel_2:
		Novel_CH_2_Draw();
		break;

	case Novel_3:
		Novel_CH_3_Draw();
		break;

	case Novel_4:
		Novel_CH_4_Draw();
		break;
	
	case Novel_5:
		Novel_CH_5_Draw();
		break;

	case Game_1:
		HanahudaMgr_Draw();
		break;

	case Game_2:
		HanahudaMgr_Draw_2();
		break;

	case Game_3:
		HanahudaMgr_Draw_3();
		break;

	case Game_4:
		HanahudaMgr_Draw_4();
		break;

	case Config:
		//Config_Draw();
		break;
	}

}

//引数 nextSceneにシーンを変更する
void SceneMgr_ChangeScene(eScene nextScene) {

	mNextScene = nextScene;

}


//指定モジュールを初期化する
static void SceneMgr_InitalizeModule(eScene scene) {
	
		switch (scene) {	//シーンによって更新処理を分岐

		case Title:	//現在シーンがタイトルの場合			
			Title_Initialize();//各シーンの初期化をする、以下省略
			break;
		case Chapter:
			Chapter_Initialize();
			break;
		case Novel_0:
			Novel_CH_1_Initialize();
			break;
		case Novel_1:
			//Novel_CH_1_Initialize();
			break;

		case Novel_2:
			Novel_CH_2_Initialize();
			break;

		case Novel_3:
			Novel_CH_3_Initialize();
			break;

		case Novel_4:
			Novel_CH_4_Initialize();
			break;

		case Novel_5:
			Novel_CH_5_Initialize();
			break;

		case Game_1:
			HanahudaMgr_Initialize();
			break;

		case Game_2:
			HanahudaMgr_Initialize_2();
			break;

		case Game_3:
			HanahudaMgr_Initialize_3();
			break;

		case Game_4:
			HanahudaMgr_Initialize_4();
			break;

		case Config:
			//Config_Initialize();
			break;
		}
}

static void SceneMgr_FinalizeModule(eScene scene) {

	
	switch (scene) {

	case Title:	//現在シーンがタイトルの場合
		Title_Finalize();	//各シーンの初期化をする、以下省略
		break;
	case Chapter:
		Chapter_Finalize();
		break;
	case Novel_0:
		Novel_CH_1_Finalize();
		break;
	case Novel_1:
		//Novel_CH_1_Finalize();
		break;

	case Novel_2:
		Novel_CH_2_Finalize();
		break;

	case Novel_3:
		Novel_CH_3_Finalize();
		break;

	case Novel_4:
		Novel_CH_4_Finalize();
		break;

	case Novel_5:
		Novel_CH_5_Finalize();
		break;

	case Game_1:
		HanahudaMgr_Finalize();
		break;

	case Game_2:
		HanahudaMgr_Finalize_2();
		break;

	case Game_3:
		HanahudaMgr_Finalize_3();
		break;

	case Game_4:
		HanahudaMgr_Finalize_4();
		break;

	case Config:
		//Config_Finalize();
		break;
	}

}

