#include "DxLib.h"
#include "../library/t2klib.h"
#include "../support/Support.h"
#include "00.SceneMgr.h"
#include "02.Chapter.h"
#include "04_01.HanahudaMgr.h"
#include "04_99.Hanahuda_battle_Modules.h"
#include "04_99.Hanahuda_Card_Modules.h"
#include "04_99.Hanahuda_Score_Modules.h"
#include <time.h>


//BGM
static int BattleBGM = 0;

//�ԎD�̏������N���X
Hanahuda_Card Card;

//�v���C���[�N���X
Player player;	//�v���C���[��{���
Player enemy;	//�G�̊�{���

//�J�[�h�i���o�[������p
static int CardSel_NUM_ = 8;
static int NowSelect = 0;	//�I�𒆂̎�D


//�V�[���J��
static int GameScene_= Progress0;	//�Q�[�����V�[����0����n�܂�


//�v���g�^�C�v�錾
//�t�@�C�����ŕK�{�̌Ăяo���֐��B
//Mgr�`�Ƃ��֐��͂��̃t�@�C�����̊֐�,��ԉ��ɂ���B���̂ق��̊֐��͂��ׂ�battle_Modules.cpp�ɏW��
void Mgr_Player_Card_Placement();
void Mgr_Enemy_Card_Placement();

void Mgr_Player_Card_Move();
void Mgr_Enemy_Card_Move();


//-------------------------------------��������Ǘ��p���C���֐�------------------------------------------------

									
//�������Ǘ�
void HanahudaMgr_Initialize() {
	

	player.MainScene_ = Progress0;
	
	//�D�̏�����	
	Card.Card_Modules_Initialize();	


	//�����E�G�̎D�̍ŏ��̃V���b�t��
	player.Card_Moudules_First_Place(&player);
	enemy.Card_Moudules_First_Place(&enemy);

	//�D�𗐐��ŃV���b�t������i�����݁E�����Ɂj
	player.Card_Modules_YAKU_shuffle(&player, CardSel_NUM_);
	enemy.Card_Modules_YAKU_shuffle(&enemy, CardSel_NUM_);

	player.Card_Modules_3_shuffle(&player, CardSel_NUM_);
	enemy.Card_Modules_3_shuffle(&enemy, CardSel_NUM_);
		
	//BGM������
	BattleBGM = LoadSoundMem("sound/Battle_Stage_1.mp3");
	ChangeVolumeSoundMem(160,BattleBGM);
	PlaySoundMem(BattleBGM, DX_PLAYTYPE_LOOP);
	

	//����
	srand((unsigned int)time(0));

	
	//�摜�E���W�ESE�E�t�H���g����������
	player.Init_Battle(&player, &enemy, 1);

	
	//�����E�G�̎D�̍��W������
	for (int i = 0; i < 8; i++) {

		player.cpos_x[i] = 100 + (i * 100);
		player.cpos_y[i] = 750;

		enemy.cpos_x[i] = 200 + (i * 100);
		enemy.cpos_y[i] = 100;

	}

	//HP�̏�����
	/*player.HP = 5000;
	enemy.HP = 1000;*/

	//�G�̍U�����W�̍X�V
	enemy.AT_pos_x = 1200;
	enemy.AT_pos_y = -300;
	

}


//�I������
void HanahudaMgr_Finalize() {
	
	Card.Card_Modules_Finalize();
	DeleteSoundMem(BattleBGM);

	player.Finalize_Battle(&player);
	enemy.Finalize_Battle(&enemy);
	

}


//�X�V�E�v�Z�Ǘ�
void HanahudaMgr_Update() {

	//�w�i�\��
	DrawRotaGraph(512, 350, 1.0f, 0, player.Back_Image, true);
	player.System_Messeage(&player,&enemy);

	if (player.MainScene_ == Progress0) {	//�J�n���}

		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RETURN)) {	
	
			player.MainScene_ = Progress1;

		}



	}	
	else if (player.MainScene_ == Progress1) {	//�����J�[�h�̈ړ��^�[��
		
		
		//�y�֐��z�U���E�񕜂̃��j���[�\��
		player.Card_Modules_Menu(&player);

		
	}
	else if (player.MainScene_ == Progress2) {	//�v�Z�E�U������1
		
		Mgr_Player_Card_Move();	//�����J�[�h�̈ړ��֐�


		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RETURN)) {	//�o���D�̌��肷��

			player.Moudules_Myplayer_YAKUScore_RETURN(&player);	//����Ƌ��Ɏ��v���C���[�̖��X�R�A�̌v�Z������
			player.Game_Start = true; //�D��3���ȏ�グ�邱�Ƃ𐧌�
			player.Count_3 = 4;	 //�D��3���ȏ�グ�邱�Ƃ𐧌�

		}


		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_SPACE)) {	//���V�[���ֈړ�

			Mgr_Enemy_Card_Move();								//�V�[���ړ��Ɠ����ɓG�̃J�[�h�v�Z���s��
			enemy.Moudules_Enemy_Card_Place(&player, &enemy);	///�V�[���ړ��Ɠ����ɓG�̃J�[�h�v�Z���A�����3���o���i�v���C���[�J�[�h���v�Z���Ĕ��f�j
			enemy.Moudules_Enemy_YAKUScore_RETURN(&enemy);
			player.Moudules_All_Score_RETURN(&player, &enemy);	//3�����݁E���̓_�������Z


			player.MainScene_ = Progress3;
		}
		

	}
	else if (player.MainScene_ == Progress3) {	//�v�Z�E�U������2
	
		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_SPACE)) {	//���V�[���ֈړ�


			player.MainScene_ = Progress4;

		}

		
	}
	else if (player.MainScene_ == Progress4) {	//�v�Z�E�U������3
		
		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_SPACE)) {	//���V�[���ֈړ�

			//�����̍U�����[�V�����������E���Ԃ��������烂�W���[��cpp�Ɉړ�
			player.Modules_Attack_init(&player, &enemy);

			player.Moudules_Player_Attack(&player, &enemy, 0);//���v���C���[�̍U������(������)
			enemy.Moudules_Enemy_Attack(&player, &enemy, 0);//�G�̍U������	


			player.MainScene_ = Progress5;
			//player.AT_Wait[0] = false;

		}

		
	}
	else if (player.MainScene_ == Progress5) {	//�D�V���b�t���E������
		
		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_SPACE)) {	//���V�[���ֈړ�


			player.Moudules_Player_Attack(&player, &enemy, 1);//���v���C���[�̍U������(��)		
			enemy.Moudules_Enemy_Attack(&player, &enemy, 1);//�G�̍U������	

			//�G�̍U�����[�V�����������E���Ԃ��������烂�W���[��cpp�Ɉړ�
			player.Modules_Attack_init(&player, &enemy);

			if (player.HP <= 0 || enemy.HP <= 0) {

				player.MainScene_ = Progress7;

			}
			else {

				player.MainScene_ = Progress6;

			}



		}
		
		
		
	}
	else if (player.MainScene_ == Progress6) {

		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RETURN)) { //Progress0�ɖ߂�

			player.Card_Moudules_YAKU_Reshaffle(&player, 8,1);
			enemy.Card_Moudules_YAKU_Reshaffle(&enemy, 8,2);

			player.MainScene_ = Progress0;
			player.Game_Start = false;
		}
		

	}
	else if (player.MainScene_ == Progress7) {


		//�����I��


	}
	else if (player.MainScene_ == Progress8) {


		player.Card_Modules_Recovery_Menu(&player);



	}
	else if (player.MainScene_ == Progress9) {


		//�w���v���


	}
	else if (player.MainScene_ == Progress10) {


		//���ꗗ


	}
	else if (player.MainScene_ == Progress11) {



		//�߂��ʂ̕\��
		player.Card_Modules_Back_Menu(&player);


	}

	

	
}


//�`��Ǘ�
void HanahudaMgr_Draw() {
		
	//�v���C���[HP�o�[
	player.HP_now =1.0f * ( (float)player.HP / 5000.0f);

	//enemyHP�o�[
	enemy.HP_now = 1.0f * ((float)enemy.HP / 5000.0f);


	//�����̎�D��z�u	
	Mgr_Player_Card_Placement();

	//�G�̎�D�̔z�u
	Mgr_Enemy_Card_Placement();

	
	//HP�o�[
	DrawRotaGraph3(20, 700, 0, 0, player.HP_now, 0.5f, 0, player.HP_var, TRUE);
	DrawStringEx(20, 675, -1, "HP:%d / %d", player.HP, 5000);
	
	//HP�E�G�o�[
	DrawRotaGraph3(700, 50, 0, 0, enemy.HP_now, 0.5f, 0, enemy.HP_var, TRUE);
	DrawStringEx(700, 25, -1, "HP:%d / %d", enemy.HP, 5000);

	//�J�n���}�̊֐�
	player.Modules_Battle_Start(&player);
	
	//3�����݂̍U�����[�V�����iSE�Ɨ����G�Ɖ��y�̕\���j�EProgress3�̎�����
	player.Modules_Attack_Motion(&player,&enemy,Progress4);


	//���̍U�����[�V����
	player.Modules_Attack_Motion_YAKU(&player, &enemy, Progress5);


	//resurt���ʂ̕\��
	player.Modules_Result(&player, &enemy,2);

	//�w���v��ʂ̕\��
	player.Card_Modules_Help(&player, Progress9);

	//���ꗗ���X�g�̕\��
	player.Card_Modules_YakuList(&player, Progress10);

			
	/*DrawStringEx(50, 700, -1, "MY HP: %d", player.HP);
	DrawStringEx(50, 730, -1, "TotalScore: %d", player.TotalScore);
	DrawStringEx(50, 100, -1, "ENEMY HP: %d", enemy.HP);
	DrawStringEx(40, 130, -1, "TotalScore: %d", enemy.TotalScore);
	DrawStringEx(50, 250, -1, "�Q�[���V�[���i���o�[ : %d", player.MainScene_);
	DrawStringEx(50, 400, -1, "AT_count: %d", player.AT_counter);*/

	//
	//DrawStringEx(800, 200, -1, "jan : %d", player.Jan);
	//DrawStringEx(800, 230, -1, "Feb : %d", player.Feb);
	//DrawStringEx(800, 260, -1, "Mar : %d", player.Mar);
	//DrawStringEx(800, 290, -1, "Apr : %d", player.Apr);
	//DrawStringEx(800, 310, -1, "may : %d", player.May);
	//DrawStringEx(800, 340, -1, "jun : %d", player.Jun);
	//DrawStringEx(800, 370, -1, "july : %d", player.Jul);
	//DrawStringEx(800, 400, -1, "aug : %d", player.Aug);
	//DrawStringEx(800, 430, -1, "sep : %d", player.Sep);
	//DrawStringEx(800, 460, -1, "oct : %d", player.Oct);
	//DrawStringEx(800, 490, -1, "nov : %d", player.Oct);
	//DrawStringEx(800, 520, -1, "dec : %d", player.Oct);


	/*DrawStringEx(50, 330, -1, "Ene_Sukim_3_Coun0:%d", enemy.Ene_Sukim_3_Count[0]);
	DrawStringEx(50, 360, -1, "Ene_Sukim_3_Coun1:%d", enemy.Ene_Sukim_3_Count[1]);
	DrawStringEx(50, 390, -1, "Ene_Sukim_3_Coun2:%d", enemy.Ene_Sukim_3_Count[2]);
	DrawStringEx(50, 410, -1, "enemy.Count_3:%d", enemy.Count_3);*/


	/*for (int i = 0; i < 8; i++) {

		DrawStringEx(50+(i*30),270, -1, " %d", player.YAKU_R[i]);

	}*/

	


}

//-------------------------------------��������Ăяo���p�֐�-------------------------------------------------

//�`��E�ԎD�̔z�u�֐�
void Mgr_Player_Card_Placement() {	//�����̉ԎD�z�u

	for (int i = 0; i < 8; i++) {


		if (player.Huda_UP[i] ) {
			
			player.cpos_y[i] = 450;

		}		
		else if (i == NowSelect) {

			
			player.cpos_x[i] = 100 + (i * 100);
			player.cpos_y[i] = 500;

		}
		else {

			player.cpos_x[i] = 100+(i *100);
			player.cpos_y[i] = 600;

		}

		//�������ꍞ��		
		player.cYaku_Num = player.YAKU_R[i];
		//player.cYaku_Num = 0;	//�e�X�g
		player.c3_Num1 = player.Sukumi_R[i];
	

		DrawRotaGraph(player.cpos_x[i] , player.cpos_y[i], 1.0f, 0, Card.Card[player.uraomote][player.cYaku_Num][player.c3_Num1], true);
		//DrawRotaGraph(player.cpos_x[i] + (i * 100), player.cpos_y[i], 1.0f, 0, Card.Card[player.uraomote][0][0], true);

	}

}

void Mgr_Enemy_Card_Placement() {	//�G�̉ԎD�z�u

	for (int i = 0; i < 8; i++) {

		//�������ꍞ��		
		enemy.cYaku_Num = enemy.YAKU_R[i];	//�e�X�g��		
		enemy.c3_Num1 = enemy.Sukumi_R[i];
		
	
		if (enemy.Huda_UP[i]) {

			enemy.cpos_y[i] = 300;

		}
		else {

			enemy.cpos_x[i] = 200 + (i * 100);
			enemy.cpos_y[i] = 150;

		}
		
		DrawRotaGraph(enemy.cpos_x[i], enemy.cpos_y[i], 1.0f, 0, Card.Card[enemy.uraomote][enemy.cYaku_Num][enemy.c3_Num1], true);
		
	}

}


//�����̃J�[�h�̈ړ�����
void Mgr_Player_Card_Move() {
	
	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RIGHT) && player.Game_Start == false) {	//�E�Ɉړ�

		NowSelect = (NowSelect + 1) % CardSel_NUM_;

	}

	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_LEFT) && player.Game_Start == false) {	//���Ɉړ�

		NowSelect = (NowSelect + (CardSel_NUM_ -1)) % CardSel_NUM_;

		for (int i = 0; i < 8; i++) {
	
			if (player.Huda_UP[i] ) {

				player.cpos_y[i] = 450;

			}
			else if (i == NowSelect) {

				player.cpos_y[i] = 500;

			}
			else {

				player.cpos_y[i] = 600;

			}
			
		}

	}

	
	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_UP) && player.Game_Start == false) {	//����ɏo���D�������肷��

		for (int i = 0; i < 8; i++) {

			if (i == NowSelect && player.Count_3 <3){

				int SelectNum_r = NowSelect;
				player.Count_3++;				
				player.Huda_UP[SelectNum_r] = true;
				player.UR_Storage[SelectNum_r] = eCard_Omote;
				player.YAKU1_Storage[SelectNum_r] = player.YAKU_R[SelectNum_r];
				//player.YAKU1_Storage[SelectNum_r] = 0;	//�e�X�g
								
				
				if (player.Count_3 == 1) {
				
					player.SUKUMI_Storage[0] = player.Sukumi_R[SelectNum_r];
					player.cpos_x[SelectNum_r] = 400;

				}
				else if (player.Count_3 == 2) {

					player.SUKUMI_Storage[1] = player.Sukumi_R[SelectNum_r];
					player.cpos_x[SelectNum_r] = 500;

				}
				else if (player.Count_3 == 3) {

					player.SUKUMI_Storage[2] = player.Sukumi_R[SelectNum_r];
					player.cpos_x[SelectNum_r] = 600;

				}


			}

		}

	}

	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_DOWN) && player.Game_Start == false) {	//�D��������

		for (int i = 0; i < 8; i++) {
			
			player.Count_3 = 0;
			player.Huda_UP[i] = false;
			player.UR_Storage[i] = eCard_Omote;
			player.YAKU1_Storage[i] = 99;
			player.SUKUMI_Storage[i] = 99;		

		}

		player.TotalScore = 0;
		player.Jan = 0;
		player.Feb = 0;
		player.Mar = 0;
		player.Apr = 0;
		player.May = 0;
		player.Jun = 0;
		player.Jul = 0;
		player.Aug = 0;
		player.Sep = 0;
		player.Oct = 0;
		player.Nov = 0;
		player.Dec = 0;
	
	}


}

//�G�̃J�[�h�̈ړ�����
void Mgr_Enemy_Card_Move() {
		
	for (int i = 0; i < 8; i++) {

		enemy.UR_Storage[i] = eCard_Omote;
		enemy.YAKU1_Storage[i] = enemy.YAKU_R[i];	
		enemy.SUKUMI_Storage[i] = enemy.Sukumi_R[i];		

	}
	




}







