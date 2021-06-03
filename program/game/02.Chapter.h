#pragma once

//---------------------------------------------
//チャプターシーンの管理クラス
//---------------------------------------------

//チャプターアンロックの制御クラス
class Chapter_Key {
public:
	bool Chapter_Unlock[5] = { 1,0,0,0,0 };	//チャプター制御用
};

enum eChapter_Unlock {
	eUnlock_Chpter_0,	//チャプター0話・プロローグのため最初から解放
	eUnlock_Chpter_1,	//チャプター1話、0話読了後解放される
	eUnlock_Chpter_2,	//チャプター2話、1話での花札の戦闘で勝利後解放される
	eUnlock_Chpter_3,	//チャプター3話、2話での花札の戦闘で勝利後解放される
	eUnlock_Chpter_4,	//チャプター最終話、3話での花札の戦闘で勝利後解放される
};


//セーブデータ管理
struct save_deta_t {
	bool s_Chapter_Unlock[5] = {1,0,0,0,0};
};

//初期化
void Chapter_Initialize();

//終了処理
void Chapter_Finalize();

//更新
void Chapter_Update();

	//更新-チャプター制御解除用関数
	void Chapter_Unlock(int *chapter_NUM);

//描画
void Chapter_Draw();


