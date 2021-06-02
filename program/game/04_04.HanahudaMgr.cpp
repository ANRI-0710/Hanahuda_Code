#include "DxLib.h"
#include "../library/t2klib.h"
#include "../support/Support.h"
#include "00.SceneMgr.h"
#include "02.Chapter.h"
#include "04_04.HanahudaMgr.h"
#include "04_99.Hanahuda_battle_Modules.h"
#include "04_99.Hanahuda_Card_Modules.h"
#include "04_99.Hanahuda_Score_Modules.h"
#include <time.h>


//BGM
static int BattleBGM = 0;

//�ԎD�̏������N���X
Hanahuda_Card Card4;

//�v���C���[�N���X
Player player4;	//�v���C���[��{���
Player enemy4;	//�G�̊�{���

//�J�[�h�i���o�[������p
static int CardSel_NUM_ = 8;
static int NowSelect = 0;	//�I�𒆂̎�D


//�V�[���J��
static int GameScene_ = Progress0;	//�Q�[�����V�[����0����n�܂�


//�v���g�^�C�v�錾
//�t�@�C�����ŕK�{�̌Ăяo���֐��B
//Mgr�`�Ƃ��֐��͂��̃t�@�C�����̊֐�,��ԉ��ɂ���B���̂ق��̊֐��͂��ׂ�battle_Modules.cpp�ɏW��
void Mgr_Player_Card_Placement_4();
void Mgr_Enemy_Card_Placement_4();

void Mgr_Player_Card_Move_4();
void Mgr_Enemy_Card_Move_4();


//-------------------------------------��������Ǘ��p���C���֐�------------------------------------------------


//�������Ǘ�
void HanahudaMgr_Initialize_4() {


	player4.MainScene_ = Progress0;

	//�D�̏�����	
	Card4.Card_Modules_Initialize();

	//BGM������
	BattleBGM = LoadSoundMem("sound/Battle_Stage_1.mp3");
	ChangeVolumeSoundMem(160, BattleBGM);
	PlaySoundMem(BattleBGM, DX_PLAYTYPE_LOOP);


	//����
	srand(time(0));

	//�摜�E���W�ESE�E�t�H���g����������
	player4.Init_Battle(&player4, &enemy4, 4);

	//�����E�G�̎D�̍ŏ��̃V���b�t��
	player4.Card_Moudules_First_Place(&player4);
	enemy4.Card_Moudules_First_Place(&enemy4);


	//�D�𗐐��ŃV���b�t������i�����݁E�����Ɂj
	player4.Card_Modules_YAKU_shuffle(&player4, CardSel_NUM_);
	enemy4.Card_Modules_YAKU_shuffle(&enemy4, CardSel_NUM_);

	player4.Card_Modules_3_shuffle(&player4, CardSel_NUM_);
	enemy4.Card_Modules_3_shuffle(&enemy4, CardSel_NUM_);


	//�����E�G�̎D�̍��W������
	for (int i = 0; i < 8; i++) {

		player4.cpos_x[i] = 100 + (i * 100);
		player4.cpos_y[i] = 750;

		enemy4.cpos_x[i] = 200 + (i * 100);
		enemy4.cpos_y[i] = 100;

	}

	////HP�̏�����
	//player4.HP = 5000.0f;
	//enemy4.HP = 5000.0f;

	//�G�̍U�����W�̍X�V
	enemy4.AT_pos_x = 1200;
	enemy4.AT_pos_y = -300;


}


//�I������
void HanahudaMgr_Finalize_4() {

	Card4.Card_Modules_Finalize();
	DeleteSoundMem(BattleBGM);

	player4.Finalize_Battle(&player4);
	enemy4.Finalize_Battle(&enemy4);


}


//�X�V�E�v�Z�Ǘ�
void HanahudaMgr_Update_4() {


	//�w�i�\��
	DrawRotaGraph(512, 350, 1.0f, 0, player4.Back_Image, true);
	player4.System_Messeage(&player4, &enemy4);

	if (player4.MainScene_ == Progress0) {	//�J�n���}

		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RETURN)) {

			player4.MainScene_ = Progress1;

		}

	}
	else if (player4.MainScene_ == Progress1) {	//�����J�[�h�̈ړ��^�[��


		//�y�֐��z�U���E�񕜂̃��j���[�\��
		player4.Card_Modules_Menu(&player4);


	}
	else if (player4.MainScene_ == Progress2) {	//�v�Z�E�U������1

		Mgr_Player_Card_Move_4();	//�����J�[�h�̈ړ��֐�


		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RETURN)) {	//�o���D�̌��肷��

			player4.Moudules_Myplayer_YAKUScore_RETURN(&player4);	//����Ƌ��Ɏ��v���C���[�̖��X�R�A�̌v�Z������
			player4.Game_Start = true; //�D��3���ȏ�グ�邱�Ƃ𐧌�
			player4.Count_3 = 4;	 //�D��3���ȏ�グ�邱�Ƃ𐧌�

		}


		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_SPACE)) {	//���V�[���ֈړ�

			Mgr_Enemy_Card_Move_4();								//�V�[���ړ��Ɠ����ɓG�̃J�[�h�v�Z���s��
			enemy4.Moudules_Enemy_Card_Place_4(&player4, &enemy4);	///�V�[���ړ��Ɠ����ɓG�̃J�[�h�v�Z���A�����3���o���i�v���C���[�J�[�h���v�Z���Ĕ��f�j
			enemy4.Moudules_Enemy_YAKUScore_RETURN(&enemy4);
			player4.Moudules_All_Score_RETURN(&player4, &enemy4);	//3�����݁E���̓_�������Z


			player4.MainScene_ = Progress3;
		}


	}
	else if (player4.MainScene_ == Progress3) {	//�v�Z�E�U������2

		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_SPACE)) {	//���V�[���ֈړ�

			player4.MainScene_ = Progress4;

		}


	}
	else if (player4.MainScene_ == Progress4) {	//�v�Z�E�U������3

		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_SPACE)) {	//���V�[���ֈړ�

			//�����̍U�����[�V�����������E���Ԃ��������烂�W���[��cpp�Ɉړ�
			player4.Modules_Attack_init(&player4, &enemy4);

			player4.Moudules_Player_Attack(&player4, &enemy4, 0);//���v���C���[�̍U������(������)
			enemy4.Moudules_Enemy_Attack(&player4, &enemy4, 0);//�G�̍U������	


			player4.MainScene_ = Progress5;
			//player4.AT_Wait[0] = false;

		}


	}
	else if (player4.MainScene_ == Progress5) {	//�D�V���b�t���E������

		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_SPACE)) {	//���V�[���ֈړ�


			player4.Moudules_Player_Attack(&player4, &enemy4, 1);//���v���C���[�̍U������(��)		
			enemy4.Moudules_Enemy_Attack(&player4, &enemy4, 1);//�G�̍U������	

			//�G�̍U�����[�V�����������E���Ԃ��������烂�W���[��cpp�Ɉړ�
			player4.Modules_Attack_init(&player4, &enemy4);

			if (player4.HP <= 0 || enemy4.HP <= 0) {

				player4.MainScene_ = Progress7;

			}
			else {

				player4.MainScene_ = Progress6;

			}


		}



	}
	else if (player4.MainScene_ == Progress6) {

		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RETURN)) { //Progress0�ɖ߂�

			player4.Card_Moudules_YAKU_Reshaffle(&player4, 8, 1);
			enemy4.Card_Moudules_YAKU_Reshaffle(&enemy4, 8, 1);

			player4.MainScene_ = Progress0;
			player4.Game_Start = false;
		}


	}
	else if (player4.MainScene_ == Progress7) {


		//�����I��


	}
	else if (player4.MainScene_ == Progress8) {


		player4.Card_Modules_Recovery_Menu(&player4);



	}
	else if (player4.MainScene_ == Progress9) {


		//�w���v���


	}
	else if (player4.MainScene_ == Progress10) {


		//���ꗗ


	}
	else if (player4.MainScene_ == Progress11) {



		//�߂��ʂ̕\��
		player4.Card_Modules_Back_Menu(&player4);


	}




}


//�`��Ǘ�
void HanahudaMgr_Draw_4() {

	//�v���C���[HP�o�[
	player4.HP_now = 1.0f * ((float)player4.HP / MAXHP_1);

	//enemyHP�o�[
	enemy4.HP_now = 1.0f * ((float)enemy4.HP / MAXHP_1);


	//�����̎�D��z�u	
	Mgr_Player_Card_Placement_4();

	//�G�̎�D�̔z�u
	Mgr_Enemy_Card_Placement_4();

	//HP�o�[
	DrawRotaGraph3(20, 700, 0, 0, player4.HP_now, 0.5f, 0, player4.HP_var, TRUE);
	DrawStringEx(20, 675, -1, "HP:%d / %d", player4.HP, 5000);

	//HP�E�G�o�[
	DrawRotaGraph3(700, 50, 0, 0, enemy4.HP_now, 0.5f, 0, enemy4.HP_var, TRUE);
	DrawStringEx(700, 25, -1, "HP:%d / %d", enemy4.HP, 5000);


	//�J�n���}�̊֐�
	player4.Modules_Battle_Start(&player4);

	//3�����݂̍U�����[�V�����iSE�Ɨ����G�Ɖ��y�̕\���j�EProgress3�̎�����
	player4.Modules_Attack_Motion(&player4, &enemy4, Progress4);


	//���̍U�����[�V����
	player4.Modules_Attack_Motion_YAKU(&player4, &enemy4, Progress5);


	//resurt���ʂ̕\��
	player4.Modules_Result(&player4, &enemy4, 5);

	//�w���v��ʂ̕\��
	player4.Card_Modules_Help(&player4, Progress1);

	//���ꗗ���X�g�̕\��
	player4.Card_Modules_YakuList(&player4, Progress10);


	/*DrawStringEx(50, 700, -1, "MY HP: %d", player4.HP);
	DrawStringEx(50, 730, -1, "TotalScore: %d", player4.TotalScore);
	DrawStringEx(50, 100, -1, "ENEMY HP: %d", enemy4.HP);
	DrawStringEx(40, 130, -1, "TotalScore: %d", enemy4.TotalScore);
	DrawStringEx(50, 250, -1, "�Q�[���V�[���i���o�[ : %d", player4.MainScene_);
	DrawStringEx(50, 400, -1, "AT_count: %d", player4.AT_counter);


	DrawStringEx(800, 200, -1, "jan : %d", enemy4.Jan);
	DrawStringEx(800, 230, -1, "Feb : %d", enemy4.Feb);
	DrawStringEx(800, 260, -1, "Mar : %d", enemy4.Mar);
	DrawStringEx(800, 290, -1, "Apr : %d", enemy4.Apr);
	DrawStringEx(800, 310, -1, "may : %d", enemy4.May);
	DrawStringEx(800, 340, -1, "jun : %d", enemy4.Jun);
	DrawStringEx(800, 370, -1, "july : %d", enemy4.Jul);
	DrawStringEx(800, 400, -1, "aug : %d", enemy4.Aug);
	DrawStringEx(800, 430, -1, "sep : %d", enemy4.Sep);
	DrawStringEx(800, 460, -1, "oct : %d", enemy4.Oct);
	DrawStringEx(800, 490, -1, "nov : %d", enemy4.Oct);
	DrawStringEx(800, 520, -1, "dec : %d", enemy4.Oct);*/


	/*DrawStringEx(50, 330, -1, "Ene_Sukim_3_Coun0:%d", enemy4.Ene_Sukim_3_Count[0]);
	DrawStringEx(50, 360, -1, "Ene_Sukim_3_Coun1:%d", enemy4.Ene_Sukim_3_Count[1]);
	DrawStringEx(50, 390, -1, "Ene_Sukim_3_Coun2:%d", enemy4.Ene_Sukim_3_Count[2]);
	DrawStringEx(50, 410, -1, "enemy4.Count_3:%d", enemy4.Count_3);*/


	/*for (int i = 0; i < 8; i++) {

		DrawStringEx(50 + (i * 30), 270, -1, " %d", enemy4.YAKU2_Storage[i]);

	}*/

}

//-------------------------------------��������Ăяo���p�֐�-------------------------------------------------

//�`��E�ԎD�̔z�u�֐�
void Mgr_Player_Card_Placement_4() {	//�����̉ԎD�z�u

	for (int i = 0; i < 8; i++) {


		if (player4.Huda_UP[i]) {

			player4.cpos_y[i] = 450;

		}
		else if (i == NowSelect) {


			player4.cpos_x[i] = 100 + (i * 100);
			player4.cpos_y[i] = 500;

		}
		else {

			player4.cpos_x[i] = 100 + (i * 100);
			player4.cpos_y[i] = 600;

		}

		//�������ꍞ��		
		player4.cYaku_Num = player4.YAKU_R[i];
		//player4.cYaku_Num = 0;	//�e�X�g
		player4.c3_Num1 = player4.Sukumi_R[i];


		DrawRotaGraph(player4.cpos_x[i], player4.cpos_y[i], 1.0f, 0, Card4.Card[player4.uraomote][player4.cYaku_Num][player4.c3_Num1], true);
		//DrawRotaGraph(player4.cpos_x[i] + (i * 100), player4.cpos_y[i], 1.0f, 0, Card2.Card[player4.uraomote][0][0], true);

	}

}

void Mgr_Enemy_Card_Placement_4() {	//�G�̉ԎD�z�u

	for (int i = 0; i < 8; i++) {

		//�������ꍞ��		
		enemy4.cYaku_Num = enemy4.YAKU_R[i];	//�e�X�g��		
		enemy4.c3_Num1 = enemy4.Sukumi_R[i];


		if (enemy4.Huda_UP[i]) {

			enemy4.cpos_y[i] = 300;

		}
		else {

			enemy4.cpos_x[i] = 200 + (i * 100);
			enemy4.cpos_y[i] = 150;

		}

		DrawRotaGraph(enemy4.cpos_x[i], enemy4.cpos_y[i], 1.0f, 0, Card4.Card[enemy4.uraomote][enemy4.cYaku_Num][enemy4.c3_Num1], true);

	}

}


//�����̃J�[�h�̈ړ�����
void Mgr_Player_Card_Move_4() {

	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RIGHT) && player4.Game_Start == false) {	//�E�Ɉړ�

		NowSelect = (NowSelect + 1) % CardSel_NUM_;

	}

	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_LEFT) && player4.Game_Start == false) {	//���Ɉړ�

		NowSelect = (NowSelect + (CardSel_NUM_ - 1)) % CardSel_NUM_;

		for (int i = 0; i < 8; i++) {

			if (player4.Huda_UP[i]) {

				player4.cpos_y[i] = 450;

			}
			else if (i == NowSelect) {

				player4.cpos_y[i] = 500;

			}
			else {

				player4.cpos_y[i] = 600;

			}

		}

	}


	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_UP) && player4.Game_Start == false) {	//����ɏo���D�������肷��

		for (int i = 0; i < 8; i++) {

			if (i == NowSelect && player4.Count_3 < 3) {

				int SelectNum_r = NowSelect;
				player4.Count_3++;
				player4.Huda_UP[SelectNum_r] = true;
				player4.UR_Storage[SelectNum_r] = eCard_Omote;
				player4.YAKU1_Storage[SelectNum_r] = player4.YAKU_R[SelectNum_r];
				//player4.YAKU1_Storage[SelectNum_r] = 0;	//�e�X�g


				if (player4.Count_3 == 1) {

					player4.SUKUMI_Storage[0] = player4.Sukumi_R[SelectNum_r];
					player4.cpos_x[SelectNum_r] = 400;

				}
				else if (player4.Count_3 == 2) {

					player4.SUKUMI_Storage[1] = player4.Sukumi_R[SelectNum_r];
					player4.cpos_x[SelectNum_r] = 500;

				}
				else if (player4.Count_3 == 3) {

					player4.SUKUMI_Storage[2] = player4.Sukumi_R[SelectNum_r];
					player4.cpos_x[SelectNum_r] = 600;

				}


			}

		}

	}

	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_DOWN) && player4.Game_Start == false) {	//�D��������

		for (int i = 0; i < 8; i++) {

			player4.Count_3 = 0;
			player4.Huda_UP[i] = false;
			player4.UR_Storage[i] = eCard_Omote;
			player4.YAKU1_Storage[i] = 99;
			player4.SUKUMI_Storage[i] = 99;

		}

		player4.TotalScore = 0;
		player4.Jan = 0;
		player4.Feb = 0;
		player4.Mar = 0;
		player4.Apr = 0;
		player4.May = 0;
		player4.Jun = 0;
		player4.Jul = 0;
		player4.Aug = 0;
		player4.Sep = 0;
		player4.Oct = 0;
		player4.Nov = 0;
		player4.Dec = 0;

	}


}

//�G�̃J�[�h�̈ړ�����
void Mgr_Enemy_Card_Move_4() {

	for (int i = 0; i < 8; i++) {

		enemy4.UR_Storage[i] = eCard_Omote;
		enemy4.YAKU1_Storage[i] = enemy4.YAKU_R[i];
		enemy4.SUKUMI_Storage[i] = enemy4.Sukumi_R[i];

	}


}







