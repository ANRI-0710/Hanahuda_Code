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



//������
void Novel_CH_5_Initialize() {


	SetDrawArea(0, 70, 1024, 700);


	Novel5.Novel_Init(&Novel5);	//������


	namae = LoadGraph("graphics/wafuu_mini1_0921.png");
	kaiwabokkusu = LoadGraph("graphics/wafuu_kaiwabox.png");

	PlaySoundMem(Novel5.BGM5, DX_PLAYTYPE_LOOP);




}

//�I������
void Novel_CH_5_Finalize() {


	Scene = 0;
	SetDrawArea(0, 0, 1024, 764);

	Novel5.Novel_Fin(&Novel5);	//������





}


//�X�V
void Novel_CH_5_Update() {

	










}


//�`��
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

		Novel5.Novel("�d��",
			"�w���c�܂����M�l���Ƃ��ɂ����Ȃ�āc�x",
			"",
			"");







	}
	else if (Scene == 1) {

		Novel5.Tatie_BACKIMAGE(Novel5.Back_02);

	
		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel5.Novel("",
			"�d�ς͂��񂾂�Ǝ��A�ؙz�̑̂ɓ����Ă���",
			"�d�ς̍������������Ă����c�B",
			"");


	}
	else if (Scene == 2) {

		Novel5.Tatie_BACKIMAGE(Novel5.Back_02);

		Novel5.Tatie_LEFT(Novel5.Tatie_03_O);
		Novel5.Tatie_Right(Novel5.Tatie_04_02_K);


		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel5.Novel("�ؙz",
			"�w���c�˂������c�c�A�ˑR���Ȃ��Ȃ��āc���c�߂�ˁc�x",
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
			"�܂������ɗ��܂��Ă����ؙz�̍����A�������̂��낤��",
			"",
			"");







	}
	else if (Scene == 4) {


		Novel5.Tatie_BACKIMAGE(Novel5.Back_02);

		Novel5.Tatie_LEFT(Novel5.Tatie_03_O);
		Novel5.Tatie_Right(Novel5.Tatie_04_02_K);


		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel5.Novel("�ؙz",
			"�w��ɏ퐢�ɂ����Ă邾��������c�ˁc�߂��܂Ȃ��Łc�x",
			"",
			"");







	}
	else if (Scene == 5) {

	Novel5.Tatie_BACKIMAGE(Novel5.Back_02);

	Novel5.Tatie_LEFT(Novel5.Tatie_03_O);
	Novel5.Tatie_Right(Novel5.Tatie_04_02_K);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel5.Novel("�~��",
		"�w�ؙz�E�E�E�E�I�x",
		"",
		"");








	}
	else if (Scene == 6) {

	Novel5.Tatie_BACKIMAGE(Novel5.Back_02);

	Novel5.Tatie_LEFT(Novel5.Tatie_03_O);
	Novel5.Tatie_Right(Novel5.Tatie_04_02_K);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel5.Novel("�ؙz",
		"�w�܂��E�E�E�E�ԎD�E�E�E���悤�ˁI�x",
		"",
		"");







	}
	else if (Scene == 7) {


	Novel5.Tatie_BACKIMAGE(Novel5.Back_02);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel5.Novel("",
		"���������c���ƁA�ؙz�̍��͏퐢�ɋA���Ă������B",
		"",
		"");








	}
	else if (Scene == 8) {


	Novel5.Tatie_BACKIMAGE(Novel5.Back_02);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel5.Novel("",
		"�~���������������ɖ{���Ɋk�ɂȂ����ؙz�̕������߂���ɁA",
		"��������������B",
		"");


	}
	else if (Scene == 9) {



	Novel5.Tatie_BACKIMAGE(Novel5.Back_02);

	Novel5.Tatie_LEFT(Novel5.Tatie_00_S);
	Novel5.Tatie_Right(Novel5.Tatie_03_S_2);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel5.Novel("�~��",
		"�w���R���Ȃ��Ȃ����Ⴄ���̂�����c",
		"�Ō�Ɍ��t�����킷���Ƃ��ł��Ȃ������́x",
		"");



	}
	else if (Scene == 10) {


	Novel5.Tatie_BACKIMAGE(Novel5.Back_02);

	Novel5.Tatie_LEFT(Novel5.Tatie_00_S);
	Novel5.Tatie_Right(Novel5.Tatie_03_S);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel5.Novel("�~��",
		"�w��΁A�{���ɂ��肪�Ƃ��x",
		"",
		"");







	}
	else if (Scene == 11) {


	Novel5.Tatie_BACKIMAGE(Novel5.Back_05);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel5.Novel("",
		"�������āA����Ă��������k�͂��ׂĐ��C�����߂�",
		"��A�̎����̉����������B",
		"");








	}
	else if (Scene == 12) {


	Novel5.Tatie_BACKIMAGE(Novel5.Back_05);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel5.Novel("",
		"�t�̂����炬�������Ȃ���A�������Ė�����",
		"���͂��̊w�@�̐��k�ɂȂ����̂������B",
		"");









	}
	else if (Scene == 13) {





		SceneMgr_ChangeScene(Title);




	}




	DrawStringEx(670, 660, -1, "S�L�[�ŃV�i���I�X�L�b�v�ł��܂��B");
}