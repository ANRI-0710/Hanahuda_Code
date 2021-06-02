#include "DxLib.h"
#include "../library/t2klib.h"
#include "../support/Support.h"
#include "00.SceneMgr.h"
#include "02.Chapter.h"
#include "04_03.HanahudaMgr.h"
#include "04_99.Hanahuda_battle_Modules.h"
#include "04_99.Hanahuda_Card_Modules.h"
#include "04_99.Hanahuda_Score_Modules.h"
#include <time.h>


//BGM
static int BattleBGM = 0;

//�ԎD�̏������N���X
Hanahuda_Card Card3;

//�v���C���[�N���X
Player player3;	//�v���C���[��{���
Player enemy3;	//�G�̊�{���

//�J�[�h�i���o�[������p
static int CardSel_NUM_ = 8;
static int NowSelect = 0;	//�I�𒆂̎�D


//�V�[���J��
static int GameScene_ = Progress0;	//�Q�[�����V�[����0����n�܂�


//�v���g�^�C�v�錾
//�t�@�C�����ŕK�{�̌Ăяo���֐��B
//Mgr�`�Ƃ��֐��͂��̃t�@�C�����̊֐�,��ԉ��ɂ���B���̂ق��̊֐��͂��ׂ�battle_Modules.cpp�ɏW��
void Mgr_Player_Card_Placement_3();
void Mgr_Enemy_Card_Placement_3();

void Mgr_Player_Card_Move_3();
void Mgr_Enemy_Card_Move_3();


//-------------------------------------��������Ǘ��p���C���֐�------------------------------------------------


//�������Ǘ�
void HanahudaMgr_Initialize_3() {


	player3.MainScene_ = Progress0;

	//�D�̏�����	
	Card3.Card_Modules_Initialize();

	//BGM������
	BattleBGM = LoadSoundMem("sound/Battle_Stage_1.mp3");
	ChangeVolumeSoundMem(160, BattleBGM);
	PlaySoundMem(BattleBGM, DX_PLAYTYPE_LOOP);


	//����
	srand(time(0));

	//�摜�E���W�ESE�E�t�H���g����������
	player3.Init_Battle(&player3, &enemy3, 3);

	//�����E�G�̎D�̍ŏ��̃V���b�t��
	player3.Card_Moudules_First_Place(&player3);
	enemy3.Card_Moudules_First_Place(&enemy3);


	//�D�𗐐��ŃV���b�t������i�����݁E�����Ɂj
	player3.Card_Modules_YAKU_shuffle(&player3, CardSel_NUM_);
	enemy3.Card_Modules_YAKU_shuffle(&enemy3, CardSel_NUM_);

	player3.Card_Modules_3_shuffle(&player3, CardSel_NUM_);
	enemy3.Card_Modules_3_shuffle(&enemy3, CardSel_NUM_);


	//�����E�G�̎D�̍��W������
	for (int i = 0; i < 8; i++) {

		player3.cpos_x[i] = 100 + (i * 100);
		player3.cpos_y[i] = 750;

		enemy3.cpos_x[i] = 200 + (i * 100);
		enemy3.cpos_y[i] = 100;

	}

	//HP�̏�����
	/*player3.HP = 5000.0f;
	enemy3.HP = 5000.0f;*/

	//�G�̍U�����W�̍X�V
	enemy3.AT_pos_x = 1200;
	enemy3.AT_pos_y = -300;


}


//�I������
void HanahudaMgr_Finalize_3() {

	Card3.Card_Modules_Finalize();
	DeleteSoundMem(BattleBGM);

	player3.Finalize_Battle(&player3);
	enemy3.Finalize_Battle(&enemy3);


}


//�X�V�E�v�Z�Ǘ�
void HanahudaMgr_Update_3() {


	//�w�i�\��
	DrawRotaGraph(512, 350, 1.0f, 0, player3.Back_Image, true);
	player3.System_Messeage(&player3, &enemy3);

	if (player3.MainScene_ == Progress0) {	//�J�n���}

		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RETURN)) {

			player3.MainScene_ = Progress1;

		}

	}
	else if (player3.MainScene_ == Progress1) {	//�����J�[�h�̈ړ��^�[��


		//�y�֐��z�U���E�񕜂̃��j���[�\��
		player3.Card_Modules_Menu(&player3);


	}
	else if (player3.MainScene_ == Progress2) {	//�v�Z�E�U������1

		Mgr_Player_Card_Move_3();	//�����J�[�h�̈ړ��֐�


		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RETURN)) {	//�o���D�̌��肷��

			player3.Moudules_Myplayer_YAKUScore_RETURN(&player3);	//����Ƌ��Ɏ��v���C���[�̖��X�R�A�̌v�Z������
			player3.Game_Start = true; //�D��3���ȏ�グ�邱�Ƃ𐧌�
			player3.Count_3 = 4;	 //�D��3���ȏ�グ�邱�Ƃ𐧌�

		}


		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_SPACE)) {	//���V�[���ֈړ�

			Mgr_Enemy_Card_Move_3();								//�V�[���ړ��Ɠ����ɓG�̃J�[�h�v�Z���s��
			enemy3.Moudules_Enemy_Card_Place_3(&player3, &enemy3);	///�V�[���ړ��Ɠ����ɓG�̃J�[�h�v�Z���A�����3���o���i�v���C���[�J�[�h���v�Z���Ĕ��f�j
			enemy3.Moudules_Enemy_YAKUScore_RETURN(&enemy3);
			player3.Moudules_All_Score_RETURN(&player3, &enemy3);	//3�����݁E���̓_�������Z


			player3.MainScene_ = Progress3;
		}


	}
	else if (player3.MainScene_ == Progress3) {	//�v�Z�E�U������2

		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_SPACE)) {	//���V�[���ֈړ�

			player3.MainScene_ = Progress4;

		}


	}
	else if (player3.MainScene_ == Progress4) {	//�v�Z�E�U������3

		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_SPACE)) {	//���V�[���ֈړ�

			//�����̍U�����[�V�����������E���Ԃ��������烂�W���[��cpp�Ɉړ�
			player3.Modules_Attack_init(&player3, &enemy3);

			player3.Moudules_Player_Attack(&player3, &enemy3, 0);//���v���C���[�̍U������(������)
			enemy3.Moudules_Enemy_Attack(&player3, &enemy3, 0);//�G�̍U������	


			player3.MainScene_ = Progress5;
			//player3.AT_Wait[0] = false;

		}


	}
	else if (player3.MainScene_ == Progress5) {	//�D�V���b�t���E������

		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_SPACE)) {	//���V�[���ֈړ�


			player3.Moudules_Player_Attack(&player3, &enemy3, 1);//���v���C���[�̍U������(��)		
			enemy3.Moudules_Enemy_Attack(&player3, &enemy3, 1);//�G�̍U������	

			//�G�̍U�����[�V�����������E���Ԃ��������烂�W���[��cpp�Ɉړ�
			player3.Modules_Attack_init(&player3, &enemy3);

			if (player3.HP <= 0 || enemy3.HP <= 0) {

				player3.MainScene_ = Progress7;

			}
			else {

				player3.MainScene_ = Progress6;

			}


		}



	}
	else if (player3.MainScene_ == Progress6) {

		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RETURN)) { //Progress0�ɖ߂�

			player3.Card_Moudules_YAKU_Reshaffle(&player3, 8, 1);
			enemy3.Card_Moudules_YAKU_Reshaffle(&enemy3, 8, 4);

			player3.MainScene_ = Progress0;
			player3.Game_Start = false;
		}


	}
	else if (player3.MainScene_ == Progress7) {


		//�����I��


	}
	else if (player3.MainScene_ == Progress8) {


		player3.Card_Modules_Recovery_Menu(&player3);



	}
	else if (player3.MainScene_ == Progress9) {


		//�w���v���


	}
	else if (player3.MainScene_ == Progress10) {


		//���ꗗ


	}
	else if (player3.MainScene_ == Progress11) {



		//�߂��ʂ̕\��
		player3.Card_Modules_Back_Menu(&player3);


	}




}


//�`��Ǘ�
void HanahudaMgr_Draw_3() {

	//�v���C���[HP�o�[
	player3.HP_now = 1.0f * ((float)player3.HP / MAXHP_1);

	//enemyHP�o�[
	enemy3.HP_now = 1.0f * ((float)enemy3.HP / MAXHP_1);


	//�����̎�D��z�u	
	Mgr_Player_Card_Placement_3();

	//�G�̎�D�̔z�u
	Mgr_Enemy_Card_Placement_3();

	//HP�o�[
	DrawRotaGraph3(20, 700, 0, 0, player3.HP_now, 0.5f, 0, player3.HP_var, TRUE);
	DrawStringEx(20, 675, -1, "HP:%d / %d", player3.HP, 5000);

	//HP�E�G�o�[
	DrawRotaGraph3(700, 50, 0, 0, enemy3.HP_now, 0.5f, 0, enemy3.HP_var, TRUE);
	DrawStringEx(700, 25, -1, "HP:%d / %d", enemy3.HP, 5000);


	//�J�n���}�̊֐�
	player3.Modules_Battle_Start(&player3);

	//3�����݂̍U�����[�V�����iSE�Ɨ����G�Ɖ��y�̕\���j�EProgress3�̎�����
	player3.Modules_Attack_Motion(&player3, &enemy3, Progress4);


	//���̍U�����[�V����
	player3.Modules_Attack_Motion_YAKU(&player3, &enemy3, Progress5);


	//resurt���ʂ̕\��
	player3.Modules_Result(&player3, &enemy3, 4);

	//�w���v��ʂ̕\��
	player3.Card_Modules_Help(&player3, Progress1);

	//���ꗗ���X�g�̕\��
	player3.Card_Modules_YakuList(&player3, Progress10);


	/*DrawStringEx(50, 700, -1, "MY HP: %d", player3.HP);
	DrawStringEx(50, 730, -1, "TotalScore: %d", player3.TotalScore);
	DrawStringEx(50, 100, -1, "ENEMY HP: %d", enemy3.HP);
	DrawStringEx(40, 130, -1, "TotalScore: %d", enemy3.TotalScore);
	DrawStringEx(50, 250, -1, "�Q�[���V�[���i���o�[ : %d", player3.MainScene_);
	DrawStringEx(50, 400, -1, "AT_count: %d", player3.AT_counter);


	DrawStringEx(800, 200, -1, "jan : %d", enemy3.Jan);
	DrawStringEx(800, 230, -1, "Feb : %d", enemy3.Feb);
	DrawStringEx(800, 260, -1, "Mar : %d", enemy3.Mar);
	DrawStringEx(800, 290, -1, "Apr : %d", enemy3.Apr);
	DrawStringEx(800, 310, -1, "may : %d", enemy3.May);
	DrawStringEx(800, 340, -1, "jun : %d", enemy3.Jun);
	DrawStringEx(800, 370, -1, "july : %d",enemy3.Jul);
	DrawStringEx(800, 400, -1, "aug : %d", enemy3.Aug);
	DrawStringEx(800, 430, -1, "sep : %d", enemy3.Sep);
	DrawStringEx(800, 460, -1, "oct : %d", enemy3.Oct);
	DrawStringEx(800, 490, -1, "nov : %d", enemy3.Oct);
	DrawStringEx(800, 520, -1, "dec : %d", enemy3.Oct);*/


	/*DrawStringEx(50, 330, -1, "Ene_Sukim_3_Coun0:%d", enemy3.Ene_Sukim_3_Count[0]);
	DrawStringEx(50, 360, -1, "Ene_Sukim_3_Coun1:%d", enemy3.Ene_Sukim_3_Count[1]);
	DrawStringEx(50, 390, -1, "Ene_Sukim_3_Coun2:%d", enemy3.Ene_Sukim_3_Count[2]);
	DrawStringEx(50, 410, -1, "enemy3.Count_3:%d", enemy3.Count_3);*/


	/*for (int i = 0; i < 8; i++) {

		DrawStringEx(50 + (i * 30), 270, -1, " %d", enemy3.YAKU2_Storage[i]);

	}*/

}

//-------------------------------------��������Ăяo���p�֐�-------------------------------------------------

//�`��E�ԎD�̔z�u�֐�
void Mgr_Player_Card_Placement_3() {	//�����̉ԎD�z�u

	for (int i = 0; i < 8; i++) {


		if (player3.Huda_UP[i]) {

			player3.cpos_y[i] = 450;

		}
		else if (i == NowSelect) {


			player3.cpos_x[i] = 100 + (i * 100);
			player3.cpos_y[i] = 500;

		}
		else {

			player3.cpos_x[i] = 100 + (i * 100);
			player3.cpos_y[i] = 600;

		}

		//�������ꍞ��		
		player3.cYaku_Num = player3.YAKU_R[i];
		//player3.cYaku_Num = 0;	//�e�X�g
		player3.c3_Num1 = player3.Sukumi_R[i];


		DrawRotaGraph(player3.cpos_x[i], player3.cpos_y[i], 1.0f, 0, Card3.Card[player3.uraomote][player3.cYaku_Num][player3.c3_Num1], true);
		//DrawRotaGraph(player3.cpos_x[i] + (i * 100), player3.cpos_y[i], 1.0f, 0, Card2.Card[player3.uraomote][0][0], true);

	}

}

void Mgr_Enemy_Card_Placement_3() {	//�G�̉ԎD�z�u

	for (int i = 0; i < 8; i++) {

		//�������ꍞ��		
		enemy3.cYaku_Num = enemy3.YAKU_R[i];	//�e�X�g��		
		enemy3.c3_Num1 = enemy3.Sukumi_R[i];


		if (enemy3.Huda_UP[i]) {

			enemy3.cpos_y[i] = 300;

		}
		else {

			enemy3.cpos_x[i] = 200 + (i * 100);
			enemy3.cpos_y[i] = 150;

		}

		DrawRotaGraph(enemy3.cpos_x[i], enemy3.cpos_y[i], 1.0f, 0, Card3.Card[enemy3.uraomote][enemy3.cYaku_Num][enemy3.c3_Num1], true);

	}

}


//�����̃J�[�h�̈ړ�����
void Mgr_Player_Card_Move_3() {

	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RIGHT) && player3.Game_Start == false) {	//�E�Ɉړ�

		NowSelect = (NowSelect + 1) % CardSel_NUM_;

	}

	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_LEFT) && player3.Game_Start == false) {	//���Ɉړ�

		NowSelect = (NowSelect + (CardSel_NUM_ - 1)) % CardSel_NUM_;

		for (int i = 0; i < 8; i++) {

			if (player3.Huda_UP[i]) {

				player3.cpos_y[i] = 450;

			}
			else if (i == NowSelect) {

				player3.cpos_y[i] = 500;

			}
			else {

				player3.cpos_y[i] = 600;

			}

		}

	}


	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_UP) && player3.Game_Start == false) {	//����ɏo���D�������肷��

		for (int i = 0; i < 8; i++) {

			if (i == NowSelect && player3.Count_3 < 3) {

				int SelectNum_r = NowSelect;
				player3.Count_3++;
				player3.Huda_UP[SelectNum_r] = true;
				player3.UR_Storage[SelectNum_r] = eCard_Omote;
				player3.YAKU1_Storage[SelectNum_r] = player3.YAKU_R[SelectNum_r];
				//player3.YAKU1_Storage[SelectNum_r] = 0;	//�e�X�g


				if (player3.Count_3 == 1) {

					player3.SUKUMI_Storage[0] = player3.Sukumi_R[SelectNum_r];
					player3.cpos_x[SelectNum_r] = 400;

				}
				else if (player3.Count_3 == 2) {

					player3.SUKUMI_Storage[1] = player3.Sukumi_R[SelectNum_r];
					player3.cpos_x[SelectNum_r] = 500;

				}
				else if (player3.Count_3 == 3) {

					player3.SUKUMI_Storage[2] = player3.Sukumi_R[SelectNum_r];
					player3.cpos_x[SelectNum_r] = 600;

				}


			}

		}

	}

	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_DOWN) && player3.Game_Start == false) {	//�D��������

		for (int i = 0; i < 8; i++) {

			player3.Count_3 = 0;
			player3.Huda_UP[i] = false;
			player3.UR_Storage[i] = eCard_Omote;
			player3.YAKU1_Storage[i] = 99;
			player3.SUKUMI_Storage[i] = 99;

		}

		player3.TotalScore = 0;
		player3.Jan = 0;
		player3.Feb = 0;
		player3.Mar = 0;
		player3.Apr = 0;
		player3.May = 0;
		player3.Jun = 0;
		player3.Jul = 0;
		player3.Aug = 0;
		player3.Sep = 0;
		player3.Oct = 0;
		player3.Nov = 0;
		player3.Dec = 0;

	}


}

//�G�̃J�[�h�̈ړ�����
void Mgr_Enemy_Card_Move_3() {

	for (int i = 0; i < 8; i++) {

		enemy3.UR_Storage[i] = eCard_Omote;
		enemy3.YAKU1_Storage[i] = enemy3.YAKU_R[i];
		enemy3.SUKUMI_Storage[i] = enemy3.Sukumi_R[i];

	}


}







