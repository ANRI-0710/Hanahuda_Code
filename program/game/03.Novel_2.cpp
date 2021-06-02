#include "DxLib.h"
#include "../library/t2klib.h"
#include "../support/Support.h"
#include "00.SceneMgr.h"
#include"02.Chapter.h"
#include "03.Novel_2.h"
#include "03.Novel_99_Modules.h"

static int BGM;
static int test_tatie;
static int back;
static int kaiwabokkusu;
static int namae;
static int Scene = 0;

NovelModules Novel2;

//初期化
void Novel_CH_2_Initialize() {


	SetDrawArea(0, 70, 1024, 700);
	
	Novel2.Novel_Init(&Novel2);	//初期化

	
	namae = LoadGraph("graphics/wafuu_mini1_0921.png");
	kaiwabokkusu = LoadGraph("graphics/wafuu_kaiwabox.png");

	PlaySoundMem(Novel2.BGM3, DX_PLAYTYPE_LOOP);


}

//終了処理
void Novel_CH_2_Finalize() {

	Novel2.Novel_Fin(&Novel2);	//初期化
	Scene = 0;
	SetDrawArea(0, 0, 1024, 764);
	


}


//更新
void Novel_CH_2_Update() {




}


//描画
void Novel_CH_2_Draw() {


	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RETURN)) {

		Scene++;

	}

	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_S)) {

		Scene = 31;

	}



	if (Scene == 0) {

		Novel2.Tatie_BACKIMAGE(Novel2.Back_02);

		Novel2.Tatie_LEFT(Novel2.Tatie_00_I_1);
		Novel2.Tatie_Right(Novel2.Tatie_01_K);


		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel2.Novel("",
			"涼花との試合になんとか勝つことができた。",
			"",
			"");
	



	}
	else if (Scene == 1) {

		Novel2.Tatie_BACKIMAGE(Novel2.Back_02);

		Novel2.Tatie_LEFT(Novel2.Tatie_00_I_1);
		Novel2.Tatie_Right(Novel2.Tatie_01_K);


		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel2.Novel("涼花",
			"『あれ…わたし今までなにを…』",
			"",
			"");
		
		
			

	}
	else if (Scene == 2) {

		Novel2.Tatie_BACKIMAGE(Novel2.Back_02);

		Novel2.Tatie_LEFT(Novel2.Tatie_00_H);
		Novel2.Tatie_Right(Novel2.Tatie_01_K);


		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel2.Novel("",
			"どうやら正気を取り戻してくれたようだった。",
			"華凛がいってくれたように、この花札で勝つと",
			"呪いが解けるというのは本当のようだ。");

		
			
			



	}
	else if (Scene == 3) {


		Novel2.Tatie_BACKIMAGE(Novel2.Back_02);

		Novel2.Tatie_LEFT(Novel2.Tatie_00_H);
		Novel2.Tatie_Right(Novel2.Tatie_01_H);


		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel2.Novel("涼花",
			"『面白い花札で遊ぼうって、3年の先輩にいわれて、",
			"その先輩からもらった花札で",
			"遊んでいて勝負に負けたの』");


		
			
			



	}
	else if (Scene == 4) {

		Novel2.Tatie_BACKIMAGE(Novel2.Back_02);

		Novel2.Tatie_LEFT(Novel2.Tatie_00_H);
		Novel2.Tatie_Right(Novel2.Tatie_01_K);


		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel2.Novel("涼花",
			"『そしたら、だんだん意識が朦朧としてきて…そこから記憶がないの』",
			"",
			"");

		
			



	}
	else if (Scene == 5) {
		Novel2.Tatie_BACKIMAGE(Novel2.Back_02);

	


		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel2.Novel("",
			"なるほど。いろいろ話を聞いてみたが",
			"どうやら何者からもらった花札で勝負に負けてしまうと",
			"呪いに掛かってしまうらしい。");

		

	}
	else if (Scene == 6) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_02);

	


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("",
		"そして元凶を巻いているのは3年の先輩であることと、特定の1人から",
		"この呪いは拡散しているようだ。",
		"");

	
		

	}
	else if (Scene == 7) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_02);

	Novel2.Tatie_LEFT(Novel2.Tatie_00_S);
	Novel2.Tatie_Right(Novel2.Tatie_01_K);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("千歳",
		"『わかった。いろいろ聞かせてくれてありがとう』",
		"",
		"");

	
		



	}
	else if (Scene == 8) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_02);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("",
		"とりあえず、もう何人か呪いに掛かってしまった女生徒と勝負をすれば",
		"芋づる式で犯人が割り出せるかもしれない。",
		"");

	

	}
	else if (Scene == 9) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_02);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("",
		"そこで私は何人かの生徒と花札勝負をすることにした。",
		"",
		"");

	
	}
	else if (Scene == 10) {



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("",
		"・・・",
		"",
		"");
	

	}
	else if (Scene == 11) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_CENTER(Novel2.Tatie_02_H);
	
	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("",
		"何人かと勝負をした後、",
		"1人の凛とした女生徒がこちらに向かってきた。",
		"");
	

	}
	else if (Scene == 12) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_CENTER(Novel2.Tatie_02_I);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("？？？",
		"『私以外にも正気を保ちながら花札勝負してる奴がいるなんてね",
		"あなたも犯人捜しをしているのかしら？』",
		"");
	
	}
	else if (Scene == 13) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_Right(Novel2.Tatie_02_H);
	Novel2.Tatie_LEFT(Novel2.Tatie_00_H);

	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("千歳",
		"『ええ。私の名前は千歳。今日からこの学院に転校してきたの。』",
		"",
		"");
	
	}
	else if (Scene == 14) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_Right(Novel2.Tatie_02_S);
	Novel2.Tatie_LEFT(Novel2.Tatie_00_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("文香",
		"『私の名前は文香。二年よ。』",
		"",
		"");
		
	}
	else if (Scene == 15) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_Right(Novel2.Tatie_02_H);
	Novel2.Tatie_LEFT(Novel2.Tatie_00_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("千歳",
		"『貴女も、北校舎の倉庫で女の子からこの白い花札をもらったの？』",
		"",
		"");
	
		


	}
	else if (Scene == 16) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_Right(Novel2.Tatie_02_I);
	Novel2.Tatie_LEFT(Novel2.Tatie_00_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("文香",
		"『北校舎の倉庫？白い花札？そんなの知らないわ。",
		"私は小さい頃から花札をやっていて、負けしらずなのよ",
		"だから、他のみんなのようにおかしくなったりしないだけ』");
		

	}
	else if (Scene == 17) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("",
		"私は文香に、今まで起こったことの事象を説明をした。",
		"",
		"");
	

	}
	else if (Scene == 18) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_Right(Novel2.Tatie_02_S);
	Novel2.Tatie_LEFT(Novel2.Tatie_00_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("文香",
		"『なるほど、その白い花札で勝負をして勝つと、呪われた人間の",
		"呪いを解くことができるのね。』",
		"");
	

	}
	else if (Scene == 19) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_CENTER(Novel2.Tatie_02_S);
	


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("文香",
		"『・・・私、実は犯人を特定できたの』",
		"",
		"");
		

	}
	else if (Scene == 20) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_Right(Novel2.Tatie_02_I);
	Novel2.Tatie_LEFT(Novel2.Tatie_00_A);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("千歳",
		"『本当に！？』",
		"",
		"");
	
		



	}
	else if (Scene == 21) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_Right(Novel2.Tatie_02_H);
	Novel2.Tatie_LEFT(Novel2.Tatie_00_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("文香",
		"『ええ。3年生の冬音先輩が犯人みたいね』",
		"",
		"");
	
		

	}
	else if (Scene == 22) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_Right(Novel2.Tatie_02_I);
	Novel2.Tatie_LEFT(Novel2.Tatie_00_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("文香",
		"『彼女が複数人の女生徒に花札を渡したあとに、",
		"勝負をして呪いを掛けていたところを",
		"見かけた友達がいるのよ");

	
		
		

	}
	else if (Scene == 23) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_Right(Novel2.Tatie_02_I);
	Novel2.Tatie_LEFT(Novel2.Tatie_00_S);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("千歳",
		"『じゃあ、その先輩と説得するか、",
		"花札勝負に勝てばなんとかなるかもしれないね。』",
		"");

	
		


	}
	else if (Scene == 24) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_Right(Novel2.Tatie_02_S);
	Novel2.Tatie_LEFT(Novel2.Tatie_00_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("文香",
		"『おそらくね』",
		"",
		"");
	
		

	}
	else if (Scene == 25) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_Right(Novel2.Tatie_02_S);
	Novel2.Tatie_LEFT(Novel2.Tatie_00_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("文香",
		"『その前に私とあなたで花札をしない？』",
		"",
		"");
	
		

	}
	else if (Scene == 26) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_Right(Novel2.Tatie_02_S);
	Novel2.Tatie_LEFT(Novel2.Tatie_00_A);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("千歳",
		"『え…？』",
		"",
		"");
		

	}
	else if (Scene == 27) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_Right(Novel2.Tatie_02_I);
	Novel2.Tatie_LEFT(Novel2.Tatie_00_A);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("文香",
		"『一歩間違えて負けてしまえば、呪いにかかってしまうのだから",
		"より強い者がその白い花札を使って先輩に勝負を挑むべきよ』",
		"");
	

	}
	else if (Scene == 28) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_Right(Novel2.Tatie_02_I);
	Novel2.Tatie_LEFT(Novel2.Tatie_00_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("",
		"確かに、負けてしまえばこの身に何がおこるかわからない。",
		"",
		"");
	

	}
	else if (Scene == 29) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_Right(Novel2.Tatie_02_I);
	Novel2.Tatie_LEFT(Novel2.Tatie_00_I_1);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("千歳",
		"『わかったわ。勝負をしましょう。』",
		"",
		"");
	
		
		

	}
	else if (Scene == 30) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_Right(Novel2.Tatie_02_I);
	Novel2.Tatie_LEFT(Novel2.Tatie_00_I_1);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("",
		"こうして私は、文香との勝負をすることになった",
		"",
		"");
	

	}
	else if (Scene == 31) {

	


	SceneMgr_ChangeScene(Game_2);



	}


	DrawStringEx(670, 660, -1, "Sキーでシナリオスキップできます。");

}