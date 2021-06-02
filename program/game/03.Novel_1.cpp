#include "DxLib.h"
#include "../library/t2klib.h"
#include "../support/Support.h"
#include "00.SceneMgr.h"
#include"02.Chapter.h"
#include "03.Novel_1.h"
#include "03.Novel_99_Modules.h"

static int BGM;
static int test_tatie;
static int back;
static int kaiwabokkusu;
static int namae;
static int Scene = 0;

NovelModules Novel0;

//初期化
void Novel_CH_1_Initialize() {

	SetDrawArea(0, 70, 1024, 700);

	
	Novel0.Novel_Init(&Novel0);	//初期化
	namae = LoadGraph("graphics/wafuu_mini1_0921.png");
	kaiwabokkusu = LoadGraph("graphics/wafuu_kaiwabox.png");
	PlaySoundMem(Novel0.BGM2,DX_PLAYTYPE_LOOP);
	
}

//終了処理
void Novel_CH_1_Finalize() {
	
	SetDrawArea(0, 0, 1024, 764);
	Novel0.Novel_Fin(&Novel0);	//初期化
	Scene = 0;
	
}

//更新
void Novel_CH_1_Update() {

}


//描画
void Novel_CH_1_Draw() {

	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RETURN)) {

		Scene++;
	}

	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_S)) {

		Scene = 35;
	}

	if (Scene == 0) {
		
		Novel0.Tatie_BACKIMAGE(Novel0.Back_01);
		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel0.Novel("",
			"大正8年の卯月の時が終わるころ、",
			"私、鏑木千歳（チトセ）は両親の引っ越しと共に",
			"伊勢市にある高等女学院に転校をすることになった。");

	}
	else if (Scene == 1) {
		
		Novel0.Tatie_BACKIMAGE(Novel0.Back_01);
		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel0.Novel("",
			"今日は初の登校日なのだが、どうも学院の様子がおかしい",
			"",
			"");

	}
	else if (Scene == 2) {
		
		Novel0.Tatie_BACKIMAGE(Novel0.Back_01);
		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel0.Novel("",
			"先ほど担任の先生ともお会いしたが、",
			"自分の転校手続きの話をおろそかに",
			"何処か虚ろな顔で笑いながら不思議な花札の話しかしないのだ。");
		

	}
	else if (Scene == 3) {

		Novel0.Tatie_BACKIMAGE(Novel0.Back_01);
		Novel0.Tatie_LEFT(Novel0.Tatie_00_H);
		Novel0.Tatie_Right(Novel0.Tatie_MOBU_H);

		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel0.Novel("女生徒",
			"『待って待って！早く私と花札で遊びましょう！",
			"きっと楽しいわ！』",
			"");

	}
	else if (Scene == 4) {

		Novel0.Tatie_BACKIMAGE(Novel0.Back_01);
		Novel0.Tatie_LEFT(Novel0.Tatie_00_A);
		Novel0.Tatie_Right(Novel0.Tatie_MOBU_H);

		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel0.Novel("千歳",
			"『ええと、ごめん。また後でね』",
			"",
			"");



	}
	else if (Scene == 5) {
		
		Novel0.Tatie_BACKIMAGE(Novel0.Back_01);

	
		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel0.Novel("",
			"どの生徒と話しても、転校生の私への挨拶を抜きに",
			"不思議な花札での遊びを持ち掛けてくる。",
			"中には狂ったように追いかけてくる子もいた。");
		


	}
	else if (Scene == 6) {

	Novel0.Tatie_BACKIMAGE(Novel0.Back_01);

	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);


	Novel0.Novel("",
		"まるで皆何かに取り憑かれているようなのだ。",
		"",
		"");
	



	}
	else if (Scene == 7) {

		Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	

		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel0.Novel("",
			"恐怖心に駆られた私は、",
			"誰もいなさそうな北校舎の倉庫室に",
			"逃げてきたのである。");
		
		
			
			



	}
	else if (Scene == 8) {

		Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

		

		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel0.Novel("",
			"あの花札で遊んでしまったら・・・",
			"とても嫌な予感がしたのだ。",
			"");

		
			


	}
	else if (Scene == 9) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	Novel0.Tatie_LEFT(Novel0.Tatie_00_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("千歳",
		"『さて、どうしようかな…』",
		"",
		"");


	
		


	}
	else if (Scene == 10) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	Novel0.Tatie_LEFT(Novel0.Tatie_00_H);
	

	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("？？？",
		"『そこで、何をしているの？』",
		"",
		"");

	
		


	}
	else if (Scene == 11) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	Novel0.Tatie_LEFT(Novel0.Tatie_00_A);
	


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("千歳",
		"『！？』",
		"",
		"");


	
		

	}
	else if (Scene == 12) {


	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	Novel0.Tatie_CENTER(Novel0.Tatie_04_H);
	


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("",
		"振り向くとそこには、日本人形のようだけど",
		"正気がありそうな女の子が立っていた。",
		"");

	
		


	}
	else if (Scene == 13) {


	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	Novel0.Tatie_LEFT(Novel0.Tatie_00_H);
	Novel0.Tatie_Right(Novel0.Tatie_04_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("？？？",
		"『あ、気づいてくれたんだ！うれしいな』",
		"",
		"");

	
	}
	else if (Scene == 14) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	Novel0.Tatie_LEFT(Novel0.Tatie_00_A);
	Novel0.Tatie_Right(Novel0.Tatie_04_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("？？？",
		"『ごきげんよう。私の名前は華凛。",
		"よろしくね』",
		"");

	
		
		



	}
	else if (Scene == 15) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	Novel0.Tatie_LEFT(Novel0.Tatie_00_S);
	Novel0.Tatie_Right(Novel0.Tatie_04_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("千歳",
		"『私は千歳。今日初めて転校してきたの",
		"よろしくね。』",
		"");

	
		
		



	}
	else if (Scene == 16) {


	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	Novel0.Tatie_LEFT(Novel0.Tatie_00_H);
	Novel0.Tatie_Right(Novel0.Tatie_04_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("千歳",
		"『ところで聞きたいのだけど、学院の様子がとてもおかしいの。",
		"みんな不思議な花札で遊ぼうと持ち掛けてきて、",
		"嫌な予感がして逃げてきたところ。』");

	
		
		
		


	}
	else if (Scene == 17) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	Novel0.Tatie_LEFT(Novel0.Tatie_00_H);
	Novel0.Tatie_Right(Novel0.Tatie_04_H_2);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("華凛",
		"『…！あなた呪いにかかってないみたいね』",
		"",
		"");

	
		



	}
	else if (Scene == 18) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	Novel0.Tatie_LEFT(Novel0.Tatie_00_H);
	Novel0.Tatie_Right(Novel0.Tatie_04_H_2);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("千歳",
		"『呪い？』",
		"",
		"");

	
	}
	else if (Scene == 19) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	Novel0.Tatie_LEFT(Novel0.Tatie_00_H);
	Novel0.Tatie_Right(Novel0.Tatie_04_H_2);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("華凛",
		"『もしかしたらあなただったら…』",
		"",
		"");

	
	}	
	else if (Scene == 20) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	Novel0.Tatie_LEFT(Novel0.Tatie_00_H);
	Novel0.Tatie_Right(Novel0.Tatie_04_H_2);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("",
		"呪い？なんのこと？と",
		"聞こうとした瞬間、華凛から白く美しい花札を手渡された。",
		"");

	
		



	}
	else if (Scene == 21) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	Novel0.Tatie_LEFT(Novel0.Tatie_00_H);
	Novel0.Tatie_Right(Novel0.Tatie_04_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("華凛",
		"『使い手を選ぶのだけど、あなただったらきっと大丈夫』",
		"",
		"");


	
		



	}
	else if (Scene == 22) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	Novel0.Tatie_LEFT(Novel0.Tatie_00_H);
	Novel0.Tatie_Right(Novel0.Tatie_04_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("華凛",
		"『この花札で勝負して勝つことができたら、",
		"掛けられた呪いから解放することができるはず』",
		"");

	
		
		



	}
	else if (Scene == 23) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	
	Novel0.Tatie_CENTER(Novel0.Tatie_04_K);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("華凛",
		"『どうか…みんなを…姉を救って…』",
		"",
		"");

	
		



	}
	else if (Scene == 24) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	
	Novel0.Tatie_CENTER(Novel0.Tatie_00_A);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("千歳",
		"『え？どういうこと…？』",
		"",
		"");

	
		



	}
	else if (Scene == 25) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	
	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("",
		"と、華凛を問いだたそうとして振り向いたら",
		"彼女はいつの間にかいなくなっていたのだ。",
		"");




	}
	else if (Scene == 26) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);





	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("？？？",
		"『あら、あなた、一体どなたとお話していたの？』",
		"",
		"");

	
		


	}
	else if (Scene == 27) {


	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	Novel0.Tatie_CENTER(Novel0.Tatie_01_H);
	


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("",
		"校舎の倉庫室の入口から、",
		"先ほど花札で遊ぼうと",
		"追いかけてきたうちの女生徒の一人、涼花がいた。");


	}
	else if (Scene == 28) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);


	Novel0.Tatie_LEFT(Novel0.Tatie_00_H);
	Novel0.Tatie_Right(Novel0.Tatie_01_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("",
		"まずい、みつかってしまった…。",
		"",
		"");

	



	}
	else if (Scene == 29) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);


	Novel0.Tatie_LEFT(Novel0.Tatie_00_H);
	Novel0.Tatie_Right(Novel0.Tatie_01_S);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("涼花",
		"『やっと、見つけた！さぁ、私と花札で遊びましょう♪』",
		"",
		"");

	
		


	}
	else if (Scene == 30) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);


	Novel0.Tatie_LEFT(Novel0.Tatie_00_I_1);
	Novel0.Tatie_Right(Novel0.Tatie_01_S);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("千歳",
		"『・・・・・・』",
		"",
		"");


	
		


	}
	else if (Scene == 31) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);


	Novel0.Tatie_LEFT(Novel0.Tatie_00_I_1);
	Novel0.Tatie_Right(Novel0.Tatie_01_S);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("",
		"状況は全く理解はできてはいない。",
		"",
		"");

	


	}
	else if (Scene == 32) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);


	Novel0.Tatie_LEFT(Novel0.Tatie_00_I_1);
	Novel0.Tatie_Right(Novel0.Tatie_01_S);

	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("",
		"しかし、この学院で起こっている謎を解くためには",
		"この白い花札で、勝負をして勝つしかない。",
		"");

	
		


	}
	else if (Scene == 33) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);


	Novel0.Tatie_LEFT(Novel0.Tatie_00_I_2);
	Novel0.Tatie_Right(Novel0.Tatie_01_S);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("千歳",
		"『ええ、望むところよ。』",
		"",
		"");

	
		


	}
	else if (Scene == 34) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	Novel0.Tatie_LEFT(Novel0.Tatie_00_I_2);
	Novel0.Tatie_Right(Novel0.Tatie_01_S);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("",
		"白い花札を強く握りしめ",
		"私は涼花との花札勝負を始めた。",
		"");

	
		


	}
	else if (Scene == 35) {



		int UNLOCK = eUnlock_Chpter_1;
		Chapter_Unlock(&UNLOCK);

		SceneMgr_ChangeScene(Chapter);





	}



	DrawStringEx(670, 660, -1, "Sキーでシナリオスキップできます。");




}






