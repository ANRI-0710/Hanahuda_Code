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

//������
void Novel_CH_2_Initialize() {


	SetDrawArea(0, 70, 1024, 700);
	
	Novel2.Novel_Init(&Novel2);	//������

	
	namae = LoadGraph("graphics/wafuu_mini1_0921.png");
	kaiwabokkusu = LoadGraph("graphics/wafuu_kaiwabox.png");

	PlaySoundMem(Novel2.BGM3, DX_PLAYTYPE_LOOP);


}

//�I������
void Novel_CH_2_Finalize() {

	Novel2.Novel_Fin(&Novel2);	//������
	Scene = 0;
	SetDrawArea(0, 0, 1024, 764);
	


}


//�X�V
void Novel_CH_2_Update() {




}


//�`��
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
			"���ԂƂ̎����ɂȂ�Ƃ������Ƃ��ł����B",
			"",
			"");
	



	}
	else if (Scene == 1) {

		Novel2.Tatie_BACKIMAGE(Novel2.Back_02);

		Novel2.Tatie_LEFT(Novel2.Tatie_00_I_1);
		Novel2.Tatie_Right(Novel2.Tatie_01_K);


		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel2.Novel("����",
			"�w����c�킽�����܂łȂɂ��c�x",
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
			"�ǂ���琳�C�����߂��Ă��ꂽ�悤�������B",
			"�ؙz�������Ă��ꂽ�悤�ɁA���̉ԎD�ŏ���",
			"�􂢂�������Ƃ����͖̂{���̂悤���B");

		
			
			



	}
	else if (Scene == 3) {


		Novel2.Tatie_BACKIMAGE(Novel2.Back_02);

		Novel2.Tatie_LEFT(Novel2.Tatie_00_H);
		Novel2.Tatie_Right(Novel2.Tatie_01_H);


		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel2.Novel("����",
			"�w�ʔ����ԎD�ŗV�ڂ����āA3�N�̐�y�ɂ����āA",
			"���̐�y�����������ԎD��",
			"�V��ł��ď����ɕ������́x");


		
			
			



	}
	else if (Scene == 4) {

		Novel2.Tatie_BACKIMAGE(Novel2.Back_02);

		Novel2.Tatie_LEFT(Novel2.Tatie_00_H);
		Novel2.Tatie_Right(Novel2.Tatie_01_K);


		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel2.Novel("����",
			"�w��������A���񂾂�ӎ����N�O�Ƃ��Ă��āc��������L�����Ȃ��́x",
			"",
			"");

		
			



	}
	else if (Scene == 5) {
		Novel2.Tatie_BACKIMAGE(Novel2.Back_02);

	


		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel2.Novel("",
			"�Ȃ�قǁB���낢��b�𕷂��Ă݂���",
			"�ǂ���牽�҂����������ԎD�ŏ����ɕ����Ă��܂���",
			"�􂢂Ɋ|�����Ă��܂��炵���B");

		

	}
	else if (Scene == 6) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_02);

	


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("",
		"�����Č����������Ă���̂�3�N�̐�y�ł��邱�ƂƁA�����1�l����",
		"���̎􂢂͊g�U���Ă���悤���B",
		"");

	
		

	}
	else if (Scene == 7) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_02);

	Novel2.Tatie_LEFT(Novel2.Tatie_00_S);
	Novel2.Tatie_Right(Novel2.Tatie_01_K);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("���",
		"�w�킩�����B���낢�땷�����Ă���Ă��肪�Ƃ��x",
		"",
		"");

	
		



	}
	else if (Scene == 8) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_02);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("",
		"�Ƃ肠�����A�������l���􂢂Ɋ|�����Ă��܂��������k�Ə����������",
		"���Â鎮�ŔƐl������o���邩������Ȃ��B",
		"");

	

	}
	else if (Scene == 9) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_02);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("",
		"�����Ŏ��͉��l���̐��k�ƉԎD���������邱�Ƃɂ����B",
		"",
		"");

	
	}
	else if (Scene == 10) {



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("",
		"�E�E�E",
		"",
		"");
	

	}
	else if (Scene == 11) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_CENTER(Novel2.Tatie_02_H);
	
	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("",
		"���l���Ə�����������A",
		"1�l�̙z�Ƃ��������k��������Ɍ������Ă����B",
		"");
	

	}
	else if (Scene == 12) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_CENTER(Novel2.Tatie_02_I);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("�H�H�H",
		"�w���ȊO�ɂ����C��ۂ��Ȃ���ԎD�������Ă�z������Ȃ�Ă�",
		"���Ȃ����Ɛl�{�������Ă���̂�����H�x",
		"");
	
	}
	else if (Scene == 13) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_Right(Novel2.Tatie_02_H);
	Novel2.Tatie_LEFT(Novel2.Tatie_00_H);

	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("���",
		"�w�����B���̖��O�͐�΁B�������炱�̊w�@�ɓ]�Z���Ă����́B�x",
		"",
		"");
	
	}
	else if (Scene == 14) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_Right(Novel2.Tatie_02_S);
	Novel2.Tatie_LEFT(Novel2.Tatie_00_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("����",
		"�w���̖��O�͕����B��N��B�x",
		"",
		"");
		
	}
	else if (Scene == 15) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_Right(Novel2.Tatie_02_H);
	Novel2.Tatie_LEFT(Novel2.Tatie_00_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("���",
		"�w�M�����A�k�Z�ɂ̑q�ɂŏ��̎q���炱�̔����ԎD����������́H�x",
		"",
		"");
	
		


	}
	else if (Scene == 16) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_Right(Novel2.Tatie_02_I);
	Novel2.Tatie_LEFT(Novel2.Tatie_00_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("����",
		"�w�k�Z�ɂ̑q�ɁH�����ԎD�H����Ȃ̒m��Ȃ���B",
		"���͏�����������ԎD������Ă��āA�������炸�Ȃ̂�",
		"������A���݂̂�Ȃ̂悤�ɂ��������Ȃ����肵�Ȃ������x");
		

	}
	else if (Scene == 17) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);



	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("",
		"���͕����ɁA���܂ŋN���������Ƃ̎��ۂ�����������B",
		"",
		"");
	

	}
	else if (Scene == 18) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_Right(Novel2.Tatie_02_S);
	Novel2.Tatie_LEFT(Novel2.Tatie_00_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("����",
		"�w�Ȃ�قǁA���̔����ԎD�ŏ��������ď��ƁA���ꂽ�l�Ԃ�",
		"�􂢂��������Ƃ��ł���̂ˁB�x",
		"");
	

	}
	else if (Scene == 19) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_CENTER(Novel2.Tatie_02_S);
	


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("����",
		"�w�E�E�E���A���͔Ɛl�����ł����́x",
		"",
		"");
		

	}
	else if (Scene == 20) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_Right(Novel2.Tatie_02_I);
	Novel2.Tatie_LEFT(Novel2.Tatie_00_A);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("���",
		"�w�{���ɁI�H�x",
		"",
		"");
	
		



	}
	else if (Scene == 21) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_Right(Novel2.Tatie_02_H);
	Novel2.Tatie_LEFT(Novel2.Tatie_00_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("����",
		"�w�����B3�N���̓~����y���Ɛl�݂����ˁx",
		"",
		"");
	
		

	}
	else if (Scene == 22) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_Right(Novel2.Tatie_02_I);
	Novel2.Tatie_LEFT(Novel2.Tatie_00_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("����",
		"�w�ޏ��������l�̏����k�ɉԎD��n�������ƂɁA",
		"���������Ď􂢂��|���Ă����Ƃ����",
		"���������F�B������̂�");

	
		
		

	}
	else if (Scene == 23) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_Right(Novel2.Tatie_02_I);
	Novel2.Tatie_LEFT(Novel2.Tatie_00_S);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("���",
		"�w���Ⴀ�A���̐�y�Ɛ������邩�A",
		"�ԎD�����ɏ��Ă΂Ȃ�Ƃ��Ȃ邩������Ȃ��ˁB�x",
		"");

	
		


	}
	else if (Scene == 24) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_Right(Novel2.Tatie_02_S);
	Novel2.Tatie_LEFT(Novel2.Tatie_00_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("����",
		"�w�����炭�ˁx",
		"",
		"");
	
		

	}
	else if (Scene == 25) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_Right(Novel2.Tatie_02_S);
	Novel2.Tatie_LEFT(Novel2.Tatie_00_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("����",
		"�w���̑O�Ɏ��Ƃ��Ȃ��ŉԎD�����Ȃ��H�x",
		"",
		"");
	
		

	}
	else if (Scene == 26) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_Right(Novel2.Tatie_02_S);
	Novel2.Tatie_LEFT(Novel2.Tatie_00_A);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("���",
		"�w���c�H�x",
		"",
		"");
		

	}
	else if (Scene == 27) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_Right(Novel2.Tatie_02_I);
	Novel2.Tatie_LEFT(Novel2.Tatie_00_A);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("����",
		"�w����ԈႦ�ĕ����Ă��܂��΁A�􂢂ɂ������Ă��܂��̂�����",
		"��苭���҂����̔����ԎD���g���Đ�y�ɏ����𒧂ނׂ���x",
		"");
	

	}
	else if (Scene == 28) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_Right(Novel2.Tatie_02_I);
	Novel2.Tatie_LEFT(Novel2.Tatie_00_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("",
		"�m���ɁA�����Ă��܂��΂��̐g�ɉ��������邩�킩��Ȃ��B",
		"",
		"");
	

	}
	else if (Scene == 29) {

	Novel2.Tatie_BACKIMAGE(Novel2.Back_03);

	Novel2.Tatie_Right(Novel2.Tatie_02_I);
	Novel2.Tatie_LEFT(Novel2.Tatie_00_I_1);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel2.Novel("���",
		"�w�킩������B���������܂��傤�B�x",
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
		"�������Ď��́A�����Ƃ̏��������邱�ƂɂȂ���",
		"",
		"");
	

	}
	else if (Scene == 31) {

	


	SceneMgr_ChangeScene(Game_2);



	}


	DrawStringEx(670, 660, -1, "S�L�[�ŃV�i���I�X�L�b�v�ł��܂��B");

}