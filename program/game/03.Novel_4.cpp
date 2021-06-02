#include "DxLib.h"
#include "../library/t2klib.h"
#include "../support/Support.h"
#include "00.SceneMgr.h"
#include"02.Chapter.h"
#include "03.Novel_4.h"
#include "03.Novel_99_Modules.h"


static int kaiwabokkusu;
static int namae;

static int Scene = 0;

NovelModules Novel4;


//初期化
void Novel_CH_4_Initialize() {


	SetDrawArea(0, 70, 1024, 700);


	Novel4.Novel_Init(&Novel4);	//初期化


	namae = LoadGraph("graphics/wafuu_mini1_0921.png");
	kaiwabokkusu = LoadGraph("graphics/wafuu_kaiwabox.png");

	PlaySoundMem(Novel4.BGM4, DX_PLAYTYPE_LOOP);








}

//終了処理
void Novel_CH_4_Finalize() {


	Scene = 0;
	SetDrawArea(0, 0, 1024, 764);

	Novel4.Novel_Fin(&Novel4);	//初期化





}


//更新
void Novel_CH_4_Update() {





	






}


//描画
void Novel_CH_4_Draw() {

	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RETURN)) {

		Scene++;

	}

	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_S)) {

		Scene = 33;

	}


	if (Scene == 0) {
	
	
		Novel4.Tatie_BACKIMAGE(Novel4.Back_04);

		Novel4.Tatie_CENTER(Novel4.Tatie_03_H_kamen);



		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel4.Novel("冬音",
			"『まさか私が負けるなんて…』",
			"",
			"");





	
	
	}
	else if (Scene == 1) {


		Novel4.Tatie_BACKIMAGE(Novel4.Back_04);

		Novel4.Tatie_CENTER(Novel4.Tatie_03_H);

		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel4.Novel("",
			"狐のお面を外した先輩が物悲しそうに、呟いた。",
			"",
			"");


	}
	else if (Scene == 2) {


		Novel4.Tatie_BACKIMAGE(Novel4.Back_04);

		Novel4.Tatie_CENTER(Novel4.Tatie_03_H);



		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel4.Novel("冬音",
			"『わかりました。すべてをお話ししましょう。",
			"北校舎の倉庫室までついてきて。そこで話すわ』",
			"");




	}
	else if (Scene == 3) {

		Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

		



		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel4.Novel("",
			"そういわれて、私は北校舎の倉庫にやってきた。",
			"",
			"");





	}
	else if (Scene == 4) {

		Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

		Novel4.Tatie_CENTER(Novel4.Tatie_03_H);



		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel4.Novel("冬音",
			"『…つい先日、私の妹が亡くなったの。』",
			"",
			"");





	}
	else if (Scene == 5) {


	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("",
		"今年の春からこの高校に入学する予定だった妹さん",
		"だったが、入学式の当日に交通事故にあって亡くなってしまったらしい。",
		"");




	}
	else if (Scene == 6) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	Novel4.Tatie_CENTER(Novel4.Tatie_03_S);



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("冬音",
		"『私は妹のことが大好きで、いつも白い花札で彼女と遊ぶのが",
		"幸せだった…』",
		"");





	}
	else if (Scene == 7) {


	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	Novel4.Tatie_CENTER(Novel4.Tatie_03_I);



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("冬音",
		"『……何にもする気になれず、私も死のうしてきたところに…",
		"やってきたの…』",
		"");




	}
	else if (Scene == 8) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	Novel4.Tatie_CENTER(Novel4.Tatie_03_I);



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("冬音",
		"『狐が…』",
		"",
		"");





	}
	else if (Scene == 9) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	
	Novel4.Tatie_LEFT(Novel4.Tatie_00_A);
	Novel4.Tatie_Right(Novel4.Tatie_03_I);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("千歳",
		"『き、狐…！』",
		"",
		"");




	}
	else if (Scene == 10) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	Novel4.Tatie_LEFT(Novel4.Tatie_00_A);
	Novel4.Tatie_Right(Novel4.Tatie_03_I);



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("",
		"大正の世であるが、まさか妖狐の部類まで存在していたなんて。",
		"信じられなかった。",
		"");





	}
	else if (Scene == 11) {


	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	Novel4.Tatie_LEFT(Novel4.Tatie_00_A);
	Novel4.Tatie_Right(Novel4.Tatie_03_I);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("冬音",
		"『狐がこういったの、",
		"お前の妹を生き返らせる代わりに、この呪われた花札を",
		"ばら撒き、そして勝負に勝ち、その者の精気をこの桶の中に集めろと』");





	}
	else if (Scene == 12) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	Novel4.Tatie_LEFT(Novel4.Tatie_00_A);
	Novel4.Tatie_Right(Novel4.Tatie_03_I);



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("千歳",
		"『ちょっと待って、その桶の中に入っているのってもしかして…』",
		"",
		"");






	}
	else if (Scene == 13) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	Novel4.Tatie_LEFT(Novel4.Tatie_00_A);
	Novel4.Tatie_Right(Novel4.Tatie_03_H);



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("冬音",
		"『ええ…妹の死体が入っているわ…』",
		"",
		"");






	}
	else if (Scene == 14) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	

	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("",
		"驚きのあまり、言葉を失ってしまった。",
		"",
		"");






	}
	else if (Scene == 15) {


	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	Novel4.Tatie_LEFT(Novel4.Tatie_00_A);
	Novel4.Tatie_Right(Novel4.Tatie_03_S);



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("冬音",
		"『でも、もういいの、悲しいけれど…",
		"貴女のおかげであきらめることができたわ』",
		"");





	}
	else if (Scene == 16) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	Novel4.Tatie_Right(Novel4.Tatie_03_H);
	Novel4.Tatie_LEFT(Novel4.Tatie_00_H);



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("千歳",
		"『もしかして、あなたの妹さんの名前って華凛って子？』",
		"",
		"");



	}
	else if (Scene == 17) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	Novel4.Tatie_Right(Novel4.Tatie_03_O);
	Novel4.Tatie_LEFT(Novel4.Tatie_00_H);



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("冬音",
		"『！？",
		"どうしてあなたがその名前を？』",
		"");



	}
	else if (Scene == 18) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("？？？",
		"『ククク・・・・』",
		"",
		"");



	}
	else if (Scene == 19) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	Novel4.Tatie_CENTER(Novel4.Tatie_05);



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("",
		"どこからともなく、怪しい妖狐が、現れたのである。",
		"",
		"");



	}
	else if (Scene == 20) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	Novel4.Tatie_CENTER(Novel4.Tatie_00_A);



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("千歳",
		"『狐…！』",
		"",
		"");



	}
	else if (Scene == 21) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	Novel4.Tatie_CENTER(Novel4.Tatie_05);



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("妖狐",
		"『契約不履行ってことかね…？でももう遅い…！』",
		"",
		"");



	}
	else if (Scene == 22) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	Novel4.Tatie_CENTER(Novel4.Tatie_05);



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("妖狐",
		"『精気は十分に集まった。",
		"約束通り、貴様の願いを叶えてやろう』",
		"");



	}
	else if (Scene == 23) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);


	Novel4.Tatie_CENTER(Novel4.Tatie_04_02_H_2);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("",
		"眩い輝きを放ったあと、狐耳の少女が鎮座していた。",
		"",
		"");



	}
	else if (Scene == 24) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);


	Novel4.Tatie_CENTER(Novel4.Tatie_03_O);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("冬音",
		"華凛！！！！！！！",
		"",
		"");



	}
	else if (Scene == 25) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);


	Novel4.Tatie_CENTER(Novel4.Tatie_04_02_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("？？？",
		"『ククク…ご苦労様でした。』",
		"",
		"");



	}
	else if (Scene == 26) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);


	Novel4.Tatie_CENTER(Novel4.Tatie_03_O);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("冬音",
		"『きゃっ…っ』",
		"",
		"");



	}
	else if (Scene == 27) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);


	


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("",
		"華凛の姿をした何者かは、強い霊力で冬音を吹き飛ばした。",
		"",
		"");



	}
	else if (Scene == 28) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);


	Novel4.Tatie_Right(Novel4.Tatie_04_02_H);
	Novel4.Tatie_LEFT(Novel4.Tatie_00_I_1);

	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("妖狐",
		"『ちょうど魂が抜け落ちた動ける肉体が欲しかったんだよ』",
		"",
		"");



	}
	else if (Scene == 29) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);


	Novel4.Tatie_Right(Novel4.Tatie_04_02_H_2);
	Novel4.Tatie_LEFT(Novel4.Tatie_00_I_1);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("妖狐",
		"『これで、また小癪な手を使わずとも、人間共倒せる…！』",
		"",
		"");



	}
	else if (Scene == 30) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("",
		"そう、妖狐は妹を亡くした冬音に付け込んで、",
		"上手く騙していただけなのだった。",
		"");



	}
	else if (Scene == 31) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	Novel4.Tatie_Right(Novel4.Tatie_04_02_H_2);
	Novel4.Tatie_LEFT(Novel4.Tatie_00_I_2);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("千歳",
		"『人の弱みにつけこんで…絶対に許さない！』",
		"",
		"");



	}

	else if (Scene == 32) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	Novel4.Tatie_Right(Novel4.Tatie_04_02_H_2);
	Novel4.Tatie_LEFT(Novel4.Tatie_00_I_2);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("",
		"こうして、私は最後の力を振り絞り、妖狐との闘いに挑んだ。",
		"",
		"");



	}
	else if (Scene == 33) {

	
		SceneMgr_ChangeScene(Game_4);

	}

	DrawStringEx(670, 660, -1, "Sキーでシナリオスキップできます。");

}