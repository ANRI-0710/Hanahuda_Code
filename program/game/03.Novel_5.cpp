#include "DxLib.h"
#include "../library/t2klib.h"
#include "../support/Support.h"
#include "00.SceneMgr.h"
#include"02.Chapter.h"
#include "03.Novel_5.h"
#include "03.Novel_99_Modules.h"

static int kaiwabokkusu;
static int namae;

static int Scene = 0;

NovelModules Novel5;



//初期化
void Novel_CH_5_Initialize() {


	SetDrawArea(0, 70, 1024, 700);


	Novel5.Novel_Init(&Novel5);	//初期化


	namae = LoadGraph("graphics/wafuu_mini1_0921.png");
	kaiwabokkusu = LoadGraph("graphics/wafuu_kaiwabox.png");

	PlaySoundMem(Novel5.BGM5, DX_PLAYTYPE_LOOP);




}

//終了処理
void Novel_CH_5_Finalize() {


	Scene = 0;
	SetDrawArea(0, 0, 1024, 764);

	Novel5.Novel_Fin(&Novel5);	//初期化





}


//更新
void Novel_CH_5_Update() {

	










}


//描画
void Novel_CH_5_Draw() {

	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RETURN)) {

		Scene++;

	}

	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_S)) {

		Scene = 12;

	}


	if (Scene == 0) {


		Novel5.Tatie_BACKIMAGE(Novel5.Back_02);

		Novel5.Tatie_CENTER(Novel5.Tatie_05);



		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel5.Novel("妖狐",
			"『く…まさか貴様ごときにやられるなんて…』",
			"",
			"");







	}
	else if (Scene == 1) {

		Novel5.Tatie_BACKIMAGE(Novel5.Back_02);

	
		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel5.Novel("",
			"妖狐はだんだんと弱り、華凛の体に入っていた",
			"妖狐の魂が抜け落ちていく…。",
			"");


	}
	else if (Scene == 2) {

		Novel5.Tatie_BACKIMAGE(Novel5.Back_02);

		Novel5.Tatie_LEFT(Novel5.Tatie_03_O);
		Novel5.Tatie_Right(Novel5.Tatie_04_02_K);


		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel5.Novel("華凛",
			"『お…ねえちゃん……、突然いなくなって…ご…めんね…』",
			"",
			"");








	}
	else if (Scene == 3) {


		Novel5.Tatie_BACKIMAGE(Novel5.Back_02);

		Novel5.Tatie_LEFT(Novel5.Tatie_03_O);
		Novel5.Tatie_Right(Novel5.Tatie_04_02_K);


		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel5.Novel("",
			"まだ現世に留まっていた華凛の魂が、共鳴したのだろうか",
			"",
			"");







	}
	else if (Scene == 4) {


		Novel5.Tatie_BACKIMAGE(Novel5.Back_02);

		Novel5.Tatie_LEFT(Novel5.Tatie_03_O);
		Novel5.Tatie_Right(Novel5.Tatie_04_02_K);


		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel5.Novel("華凛",
			"『先に常世にいってるだけだから…ね…悲しまないで…』",
			"",
			"");







	}
	else if (Scene == 5) {

	Novel5.Tatie_BACKIMAGE(Novel5.Back_02);

	Novel5.Tatie_LEFT(Novel5.Tatie_03_O);
	Novel5.Tatie_Right(Novel5.Tatie_04_02_K);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel5.Novel("冬音",
		"『華凛・・・・！』",
		"",
		"");








	}
	else if (Scene == 6) {

	Novel5.Tatie_BACKIMAGE(Novel5.Back_02);

	Novel5.Tatie_LEFT(Novel5.Tatie_03_O);
	Novel5.Tatie_Right(Novel5.Tatie_04_02_K);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel5.Novel("華凛",
		"『また・・・・花札・・・しようね！』",
		"",
		"");







	}
	else if (Scene == 7) {


	Novel5.Tatie_BACKIMAGE(Novel5.Back_02);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel5.Novel("",
		"そう言い残すと、華凛の魂は常世に帰っていった。",
		"",
		"");








	}
	else if (Scene == 8) {


	Novel5.Tatie_BACKIMAGE(Novel5.Back_02);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel5.Novel("",
		"冬音を愛おしそうに本当に殻になった華凛の抱きしめた後に、",
		"こちらを向いた。",
		"");


	}
	else if (Scene == 9) {



	Novel5.Tatie_BACKIMAGE(Novel5.Back_02);

	Novel5.Tatie_LEFT(Novel5.Tatie_00_S);
	Novel5.Tatie_Right(Novel5.Tatie_03_S_2);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel5.Novel("冬音",
		"『当然いなくなっちゃうものだから…",
		"最後に言葉を交わすことができなかったの』",
		"");



	}
	else if (Scene == 10) {


	Novel5.Tatie_BACKIMAGE(Novel5.Back_02);

	Novel5.Tatie_LEFT(Novel5.Tatie_00_S);
	Novel5.Tatie_Right(Novel5.Tatie_03_S);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel5.Novel("冬音",
		"『千歳、本当にありがとう』",
		"",
		"");







	}
	else if (Scene == 11) {


	Novel5.Tatie_BACKIMAGE(Novel5.Back_05);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel5.Novel("",
		"こうして、呪われていた女生徒はすべて正気を取り戻し",
		"一連の事件の解決をした。",
		"");








	}
	else if (Scene == 12) {


	Novel5.Tatie_BACKIMAGE(Novel5.Back_05);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel5.Novel("",
		"春のせせらぎを感じながら、こうして無事に",
		"私はこの学院の生徒になったのだった。",
		"");









	}
	else if (Scene == 13) {





		SceneMgr_ChangeScene(Title);




	}




	DrawStringEx(670, 660, -1, "Sキーでシナリオスキップできます。");
}