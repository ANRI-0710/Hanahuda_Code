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

//������
void Novel_CH_1_Initialize() {

	SetDrawArea(0, 70, 1024, 700);

	
	Novel0.Novel_Init(&Novel0);	//������
	namae = LoadGraph("graphics/wafuu_mini1_0921.png");
	kaiwabokkusu = LoadGraph("graphics/wafuu_kaiwabox.png");
	PlaySoundMem(Novel0.BGM2,DX_PLAYTYPE_LOOP);
	
}

//�I������
void Novel_CH_1_Finalize() {
	
	SetDrawArea(0, 0, 1024, 764);
	Novel0.Novel_Fin(&Novel0);	//������
	Scene = 0;
	
}

//�X�V
void Novel_CH_1_Update() {

}


//�`��
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
			"�吳8�N�̉K���̎����I��邱��A",
			"���A�L�ؐ�΁i�`�g�Z�j�͗��e�̈����z���Ƌ���",
			"�ɐ��s�ɂ��鍂�����w�@�ɓ]�Z�����邱�ƂɂȂ����B");

	}
	else if (Scene == 1) {
		
		Novel0.Tatie_BACKIMAGE(Novel0.Back_01);
		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel0.Novel("",
			"�����͏��̓o�Z���Ȃ̂����A�ǂ����w�@�̗l�q����������",
			"",
			"");

	}
	else if (Scene == 2) {
		
		Novel0.Tatie_BACKIMAGE(Novel0.Back_01);
		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel0.Novel("",
			"��قǒS�C�̐搶�Ƃ�����������A",
			"�����̓]�Z�葱���̘b�����낻����",
			"����������Ȋ�ŏ΂��Ȃ���s�v�c�ȉԎD�̘b�������Ȃ��̂��B");
		

	}
	else if (Scene == 3) {

		Novel0.Tatie_BACKIMAGE(Novel0.Back_01);
		Novel0.Tatie_LEFT(Novel0.Tatie_00_H);
		Novel0.Tatie_Right(Novel0.Tatie_MOBU_H);

		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel0.Novel("�����k",
			"�w�҂��đ҂��āI�������ƉԎD�ŗV�т܂��傤�I",
			"�����Ɗy������I�x",
			"");

	}
	else if (Scene == 4) {

		Novel0.Tatie_BACKIMAGE(Novel0.Back_01);
		Novel0.Tatie_LEFT(Novel0.Tatie_00_A);
		Novel0.Tatie_Right(Novel0.Tatie_MOBU_H);

		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel0.Novel("���",
			"�w�����ƁA���߂�B�܂���łˁx",
			"",
			"");



	}
	else if (Scene == 5) {
		
		Novel0.Tatie_BACKIMAGE(Novel0.Back_01);

	
		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel0.Novel("",
			"�ǂ̐��k�Ƙb���Ă��A�]�Z���̎��ւ̈��A�𔲂���",
			"�s�v�c�ȉԎD�ł̗V�т������|���Ă���B",
			"���ɂ͋������悤�ɒǂ������Ă���q�������B");
		


	}
	else if (Scene == 6) {

	Novel0.Tatie_BACKIMAGE(Novel0.Back_01);

	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);


	Novel0.Novel("",
		"�܂�ŊF�����Ɏ��߂���Ă���悤�Ȃ̂��B",
		"",
		"");
	



	}
	else if (Scene == 7) {

		Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	

		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel0.Novel("",
			"���|�S�ɋ��ꂽ���́A",
			"�N�����Ȃ������Ȗk�Z�ɂ̑q�Ɏ���",
			"�����Ă����̂ł���B");
		
		
			
			



	}
	else if (Scene == 8) {

		Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

		

		DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
		DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

		Novel0.Novel("",
			"���̉ԎD�ŗV��ł��܂�����E�E�E",
			"�ƂĂ����ȗ\���������̂��B",
			"");

		
			


	}
	else if (Scene == 9) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	Novel0.Tatie_LEFT(Novel0.Tatie_00_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("���",
		"�w���āA�ǂ����悤���ȁc�x",
		"",
		"");


	
		


	}
	else if (Scene == 10) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	Novel0.Tatie_LEFT(Novel0.Tatie_00_H);
	

	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("�H�H�H",
		"�w�����ŁA�������Ă���́H�x",
		"",
		"");

	
		


	}
	else if (Scene == 11) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	Novel0.Tatie_LEFT(Novel0.Tatie_00_A);
	


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("���",
		"�w�I�H�x",
		"",
		"");


	
		

	}
	else if (Scene == 12) {


	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	Novel0.Tatie_CENTER(Novel0.Tatie_04_H);
	


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("",
		"�U������Ƃ����ɂ́A���{�l�`�̂悤������",
		"���C�����肻���ȏ��̎q�������Ă����B",
		"");

	
		


	}
	else if (Scene == 13) {


	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	Novel0.Tatie_LEFT(Novel0.Tatie_00_H);
	Novel0.Tatie_Right(Novel0.Tatie_04_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("�H�H�H",
		"�w���A�C�Â��Ă��ꂽ�񂾁I���ꂵ���ȁx",
		"",
		"");

	
	}
	else if (Scene == 14) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	Novel0.Tatie_LEFT(Novel0.Tatie_00_A);
	Novel0.Tatie_Right(Novel0.Tatie_04_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("�H�H�H",
		"�w��������悤�B���̖��O�ؙ͉z�B",
		"��낵���ˁx",
		"");

	
		
		



	}
	else if (Scene == 15) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	Novel0.Tatie_LEFT(Novel0.Tatie_00_S);
	Novel0.Tatie_Right(Novel0.Tatie_04_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("���",
		"�w���͐�΁B�������߂ē]�Z���Ă�����",
		"��낵���ˁB�x",
		"");

	
		
		



	}
	else if (Scene == 16) {


	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	Novel0.Tatie_LEFT(Novel0.Tatie_00_H);
	Novel0.Tatie_Right(Novel0.Tatie_04_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("���",
		"�w�Ƃ���ŕ��������̂����ǁA�w�@�̗l�q���ƂĂ����������́B",
		"�݂�ȕs�v�c�ȉԎD�ŗV�ڂ��Ǝ����|���Ă��āA",
		"���ȗ\�������ē����Ă����Ƃ���B�x");

	
		
		
		


	}
	else if (Scene == 17) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	Novel0.Tatie_LEFT(Novel0.Tatie_00_H);
	Novel0.Tatie_Right(Novel0.Tatie_04_H_2);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("�ؙz",
		"�w�c�I���Ȃ��􂢂ɂ������ĂȂ��݂����ˁx",
		"",
		"");

	
		



	}
	else if (Scene == 18) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	Novel0.Tatie_LEFT(Novel0.Tatie_00_H);
	Novel0.Tatie_Right(Novel0.Tatie_04_H_2);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("���",
		"�w�􂢁H�x",
		"",
		"");

	
	}
	else if (Scene == 19) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	Novel0.Tatie_LEFT(Novel0.Tatie_00_H);
	Novel0.Tatie_Right(Novel0.Tatie_04_H_2);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("�ؙz",
		"�w�����������炠�Ȃ���������c�x",
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
		"�􂢁H�Ȃ�̂��ƁH��",
		"�������Ƃ����u�ԁA�ؙz���甒���������ԎD����n���ꂽ�B",
		"");

	
		



	}
	else if (Scene == 21) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	Novel0.Tatie_LEFT(Novel0.Tatie_00_H);
	Novel0.Tatie_Right(Novel0.Tatie_04_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("�ؙz",
		"�w�g�����I�Ԃ̂����ǁA���Ȃ��������炫���Ƒ��v�x",
		"",
		"");


	
		



	}
	else if (Scene == 22) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	Novel0.Tatie_LEFT(Novel0.Tatie_00_H);
	Novel0.Tatie_Right(Novel0.Tatie_04_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("�ؙz",
		"�w���̉ԎD�ŏ������ď����Ƃ��ł�����A",
		"�|����ꂽ�􂢂��������邱�Ƃ��ł���͂��x",
		"");

	
		
		



	}
	else if (Scene == 23) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	
	Novel0.Tatie_CENTER(Novel0.Tatie_04_K);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("�ؙz",
		"�w�ǂ����c�݂�Ȃ��c�o���~���āc�x",
		"",
		"");

	
		



	}
	else if (Scene == 24) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	
	Novel0.Tatie_CENTER(Novel0.Tatie_00_A);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("���",
		"�w���H�ǂ��������Ɓc�H�x",
		"",
		"");

	
		



	}
	else if (Scene == 25) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	
	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("",
		"�ƁA�ؙz��₢���������Ƃ��ĐU���������",
		"�ޏ��͂��̊Ԃɂ����Ȃ��Ȃ��Ă����̂��B",
		"");




	}
	else if (Scene == 26) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);





	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("�H�H�H",
		"�w����A���Ȃ��A��̂ǂȂ��Ƃ��b���Ă����́H�x",
		"",
		"");

	
		


	}
	else if (Scene == 27) {


	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);

	Novel0.Tatie_CENTER(Novel0.Tatie_01_H);
	


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("",
		"�Z�ɂ̑q�Ɏ��̓�������A",
		"��قǉԎD�ŗV�ڂ���",
		"�ǂ������Ă��������̏����k�̈�l�A���Ԃ������B");


	}
	else if (Scene == 28) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);


	Novel0.Tatie_LEFT(Novel0.Tatie_00_H);
	Novel0.Tatie_Right(Novel0.Tatie_01_H);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("",
		"�܂����A�݂����Ă��܂����c�B",
		"",
		"");

	



	}
	else if (Scene == 29) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);


	Novel0.Tatie_LEFT(Novel0.Tatie_00_H);
	Novel0.Tatie_Right(Novel0.Tatie_01_S);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("����",
		"�w����ƁA�������I�����A���ƉԎD�ŗV�т܂��傤��x",
		"",
		"");

	
		


	}
	else if (Scene == 30) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);


	Novel0.Tatie_LEFT(Novel0.Tatie_00_I_1);
	Novel0.Tatie_Right(Novel0.Tatie_01_S);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("���",
		"�w�E�E�E�E�E�E�x",
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
		"�󋵂͑S�������͂ł��Ă͂��Ȃ��B",
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
		"�������A���̊w�@�ŋN�����Ă������������߂ɂ�",
		"���̔����ԎD�ŁA���������ď������Ȃ��B",
		"");

	
		


	}
	else if (Scene == 33) {



	Novel0.Tatie_BACKIMAGE(Novel0.Back_02);


	Novel0.Tatie_LEFT(Novel0.Tatie_00_I_2);
	Novel0.Tatie_Right(Novel0.Tatie_01_S);


	DrawRotaGraph(500, 570, 1.0f, 0, kaiwabokkusu, true);
	DrawRotaGraph(250, 480, 3.0f, 0, namae, true);

	Novel0.Novel("���",
		"�w�����A�]�ނƂ����B�x",
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
		"�����ԎD���������肵��",
		"���͗��ԂƂ̉ԎD�������n�߂��B",
		"");

	
		


	}
	else if (Scene == 35) {



		int UNLOCK = eUnlock_Chpter_1;
		Chapter_Unlock(&UNLOCK);

		SceneMgr_ChangeScene(Chapter);





	}



	DrawStringEx(670, 660, -1, "S�L�[�ŃV�i���I�X�L�b�v�ł��܂��B");




}






