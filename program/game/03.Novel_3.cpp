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



//������
void Novel_CH_3_Initialize() {

	SetDrawArea(0, 70, 1024, 700);


	Novel3.Novel_Init(&Novel3);	//������

	
	namae = LoadGraph("graphics/wafuu_mini1_0921.png");
	kaiwabokkusu = LoadGraph("graphics/wafuu_kaiwabox.png");

	PlaySoundMem(Novel3.BGM1, DX_PLAYTYPE_LOOP);

}

//�I������
void Novel_CH_3_Finalize() {


	Scene = 0;
	SetDrawArea(0, 0, 1024, 764);

	Novel3.Novel_Fin(&Novel3);	//������


}


//�X�V
void Novel_CH_3_Update() {

	



}


//�`��
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

		Novel3.Novel("����",
			"�w�������ˁB",
			"�M���ɂȂ��y�Ƃ̏����ɔC�������ˁx",
			"");

	




	}
	else if (Scene == 1) {

		Novel3.Tatie_BACKIMAGE(Novel3.Back_03);

		Novel3.Tatie_Right(Novel3.Tatie_02_K);
		Novel3.Tatie_LEFT(Novel3.Tatie_00_I_1);


		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel3.Novel("����",
			"�w���̐e�F���A��y�ƉԎD�����āc���������Ȃ��Ă��܂���",
			"���_�a�@����A���Ă��Ȃ��́B",
			"������A�ǂ����A�킢�ɏ����Ăق����́x");
	


	}
	else if (Scene == 2) {

		Novel3.Tatie_BACKIMAGE(Novel3.Back_03);

		Novel3.Tatie_Right(Novel3.Tatie_02_K);
		Novel3.Tatie_LEFT(Novel3.Tatie_00_H);


		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel3.Novel("���",
			"�w�����������́c�x",
			"",
			"");

			
		


	}
	else if (Scene == 3) {

		Novel3.Tatie_BACKIMAGE(Novel3.Back_03);

		Novel3.Tatie_CENTER(Novel3.Tatie_02_I);
	


		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel3.Novel("����",
			"�w����A�����������Ă��邤���ɂ��Ȃ��̉\�𕷂�����",
			"�����炩�����Ă����݂�����x",
			"");





	}
	else if (Scene == 4) {

		Novel3.Tatie_BACKIMAGE(Novel3.Back_04);
		Novel3.Tatie_CENTER(Novel3.Tatie_03_H_kamen);


		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel3.Novel("",
			"�����̘L���̑O�Ɂc�����c�~����y�������ӂ������Ă����B",
			"",
			"");





	}
	else if (Scene == 5) {

	Novel3.Tatie_BACKIMAGE(Novel3.Back_04);

	Novel3.Tatie_Right(Novel3.Tatie_03_H_kamen);
	Novel3.Tatie_LEFT(Novel3.Tatie_00_I_1);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel3.Novel("�~��",
		"�w�����������������ŁA������肭�i�݂����������̂�",
		"��񂾎ז����������݂����ˁB�x",
		"");





	}
	else if (Scene == 6) {

	Novel3.Tatie_BACKIMAGE(Novel3.Back_04);

	Novel3.Tatie_Right(Novel3.Tatie_03_H_kamen);
	Novel3.Tatie_LEFT(Novel3.Tatie_00_I_2);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel3.Novel("���",
		"�w�M���������Ȃ̂ˁd�d�ǂ����Ă���Ȃ��Ƃ�����́I�H�x",
		"",
		"");





	}
	else if (Scene == 7) {


	Novel3.Tatie_BACKIMAGE(Novel3.Back_04);

	Novel3.Tatie_Right(Novel3.Tatie_03_H_kamen);
	Novel3.Tatie_LEFT(Novel3.Tatie_00_I_1);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel3.Novel("�~��",
		"�w���R�𕷂����Ă����Ă��悢����ǁA",
		"���Ƃ̏����ɏ�������ˁB�x",
		"");




	}
	else if (Scene == 8) {

	Novel3.Tatie_BACKIMAGE(Novel3.Back_04);

	Novel3.Tatie_CENTER(Novel3.Tatie_03_H_kamen);
	


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel3.Novel("�~��",
		"�w�܂��A�������ł��傤����",
		"�M���͉i���ɗ��R�𕷂����ƂȂȂ��ł��傤�ˁI�x",
		"");



	}
	else if (Scene == 9) {

	Novel3.Tatie_BACKIMAGE(Novel3.Back_04);

	Novel3.Tatie_CENTER(Novel3.Tatie_03_H_kamen);



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel3.Novel("",
		"�������āA�����ł���~���Ƃ̉ԎD�������n�܂����B",
		"",
		"");





	}
	else if (Scene == 10) {


	SceneMgr_ChangeScene(Game_3);


	}
	
	
	
	DrawStringEx(670, 660, -1, "S�L�[�ŃV�i���I�X�L�b�v�ł��܂��B");
	




}