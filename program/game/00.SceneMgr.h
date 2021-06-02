#pragma once

//---------------------------------------------
//シーン遷移の管理クラス
//---------------------------------------------

typedef enum {

	Title, //メニュー画面
	Chapter,	//メインチャプター画面
	Novel_0,
	Novel_1,
	Novel_2,
	Novel_3,
	Novel_4,
	Novel_5,	//最終試合クリア後のエンディングシナリオ

	Game_1,
	Game_2,
	Game_3,
	Game_4,
	Config,
	None,

}eScene;

	
	void SceneMgr_Music();	//	音楽管理

	void SceneMgr_Initialize();	//初期化

	void SceneMgr_Finalize();	//終了処理

	void SceneMgr_Update();	//更新処理

	void SceneMgr_Draw();	//描画処理

	void SceneMgr_ChangeScene(eScene nextScene); //引数 nextSceneにシーンを変更する