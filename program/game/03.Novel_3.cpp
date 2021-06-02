#include "DxLib.h"
#include "../library/t2klib.h"
#include "../support/Support.h"
#include "00.SceneMgr.h"
#include"02.Chapter.h"
#include "03.Novel_3.h"
#include "03.Novel_99_Modules.h"

static int BGM;
static int test_tatie;
static int back;
static int kaiwabokkusu;
static int namae;

static int Scene = 0;

 NovelModules Novel3;



//初期化
void Novel_CH_3_Initialize() {

	SetDrawArea(0, 70, 1024, 700);


	Novel3.Novel_Init(&Novel3);	//初期化

	
	namae = LoadGraph("graphics/wafuu_mini1_0921.png");
	kaiwabokkusu = LoadGraph("graphics/wafuu_kaiwabox.png");

	PlaySoundMem(Novel3.BGM1, DX_PLAYTYPE_LOOP);

}

//終了処理
void Novel_CH_3_Finalize() {


	Scene = 0;
	SetDrawArea(0, 0, 1024, 764);

	Novel3.Novel_Fin(&Novel3);	//初期化


}


//更新
void Novel_CH_3_Update() {

	



}


//描画
void Novel_CH_3_Draw() {

	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RETURN)) {

		Scene++;

	}

	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_S)) {

		Scene = 10;

	}


	
	if (Scene == 0) {

		Novel3.Tatie_BACKIMAGE(Novel3.Back_03);

		Novel3.Tatie_Right(Novel3.Tatie_02_S);
		Novel3.Tatie_LEFT(Novel3.Tatie_00_I_1);


		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel3.Novel("文香",
			"『さすがね。",
			"貴女になら先輩との勝負に任せられるわね』",
			"");

	




	}
	else if (Scene == 1) {

		Novel3.Tatie_BACKIMAGE(Novel3.Back_03);

		Novel3.Tatie_Right(Novel3.Tatie_02_K);
		Novel3.Tatie_LEFT(Novel3.Tatie_00_I_1);


		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel3.Novel("文香",
			"『私の親友も、先輩と花札をして…おかしくなってしまって",
			"精神病院から帰ってこないの。",
			"だから、どうか、戦いに勝ってほしいの』");
	


	}
	else if (Scene == 2) {

		Novel3.Tatie_BACKIMAGE(Novel3.Back_03);

		Novel3.Tatie_Right(Novel3.Tatie_02_K);
		Novel3.Tatie_LEFT(Novel3.Tatie_00_H);


		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel3.Novel("千歳",
			"『そうだったの…』",
			"",
			"");

			
		


	}
	else if (Scene == 3) {

		Novel3.Tatie_BACKIMAGE(Novel3.Back_03);

		Novel3.Tatie_CENTER(Novel3.Tatie_02_I);
	


		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel3.Novel("文香",
			"『あら、そうこうしているうちにあなたの噂を聞きつけて",
			"こちらからやってきたみたいよ』",
			"");





	}
	else if (Scene == 4) {

		Novel3.Tatie_BACKIMAGE(Novel3.Back_04);
		Novel3.Tatie_CENTER(Novel3.Tatie_03_H_kamen);


		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel3.Novel("",
			"教室の廊下の前に…そう…冬音先輩が立ちふさがっていた。",
			"",
			"");





	}
	else if (Scene == 5) {

	Novel3.Tatie_BACKIMAGE(Novel3.Back_04);

	Novel3.Tatie_Right(Novel3.Tatie_03_H_kamen);
	Novel3.Tatie_LEFT(Novel3.Tatie_00_I_1);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel3.Novel("冬音",
		"『せっかくもう少しで、事が上手く進みそうだったのに",
		"飛んだ邪魔が入ったみたいね。』",
		"");





	}
	else if (Scene == 6) {

	Novel3.Tatie_BACKIMAGE(Novel3.Back_04);

	Novel3.Tatie_Right(Novel3.Tatie_03_H_kamen);
	Novel3.Tatie_LEFT(Novel3.Tatie_00_I_2);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel3.Novel("千歳",
		"『貴女が元凶なのね‥‥どうしてこんなことをするの！？』",
		"",
		"");





	}
	else if (Scene == 7) {


	Novel3.Tatie_BACKIMAGE(Novel3.Back_04);

	Novel3.Tatie_Right(Novel3.Tatie_03_H_kamen);
	Novel3.Tatie_LEFT(Novel3.Tatie_00_I_1);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel3.Novel("冬音",
		"『理由を聞かせてあげてもよいけれど、",
		"私との勝負に勝ったらね。』",
		"");




	}
	else if (Scene == 8) {

	Novel3.Tatie_BACKIMAGE(Novel3.Back_04);

	Novel3.Tatie_CENTER(Novel3.Tatie_03_H_kamen);
	


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel3.Novel("冬音",
		"『まぁ、私が勝つでしょうから",
		"貴女は永遠に理由を聞くことなないでしょうね！』",
		"");



	}
	else if (Scene == 9) {

	Novel3.Tatie_BACKIMAGE(Novel3.Back_04);

	Novel3.Tatie_CENTER(Novel3.Tatie_03_H_kamen);



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel3.Novel("",
		"こうして、元凶である冬音との花札勝負が始まった。",
		"",
		"");





	}
	else if (Scene == 10) {


	SceneMgr_ChangeScene(Game_3);


	}
	
	
	
	DrawStringEx(670, 660, -1, "Sキーでシナリオスキップできます。");
	




}