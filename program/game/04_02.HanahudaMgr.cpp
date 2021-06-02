#include "DxLib.h"
#include "../library/t2klib.h"
#include "../support/Support.h"
#include "00.SceneMgr.h"
#include "02.Chapter.h"
#include "04_02.HanahudaMgr.h"
#include "04_99.Hanahuda_battle_Modules.h"
#include "04_99.Hanahuda_Card_Modules.h"
#include "04_99.Hanahuda_Score_Modules.h"
#include <time.h>


//BGM
static int BattleBGM = 0;

//�ԎD�̏������N���X
Hanahuda_Card Card2;

//�v���C���[�N���X
Player player2;	//�v���C���[��{���
Player enemy2;	//�G�̊�{���

//�J�[�h�i���o�[������p
static int CardSel_NUM_ = 8;
static int NowSelect = 0;	//�I�𒆂̎�D


//�V�[���J��
static int GameScene_ = Progress0;	//�Q�[�����V�[����0����n�܂�


//�v���g�^�C�v�錾
//�t�@�C�����ŕK�{�̌Ăяo���֐��B
//Mgr�`�Ƃ��֐��͂��̃t�@�C�����̊֐�,��ԉ��ɂ���B���̂ق��̊֐��͂��ׂ�battle_Modules.cpp�ɏW��
void Mgr_Player_Card_Placement_2();
void Mgr_Enemy_Card_Placement_2();

void Mgr_Player_Card_Move_2();
void Mgr_Enemy_Card_Move_2();


//-------------------------------------��������Ǘ��p���C���֐�------------------------------------------------


//�������Ǘ�
void HanahudaMgr_Initialize_2() {


	player2.MainScene_ = Progress0;

	//�D�̏�����	
	Card2.Card_Modules_Initialize();

	//BGM������
	BattleBGM = LoadSoundMem("sound/Battle_Stage_1.mp3");
	ChangeVolumeSoundMem(160, BattleBGM);
	PlaySoundMem(BattleBGM, DX_PLAYTYPE_LOOP);


	//����
	srand(time(0));

	//�摜�E���W�ESE�E�t�H���g����������
	player2.Init_Battle(&player2, &enemy2, 2);

	//�����E�G�̎D�̍ŏ��̃V���b�t��
	player2.Card_Moudules_First_Place(&player2);
	enemy2.Card_Moudules_First_Place(&enemy2);


	//�D�𗐐��ŃV���b�t������i�����݁E�����Ɂj
	player2.Card_Modules_YAKU_shuffle(&player2, CardSel_NUM_);
	enemy2.Card_Modules_YAKU_shuffle(&enemy2, CardSel_NUM_);

	player2.Card_Modules_3_shuffle(&player2, CardSel_NUM_);
	enemy2.Card_Modules_3_shuffle(&enemy2, CardSel_NUM_);


	//�����E�G�̎D�̍��W������
	for (int i = 0; i < 8; i++) {

		player2.cpos_x[i] = 100 + (i * 100);
		player2.cpos_y[i] = 750;

		enemy2.cpos_x[i] = 200 + (i * 100);
		enemy2.cpos_y[i] = 100;

	}

	//HP�̏�����
	/*player2.HP = 5000.0f;
	enemy2.HP = 5000.0f;*/

	//�G�̍U�����W�̍X�V
	enemy2.AT_pos_x = 1200;
	enemy2.AT_pos_y = -300;


}


//�I������
void HanahudaMgr_Finalize_2() {

	Card2.Card_Modules_Finalize();
	DeleteSoundMem(BattleBGM);

	player2.Finalize_Battle(&player2);
	enemy2.Finalize_Battle(&enemy2);


}


//�X�V�E�v�Z�Ǘ�
void HanahudaMgr_Update_2() {

	
	//�w�i�\��
	DrawRotaGraph(512, 350, 1.0f, 0, player2.Back_Image, true);
	player2.System_Messeage(&player2, &enemy2);

	if (player2.MainScene_ == Progress0) {	//�J�n���}

		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RETURN)) {

			player2.MainScene_ = Progress1;

		}

	}
	else if (player2.MainScene_ == Progress1) {	//�����J�[�h�̈ړ��^�[��


		//�y�֐��z�U���E�񕜂̃��j���[�\��
		player2.Card_Modules_Menu(&player2);


	}
	else if (player2.MainScene_ == Progress2) {	//�v�Z�E�U������1

		Mgr_Player_Card_Move_2();	//�����J�[�h�̈ړ��֐�


		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RETURN)) {	//�o���D�̌��肷��

			player2.Moudules_Myplayer_YAKUScore_RETURN(&player2);	//����Ƌ��Ɏ��v���C���[�̖��X�R�A�̌v�Z������
			player2.Game_Start = true; //�D��3���ȏ�グ�邱�Ƃ𐧌�
			player2.Count_3 = 4;	 //�D��3���ȏ�グ�邱�Ƃ𐧌�

		}


		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_SPACE)) {	//���V�[���ֈړ�

			Mgr_Enemy_Card_Move_2();								//�V�[���ړ��Ɠ����ɓG�̃J�[�h�v�Z���s��
			enemy2.Moudules_Enemy_Card_Place_2(&player2, &enemy2);	///�V�[���ړ��Ɠ����ɓG�̃J�[�h�v�Z���A�����3���o���i�v���C���[�J�[�h���v�Z���Ĕ��f�j
			enemy2.Moudules_Enemy_YAKUScore_RETURN(&enemy2);
			player2.Moudules_All_Score_RETURN(&player2, &enemy2);	//3�����݁E���̓_�������Z


			player2.MainScene_ = Progress3;
		}


	}
	else if (player2.MainScene_ == Progress3) {	//�v�Z�E�U������2

		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_SPACE)) {	//���V�[���ֈړ�

			player2.MainScene_ = Progress4;

		}


	}
	else if (player2.MainScene_ == Progress4) {	//�v�Z�E�U������3

		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_SPACE)) {	//���V�[���ֈړ�

			//�����̍U�����[�V�����������E���Ԃ��������烂�W���[��cpp�Ɉړ�
			player2.Modules_Attack_init(&player2, &enemy2);

			player2.Moudules_Player_Attack(&player2, &enemy2, 0);//���v���C���[�̍U������(������)
			enemy2.Moudules_Enemy_Attack(&player2, &enemy2, 0);//�G�̍U������	


			player2.MainScene_ = Progress5;
			//player2.AT_Wait[0] = false;

		}


	}
	else if (player2.MainScene_ == Progress5) {	//�D�V���b�t���E������

		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_SPACE)) {	//���V�[���ֈړ�


			player2.Moudules_Player_Attack(&player2, &enemy2, 1);//���v���C���[�̍U������(��)		
			enemy2.Moudules_Enemy_Attack(&player2, &enemy2, 1);//�G�̍U������	

			//�G�̍U�����[�V�����������E���Ԃ��������烂�W���[��cpp�Ɉړ�
			player2.Modules_Attack_init(&player2, &enemy2);

			if (player2.HP <= 0 || enemy2.HP <= 0) {

				player2.MainScene_ = Progress7;

			}
			else {

				player2.MainScene_ = Progress6;

			}


		}



	}
	else if (player2.MainScene_ == Progress6) {

		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RETURN)) { //Progress0�ɖ߂�

			player2.Card_Moudules_YAKU_Reshaffle(&player2, 8, 1);
			enemy2.Card_Moudules_YAKU_Reshaffle(&enemy2, 8, 3);

			player2.MainScene_ = Progress0;
			player2.Game_Start = false;
		}


	}
	else if (player2.MainScene_ == Progress7) {


		//�����I��


	}
	else if (player2.MainScene_ == Progress8) {


		player2.Card_Modules_Recovery_Menu(&player2);



	}
	else if (player2.MainScene_ == Progress9) {


		//�w���v���


	}
	else if (player2.MainScene_ == Progress10) {


		//���ꗗ


	}
	else if (player2.MainScene_ == Progress11) {



		//�߂��ʂ̕\��
		player2.Card_Modules_Back_Menu(&player2);


	}




}


//�`��Ǘ�
void HanahudaMgr_Draw_2() {

	//�v���C���[HP�o�[
	player2.HP_now = 1.0f * ((float)player2.HP / MAXHP_1);

	//enemyHP�o�[
	enemy2.HP_now = 1.0f * ((float)enemy2.HP / MAXHP_1);


	//�����̎�D��z�u	
	Mgr_Player_Card_Placement_2();

	//�G�̎�D�̔z�u
	Mgr_Enemy_Card_Placement_2();

	//HP�o�[
	DrawRotaGraph3(20, 700, 0, 0, player2.HP_now, 0.5f, 0, player2.HP_var, TRUE);
	DrawStringEx(20, 675, -1, "HP:%d / %d", player2.HP, 5000);

	//HP�E�G�o�[
	DrawRotaGraph3(700, 50, 0, 0, enemy2.HP_now, 0.5f, 0, enemy2.HP_var, TRUE);
	DrawStringEx(700, 25, -1, "HP:%d / %d", enemy2.HP, 5000);


	//�J�n���}�̊֐�
	player2.Modules_Battle_Start(&player2);

	//3�����݂̍U�����[�V�����iSE�Ɨ����G�Ɖ��y�̕\���j�EProgress3�̎�����
	player2.Modules_Attack_Motion(&player2, &enemy2, Progress4);


	//���̍U�����[�V����
	player2.Modules_Attack_Motion_YAKU(&player2, &enemy2, Progress5);


	//resurt���ʂ̕\��
	player2.Modules_Result(&player2, &enemy2, 3);

	//�w���v��ʂ̕\��
	player2.Card_Modules_Help(&player2, Progress1);

	//���ꗗ���X�g�̕\��
	player2.Card_Modules_YakuList(&player2, Progress10);


	/*DrawStringEx(50, 700, -1, "MY HP: %d", player2.HP);
	DrawStringEx(50, 730, -1, "TotalScore: %d", player2.TotalScore);
	DrawStringEx(50, 100, -1, "ENEMY HP: %d", enemy2.HP);
	DrawStringEx(40, 130, -1, "TotalScore: %d", enemy2.TotalScore);
	DrawStringEx(50, 250, -1, "�Q�[���V�[���i���o�[ : %d", player2.MainScene_);
	DrawStringEx(50, 400, -1, "AT_count: %d", player2.AT_counter);


	DrawStringEx(800, 200, -1, "jan : %d", enemy2.Jan);
	DrawStringEx(800, 230, -1, "Feb : %d", enemy2.Feb);
	DrawStringEx(800, 260, -1, "Mar : %d", enemy2.Mar);
	DrawStringEx(800, 290, -1, "Apr : %d", enemy2.Apr);
	DrawStringEx(800, 310, -1, "may : %d", enemy2.May);
	DrawStringEx(800, 340, -1, "jun : %d", enemy2.Jun);
	DrawStringEx(800, 370, -1, "july : %d", enemy2.Jul);
	DrawStringEx(800, 400, -1, "aug : %d", enemy2.Aug);
	DrawStringEx(800, 430, -1, "sep : %d", enemy2.Sep);
	DrawStringEx(800, 460, -1, "oct : %d", enemy2.Oct);
	DrawStringEx(800, 490, -1, "nov : %d", enemy2.Oct);
	DrawStringEx(800, 520, -1, "dec : %d", enemy2.Oct);*/


	/*DrawStringEx(50, 330, -1, "Ene_Sukim_3_Coun0:%d", enemy2.Ene_Sukim_3_Count[0]);
	DrawStringEx(50, 360, -1, "Ene_Sukim_3_Coun1:%d", enemy2.Ene_Sukim_3_Count[1]);
	DrawStringEx(50, 390, -1, "Ene_Sukim_3_Coun2:%d", enemy2.Ene_Sukim_3_Count[2]);
	DrawStringEx(50, 410, -1, "enemy2.Count_3:%d", enemy2.Count_3);*/


	//for (int i = 0; i < 8; i++) {

	//	DrawStringEx(50 + (i * 30), 270, -1, " %d", enemy2.YAKU_R[i]);

	//}

}

//-------------------------------------��������Ăяo���p�֐�-------------------------------------------------

//�`��E�ԎD�̔z�u�֐�
void Mgr_Player_Card_Placement_2() {	//�����̉ԎD�z�u

	for (int i = 0; i < 8; i++) {


		if (player2.Huda_UP[i]) {

			player2.cpos_y[i] = 450;

		}
		else if (i == NowSelect) {


			player2.cpos_x[i] = 100 + (i * 100);
			player2.cpos_y[i] = 500;

		}
		else {

			player2.cpos_x[i] = 100 + (i * 100);
			player2.cpos_y[i] = 600;

		}

		//�������ꍞ��		
		player2.cYaku_Num = player2.YAKU_R[i];
		//player2.cYaku_Num = 0;	//�e�X�g
		player2.c3_Num1 = player2.Sukumi_R[i];


		DrawRotaGraph(player2.cpos_x[i], player2.cpos_y[i], 1.0f, 0, Card2.Card[player2.uraomote][player2.cYaku_Num][player2.c3_Num1], true);
		//DrawRotaGraph(player2.cpos_x[i] + (i * 100), player2.cpos_y[i], 1.0f, 0, Card2.Card[player2.uraomote][0][0], true);

	}

}

void Mgr_Enemy_Card_Placement_2() {	//�G�̉ԎD�z�u

	for (int i = 0; i < 8; i++) {

		//�������ꍞ��		
		enemy2.cYaku_Num = enemy2.YAKU_R[i];	//�e�X�g��		
		enemy2.c3_Num1 = enemy2.Sukumi_R[i];


		if (enemy2.Huda_UP[i]) {

			enemy2.cpos_y[i] = 300;

		}
		else {

			enemy2.cpos_x[i] = 200 + (i * 100);
			enemy2.cpos_y[i] = 150;

		}

		DrawRotaGraph(enemy2.cpos_x[i], enemy2.cpos_y[i], 1.0f, 0, Card2.Card[enemy2.uraomote][enemy2.cYaku_Num][enemy2.c3_Num1], true);

	}

}


//�����̃J�[�h�̈ړ�����
void Mgr_Player_Card_Move_2() {

	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RIGHT) && player2.Game_Start == false) {	//�E�Ɉړ�

		NowSelect = (NowSelect + 1) % CardSel_NUM_;

	}

	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_LEFT) && player2.Game_Start == false) {	//���Ɉړ�

		NowSelect = (NowSelect + (CardSel_NUM_ - 1)) % CardSel_NUM_;

		for (int i = 0; i < 8; i++) {

			if (player2.Huda_UP[i]) {

				player2.cpos_y[i] = 450;

			}
			else if (i == NowSelect) {

				player2.cpos_y[i] = 500;

			}
			else {

				player2.cpos_y[i] = 600;

			}

		}

	}


	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_UP) && player2.Game_Start == false) {	//����ɏo���D�������肷��

		for (int i = 0; i < 8; i++) {

			if (i == NowSelect && player2.Count_3 < 3) {

				int SelectNum_r = NowSelect;
				player2.Count_3++;
				player2.Huda_UP[SelectNum_r] = true;
				player2.UR_Storage[SelectNum_r] = eCard_Omote;
				player2.YAKU1_Storage[SelectNum_r] = player2.YAKU_R[SelectNum_r];
				//player2.YAKU1_Storage[SelectNum_r] = 0;	//�e�X�g


				if (player2.Count_3 == 1) {

					player2.SUKUMI_Storage[0] = player2.Sukumi_R[SelectNum_r];
					player2.cpos_x[SelectNum_r] = 400;

				}
				else if (player2.Count_3 == 2) {

					player2.SUKUMI_Storage[1] = player2.Sukumi_R[SelectNum_r];
					player2.cpos_x[SelectNum_r] = 500;

				}
				else if (player2.Count_3 == 3) {

					player2.SUKUMI_Storage[2] = player2.Sukumi_R[SelectNum_r];
					player2.cpos_x[SelectNum_r] = 600;

				}


			}

		}

	}

	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_DOWN) && player2.Game_Start == false) {	//�D��������

		for (int i = 0; i < 8; i++) {

			player2.Count_3 = 0;
			player2.Huda_UP[i] = false;
			player2.UR_Storage[i] = eCard_Omote;
			player2.YAKU1_Storage[i] = 99;
			player2.SUKUMI_Storage[i] = 99;

		}

		player2.TotalScore = 0;
		player2.Jan = 0;
		player2.Feb = 0;
		player2.Mar = 0;
		player2.Apr = 0;
		player2.May = 0;
		player2.Jun = 0;
		player2.Jul = 0;
		player2.Aug = 0;
		player2.Sep = 0;
		player2.Oct = 0;
		player2.Nov = 0;
		player2.Dec = 0;

	}


}

//�G�̃J�[�h�̈ړ�����
void Mgr_Enemy_Card_Move_2() {

	for (int i = 0; i < 8; i++) {

		enemy2.UR_Storage[i] = eCard_Omote;
		enemy2.YAKU1_Storage[i] = enemy2.YAKU_R[i];
		enemy2.SUKUMI_Storage[i] = enemy2.Sukumi_R[i];

	}


}







