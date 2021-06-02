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


//������
void Novel_CH_4_Initialize() {


	SetDrawArea(0, 70, 1024, 700);


	Novel4.Novel_Init(&Novel4);	//������


	namae = LoadGraph("graphics/wafuu_mini1_0921.png");
	kaiwabokkusu = LoadGraph("graphics/wafuu_kaiwabox.png");

	PlaySoundMem(Novel4.BGM4, DX_PLAYTYPE_LOOP);








}

//�I������
void Novel_CH_4_Finalize() {


	Scene = 0;
	SetDrawArea(0, 0, 1024, 764);

	Novel4.Novel_Fin(&Novel4);	//������





}


//�X�V
void Novel_CH_4_Update() {





	






}


//�`��
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

		Novel4.Novel("�~��",
			"�w�܂�������������Ȃ�āc�x",
			"",
			"");





	
	
	}
	else if (Scene == 1) {


		Novel4.Tatie_BACKIMAGE(Novel4.Back_04);

		Novel4.Tatie_CENTER(Novel4.Tatie_03_H);

		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel4.Novel("",
			"�ς̂��ʂ��O������y�����߂������ɁA�ꂢ���B",
			"",
			"");


	}
	else if (Scene == 2) {


		Novel4.Tatie_BACKIMAGE(Novel4.Back_04);

		Novel4.Tatie_CENTER(Novel4.Tatie_03_H);



		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel4.Novel("�~��",
			"�w�킩��܂����B���ׂĂ����b�����܂��傤�B",
			"�k�Z�ɂ̑q�Ɏ��܂ł��Ă��āB�����Řb����x",
			"");




	}
	else if (Scene == 3) {

		Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

		



		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel4.Novel("",
			"���������āA���͖k�Z�ɂ̑q�ɂɂ���Ă����B",
			"",
			"");





	}
	else if (Scene == 4) {

		Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

		Novel4.Tatie_CENTER(Novel4.Tatie_03_H);



		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel4.Novel("�~��",
			"�w�c������A���̖����S���Ȃ����́B�x",
			"",
			"");





	}
	else if (Scene == 5) {


	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("",
		"���N�̏t���炱�̍��Z�ɓ��w����\�肾����������",
		"���������A���w���̓����Ɍ�ʎ��̂ɂ����ĖS���Ȃ��Ă��܂����炵���B",
		"");




	}
	else if (Scene == 6) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	Novel4.Tatie_CENTER(Novel4.Tatie_03_S);



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("�~��",
		"�w���͖��̂��Ƃ���D���ŁA���������ԎD�Ŕޏ��ƗV�Ԃ̂�",
		"�K���������c�x",
		"");





	}
	else if (Scene == 7) {


	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	Novel4.Tatie_CENTER(Novel4.Tatie_03_I);



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("�~��",
		"�w�c�c���ɂ�����C�ɂȂꂸ�A�������̂����Ă����Ƃ���Ɂc",
		"����Ă����́c�x",
		"");




	}
	else if (Scene == 8) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	Novel4.Tatie_CENTER(Novel4.Tatie_03_I);



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("�~��",
		"�w�ς��c�x",
		"",
		"");





	}
	else if (Scene == 9) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	
	Novel4.Tatie_LEFT(Novel4.Tatie_00_A);
	Novel4.Tatie_Right(Novel4.Tatie_03_I);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("���",
		"�w���A�ρc�I�x",
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
		"�吳�̐��ł��邪�A�܂����d�ς̕��ނ܂ő��݂��Ă����Ȃ�āB",
		"�M�����Ȃ������B",
		"");





	}
	else if (Scene == 11) {


	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	Novel4.Tatie_LEFT(Novel4.Tatie_00_A);
	Novel4.Tatie_Right(Novel4.Tatie_03_I);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("�~��",
		"�w�ς������������́A",
		"���O�̖��𐶂��Ԃ点�����ɁA���̎��ꂽ�ԎD��",
		"�΂�T���A�����ď����ɏ����A���̎҂̐��C�����̉��̒��ɏW�߂�Ɓx");





	}
	else if (Scene == 12) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	Novel4.Tatie_LEFT(Novel4.Tatie_00_A);
	Novel4.Tatie_Right(Novel4.Tatie_03_I);



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("���",
		"�w������Ƒ҂��āA���̉��̒��ɓ����Ă���̂��Ă��������āc�x",
		"",
		"");






	}
	else if (Scene == 13) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	Novel4.Tatie_LEFT(Novel4.Tatie_00_A);
	Novel4.Tatie_Right(Novel4.Tatie_03_H);



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("�~��",
		"�w�����c���̎��̂������Ă����c�x",
		"",
		"");






	}
	else if (Scene == 14) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	

	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("",
		"�����̂��܂�A���t�������Ă��܂����B",
		"",
		"");






	}
	else if (Scene == 15) {


	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	Novel4.Tatie_LEFT(Novel4.Tatie_00_A);
	Novel4.Tatie_Right(Novel4.Tatie_03_S);



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("�~��",
		"�w�ł��A���������́A�߂�������ǁc",
		"�M���̂������ł�����߂邱�Ƃ��ł�����x",
		"");





	}
	else if (Scene == 16) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	Novel4.Tatie_Right(Novel4.Tatie_03_H);
	Novel4.Tatie_LEFT(Novel4.Tatie_00_H);



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("���",
		"�w���������āA���Ȃ��̖�����̖��O���ĉؙz���Ďq�H�x",
		"",
		"");



	}
	else if (Scene == 17) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	Novel4.Tatie_Right(Novel4.Tatie_03_O);
	Novel4.Tatie_LEFT(Novel4.Tatie_00_H);



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("�~��",
		"�w�I�H",
		"�ǂ����Ă��Ȃ������̖��O���H�x",
		"");



	}
	else if (Scene == 18) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("�H�H�H",
		"�w�N�N�N�E�E�E�E�x",
		"",
		"");



	}
	else if (Scene == 19) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	Novel4.Tatie_CENTER(Novel4.Tatie_05);



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("",
		"�ǂ�����Ƃ��Ȃ��A�������d�ς��A���ꂽ�̂ł���B",
		"",
		"");



	}
	else if (Scene == 20) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	Novel4.Tatie_CENTER(Novel4.Tatie_00_A);



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("���",
		"�w�ρc�I�x",
		"",
		"");



	}
	else if (Scene == 21) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	Novel4.Tatie_CENTER(Novel4.Tatie_05);



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("�d��",
		"�w�_��s���s���Ă��Ƃ��ˁc�H�ł������x���c�I�x",
		"",
		"");



	}
	else if (Scene == 22) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	Novel4.Tatie_CENTER(Novel4.Tatie_05);



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("�d��",
		"�w���C�͏\���ɏW�܂����B",
		"�񑩒ʂ�A�M�l�̊肢�������Ă�낤�x",
		"");



	}
	else if (Scene == 23) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);


	Novel4.Tatie_CENTER(Novel4.Tatie_04_02_H_2);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("",
		"ῂ��P������������ƁA�ώ��̏������������Ă����B",
		"",
		"");



	}
	else if (Scene == 24) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);


	Novel4.Tatie_CENTER(Novel4.Tatie_03_O);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("�~��",
		"�ؙz�I�I�I�I�I�I�I",
		"",
		"");



	}
	else if (Scene == 25) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);


	Novel4.Tatie_CENTER(Novel4.Tatie_04_02_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("�H�H�H",
		"�w�N�N�N�c����J�l�ł����B�x",
		"",
		"");



	}
	else if (Scene == 26) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);


	Novel4.Tatie_CENTER(Novel4.Tatie_03_O);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("�~��",
		"�w������c���x",
		"",
		"");



	}
	else if (Scene == 27) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);


	


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("",
		"�ؙz�̎p���������҂��́A������͂œ~���𐁂���΂����B",
		"",
		"");



	}
	else if (Scene == 28) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);


	Novel4.Tatie_Right(Novel4.Tatie_04_02_H);
	Novel4.Tatie_LEFT(Novel4.Tatie_00_I_1);

	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("�d��",
		"�w���傤�Ǎ���������������������̂��~���������񂾂�x",
		"",
		"");



	}
	else if (Scene == 29) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);


	Novel4.Tatie_Right(Novel4.Tatie_04_02_H_2);
	Novel4.Tatie_LEFT(Novel4.Tatie_00_I_1);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("�d��",
		"�w����ŁA�܂���ᛂȎ���g�킸�Ƃ��A�l�ԋ��|����c�I�x",
		"",
		"");



	}
	else if (Scene == 30) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("",
		"�����A�d�ς͖���S�������~���ɕt������ŁA",
		"��肭�x���Ă��������Ȃ̂������B",
		"");



	}
	else if (Scene == 31) {

	Novel4.Tatie_BACKIMAGE(Novel4.Back_02);

	Novel4.Tatie_Right(Novel4.Tatie_04_02_H_2);
	Novel4.Tatie_LEFT(Novel4.Tatie_00_I_2);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel4.Novel("���",
		"�w�l�̎�݂ɂ�����Łc��΂ɋ����Ȃ��I�x",
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
		"�������āA���͍Ō�̗͂�U��i��A�d�ςƂ̓����ɒ��񂾁B",
		"",
		"");



	}
	else if (Scene == 33) {

	
		SceneMgr_ChangeScene(Game_4);

	}

	DrawStringEx(670, 660, -1, "S�L�[�ŃV�i���I�X�L�b�v�ł��܂��B");

}