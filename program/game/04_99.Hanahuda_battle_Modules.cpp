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

//�y�֐��z�摜�E�G�t�F�N�g����������
void::Player::Init_Battle(Player* player, Player* enemy, int GameNum) {

	//����
	//���ʉ�������
	player->Attck_Sound = LoadSoundMem("sound/katana-slash5.mp3");
	enemy->Attck_Sound = LoadSoundMem("sound/katana-slash5.mp3");

	player->start_BGM[0] = LoadSoundMem("sound/hyoushigi2.mp3");
	player->start_BGM[1] = LoadSoundMem("sound/drum-japanese2.mp3");

	player->Finish_win_SE = LoadSoundMem("sound/katana-slash5.mp3");
	player->Finish_lose_SE = LoadSoundMem("sound/katana-slash5.mp3");

	//�w�i�\��
	player->Back_Image = LoadGraph("graphics/Backimage_0909.png");

	//�t�H���g
	player->Font_Meicho = CreateFontToHandle("�l�r ����", 20, 9, DX_FONTTYPE_NORMAL);
	player->Font_Meicho_big = CreateFontToHandle("�l�r ����", 60, 9, DX_FONTTYPE_NORMAL, -1, -1, 1, -1);
	enemy->Font_Meicho_big = CreateFontToHandle("�l�r ����", 60, 9, DX_FONTTYPE_NORMAL, -1, -1, 1, -1);


	//HP�Q�[�W�̏�����
	player->HP_var = LoadGraph("graphics/HPvar.png");
	enemy->HP_var = LoadGraph("graphics/HPvar.png");

	//�G�t�F�N�g�̏�����
	LoadDivGraph("graphics/Effect/pipo-btleffect088.png", 8, 8, 1, 240, 240, player->Attack_Effect);
	LoadDivGraph("graphics/Effect/pipo-btleffect088.png", 8, 8, 1, 240, 240, enemy->Attack_Effect);

	//�����I���̍ۂ̉摜������
	player->start_image = LoadGraph("graphics/gamestart.png");
	player->fin_image = LoadGraph("graphics/gamefin.png");
	player->Finish_win_image = LoadGraph("graphics/game_win.png");
	player->Finish_lose_image = LoadGraph("graphics/gamefin_lose.png");

	//���̉摜�\��
	player->YAKU_Sankou_image = LoadGraph("graphics/kougeki_Sankou.png");
	player->YAKU_Ameiri_Sankou_image = LoadGraph("graphics/kougeki_AmehuriSankou.png");
	player->YAKU_Inosika_chou_image = LoadGraph("graphics/kougeki_Inosika.png");
	player->YAKU_Tsukimi_image = LoadGraph("graphics/kougeki_tukimi.png");
	player->YAKU_Hanami_image = LoadGraph("graphics/kougeki_hanamide.png");
	player->YAKU_ImageJan = LoadGraph("graphics/kougeki_1gatu.png");
	player->YAKU_ImageFeb = LoadGraph("graphics/kougeki_2gatu.png");
	player->YAKU_ImageMar = LoadGraph("graphics/kougeki_3gatu.png");
	player->YAKU_ImageApr = LoadGraph("graphics/kougeki_4gatu.png");
	player->YAKU_ImageMay = LoadGraph("graphics/kougeki_5gatu.png");
	player->YAKU_ImageJun = LoadGraph("graphics/kougeki_6gatu.png");
	player->YAKU_ImageJul = LoadGraph("graphics/kougeki_7gatu.png");
	player->YAKU_ImageAug = LoadGraph("graphics/kougeki_8gatu.png");
	player->YAKU_ImageSep = LoadGraph("graphics/kougeki_9gatu.png");
	player->YAKU_ImageOct = LoadGraph("graphics/kougeki_10gatu.png");
	player->YAKU_ImageNov = LoadGraph("graphics/kougeki_11gatu.png");
	player->YAKU_ImageSep = LoadGraph("graphics/kougeki_12gatu.png");

	enemy->YAKU_Sankou_image = LoadGraph("graphics/kougeki_Sankou.png");
	enemy->YAKU_Ameiri_Sankou_image = LoadGraph("graphics/kougeki_AmehuriSankou.png");
	enemy->YAKU_Inosika_chou_image = LoadGraph("graphics/kougeki_Inosika.png");
	enemy->YAKU_Tsukimi_image = LoadGraph("graphics/kougeki_tukimi.png");
	enemy->YAKU_Hanami_image = LoadGraph("graphics/kougeki_hanamide.png");
	enemy->YAKU_ImageJan = LoadGraph("graphics/kougeki_1gatu.png");
	enemy->YAKU_ImageFeb = LoadGraph("graphics/kougeki_2gatu.png");
	enemy->YAKU_ImageMar = LoadGraph("graphics/kougeki_3gatu.png");
	enemy->YAKU_ImageApr = LoadGraph("graphics/kougeki_4gatu.png");
	enemy->YAKU_ImageMay = LoadGraph("graphics/kougeki_5gatu.png");
	enemy->YAKU_ImageJun = LoadGraph("graphics/kougeki_6gatu.png");
	enemy->YAKU_ImageJul = LoadGraph("graphics/kougeki_7gatu.png");
	enemy->YAKU_ImageAug = LoadGraph("graphics/kougeki_8gatu.png");
	enemy->YAKU_ImageSep = LoadGraph("graphics/kougeki_9gatu.png");
	enemy->YAKU_ImageOct = LoadGraph("graphics/kougeki_10gatu.png");
	enemy->YAKU_ImageNov = LoadGraph("graphics/kougeki_11gatu.png");
	enemy->YAKU_ImageSep = LoadGraph("graphics/kougeki_12gatu.png");

	
	//���񂷂��ݕ\�̕\��
	player->Sansukumi = LoadGraph("graphics/zokuseihyou.png");


	//�w���v��ʂ̏�����
	player->HelpImage = LoadGraph("graphics/help1.png");
	player->HelpImage2 = LoadGraph("graphics/help2.png");

	//���ꗗ���X�g
	player->YakuList = LoadGraph("graphics/Yakuitiranhyou.png");

	//�����E�G�̎D�̍��W������
	for (int i = 0; i < 8; i++) {

		player->cpos_x[i] = 100 + (i * 100);
		player->cpos_y[i] = 750;

		enemy->cpos_x[i] = 200 + (i * 100);
		enemy->cpos_y[i] = 100;

	}

	//HP�̏�����
	player->HP = 5000;
	enemy->HP = 5000;

	//�G�̍U�����W�̍X�V
	enemy->AT_pos_x = 1200;
	enemy->AT_pos_y = -300;

	//�Q�[���V�[���ɂ���ĕύX����V�[��

	if (GameNum == 1) {

		//�U�����̗����G�̏�����
		player->Attack_Image = LoadGraph("graphics/00_kougeki.png");
		enemy->Attack_Image = LoadGraph("graphics/01_kougeki.png");

		//�J�n���}�̉摜�̏�����
		player->VS_player_img = LoadGraph("graphics/vsplayer.png");
		player->VS_enemy_img = LoadGraph("graphics/vsenemy1.png");


	}
	else if (GameNum == 2) {

		//�U�����̗����G�̏�����
		player->Attack_Image = LoadGraph("graphics/00_kougeki.png");
		enemy->Attack_Image = LoadGraph("graphics/02_kougeki.png");

		//�J�n���}�̉摜�̏�����
		player->VS_player_img = LoadGraph("graphics/vsplayer.png");
		player->VS_enemy_img = LoadGraph("graphics/vsenemy2.png");



	}
	else if (GameNum == 3) {


		//�U�����̗����G�̏�����
		player->Attack_Image = LoadGraph("graphics/00_kougeki.png");
		enemy->Attack_Image = LoadGraph("graphics/03_kougeki.png");

		//�J�n���}�̉摜�̏�����
		player->VS_player_img = LoadGraph("graphics/vsplayer.png");
		player->VS_enemy_img = LoadGraph("graphics/vsenemy3.png");



	}
	else if (GameNum == 4) {


		//�U�����̗����G�̏�����
		player->Attack_Image = LoadGraph("graphics/00_kougeki.png");
		enemy->Attack_Image = LoadGraph("graphics/04_kougeki.png");

		//�J�n���}�̉摜�̏�����
		player->VS_player_img = LoadGraph("graphics/vsplayer.png");
		player->VS_enemy_img = LoadGraph("graphics/vsenemy4.png");



	}


}


//�y�֐��z�����J�n�֐�
void::Player::Modules_Battle_Start(Player* player) {

	player->Start_time++;

	if (player->MainScene_ == Progress0) {

		if (30 < player->Start_time && player->Start_time <= 100) {

			DrawRotaGraph(700, 200, 0.5f, 0, player->VS_enemy_img, true);

			DrawRotaGraph(250, 600, 0.5f, 0, player->VS_player_img, true);
			PlaySoundMem(player->start_BGM[0], DX_PLAYTYPE_BACK);

		}
		else if (100 < player->Start_time && player->Start_time <= 200) {


			DrawRotaGraph(512, 384, 1.0f, 0, player->start_image, true);
			
		}
		else if (player->Start_time > 250) {

			PlaySoundMem(player->start_BGM[1], DX_PLAYTYPE_BACK);
			player->MainScene_ = Progress1;
			
		}

	}


}


//�I�����U���g
void::Player::Modules_Result(Player* player, Player* enemy, int UNLOCKNUM) {

	if (player->MainScene_ == Progress7) {

		player->Finish_time[0]++;

		if (60 < player->Finish_time[0] && player->Finish_time[0] <= 360) {


			DrawRotaGraph(512, 384, 1.0f, 0, player->fin_image, true);


		}
		else if (360 < player->Finish_time[0] && player->Finish_time[0] <= 720) {

			if (enemy->HP <= 0) {

				DrawRotaGraph(512, 384, 1.0f, 0, player->Finish_win_image, true);

				int UNLOCK = UNLOCKNUM;
				Chapter_Unlock(&UNLOCK);

			}
			else if (player->HP <= 0) {

				DrawRotaGraph(512, 384, 1.0f, 0, player->Finish_lose_image, true);

			}

		}
		else if (720 < player->Finish_time[0] && player->Finish_time[0] <= 1200) {

			player->Start_time = 0;
			player->AT_speed_1 = 50;
			player->AT_pos_x = 30;
			player->AT_pos_y = 700;
			player->AT_counter = 0;
			player->Attck_E_anim = 0;
			player->Attack_E_time = 0;

			enemy->AT_speed_1 = 50;
			enemy->AT_pos_x = 1000;
			enemy->AT_pos_y = 30;
			enemy->AT_counter = 0;
			enemy->Attck_E_anim = 0;
			enemy->Attack_E_time = 0;

			
			player->Finalize_Battle(player);
			enemy->Finalize_Battle(enemy);

			player->MainScene_ = Progress0;

			HanahudaMgr_Finalize();

			if (UNLOCKNUM == 5) {

				SceneMgr_ChangeScene(Novel_5);


			}
			else {

				SceneMgr_ChangeScene(Chapter);


			}

			

		}


	}


}


//�\�����b�Z�[�W�̊Ǘ�
void::Player::System_Messeage(Player* player,Player* enemy) {

	if (player->MainScene_ == Progress1) {

		DrawStringEx(450, 680, -1, "�E���j���[���牽�����邩�I��ł��������B");

	}
	else if (player->MainScene_ == Progress2) {

		if (player->Count_3 == 0) {

			DrawStringEx(450, 680, -1, "1�Ԏ�ɏo����D�����߂Ă��������B");

		}
		else if (player->Count_3 == 1) {

			DrawStringEx(450, 680, -1, "2�Ԏ�ɏo����D�����߂Ă��������B");

		}
		else if (player->Count_3 == 2) {

			DrawStringEx(450, 680, -1, "3�Ԏ�ɏo����D�����߂Ă��������B");

		}
		else if (player->Count_3 == 3) {

			DrawStringEx(450, 680, -1, "���̎D�Ō���ł����Enter�L�[�������Ă��������B");
			DrawStringEx(450, 710, -1, "�l���Ȃ����ꍇ�́A���{�^���������Ă��������B");

		}
		else if (player->Count_3 == 4) {

			DrawStringEx(450, 680, -1, "�D�����肵�܂����B�X�y�[�X�L�[�œG�̃^�[���ɓ���܂��B");

		}

	}
	else if (player->MainScene_ == Progress3) {

	
		DrawStringEx(450, 680, -1, "�G�̎�D�����܂�܂����B", player->MainScene_);
		DrawStringEx(450, 710, -1, "�X�y�[�X�L�[�ő����U���ɓ���܂��B");

	}
	else if (player->MainScene_ == Progress4) {


		DrawStringEx(450, 680, -1, "�����U���J�n!", player->MainScene_);
		DrawStringEx(450, 710, -1, "�X�y�[�X�L�[�Ŗ��U���ɓ���܂��B");

	}
	else if (player->MainScene_ == Progress5) {


		DrawStringEx(450, 680, -1, "���U���J�n!", player->MainScene_);
		

	}
	else if (player->MainScene_ == Progress6) {

		DrawStringEx(450, 680, -1, "�^�[�����I�����܂����B��ɏo�����D���V���b�t�����܂��B", player->MainScene_);
		DrawStringEx(450, 710, -1, "Enter�{�^���������Ă��������B", player->MainScene_);

	}

	//SetFontSize(30);
	DrawStringToHandle(390, 360, "��", GetColor(255, 255, 255), player->Font_Meicho);
	DrawStringToHandle(490, 360, "��", GetColor(255, 255, 255), player->Font_Meicho);
	DrawStringToHandle(590, 360, "�Q", GetColor(255, 255, 255), player->Font_Meicho);

	
	//���񂷂��ݕ\��
	DrawRotaGraph(70, 150, 0.4f, 0, player->Sansukumi, true);
		

}

//�y�֐��z�U���E�񕜂̃��j���[�\��
void::Player::Card_Modules_Menu(Player* player) {

	//�v�Z����
	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_DOWN)) {

		player->NowSelect_M = (player->NowSelect_M + 1) % 5;
		//PlaySoundMem(Change_SE, DX_PLAYTYPE_BACK);

	}

	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_UP)) {

		player->NowSelect_M = (player->NowSelect_M + (5 - 1)) % 5;
		//PlaySoundMem(Change_SE, DX_PLAYTYPE_BACK);
	}

	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RETURN)) {

		switch (player->NowSelect_M)
		{
		case 0:
			player->MainScene_ = Progress2;
			break;

		case 1:
			player->MainScene_ = Progress8;
			break;
		case 2:
			player->MainScene_ = Progress9;
			break;
		case 3:
			player->MainScene_ = Progress10;
			break;
		
		case 4:
			player->MainScene_ = Progress11;
			break;


		}
		//PlaySoundMem(ENTER_SE, DX_PLAYTYPE_BACK);
		
	}

	int y_t = 0;
	
	switch (player->NowSelect_M)
	{
	case 0:
		y_t = 570;
		break;

	case 1:
		y_t = 600;
		break;
	case 2:
		y_t = 630;
		break;

	case 3:
		y_t = 660;
		break;

	case 4:
		y_t = 690;
		break;



	}

	//���j���[�`��		
	DrawStringToHandle(870, y_t, "��", GetColor(255, 255, 255), player->Font_Meicho);
	DrawStringToHandle(900, 570, "�U��", GetColor(255, 255, 255), player->Font_Meicho);
	DrawStringToHandle(900, 600, "��", GetColor(255, 255, 255), player->Font_Meicho);
	DrawStringToHandle(900, 630, "�w���v", GetColor(255, 255, 255), player->Font_Meicho);
	DrawStringToHandle(900, 660, "���ꗗ", GetColor(255, 255, 255), player->Font_Meicho);
	DrawStringToHandle(900, 690, "�������f", GetColor(255, 255, 255), player->Font_Meicho);	
}

//�񕜃��j���[�̕\��
void::Player::Card_Modules_Recovery_Menu(Player* player) {

	//�v�Z����
	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_DOWN)) {

		player->NowSelect_Kaihuku = (player->NowSelect_Kaihuku + 1) % 3;

	}

	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_UP)) {

		player->NowSelect_Kaihuku = (player->NowSelect_Kaihuku + (3 - 1)) % 3;
	}

	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RETURN)) {

		switch (player->NowSelect_Kaihuku)
		{
		case 0:
			player->Card_Modules_HP_Recovery(player, 1);
			player->MainScene_ = Progress2;
			break;

		case 1:
			player->Card_Modules_HP_Recovery(player, 2);
			player->MainScene_ = Progress2;
			break;
		case 2:
			player->Card_Modules_HP_Recovery(player, 3);
			player->MainScene_ = Progress2;
			break;

		}

	}

	int y_t = 0;

	switch (player->NowSelect_Kaihuku)
	{
	case 0:
		y_t = 600;
		DrawStringEx(450, 700, -1, "HP��500�񕜂��܂��B");
		break;

	case 1:
		y_t = 650;
		DrawStringEx(450, 700, -1, "HP��1000�񕜂��܂��B");
		break;
	case 2:
		y_t = 700;
		DrawStringEx(450, 700, -1, "HP��1500�񕜂��܂��B");

	}

	//�`��	
	DrawStringEx(850, y_t, -1, "��");
	DrawStringEx(870, 600, -1, "�񕜎�i���j�~%d",player->Kihuku_small);
	DrawStringEx(870, 650, -1, "�񕜎�i���j�~%d", player->Kihuku_Midium);
	DrawStringEx(870, 700, -1, "�񕜎�i��j�~%d", player->Kihuku_Big);

}

//�񕜏���
void::Player::Card_Modules_HP_Recovery(Player* player, int kaihukuNum) {
	
	if (kaihukuNum == 1 && player->Kihuku_small >= 0) {

		player->HP += 500;

		if (player->HP > MAXHP_1) {

			player->HP = MAXHP_1;

		}


		player->Kihuku_small -= 1;


	}
	else if (kaihukuNum == 2 && player->Kihuku_Midium >= 0 ) {

		player->HP += 1000;
		player->Kihuku_Midium -= 1;
	}
	else if (kaihukuNum == 3 && player->Kihuku_Big >= 0) {


		player->HP += 1500;
		player->Kihuku_Big -= 1;

	}

}

//�w���v��ʂ̕\��
void Player::Card_Modules_Help(Player* player, int nowscene) {

	if (player->MainScene_ == Progress9) {

		if (player->Help_Scene_1 == 0) {

					
			DrawRotaGraph(512, 350, 1.0f, 0, player->HelpImage, true);
			DrawStringEx(150, 550, -1, "H�L�[�Ŏ��̃y�[�W�ɐi�݂܂��B");

			if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_H)) {
		
				player->Help_Scene_1++;

			}

		}
		else if (player->Help_Scene_1 == 1) {


			DrawRotaGraph(512, 350, 1.0f, 0, player->HelpImage2, true);
			DrawStringEx(150, 550, -1, "H�L�[�Ń��j���[�ɖ߂�܂��B");

			if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_H)) {


				player->MainScene_ = Progress1;
				player->Help_Scene_1 = 0;
			}


		}

	}

}


//���ꗗ���X�g�̕\��
void Player::Card_Modules_YakuList(Player* player, int nowscene) {

	if (player->MainScene_ == Progress10) {

	
			DrawRotaGraph(512, 350, 1.0f, 0, player->YakuList, true);
			DrawStringEx(300, 130, -1, "H�L�[�Ń��j���[�ɖ߂�܂��B");

			if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_H)) {


				player->MainScene_ = Progress1;
				player->Help_Scene_1 = 0;
			}


	}

}

void Player::Card_Modules_Back_Menu(Player* player) {

	if (player->MainScene_ == Progress11) {


		//�v�Z����
		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_DOWN)) {

			player->GoBack_Num = (player->GoBack_Num + 1) % 2;
			//PlaySoundMem(Change_SE, DX_PLAYTYPE_BACK);

		}

		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_UP)) {

			player->GoBack_Num = (player->GoBack_Num + (2 - 1)) % 2;
			//PlaySoundMem(Change_SE, DX_PLAYTYPE_BACK);
		}

		if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RETURN)) {

			switch (player->GoBack_Num)
			{
			case 0:
				player->MainScene_ = Progress1;
				break;

			case 1:
				SceneMgr_ChangeScene(Chapter);
				
				break;

			}
			//PlaySoundMem(ENTER_SE, DX_PLAYTYPE_BACK);

		}


		int y_t = 0;

		switch (player->GoBack_Num)
		{
		case 0:
			y_t = 600;
			break;

		case 1:
			y_t = 650;
			break;

		}

		//�`��	
		DrawStringEx(870, y_t, -1, "��");
		DrawStringEx(900, 600, -1, "������", player->Kihuku_small);
		DrawStringEx(900, 650, -1, "�͂�", player->Kihuku_Midium);

		DrawStringEx(450, 700, -1, "�`���v�^�[��ʂɖ߂�܂����H");



	}


}





//�����D�z�u
void::Player::Card_Moudules_First_Place(Player* player) {

	for (int i = 0; i < 8; i++) {

		player->YAKU_R[i] = i;		
	}

	for (int i = 0; i < 8; i++) {

		player->Sukumi_R[i] = i % 3;

	}

}


//�y�֐��z�I��������
void::Player::Finalize_Battle(Player* player) {

	player->MainScene_ = Progress0;
	player->Start_time = 0;
	
	player->Jan = 0;
	player->Feb = 0;
	player->Mar = 0;
	player->Apr = 0;
	player->May = 0;
	player->Jun = 0;
	player->Jul = 0;
	player->Aug = 0;
	player->Sep = 0;
	player->Oct = 0;
	player->Nov = 0;
	player->Dec = 0;

	player->Jan2 = 0;
	player->Feb2 = 0;
	player->Mar2 = 0;
	player->Apr2 = 0;
	player->May2 = 0;
	player->Jun2 = 0;
	player->Jul2 = 0;
	player->Aug2 = 0;
	player->Sep2 = 0;
	player->Oct2 = 0;
	player->Nov2 = 0;
	player->Dec2 = 0;

	player->YAKU_Ari = false;
	player->YAKU_Sankou = false;
	player->YAKU_Ameiri_Sankou = false;
	player->YAKU_Inosika_chou = false;
	player->YAKU_Akatan = false;
	player->YAKU_Aotan = false;
	player->YAKU_Tsukimi = false;
	player->YAKU_Hanami = false;

	player->YAKU_Jan = false;
	player->YAKU_Feb = false;
	player->YAKU_Mar = false;
	player->YAKU_Apr = false;
	player->YAKU_May = false;
	player->YAKU_Jun = false;
	player->YAKU_Jul = false;
	player->YAKU_Aug = false;
	player->YAKU_Sep = false;
	player->YAKU_Oct = false;
	player->YAKU_Nov = false;
	player->YAKU_Dec = false;

	player->PAR_RED_0 = 0;
	player->GU_GREEN_1 = 0;
	player->CHOKI_BLUE_2 = 0;

	player->Ene_Sukim_3_Count[0] = 99;
	player->Ene_Sukim_3_Count[1] = 99;
	player->Ene_Sukim_3_Count[2] = 99;
	player->Count_3 = 0;
	player->TotalScore = 0;
	player->Total_3_Score = 0;

	player->Attck_E_anim = 0;
	player->Attack_E_time = 0;

	player->Game_Start = false;

	player->Finish_time[0] = 0;

	player->Kihuku_small = 3;
	player->Kihuku_Midium = 1;
	player->Kihuku_Big = 1;

	


	for (int i = 0; i < 8; i++) {

		player->Huda_UP[i] = false;
		player->UR_Storage[i] = eCard_Omote;
		player->YAKU1_Storage[i] = 99;
		player->SUKUMI_Storage[i] = 99;
	}

	
	for (int i = 0; i < 8; i++) {

		DeleteGraph(player->Attack_Effect[i]);


	}

	DeleteGraph(player->Attack_Image);
	DeleteGraph(player->fin_image);
	DeleteGraph(player->Finish_win_image);
	DeleteGraph(player->Finish_lose_image);


	DeleteGraph(player->YAKU_Sankou_image);
	DeleteGraph(player->YAKU_Ameiri_Sankou_image);
	DeleteGraph(player->YAKU_Inosika_chou_image);
	DeleteGraph(player->YAKU_Tsukimi_image);
	DeleteGraph(player->YAKU_Hanami_image);
	DeleteGraph(player->YAKU_ImageJan);
	DeleteGraph(player->YAKU_ImageFeb);
	DeleteGraph(player->YAKU_ImageMar);
	DeleteGraph(player->YAKU_ImageApr);
	DeleteGraph(player->YAKU_ImageMay);

	DeleteGraph(player->YAKU_ImageJun);
	DeleteGraph(player->YAKU_ImageJul);
	DeleteGraph(player->YAKU_ImageAug);
	DeleteGraph(player->YAKU_ImageSep);
	DeleteGraph(player->YAKU_ImageOct);
	DeleteGraph(player->YAKU_ImageNov);
	DeleteGraph(player->YAKU_ImageDec);

	DeleteGraph(player->HelpImage);
	DeleteGraph(player->HelpImage2);

	DeleteGraph(player->YakuList);
	
	

	
}






//�����V���b�t���i�ԎD�̎�ށj
void Player::Card_Modules_YAKU_shuffle(Player* player, int size) {

	for (int i = 0; i < size; i++) {

		int j = rand() % 48;

		player->YAKU_R[i] = j;
		
	}


}



//�����V���b�t���E�d���A���i����񂯂�j
void::Player::Card_Modules_3_shuffle(Player* player, int size) {
	
	for (int i = 0; i < size; i++) {

		int k = rand() % 3;
		k = player->Sukumi_R[i];

	}

}

//��ɏo�����D�̂݃V���b�t��������
void::Player::Card_Moudules_YAKU_Reshaffle(Player* player, int size, int YAKUNUM) {

		player->Jan = 0;
		player->Feb = 0;
		player->Mar = 0;
		player->Apr = 0;
		player->May = 0;
		player->Jun = 0;
		player->Jul = 0;
		player->Aug = 0;
		player->Sep = 0;
		player->Oct = 0;
		player->Nov = 0;
		player->Dec = 0;

		player->Jan2 = 0;
		player->Feb2 = 0;
		player->Mar2 = 0;
		player->Apr2 = 0;
		player->May2 = 0;
		player->Jun2 = 0;
		player->Jul2 = 0;
		player->Aug2 = 0;
		player->Sep2 = 0;
		player->Oct2 = 0;
		player->Nov2 = 0;
		player->Dec2 = 0;

		player->YAKU_Ari = false;
		player->YAKU_Sankou = false;
		player->YAKU_Ameiri_Sankou = false;
		player->YAKU_Inosika_chou = false;
		player->YAKU_Akatan = false;
		player->YAKU_Aotan = false;
		player->YAKU_Tsukimi = false;
		player->YAKU_Hanami = false;

		player->YAKU_Jan = false;
		player->YAKU_Feb = false;
		player->YAKU_Mar = false;
		player->YAKU_Apr = false;
		player->YAKU_May = false;
		player->YAKU_Jun = false;
		player->YAKU_Jul = false;
		player->YAKU_Aug = false;
		player->YAKU_Sep = false;
		player->YAKU_Oct = false;
		player->YAKU_Nov = false;
		player->YAKU_Dec = false;

		

		player->PAR_RED_0 = 0;
		player->GU_GREEN_1 = 0;
		player->CHOKI_BLUE_2 = 0;

		player->Ene_Sukim_3_Count[0] = 99;
		player->Ene_Sukim_3_Count[1] = 99;
		player->Ene_Sukim_3_Count[2] = 99;
		player->Count_3 = 0;
		player->TotalScore = 0;
		player->Total_3_Score = 0;

		player->Attck_E_anim = 0;
		player->Attack_E_time = 0;


		player->Count_3 = 0;


		player->Kihuku_small = 3;
		player->Kihuku_Midium = 1;
		player->Kihuku_Big = 1;

		
		for (int k = 0; k < 8; k++) {

			player->YAKU2_Storage[k] = 99;

		}
		
			
		for (int i = 0; i < size; i++) {

			int j = rand() % 48;
			int k = rand() % 3;

			int p = rand() % 3 +1;
		

			if (player->YAKU1_Storage[i] != 99 && Huda_UP[i]) {

				
				
				if (YAKUNUM == 1) {	//��l���p��3�{�X�p�A�O���̖���3����1�̊m���ő���

					if (p == 0) {

						player->YAKU_R[i] = j;
						player->Sukumi_R[i] = k;
						player->Huda_UP[i] = false;


					}
					else if (p == 1) {


						player->YAKU_R[i] = j;
						player->Sukumi_R[i] = k;
						player->Huda_UP[i] = false;

					}
					else if (p == 2) {

						int g = rand() % 3;

						if (g == 0) {


							player->YAKU_R[i] = 0;	//1��
							player->Sukumi_R[i] = k;
							player->Huda_UP[i] = false;

						}
						else if (g == 1) {


							player->YAKU_R[i] = 8;	//3��
							player->Sukumi_R[i] = k;
							player->Huda_UP[i] = false;


						}
						else if (g == 2) {

							player->YAKU_R[i] = 28;	//8��
							player->Sukumi_R[i] = k;
							player->Huda_UP[i] = false;


						}
						else {


							player->YAKU_R[i] = j;
							player->Sukumi_R[i] = k;
							player->Huda_UP[i] = false;

						}




					}


				}

				if (YAKUNUM == 2) {	//enemy1�E�������̖���3����1�̊m���ő���


					if (p == 0) {

						player->YAKU_R[i] = j;
						player->Sukumi_R[i] = k;
						player->Huda_UP[i] = false;


					}
					else if (p == 1) {


						player->YAKU_R[i] = j;
						player->Sukumi_R[i] = k;
						player->Huda_UP[i] = false;

					}
					else if (p == 2) {

						int g = rand() % 3;

						if (g == 0) {


							player->YAKU_R[i] = 24;	//6��
							player->Sukumi_R[i] = k;
							player->Huda_UP[i] = false;

						}
						else if (g == 1) {


							player->YAKU_R[i] = 36;	//10��
							player->Sukumi_R[i] = k;
							player->Huda_UP[i] = false;


						}
						else if (g == 2) {

							player->YAKU_R[i] = 20;	//7��
							player->Sukumi_R[i] = k;
							player->Huda_UP[i] = false;

						}
						else {


							player->YAKU_R[i] = j;
							player->Sukumi_R[i] = k;
							player->Huda_UP[i] = false;

						}


					}

				}


				if (YAKUNUM == 3) {	//enemy2�E�����ň�t��3����1���炢�̊m���łł�B


					if (p == 0) {

						player->YAKU_R[i] = j;
						player->Sukumi_R[i] = k;
						player->Huda_UP[i] = false;


					}
					else if (p == 1) {


						player->YAKU_R[i] = j;
						player->Sukumi_R[i] = k;
						player->Huda_UP[i] = false;

					}
					else if (p == 2) {

						int g = rand() % 3;

						if (g == 0) {


							player->YAKU_R[i] = 28;	//8��
							player->Sukumi_R[i] = k;
							player->Huda_UP[i] = false;

						}
						else if (g == 1) {


							player->YAKU_R[i] = 32;	//9��
							player->Sukumi_R[i] = k;
							player->Huda_UP[i] = false;


						}
						else if (g == 2) {

							player->YAKU_R[i] = j;
							player->Sukumi_R[i] = k;
							player->Huda_UP[i] = false;


						}


					}
					else {


						player->YAKU_R[i] = j;
						player->Sukumi_R[i] = k;
						player->Huda_UP[i] = false;




					}


				}



				if (YAKUNUM == 4) {	//enemy4�@�J�~��3��

					if (p == 0) {

						player->YAKU_R[i] = j;
						player->Sukumi_R[i] = k;
						player->Huda_UP[i] = false;


					}
					else if (p == 1) {

						player->YAKU_R[i] = j;
						player->Sukumi_R[i] = k;
						player->Huda_UP[i] = false;

					}
					else if (p == 2) {

						int g = rand() % 3;

						if (g == 0) {

							player->YAKU_R[i] = 0;	//1��
							player->Sukumi_R[i] = k;
							player->Huda_UP[i] = false;

						}
						else if (g == 1) {


							player->YAKU_R[i] = 40;	//11��
							player->Sukumi_R[i] = k;
							player->Huda_UP[i] = false;


						}
						else if (g == 2) {

							player->YAKU_R[i] = 44;	//12��
							player->Sukumi_R[i] = k;
							player->Huda_UP[i] = false;

						}


					}


				}
			
			
			}

		

		}
	

		for (int i = 0; i < 8; i++) {

			player->Huda_UP[i] = false;
			player->UR_Storage[i] = eCard_Omote;
			player->YAKU1_Storage[i] = 99;
			player->SUKUMI_Storage[i] = 99;

		}


}


//�U�����[�V���������݁i�v���C���[�E�G���ʁj
void::Player::Modules_Attack_Motion(Player* player, Player* enemy, int scene) {

	if (player->MainScene_ == scene) {

			player->AT_counter++;
			enemy->AT_counter++;

			player->Attack_E_time++;
			enemy->Attack_E_time++;

			
			//�����݂̍U�����[�V�����i�v���C���[�E�G�E�����j

			if (player->Total_3_Score > 0) {


				DrawStringEx(600, 670, -1, "�G��%d�̃_���[�W!", player->Total_3_Score);

				if (player->AT_pos_y > 400 && player->AT_counter < 100) {

					player->AT_pos_x += player->AT_speed_1;
					player->AT_pos_y -= player->AT_speed_1;

				}
				else if (player->AT_counter < 100) {

					player->AT_speed_1 = 0;

				}
				else if (player->AT_counter > 100) {

					player->AT_pos_x -= player->AT_speed_2;
					player->AT_pos_y += player->AT_speed_2;

				}


				DrawRotaGraph(player->AT_pos_x, player->AT_pos_y, 1.0f, 0, player->Attack_Image, true);
				

				if (player->Attack_E_time < 30) { //�U�����̃G�t�F�N�g

					PlaySoundMem(player->Attck_Sound, DX_PLAYTYPE_BACK);

					if (player->Attck_E_anim < 7) {

						player->Attck_E_anim++;
					}

					DrawRotaGraph(700, 200, 1.0f, 0, player->Attack_Effect[player->Attck_E_anim], true);
					
					
				

				}

				if (player->Attack_E_time < 120) {

					if (player->Total_3_Score == 100) {

						DrawStringToHandle(550, 200, "-100�_", GetColor(255, 255, 255), player->Font_Meicho_big);

					}
					else if (player->Total_3_Score == 200) {


						DrawStringToHandle(550, 200, "-200�_", GetColor(255, 255, 255), player->Font_Meicho_big);

					}
					else if (player->Total_3_Score == 300) {


						DrawStringToHandle(550, 200, "-300�_", GetColor(255, 255, 255), player->Font_Meicho_big);

					}




				}


				





			}			
			else {

				//DrawStringEx(650, 670, -1, "�v���C���[�E�U���Ȃ�");
				DrawStringToHandle(50, 480, "�U���Ȃ�", GetColor(255, 255, 255), player->Font_Meicho_big);

			}	
			

	

			if (enemy->Total_3_Score > 0) {


				//DrawStringEx(600, 700, -1, "�`�g�Z��%d�̃_���[�W!", enemy->Total_3_Score);

				if (enemy->AT_pos_y < 300 && enemy->AT_counter > 50 && enemy->AT_counter < 100) {

					enemy->AT_pos_x -= enemy->AT_speed_1;
					enemy->AT_pos_y += enemy->AT_speed_1;

				}
				else if (enemy->AT_counter > 100 && enemy->AT_counter < 150) {

					enemy->AT_speed_1 = 0;

				}
				else if (enemy->AT_counter > 200) {

					enemy->AT_pos_x += enemy->AT_speed_2;
					enemy->AT_pos_y -= enemy->AT_speed_2;

					DrawStringEx(700, 730, -1, "�X�y�[�X�L�[�Ŏ��ɐi�݂܂��B");
				}


				DrawRotaGraph(enemy->AT_pos_x, enemy->AT_pos_y, 1.0f, 0, enemy->Attack_Image, true);


				if (enemy->Attack_E_time > 50 && enemy->Attack_E_time < 80) {

					PlaySoundMem(enemy->Attck_Sound, DX_PLAYTYPE_BACK);

					if (enemy->Attck_E_anim < 7) {

						enemy->Attck_E_anim++;
					}

					DrawRotaGraph(300, 600, 1.0f, 0, enemy->Attack_Effect[enemy->Attck_E_anim], true);


				}

				if (enemy->Attack_E_time < 50 && enemy->Attack_E_time < 170) {

					if (enemy->Total_3_Score == 100) {

						DrawStringToHandle(50, 400, "-100�_", GetColor(255, 255, 255), player->Font_Meicho_big);

					}
					else if (enemy->Total_3_Score == 200) {


						DrawStringToHandle(50, 400, "-200�_", GetColor(255, 255, 255), player->Font_Meicho_big);

					}
					else if (enemy->Total_3_Score == 300) {


						DrawStringToHandle(50, 400, "-300�_", GetColor(255, 255, 255), player->Font_Meicho_big);

					}



				}

				

			}		
			else {

			//DrawStringEx(650, 670, -1, "�G�F�U���Ȃ�");
			DrawStringToHandle(750, 200, "�U���Ȃ�", GetColor(255, 255, 255), enemy->Font_Meicho_big);


			}

	
	}
	
		

}

//�y�֐��z�U�����[�V�����i���j
void::Player::Modules_Attack_Motion_YAKU(Player* player, Player* enemy, int scene) {


	if (player->MainScene_ == scene) {

		player->AT_counter++;
		enemy->AT_counter++;

		player->Attack_E_time++;
		enemy->Attack_E_time++;


		//�����݂̍U�����[�V�����i�v���C���[�E�G�E�����j

		if (player->TotalScore > 0) {


			if (player->AT_pos_y > 400 && player->AT_counter < 100) {

				player->AT_pos_x += player->AT_speed_1;
				player->AT_pos_y -= player->AT_speed_1;

			}
			else if (player->AT_counter < 100) {

				player->AT_speed_1 = 0;

			}
			else if (player->AT_counter > 100) {

				player->AT_pos_x -= player->AT_speed_2;
				player->AT_pos_y += player->AT_speed_2;

			}


			DrawRotaGraph(player->AT_pos_x, player->AT_pos_y, 1.0f, 0, player->Attack_Image, true);

			if (player->Attack_E_time < 30) { //�U�����̃G�t�F�N�g

				PlaySoundMem(player->Attck_Sound, DX_PLAYTYPE_BACK);

				if (player->Attck_E_anim < 7) {

					player->Attck_E_anim++;
				}

				DrawRotaGraph(700, 200, 1.0f, 0, player->Attack_Effect[player->Attck_E_anim], true);


			}

			//�v���C���[���̉摜
			//if (player->Attack_E_time < 60) {
			if (player->YAKU_Sankou) {

				DrawRotaGraph(180, 350, 0.8f, 0, player->YAKU_Sankou_image, true);
				DrawStringToHandle(550, 200, "-700�_", GetColor(255, 255, 255), player->Font_Meicho_big);

			}
			else if (player->YAKU_Ameiri_Sankou) {

				DrawRotaGraph(180, 350, 0.8f, 0, player->YAKU_Ameiri_Sankou_image, true);
				DrawStringToHandle(550, 200, "-700�_", GetColor(255, 255, 255), player->Font_Meicho_big);
			}
			else if (player->YAKU_Inosika_chou) {

				DrawRotaGraph(180, 350, 0.8f, 0, player->YAKU_Inosika_chou_image, true);
				DrawStringToHandle(550, 200, "-700�_", GetColor(255, 255, 255), player->Font_Meicho_big);
			}

			else if (player->YAKU_Akatan) {

				DrawRotaGraph(180, 350, 0.8f, 0, player->YAKU_ImageJan, true);
				DrawStringToHandle(700, 50, "-1000", GetColor(255, 255, 255), player->Font_Meicho_big);

			}
			else if (player->YAKU_Aotan) {

				DrawRotaGraph(180, 350, 0.8f, 0, player->YAKU_ImageJan, true);
				DrawStringToHandle(700, 50, "-1000", GetColor(255, 255, 255), player->Font_Meicho_big);
			}
			else if (player->YAKU_Tsukimi) {

				DrawRotaGraph(180, 350, 0.8f, 0, player->YAKU_Tsukimi_image, true);
				DrawStringToHandle(550, 200, "-500�_", GetColor(255, 255, 255), player->Font_Meicho_big);

			}
			else if (player->YAKU_Hanami) {

				DrawRotaGraph(180, 350, 0.8f, 0, YAKU_Hanami_image, true);
				DrawStringToHandle(550, 200, "-500�_", GetColor(255, 255, 255), player->Font_Meicho_big);
			}

			else if (player->YAKU_Jan) {

				DrawRotaGraph(180, 350, 0.8f, 0, player->YAKU_ImageJan, true);
				DrawStringToHandle(550, 200, "-300�_", GetColor(255, 255, 255), player->Font_Meicho_big);
			}
			else if (player->YAKU_Feb) {

				DrawRotaGraph(180, 350, 0.8f, 0, player->YAKU_ImageFeb, true);
				DrawStringToHandle(550, 200, "-300�_", GetColor(255, 255, 255), player->Font_Meicho_big);
			}
			else if (player->YAKU_Mar) {

				DrawRotaGraph(180, 350, 0.8f, 0, player->YAKU_ImageMar, true);
				DrawStringToHandle(550, 200, "-300�_", GetColor(255, 255, 255), player->Font_Meicho_big);
			}
			else if (player->YAKU_Apr) {

				DrawRotaGraph(180, 350, 0.8f, 0, player->YAKU_ImageApr, true);
				DrawStringToHandle(550, 200, "-300�_", GetColor(255, 255, 255), player->Font_Meicho_big);
			}
			else if (player->YAKU_May) {

				DrawRotaGraph(180, 350, 0.8f, 0, player->YAKU_ImageMay, true);
				DrawStringToHandle(550, 200, "-300�_", GetColor(255, 255, 255), player->Font_Meicho_big);
			}
			else if (player->YAKU_Jun) {

				DrawRotaGraph(180, 350, 0.8f, 0, player->YAKU_ImageJun, true);
				DrawStringToHandle(550, 200, "-300�_", GetColor(255, 255, 255), player->Font_Meicho_big);
			}
			else if (player->YAKU_Jul) {

				DrawRotaGraph(180, 350, 0.8f, 0, player->YAKU_ImageJul, true);
				DrawStringToHandle(550, 200, "-300�_", GetColor(255, 255, 255), player->Font_Meicho_big);
			}
			else if (player->YAKU_Aug) {

				DrawRotaGraph(180, 350, 0.8f, 0, player->YAKU_ImageAug, true);
				DrawStringToHandle(550, 200, "-300�_", GetColor(255, 255, 255), player->Font_Meicho_big);
			}
			else if (player->YAKU_Sep) {

				DrawRotaGraph(180, 350, 0.8f, 0, player->YAKU_ImageSep, true);
				DrawStringToHandle(550, 200, "-300�_", GetColor(255, 255, 255), player->Font_Meicho_big);
			}
			else if (player->YAKU_Oct) {

				DrawRotaGraph(180, 350, 0.8f, 0, player->YAKU_ImageOct, true);
				DrawStringToHandle(550, 200, "-300�_", GetColor(255, 255, 255), player->Font_Meicho_big);
			}
			else if (player->YAKU_Nov) {

				DrawRotaGraph(180, 350, 0.8f, 0, player->YAKU_ImageNov, true);
				DrawStringToHandle(550, 200, "-300�_", GetColor(255, 255, 255), player->Font_Meicho_big);
			}
			else if (player->YAKU_Dec) {

				DrawRotaGraph(180, 350, 0.8f, 0, player->YAKU_ImageDec, true);
				DrawStringToHandle(550, 200, "-300�_", GetColor(255, 255, 255), player->Font_Meicho_big);
			}

	

			//}
			
		
		}
		else {

			//DrawStringEx(650, 670, -1, "�v���C���[�E�U���Ȃ�");
			DrawStringToHandle(50, 480, "�U���Ȃ�", GetColor(255, 255, 255), player->Font_Meicho_big);
		}



		if (enemy->TotalScore > 0) {


			if (enemy->AT_pos_y < 300 && enemy->AT_counter > 50 && enemy->AT_counter < 100) {

				enemy->AT_pos_x -= enemy->AT_speed_1;
				enemy->AT_pos_y += enemy->AT_speed_1;

			}
			else if (enemy->AT_counter > 100 && enemy->AT_counter < 150) {


				enemy->AT_speed_1 = 0;



			}
			else if (enemy->AT_counter > 200) {

				enemy->AT_pos_x += enemy->AT_speed_2;
				enemy->AT_pos_y -= enemy->AT_speed_2;

				DrawStringEx(300, 730, -1, "�X�y�[�X�L�[�Ŏ��ɐi�݂܂��B");
			}


			DrawRotaGraph(enemy->AT_pos_x, enemy->AT_pos_y, 1.0f, 0, enemy->Attack_Image, true);

			if (enemy->Attack_E_time > 50 && enemy->Attack_E_time < 80) {

				PlaySoundMem(enemy->Attck_Sound, DX_PLAYTYPE_BACK);

				if (enemy->Attck_E_anim < 7) {

					enemy->Attck_E_anim++;
				}

				DrawRotaGraph(300, 600, 1.0f, 0, enemy->Attack_Effect[enemy->Attck_E_anim], true);

			}



			//if (enemy->Attack_E_time > 50 && enemy->Attack_E_time < 110) {

			if (enemy->YAKU_Sankou) {

				DrawRotaGraph(800, 350, 0.8f, 0, enemy->YAKU_Sankou_image, true);
				DrawStringToHandle(50, 400, "-700�_", GetColor(255, 255, 255), enemy->Font_Meicho_big);

			}
			else if (enemy->YAKU_Ameiri_Sankou) {

				DrawRotaGraph(800, 350, 0.8f, 0, enemy->YAKU_Ameiri_Sankou_image, true);
				DrawStringToHandle(50, 400, "-700�_", GetColor(255, 255, 255), enemy->Font_Meicho_big);
			}
			else if (enemy->YAKU_Inosika_chou) {

				DrawRotaGraph(800, 350, 0.8f, 0, enemy->YAKU_Inosika_chou_image, true);
				DrawStringToHandle(50, 400, "-500�_", GetColor(255, 255, 255), enemy->Font_Meicho_big);
			}
			else if (enemy->YAKU_Akatan) {

				DrawRotaGraph(800, 350, 0.8f, 0, enemy->YAKU_Tsukimi_image, true);
				DrawStringToHandle(50, 400, "-1000", GetColor(255, 255, 255), enemy->Font_Meicho_big);
			}
			else if (enemy->YAKU_Aotan) {

				DrawRotaGraph(800, 350, 0.8f, 0, enemy->YAKU_ImageJan, true);
				DrawStringToHandle(50, 400, "-1000", GetColor(255, 255, 255), enemy->Font_Meicho_big);
			}
			else if (enemy->YAKU_Tsukimi) {

				DrawRotaGraph(800, 350, 0.8f, 0, enemy->YAKU_Tsukimi_image, true);
				DrawStringToHandle(50, 400, "-500�_", GetColor(255, 255, 255), enemy->Font_Meicho_big);
			}
			else if (enemy->YAKU_Hanami) {

				DrawRotaGraph(800, 350, 0.8f, 0, enemy->YAKU_Hanami_image, true);
				DrawStringToHandle(50, 400, "-500�_", GetColor(255, 255, 255), enemy->Font_Meicho_big);
			}
			else if (enemy->YAKU_Jan) {

				DrawRotaGraph(800, 350, 0.8f, 0, enemy->YAKU_ImageJan, true);
				DrawStringToHandle(50, 400, "-300�_", GetColor(255, 255, 255), enemy->Font_Meicho_big);
			}
			else if (enemy->YAKU_Feb) {

				DrawRotaGraph(800, 350, 0.8f, 0, enemy->YAKU_ImageFeb, true);
				DrawStringToHandle(50, 400, "-300�_", GetColor(255, 255, 255), enemy->Font_Meicho_big);
			}
			else if (enemy->YAKU_Mar) {

				DrawRotaGraph(800, 350, 0.8f, 0, enemy->YAKU_ImageMar, true);
				DrawStringToHandle(50, 400, "-300�_", GetColor(255, 255, 255), enemy->Font_Meicho_big);
			}
			else if (enemy->YAKU_Apr) {

				DrawRotaGraph(800, 350, 0.8f, 0, enemy->YAKU_ImageApr, true);
				DrawStringToHandle(50, 400, "-300�_", GetColor(255, 255, 255), enemy->Font_Meicho_big);
			}
			else if (enemy->YAKU_May) {

				DrawRotaGraph(800, 350, 0.8f, 0, enemy->YAKU_ImageMay, true);
				DrawStringToHandle(50, 400, "-300�_", GetColor(255, 255, 255), enemy->Font_Meicho_big);
			}
			else if (enemy->YAKU_Jun) {

				DrawRotaGraph(800, 350, 0.8f, 0, enemy->YAKU_ImageJun, true);
				DrawStringToHandle(50, 400, "-300�_", GetColor(255, 255, 255), enemy->Font_Meicho_big);
			}
			else if (enemy->YAKU_Jul) {

				DrawRotaGraph(800, 350, 0.8f, 0, enemy->YAKU_ImageJul, true);
				DrawStringToHandle(50, 400, "-300�_", GetColor(255, 255, 255), enemy->Font_Meicho_big);
			}
			else if (enemy->YAKU_Aug) {

				DrawRotaGraph(800, 350, 0.8f, 0, enemy->YAKU_ImageAug, true);
				DrawStringToHandle(50, 400, "-300�_", GetColor(255, 255, 255), enemy->Font_Meicho_big);
			}
			else if (enemy->YAKU_Sep) {

				DrawRotaGraph(800, 350, 0.8f, 0, enemy->YAKU_ImageSep, true);
				DrawStringToHandle(50, 400, "-1000", GetColor(255, 255, 255), enemy->Font_Meicho_big);
			}
			else if (enemy->YAKU_Oct) {

				DrawRotaGraph(800, 350, 0.8f, 0, enemy->YAKU_ImageOct, true);
				DrawStringToHandle(50, 400, "-300�_", GetColor(255, 255, 255), enemy->Font_Meicho_big);
			}
			else if (enemy->YAKU_Nov) {

				DrawRotaGraph(800, 350, 0.8f, 0, enemy->YAKU_ImageNov, true);
				DrawStringToHandle(50, 400, "-300�_", GetColor(255, 255, 255), enemy->Font_Meicho_big);
			}
			else if (enemy->YAKU_Dec) {

				DrawRotaGraph(800, 350, 0.8f, 0, enemy->YAKU_ImageDec, true);
				DrawStringToHandle(50, 400, "-300�_", GetColor(255, 255, 255), enemy->Font_Meicho_big);
			}





			//}


		}
		else {

				//DrawStringEx(650, 700, -1, "�G�F�U���Ȃ�");
				DrawStringToHandle(750, 200, "�U���Ȃ�", GetColor(255, 255, 255), enemy->Font_Meicho_big);

		}
		


	}


}


//�y�֐��z�U�����[�V��������������
void::Player::Modules_Attack_init(Player* player, Player* enemy) {

	player->AT_speed_1 = 50;
	player->AT_pos_x = 30;
	player->AT_pos_y = 700;
	player->AT_counter = 0;
	player->Attck_E_anim = 0;
	player->Attack_E_time = 0;

	enemy->AT_speed_1 = 50;
	enemy->AT_pos_x = 1200;
	enemy->AT_pos_y = -300;
	enemy->AT_counter = 0;
	enemy->Attck_E_anim = 0;
	enemy->Attack_E_time = 0;

}




//�y�֐��z���v���C���[�̍U������(��)
void::Player::Moudules_Player_Attack(Player* player, Player* enemy, int TF) {
	
	
	if (TF == 0) {	//���񂷂���

		enemy->HP = enemy->HP - player->Total_3_Score;

		if (enemy->HP < 0) {


			enemy->HP = 0;

		}


	}
	else {	//��

		enemy->HP = enemy->HP - player->TotalScore;


		if (enemy->HP < 0) {


			enemy->HP = 0;

		}

	}

	


}



//�y�֐��z�G�̍U�������i���j
void::Player::Moudules_Enemy_Attack(Player* player, Player* enemy, int TF) {

	if (TF == 0) {

		player->HP = player->HP - enemy->Total_3_Score;

		if (player->HP < 0) {


			player->HP = 0;

		}




	}
	else {

		player->HP = player->HP - enemy->TotalScore;

		if (player->HP < 0) {


			player->HP = 0;

		}


	}

}



//�����̖��X�R�A�̌v�Z
void::Player::Moudules_Myplayer_YAKUScore_RETURN(Player* player) {

	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RETURN) && player->Game_Start == false) {


		//���̌v�Z
		for (int i = 0; i < 8; i++) {

			switch (player->YAKU1_Storage[i])
			{

			case 0:	//1-1
				player->Jan += 1;
				break;

			case 4:	//2-1
				player->Feb += 1;
				break;

			case 8:	//3-1
				player->Mar += 1;
				break;

			case 12:	//4-1
				player->Apr += 1;
				break;

			case 16:	//5-1
				player->May += 1;
				break;

			case 20:	//6-1
				player->Jun += 1;
				break;

			case 24:	//7-1
				player->Jul += 1;
				break;

			case 28:	//8-1
				player->Aug += 1;
				break;

			case 32:	//9-1
				player->Sep += 1;
				break;

			case 36:	//10-1
				player->Oct += 1;
				break;

			case 40:	//11-1
				player->Nov += 1;
				break;

			case 44:	//12-1
				player->Dec += 1;
				break;
			}

		}


		


	}


}

//�y�֐��z�G�̖��X�R�A�̌v�Z
void::Player::Moudules_Enemy_YAKUScore_RETURN(Player* enemy) {

	//���̌v�Z
	for (int i = 0; i < 8; i++) {

	
		//if (enemy->Huda_UP[i]) {

			switch (enemy->YAKU2_Storage[i])
			{

			case 0:	//1-1
				enemy->Jan2 += 1;
				break;

			case 4:	//2-1
				enemy->Feb2 += 1;
				break;

			case 8:	//3-1
				enemy->Mar2 += 1;
				break;

			case 12:	//4-1
				enemy->Apr2 += 1;
				break;

			case 16:	//5-1
				enemy->May2 += 1;
				break;

			case 20:	//6-1
				enemy->Jun2 += 1;
				break;

			case 24:	//7-1
				enemy->Jul2 += 1;
				break;

			case 28:	//8-1
				enemy->Aug2 += 1;
				break;

			case 32:	//9-1
				enemy->Sep2 += 1;
				break;

			case 36:	//10-1
				enemy->Oct2 += 1;
				break;

			case 40:	//11-1
				enemy->Nov2 += 1;
				break;

			case 44:	//12-1
				enemy->Dec2 += 1;
				break;
			}




		//}

			

	}



}




//�������E�G�̖��Ǝ�����3�����݂̌v�Z�����A�G�J�[�h�o�������i����ɕ���ł��鎩���̃J�[�h�̎�ޒl�E���ɂ���čs����ς���j
void::Player::Moudules_Enemy_Card_Place(Player* player, Player* enemy) {

	//���񂷂��݂̃��U���g���ʂ��o��
	for (int i = 0; i < 8; i++) {

		switch (enemy->Sukumi_R[i]) {

		case 0:	//�p�[
			enemy->PAR_RED_0 += 1;
			break;

		case 1:	//�O�[
			enemy->GU_GREEN_1 += 1;
			break;

		case 2:	//�`���L
			enemy->CHOKI_BLUE_2 += 1;
			break;

		}

	}

	for (int i = 0; i < 8; i++) {

		switch (player->Sukumi_R[i]) {

		case 0:	//�p�[
			player->PAR_RED_0 += 1;
			break;

		case 1:	//�O�[
			player->GU_GREEN_1 += 1;
			break;

		case 2:	//�`���L
			player->CHOKI_BLUE_2 += 1;
			break;

		}

	}


	//���̌���
	for (int i = 0; i < 8; i++) {

		switch (enemy->YAKU_R[i])
		{

		case 0:	//1-1
			enemy->Jan += 1;
			break;

		case 4:	//2-1
			enemy->Feb += 1;
			break;

		case 8:	//3-1
			enemy->Mar += 1;
			break;

		case 12:	//4-1
			enemy->Apr += 1;
			break;

		case 16:	//5-1
			enemy->May += 1;
			break;

		case 20:	//6-1
			enemy->Jun += 1;
			break;	

		case 24:	
			enemy->Jul += 1;
			break;

		case 28:	//8-1
			enemy->Aug += 1;
			break;

		case 32:	//9-1
			enemy->Sep += 1;
			break;

		case 36:	//10-1
			enemy->Oct += 1;
			break;

		case 40:	//11-1
			enemy->Nov += 1;
			break;

		case 44:	//12-1
			enemy->Dec += 1;
			break;
		}

	}



	if (enemy->Jul >= 1 && enemy->Oct >= 1 && enemy->Jun >= 1) {


		for (int i = 0; i < 8; i++) {


			if (enemy->YAKU1_Storage[i] == 24) {


				if (enemy->YAKU2_Storage[0] != 24) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 400;
					enemy->Count_3++;

				}
				else {


					return;

				}


			}
			else if (enemy->YAKU1_Storage[i] == 36) {


				if (enemy->YAKU2_Storage[1] != 36) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 500;
					enemy->Count_3++;


				}
				else {

					return;


				}



			}
			else if (enemy->YAKU1_Storage[i] == 20) {


				if (enemy->YAKU2_Storage[2] != 20) {


					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 600;
					enemy->Count_3++;


				}
				else {


					return;

				}



			}




		}



	}
	else if(enemy->Jul >= 3 || enemy->Oct >= 3 || enemy->Jun >= 3){

		if (enemy->Jul >= 3) {


			for (int i = 0; i < 8; i++) {

				if (enemy->YAKU1_Storage[i] == 24) {

					if (enemy->YAKU2_Storage[0] != 24) {

						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 400;
						enemy->Count_3++;

					}
					else if (enemy->YAKU2_Storage[1] != 24) {


						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 500;
						enemy->Count_3++;



					}
					else if (enemy->YAKU2_Storage[2] != 24) {


						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 600;
						enemy->Count_3++;



					}
										
					




				}






			}






		}
		else if (enemy->Oct >= 3) {

			for (int i = 0; i < 8; i++) {

				if (enemy->YAKU1_Storage[i] == 36) {

					if (enemy->YAKU2_Storage[0] != 36) {

						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 400;
						enemy->Count_3++;

					}
					else if (enemy->YAKU2_Storage[1] != 36) {


						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 500;
						enemy->Count_3++;



					}
					else if (enemy->YAKU2_Storage[2] != 36) {


						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 600;
						enemy->Count_3++;



					}






				}






			}








		}
		else if (enemy->Jun >= 3) {

			for (int i = 0; i < 8; i++) {

				if (enemy->YAKU1_Storage[i] == 20) {

					if (enemy->YAKU2_Storage[0] != 20) {

						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 400;
						enemy->Count_3++;

					}
					else if (enemy->YAKU2_Storage[1] != 20) {


						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 500;
						enemy->Count_3++;



					}
					else if (enemy->YAKU2_Storage[2] != 20) {


						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 600;
						enemy->Count_3++;



					}






				}



			}




		}




	}
	else if (player->PAR_RED_0 > player->GU_GREEN_1 && player->PAR_RED_0 > player->CHOKI_BLUE_2) {


		for (int i = 0; i < 8; i++) {

			if (enemy->SUKUMI_Storage[i] == 2 && enemy->Count_3 < 4 && enemy->YAKU1_Storage[i] != 24 && enemy->YAKU1_Storage[i] != 36 && enemy->YAKU1_Storage[i] != 20) {


				if (enemy->Count_3 == 0) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 400;
					enemy->Count_3++;

				}
				else if (enemy->Count_3 == 1) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 500;
					enemy->Count_3++;


				}
				else if (enemy->Count_3 == 2) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 600;
					enemy->Count_3++;

				}
				else {


					for (int p = 0; p < 8; p++) {

						int k = rand() % 8;

						while (enemy->Huda_UP[k]) {

							k = rand() % 8;

							if (enemy->Huda_UP[k] == false) {

								break;


							}

						}

						if (enemy->Count_3 < 4 && enemy->YAKU1_Storage[k] != 24 && enemy->YAKU1_Storage[k] != 36 && enemy->YAKU1_Storage[k] != 20) {


							if (enemy->Count_3 == 0) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 400;
								enemy->Count_3++;

							}
							else if (enemy->Count_3 == 1) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 500;
								enemy->Count_3++;

							}
							else if (enemy->Count_3 == 2) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 600;
								enemy->Count_3++;
							}
							else {

								return;

							}





						}


					}
								

				}

							

			}


		}


	}
	
	

	if (enemy->Jul >= 1 && enemy->Oct >= 1 && enemy->Jun >= 1) {


		for (int i = 0; i < 8; i++) {


			if (enemy->YAKU1_Storage[i] == 24) {

				
				if (enemy->YAKU2_Storage[0] != 24) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 400;
					enemy->Count_3++;

				}
				else {


					return;

				}
				

			}
			else if ( enemy->YAKU1_Storage[i] == 36) {

				
				if (enemy->YAKU2_Storage[1] != 36) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 500;
					enemy->Count_3++;


				}
				else {

					return;


				}
				


			}
			else if (enemy->YAKU1_Storage[i] == 20) {

				
				if (enemy->YAKU2_Storage[2] != 20) {


					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 600;
					enemy->Count_3++;


				}
				else {


					return;

				}
				
				

			}
			



		}







	}	
	else if (player->GU_GREEN_1 > player->PAR_RED_0 && player->GU_GREEN_1 > player->CHOKI_BLUE_2 ) {


		for (int i = 0; i < 8; i++) {

			if (enemy->SUKUMI_Storage[i] == 0 && enemy->Count_3 < 4 && enemy->YAKU1_Storage[i] != 24 && enemy->YAKU1_Storage[i] != 36 && enemy->YAKU1_Storage[i] != 20) {


				if (enemy->Count_3 == 0) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 400;
					enemy->Count_3++;

				}
				else if (enemy->Count_3 == 1) {


					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 500;
					enemy->Count_3++;


				}
				else if (enemy->Count_3 == 2) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 600;
					enemy->Count_3++;

				}
				else {

					for (int p = 0; p < 8; p++) {

						int k = rand() % 8;

						while (enemy->Huda_UP[k]) {

							k = rand() % 8;

							if (enemy->Huda_UP[k] == false ) {

								break;

							}

						}

						if (enemy->Count_3 < 4) {


							if (enemy->Count_3 == 0) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 400;
								enemy->Count_3++;

							}
							else if (enemy->Count_3 == 1) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 500;
								enemy->Count_3++;


							}
							else if (enemy->Count_3 == 2) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 600;
								enemy->Count_3++;

							}
							else {

								return;

							}





						}


					}


				}

				

			}

		}


	}

	
	
	if (enemy->Jul >= 1 && enemy->Oct >= 1 && enemy->Jun >= 1) {


		for (int i = 0; i < 8; i++) {


			if (enemy->YAKU1_Storage[i] == 24) {


				if (enemy->YAKU2_Storage[0] != 24) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 400;
					enemy->Count_3++;

				}
				else {


					return;

				}


			}
			else if (enemy->YAKU1_Storage[i] == 36) {


				if (enemy->YAKU2_Storage[1] != 36) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 500;
					enemy->Count_3++;


				}
				else {

					return;


				}



			}
			else if (enemy->YAKU1_Storage[i] == 20) {


				if (enemy->YAKU2_Storage[2] != 20) {


					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 600;
					enemy->Count_3++;


				}
				else {


					return;

				}



			}




		}



	}	
	else if (player->CHOKI_BLUE_2 > player->PAR_RED_0 && player->CHOKI_BLUE_2 > player->GU_GREEN_1 ) {


		for (int i = 0; i < 8; i++) {

			if (enemy->SUKUMI_Storage[i] == 1 && enemy->Count_3 < 4 && enemy->YAKU1_Storage[i] != 24 && enemy->YAKU1_Storage[i] != 36 && enemy->YAKU1_Storage[i] != 20) {


				if (enemy->Count_3 == 0) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 400;
					enemy->Count_3++;

				}
				else if (enemy->Count_3 == 1) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 500;
					enemy->Count_3++;


				}
				else if (enemy->Count_3 == 2) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 600;
					enemy->Count_3++;


				}
				else {


					for (int p = 0; p < 8; p++) {

						int k = rand() % 8;

						while (enemy->Huda_UP[k]) {

							k = rand() % 8;

							if (enemy->Huda_UP[k] == false ) {

								break;


							}

						}

						if (enemy->Count_3 < 4 && enemy->YAKU1_Storage[k] != 24 && enemy->YAKU1_Storage[k] != 36 && enemy->YAKU1_Storage[k] != 20) {


							if (enemy->Count_3 == 0) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 400;
								enemy->Count_3++;

							}
							else if (enemy->Count_3 == 1) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 500;
								enemy->Count_3++;


							}
							else if (enemy->Count_3 == 2) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 600;
								enemy->Count_3++;

							}
							else {

								return;

							}





						}


					}


				}




			}


		}


	}
	else {

		for (int i = 0; i < 3; i++) {

			int k = rand() % 8;

			while (enemy->Huda_UP[k]) {

				k = rand() % 8;

				if (enemy->Huda_UP[k] == false ) {

					break;


				}

			}


			if (enemy->Count_3 < 4 && enemy->YAKU1_Storage[k] != 24 && enemy->YAKU1_Storage[k] != 36 && enemy->YAKU1_Storage[k] != 20) {

				if (enemy->Count_3 == 0) {

					enemy->Huda_UP[k] = true;
					enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[k];
					enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[k];
					enemy->cpos_x[k] = 400;
					enemy->Count_3++;

				}
				else if (enemy->Count_3 == 1) {


					enemy->Huda_UP[k] = true;
					enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[k];
					enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[k];
					enemy->cpos_x[k] = 500;
					enemy->Count_3++;

				}
				else if (enemy->Count_3 == 2) {

					enemy->Huda_UP[k] = true;
					enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[k];
					enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[k];
					enemy->cpos_x[k] = 600;
					enemy->Count_3++;


				}
				else {

					return;

				}




			}


		}


	}


}



//�����ň�t�E�G�̖��Ǝ�����3�����݂̌v�Z�����A�G�J�[�h�o�������i����ɕ���ł��鎩���̃J�[�h�̎�ޒl�E���ɂ���čs����ς���j
void::Player::Moudules_Enemy_Card_Place_2(Player* player, Player* enemy) {

	//���񂷂��݂̃��U���g���ʂ��o��
	for (int i = 0; i < 8; i++) {

		switch (enemy->Sukumi_R[i]) {

		case 0:	//�p�[
			enemy->PAR_RED_0 += 1;
			break;

		case 1:	//�O�[
			enemy->GU_GREEN_1 += 1;
			break;

		case 2:	//�`���L
			enemy->CHOKI_BLUE_2 += 1;
			break;

		}

	}

	for (int i = 0; i < 8; i++) {

		switch (player->Sukumi_R[i]) {

		case 0:	//�p�[
			player->PAR_RED_0 += 1;
			break;

		case 1:	//�O�[
			player->GU_GREEN_1 += 1;
			break;

		case 2:	//�`���L
			player->CHOKI_BLUE_2 += 1;
			break;

		}

	}


	//���̌���
	for (int i = 0; i < 8; i++) {

		switch (enemy->YAKU_R[i])
		{

		case 0:	//1-1
			enemy->Jan += 1;
			break;

		case 4:	//2-1
			enemy->Feb += 1;
			break;

		case 8:	//3-1
			enemy->Mar += 1;
			break;

		case 12:	//4-1
			enemy->Apr += 1;
			break;

		case 16:	//5-1
			enemy->May += 1;
			break;

		case 20:	//6-1
			enemy->Jun += 1;
			break;

		case 24:
			enemy->Jul += 1;
			break;

		case 28:	//8-1
			enemy->Aug += 1;
			break;

		case 32:	//9-1
			enemy->Sep += 1;
			break;

		case 36:	//10-1
			enemy->Oct += 1;
			break;

		case 40:	//11-1
			enemy->Nov += 1;
			break;

		case 44:	//12-1
			enemy->Dec += 1;
			break;
		}

	}



	if (enemy->Sep >= 1 && enemy->Aug >= 1 ) {


		for (int i = 0; i < 8; i++) {


			if (enemy->YAKU1_Storage[i] == 28) {


				if (enemy->YAKU2_Storage[0] != 28) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 400;
					enemy->Count_3++;

				}
				else {


					return;

				}


			}
			else if (enemy->YAKU1_Storage[i] == 32) {


				if (enemy->YAKU2_Storage[1] != 32) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 500;
					enemy->Count_3++;


				}
				else {

					return;


				}



			}
			




		}



	}
	else if (enemy->Aug >= 3 || enemy->Sep >= 3) {

		if (enemy->Aug >= 3) {


			for (int i = 0; i < 8; i++) {

				if (enemy->YAKU1_Storage[i] == 28) {

					if (enemy->YAKU2_Storage[0] != 28) {

						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 400;
						enemy->Count_3++;

					}
					else if (enemy->YAKU2_Storage[1] != 28) {


						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 500;
						enemy->Count_3++;



					}
					else if (enemy->YAKU2_Storage[2] != 28) {


						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 600;
						enemy->Count_3++;



					}






				}






			}






		}
		else if (enemy->Sep >= 3) {

			for (int i = 0; i < 8; i++) {

				if (enemy->YAKU1_Storage[i] == 32) {

					if (enemy->YAKU2_Storage[0] != 32) {

						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 400;
						enemy->Count_3++;

					}
					else if (enemy->YAKU2_Storage[1] != 32) {


						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 500;
						enemy->Count_3++;



					}
					else if (enemy->YAKU2_Storage[2] != 32) {


						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 600;
						enemy->Count_3++;



					}






				}






			}








		}





	}
	else if (player->PAR_RED_0 > player->GU_GREEN_1 && player->PAR_RED_0 > player->CHOKI_BLUE_2) {


		for (int i = 0; i < 8; i++) {

			if (enemy->SUKUMI_Storage[i] == 2 && enemy->Count_3 < 4 && enemy->YAKU1_Storage[i] != 28 && enemy->YAKU1_Storage[i] != 32) {


				if (enemy->Count_3 == 0) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 400;
					enemy->Count_3++;

				}
				else if (enemy->Count_3 == 1) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 500;
					enemy->Count_3++;


				}
				else if (enemy->Count_3 == 2) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 600;
					enemy->Count_3++;

				}
				else {


					for (int p = 0; p < 8; p++) {

						int k = rand() % 8;

						while (enemy->Huda_UP[k]) {

							k = rand() % 8;

							if (enemy->Huda_UP[k] == false) {

								break;


							}

						}

						if (enemy->Count_3 < 4 && enemy->YAKU1_Storage[i] != 28 && enemy->YAKU1_Storage[i] != 32) {


							if (enemy->Count_3 == 0) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 400;
								enemy->Count_3++;

							}
							else if (enemy->Count_3 == 1) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 500;
								enemy->Count_3++;

							}
							else if (enemy->Count_3 == 2) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 600;
								enemy->Count_3++;
							}
							else {

								return;

							}





						}


					}


				}



			}


		}


	}



	if (enemy->Sep >= 1 && enemy->Aug >= 1) {


		for (int i = 0; i < 8; i++) {


			if (enemy->YAKU1_Storage[i] == 28) {


				if (enemy->YAKU2_Storage[0] != 28) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 400;
					enemy->Count_3++;

				}
				else {


					return;

				}


			}
			else if (enemy->YAKU1_Storage[i] == 32) {


				if (enemy->YAKU2_Storage[1] != 32) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 500;
					enemy->Count_3++;


				}
				else {

					return;


				}



			}
			




		}







	}
	else if (player->GU_GREEN_1 > player->PAR_RED_0 && player->GU_GREEN_1 > player->CHOKI_BLUE_2) {


		for (int i = 0; i < 8; i++) {

			if (enemy->SUKUMI_Storage[i] == 0 && enemy->Count_3 < 4 && enemy->YAKU1_Storage[i] != 28 && enemy->YAKU1_Storage[i] != 32) {


				if (enemy->Count_3 == 0) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 400;
					enemy->Count_3++;

				}
				else if (enemy->Count_3 == 1) {


					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 500;
					enemy->Count_3++;


				}
				else if (enemy->Count_3 == 2) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 600;
					enemy->Count_3++;

				}
				else {

					for (int p = 0; p < 8; p++) {

						int k = rand() % 8;

						while (enemy->Huda_UP[k]) {

							k = rand() % 8;

							if (enemy->Huda_UP[k] == false) {

								break;

							}

						}

						if (enemy->Count_3 < 4) {


							if (enemy->Count_3 == 0) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 400;
								enemy->Count_3++;

							}
							else if (enemy->Count_3 == 1) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 500;
								enemy->Count_3++;


							}
							else if (enemy->Count_3 == 2) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 600;
								enemy->Count_3++;

							}
							else {

								return;

							}



						}


					}


				}



			}

		}


	}



	if (enemy->Aug >= 1 && enemy->Sep >= 1) {


		for (int i = 0; i < 8; i++) {


			if (enemy->YAKU1_Storage[i] == 28) {


				if (enemy->YAKU2_Storage[0] != 28) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 400;
					enemy->Count_3++;

				}
				else {


					return;

				}


			}
			else if (enemy->YAKU1_Storage[i] == 32) {


				if (enemy->YAKU2_Storage[1] != 32) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 500;
					enemy->Count_3++;


				}
				else {

					return;


				}



			}



		}



	}
	else if (player->CHOKI_BLUE_2 > player->PAR_RED_0 && player->CHOKI_BLUE_2 > player->GU_GREEN_1) {


		for (int i = 0; i < 8; i++) {

			if (enemy->SUKUMI_Storage[i] == 1 && enemy->Count_3 < 4 && enemy->YAKU1_Storage[i] != 28 && enemy->YAKU1_Storage[i] != 32) {


				if (enemy->Count_3 == 0) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 400;
					enemy->Count_3++;

				}
				else if (enemy->Count_3 == 1) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 500;
					enemy->Count_3++;


				}
				else if (enemy->Count_3 == 2) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 600;
					enemy->Count_3++;


				}
				else {


					for (int p = 0; p < 8; p++) {

						int k = rand() % 8;

						while (enemy->Huda_UP[k]) {

							k = rand() % 8;

							if (enemy->Huda_UP[k] == false) {

								break;


							}

						}

						if (enemy->Count_3 < 4 && enemy->YAKU1_Storage[i] != 28 && enemy->YAKU1_Storage[i] != 32) {


							if (enemy->Count_3 == 0) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 400;
								enemy->Count_3++;

							}
							else if (enemy->Count_3 == 1) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 500;
								enemy->Count_3++;


							}
							else if (enemy->Count_3 == 2) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 600;
								enemy->Count_3++;

							}
							else {

								return;

							}





						}


					}


				}




			}


		}


	}
	else {

		for (int i = 0; i < 3; i++) {

			int k = rand() % 8;

			while (enemy->Huda_UP[k]) {

				k = rand() % 8;

				if (enemy->Huda_UP[k] == false) {

					break;


				}

			}


			if (enemy->Count_3 < 4 && enemy->YAKU1_Storage[i] != 28 && enemy->YAKU1_Storage[i] != 32) {

				if (enemy->Count_3 == 0) {

					enemy->Huda_UP[k] = true;
					enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[k];
					enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[k];
					enemy->cpos_x[k] = 400;
					enemy->Count_3++;

				}
				else if (enemy->Count_3 == 1) {


					enemy->Huda_UP[k] = true;
					enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[k];
					enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[k];
					enemy->cpos_x[k] = 500;
					enemy->Count_3++;

				}
				else if (enemy->Count_3 == 2) {

					enemy->Huda_UP[k] = true;
					enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[k];
					enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[k];
					enemy->cpos_x[k] = 600;
					enemy->Count_3++;


				}
				else {

					return;

				}




			}


		}


	}


}



//�J�~��O���E�G�̖��Ǝ�����3�����݂̌v�Z�����A�G�J�[�h�o�������i����ɕ���ł��鎩���̃J�[�h�̎�ޒl�E���ɂ���čs����ς���j
void::Player::Moudules_Enemy_Card_Place_3(Player* player, Player* enemy) {

	//���񂷂��݂̃��U���g���ʂ��o��
	for (int i = 0; i < 8; i++) {

		switch (enemy->Sukumi_R[i]) {

		case 0:	//�p�[
			enemy->PAR_RED_0 += 1;
			break;

		case 1:	//�O�[
			enemy->GU_GREEN_1 += 1;
			break;

		case 2:	//�`���L
			enemy->CHOKI_BLUE_2 += 1;
			break;

		}

	}

	for (int i = 0; i < 8; i++) {

		switch (player->Sukumi_R[i]) {

		case 0:	//�p�[
			player->PAR_RED_0 += 1;
			break;

		case 1:	//�O�[
			player->GU_GREEN_1 += 1;
			break;

		case 2:	//�`���L
			player->CHOKI_BLUE_2 += 1;
			break;

		}

	}


	//���̌���
	for (int i = 0; i < 8; i++) {

		switch (enemy->YAKU_R[i])
		{

		case 0:	//1-1
			enemy->Jan += 1;
			break;

		case 4:	//2-1
			enemy->Feb += 1;
			break;

		case 8:	//3-1
			enemy->Mar += 1;
			break;

		case 12:	//4-1
			enemy->Apr += 1;
			break;

		case 16:	//5-1
			enemy->May += 1;
			break;

		case 20:	//6-1
			enemy->Jun += 1;
			break;

		case 24:
			enemy->Jul += 1;
			break;

		case 28:	//8-1
			enemy->Aug += 1;
			break;

		case 32:	//9-1
			enemy->Sep += 1;
			break;

		case 36:	//10-1
			enemy->Oct += 1;
			break;

		case 40:	//11-1
			enemy->Nov += 1;
			break;

		case 44:	//12-1
			enemy->Dec += 1;
			break;
		}

	}



	if (enemy->Jan >= 1 && enemy->Nov >= 1 && enemy->Dec >= 1) {


		for (int i = 0; i < 8; i++) {


			if (enemy->YAKU1_Storage[i] == 0) {


				if (enemy->YAKU2_Storage[0] != 0) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 400;
					enemy->Count_3++;

				}
				else {


					return;

				}


			}
			else if (enemy->YAKU1_Storage[i] == 40) {


				if (enemy->YAKU2_Storage[1] != 40) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 500;
					enemy->Count_3++;


				}
				else {

					return;


				}



			}
			else if (enemy->YAKU1_Storage[i] == 44) {


				if (enemy->YAKU2_Storage[2] != 44) {


					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 600;
					enemy->Count_3++;


				}
				else {


					return;

				}



			}


		}



	}
	else if (enemy->Jan >= 3 || enemy->Nov >= 3 || enemy->Dec >= 3) {

		if (enemy->Jan >= 3) {


			for (int i = 0; i < 8; i++) {

				if (enemy->YAKU1_Storage[i] == 0) {

					if (enemy->YAKU2_Storage[0] != 0) {

						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 400;
						enemy->Count_3++;

					}
					else if (enemy->YAKU2_Storage[1] != 0) {


						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 500;
						enemy->Count_3++;



					}
					else if (enemy->YAKU2_Storage[2] != 0) {


						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 600;
						enemy->Count_3++;



					}






				}






			}






		}
		else if (enemy->Nov >= 3) {

			for (int i = 0; i < 8; i++) {

				if (enemy->YAKU1_Storage[i] == 40) {

					if (enemy->YAKU2_Storage[0] != 40) {

						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 400;
						enemy->Count_3++;

					}
					else if (enemy->YAKU2_Storage[1] != 40) {


						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 500;
						enemy->Count_3++;



					}
					else if (enemy->YAKU2_Storage[2] != 40) {


						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 600;
						enemy->Count_3++;



					}






				}






			}








		}
		else if (enemy->Dec >= 3) {

			for (int i = 0; i < 8; i++) {

				if (enemy->YAKU1_Storage[i] == 44) {

					if (enemy->YAKU2_Storage[0] != 44) {

						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 400;
						enemy->Count_3++;

					}
					else if (enemy->YAKU2_Storage[1] != 44) {


						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 500;
						enemy->Count_3++;



					}
					else if (enemy->YAKU2_Storage[2] != 44) {


						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 600;
						enemy->Count_3++;



					}






				}



			}




		}




	}
	else if (player->PAR_RED_0 > player->GU_GREEN_1 && player->PAR_RED_0 > player->CHOKI_BLUE_2) {


		for (int i = 0; i < 8; i++) {

			if (enemy->SUKUMI_Storage[i] == 2 && enemy->Count_3 < 4 && enemy->YAKU1_Storage[i] != 0 && enemy->YAKU1_Storage[i] != 40 && enemy->YAKU1_Storage[i] != 44) {


				if (enemy->Count_3 == 0) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 400;
					enemy->Count_3++;

				}
				else if (enemy->Count_3 == 1) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 500;
					enemy->Count_3++;


				}
				else if (enemy->Count_3 == 2) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 600;
					enemy->Count_3++;

				}
				else {


					for (int p = 0; p < 8; p++) {

						int k = rand() % 8;

						while (enemy->Huda_UP[k]) {

							k = rand() % 8;

							if (enemy->Huda_UP[k] == false) {

								break;


							}

						}

						if (enemy->Count_3 < 4 && enemy->YAKU1_Storage[k] != 0 && enemy->YAKU1_Storage[k] != 40 && enemy->YAKU1_Storage[k] != 44) {


							if (enemy->Count_3 == 0) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 400;
								enemy->Count_3++;

							}
							else if (enemy->Count_3 == 1) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 500;
								enemy->Count_3++;

							}
							else if (enemy->Count_3 == 2) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 600;
								enemy->Count_3++;
							}
							else {

								return;

							}





						}


					}


				}



			}


		}


	}



	if (enemy->Jan >= 1 && enemy->Nov >= 1 && enemy->Dec >= 1) {


		for (int i = 0; i < 8; i++) {


			if (enemy->YAKU1_Storage[i] == 0) {


				if (enemy->YAKU2_Storage[0] != 0) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 400;
					enemy->Count_3++;

				}
				else {


					return;

				}


			}
			else if (enemy->YAKU1_Storage[i] == 40) {


				if (enemy->YAKU2_Storage[1] != 40) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 500;
					enemy->Count_3++;


				}
				else {

					return;


				}



			}
			else if (enemy->YAKU1_Storage[i] == 44) {


				if (enemy->YAKU2_Storage[2] != 44) {


					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 600;
					enemy->Count_3++;


				}
				else {


					return;

				}



			}




		}







	}
	else if (player->GU_GREEN_1 > player->PAR_RED_0 && player->GU_GREEN_1 > player->CHOKI_BLUE_2) {


		for (int i = 0; i < 8; i++) {

			if (enemy->SUKUMI_Storage[i] == 0 && enemy->Count_3 < 4 && enemy->YAKU1_Storage[i] != 0 && enemy->YAKU1_Storage[i] != 40 && enemy->YAKU1_Storage[i] != 44) {


				if (enemy->Count_3 == 0) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 400;
					enemy->Count_3++;

				}
				else if (enemy->Count_3 == 1) {


					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 500;
					enemy->Count_3++;


				}
				else if (enemy->Count_3 == 2) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 600;
					enemy->Count_3++;

				}
				else {

					for (int p = 0; p < 8; p++) {

						int k = rand() % 8;

						while (enemy->Huda_UP[k]) {

							k = rand() % 8;

							if (enemy->Huda_UP[k] == false) {

								break;

							}

						}

						if (enemy->Count_3 < 4) {


							if (enemy->Count_3 == 0) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 400;
								enemy->Count_3++;

							}
							else if (enemy->Count_3 == 1) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 500;
								enemy->Count_3++;


							}
							else if (enemy->Count_3 == 2) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 600;
								enemy->Count_3++;

							}
							else {

								return;

							}





						}


					}


				}



			}

		}


	}



	if (enemy->Jan >= 1 && enemy->Nov >= 1 && enemy->Dec >= 1) {


		for (int i = 0; i < 8; i++) {


			if (enemy->YAKU1_Storage[i] == 0) {


				if (enemy->YAKU2_Storage[0] != 0) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 400;
					enemy->Count_3++;

				}
				else {


					return;

				}


			}
			else if (enemy->YAKU1_Storage[i] == 40) {


				if (enemy->YAKU2_Storage[1] != 40) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 500;
					enemy->Count_3++;


				}
				else {

					return;


				}



			}
			else if (enemy->YAKU1_Storage[i] == 44) {


				if (enemy->YAKU2_Storage[2] != 44) {


					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 600;
					enemy->Count_3++;


				}
				else {


					return;

				}



			}




		}



	}
	else if (player->CHOKI_BLUE_2 > player->PAR_RED_0 && player->CHOKI_BLUE_2 > player->GU_GREEN_1) {


		for (int i = 0; i < 8; i++) {

			if (enemy->SUKUMI_Storage[i] == 1 && enemy->Count_3 < 4 && enemy->YAKU1_Storage[i] != 0 && enemy->YAKU1_Storage[i] != 40 && enemy->YAKU1_Storage[i] != 44) {


				if (enemy->Count_3 == 0) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 400;
					enemy->Count_3++;

				}
				else if (enemy->Count_3 == 1) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 500;
					enemy->Count_3++;


				}
				else if (enemy->Count_3 == 2) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 600;
					enemy->Count_3++;


				}
				else {


					for (int p = 0; p < 8; p++) {

						int k = rand() % 8;

						while (enemy->Huda_UP[k]) {

							k = rand() % 8;

							if (enemy->Huda_UP[k] == false) {

								break;


							}

						}

						if (enemy->Count_3 < 4 && enemy->YAKU1_Storage[k] != 0 && enemy->YAKU1_Storage[k] != 40 && enemy->YAKU1_Storage[k] != 44) {


							if (enemy->Count_3 == 0) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 400;
								enemy->Count_3++;

							}
							else if (enemy->Count_3 == 1) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 500;
								enemy->Count_3++;


							}
							else if (enemy->Count_3 == 2) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 600;
								enemy->Count_3++;

							}
							else {

								return;

							}





						}


					}


				}




			}


		}


	}
	else {

		for (int i = 0; i < 3; i++) {

			int k = rand() % 8;

			while (enemy->Huda_UP[k]) {

				k = rand() % 8;

				if (enemy->Huda_UP[k] == false) {

					break;


				}

			}


			if (enemy->Count_3 < 4 && enemy->YAKU1_Storage[k] != 0 && enemy->YAKU1_Storage[k] != 40 && enemy->YAKU1_Storage[k] != 44) {

				if (enemy->Count_3 == 0) {

					enemy->Huda_UP[k] = true;
					enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[k];
					enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[k];
					enemy->cpos_x[k] = 400;
					enemy->Count_3++;

				}
				else if (enemy->Count_3 == 1) {


					enemy->Huda_UP[k] = true;
					enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[k];
					enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[k];
					enemy->cpos_x[k] = 500;
					enemy->Count_3++;

				}
				else if (enemy->Count_3 == 2) {

					enemy->Huda_UP[k] = true;
					enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[k];
					enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[k];
					enemy->cpos_x[k] = 600;
					enemy->Count_3++;


				}
				else {

					return;

				}




			}


		}


	}


}

//�O�����X�{�X�E�G�̖��Ǝ�����3�����݂̌v�Z�����A�G�J�[�h�o�������i����ɕ���ł��鎩���̃J�[�h�̎�ޒl�E���ɂ���čs����ς���j
void::Player::Moudules_Enemy_Card_Place_4(Player* player, Player* enemy) {

	//���񂷂��݂̃��U���g���ʂ��o��
	for (int i = 0; i < 8; i++) {

		switch (enemy->Sukumi_R[i]) {

		case 0:	//�p�[
			enemy->PAR_RED_0 += 1;
			break;

		case 1:	//�O�[
			enemy->GU_GREEN_1 += 1;
			break;

		case 2:	//�`���L
			enemy->CHOKI_BLUE_2 += 1;
			break;

		}

	}

	for (int i = 0; i < 8; i++) {

		switch (player->Sukumi_R[i]) {

		case 0:	//�p�[
			player->PAR_RED_0 += 1;
			break;

		case 1:	//�O�[
			player->GU_GREEN_1 += 1;
			break;

		case 2:	//�`���L
			player->CHOKI_BLUE_2 += 1;
			break;

		}

	}


	//���̌���
	for (int i = 0; i < 8; i++) {

		switch (enemy->YAKU_R[i])
		{

		case 0:	//1-1
			enemy->Jan += 1;
			break;

		case 4:	//2-1
			enemy->Feb += 1;
			break;

		case 8:	//3-1
			enemy->Mar += 1;
			break;

		case 12:	//4-1
			enemy->Apr += 1;
			break;

		case 16:	//5-1
			enemy->May += 1;
			break;

		case 20:	//6-1
			enemy->Jun += 1;
			break;

		case 24:
			enemy->Jul += 1;
			break;

		case 28:	//8-1
			enemy->Aug += 1;
			break;

		case 32:	//9-1
			enemy->Sep += 1;
			break;

		case 36:	//10-1
			enemy->Oct += 1;
			break;

		case 40:	//11-1
			enemy->Nov += 1;
			break;

		case 44:	//12-1
			enemy->Dec += 1;
			break;
		}

	}



	if (enemy->Jan >= 1 && enemy->Mar >= 1 && enemy->Aug >= 1) {


		for (int i = 0; i < 8; i++) {


			if (enemy->YAKU1_Storage[i] == 0) {


				if (enemy->YAKU2_Storage[0] != 0) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 400;
					enemy->Count_3++;

				}
				else {


					return;

				}


			}
			else if (enemy->YAKU1_Storage[i] == 8) {


				if (enemy->YAKU2_Storage[1] != 8) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 500;
					enemy->Count_3++;


				}
				else {

					return;


				}



			}
			else if (enemy->YAKU1_Storage[i] == 28) {


				if (enemy->YAKU2_Storage[2] != 28) {


					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 600;
					enemy->Count_3++;


				}
				else {


					return;

				}



			}


		}



	}
	else if (enemy->Jan >= 3 || enemy->Mar >= 3 || enemy->Aug >= 3) {

		if (enemy->Jan >= 3) {


			for (int i = 0; i < 8; i++) {

				if (enemy->YAKU1_Storage[i] == 0) {

					if (enemy->YAKU2_Storage[0] != 0) {

						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 400;
						enemy->Count_3++;

					}
					else if (enemy->YAKU2_Storage[1] != 0) {


						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 500;
						enemy->Count_3++;



					}
					else if (enemy->YAKU2_Storage[2] != 0) {


						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 600;
						enemy->Count_3++;



					}






				}






			}






		}
		else if (enemy->Mar >= 3) {

			for (int i = 0; i < 8; i++) {

				if (enemy->YAKU1_Storage[i] == 8) {

					if (enemy->YAKU2_Storage[0] != 8) {

						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 400;
						enemy->Count_3++;

					}
					else if (enemy->YAKU2_Storage[1] != 8) {


						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 500;
						enemy->Count_3++;



					}
					else if (enemy->YAKU2_Storage[2] != 8) {


						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 600;
						enemy->Count_3++;



					}






				}






			}








		}
		else if (enemy->Aug >= 3) {

			for (int i = 0; i < 8; i++) {

				if (enemy->YAKU1_Storage[i] == 28) {

					if (enemy->YAKU2_Storage[0] != 28) {

						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 400;
						enemy->Count_3++;

					}
					else if (enemy->YAKU2_Storage[1] != 28) {


						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 500;
						enemy->Count_3++;



					}
					else if (enemy->YAKU2_Storage[2] != 28) {


						enemy->Huda_UP[i] = true;
						enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[i];
						enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[i];
						enemy->cpos_x[i] = 600;
						enemy->Count_3++;



					}






				}



			}




		}




	}
	else if (player->PAR_RED_0 > player->GU_GREEN_1 && player->PAR_RED_0 > player->CHOKI_BLUE_2) {


		for (int i = 0; i < 8; i++) {

			if (enemy->SUKUMI_Storage[i] == 2 && enemy->Count_3 < 4 && enemy->YAKU1_Storage[i] != 0 && enemy->YAKU1_Storage[i] != 8 && enemy->YAKU1_Storage[i] != 28) {


				if (enemy->Count_3 == 0) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 400;
					enemy->Count_3++;

				}
				else if (enemy->Count_3 == 1) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 500;
					enemy->Count_3++;


				}
				else if (enemy->Count_3 == 2) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 600;
					enemy->Count_3++;

				}
				else {


					for (int p = 0; p < 8; p++) {

						int k = rand() % 8;

						while (enemy->Huda_UP[k]) {

							k = rand() % 8;

							if (enemy->Huda_UP[k] == false) {

								break;


							}

						}

						if (enemy->Count_3 < 4 && enemy->YAKU1_Storage[k] != 0 && enemy->YAKU1_Storage[k] != 8 && enemy->YAKU1_Storage[k] != 28) {


							if (enemy->Count_3 == 0) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 400;
								enemy->Count_3++;

							}
							else if (enemy->Count_3 == 1) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 500;
								enemy->Count_3++;

							}
							else if (enemy->Count_3 == 2) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 600;
								enemy->Count_3++;
							}
							else {

								return;

							}





						}


					}


				}



			}


		}


	}



	if (enemy->Jan >= 1 && enemy->Mar >= 1 && enemy->Aug >= 1) {


		for (int i = 0; i < 8; i++) {


			if (enemy->YAKU1_Storage[i] == 0) {


				if (enemy->YAKU2_Storage[0] != 0) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 400;
					enemy->Count_3++;

				}
				else {


					return;

				}


			}
			else if (enemy->YAKU1_Storage[i] == 8) {


				if (enemy->YAKU2_Storage[1] != 8) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 500;
					enemy->Count_3++;


				}
				else {

					return;


				}



			}
			else if (enemy->YAKU1_Storage[i] == 28) {


				if (enemy->YAKU2_Storage[2] != 28) {


					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 600;
					enemy->Count_3++;


				}
				else {


					return;

				}



			}




		}







	}
	else if (player->GU_GREEN_1 > player->PAR_RED_0 && player->GU_GREEN_1 > player->CHOKI_BLUE_2) {


		for (int i = 0; i < 8; i++) {

			if (enemy->SUKUMI_Storage[i] == 0 && enemy->Count_3 < 4 && enemy->YAKU1_Storage[i] != 0 && enemy->YAKU1_Storage[i] != 8 && enemy->YAKU1_Storage[i] != 28) {


				if (enemy->Count_3 == 0) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 400;
					enemy->Count_3++;

				}
				else if (enemy->Count_3 == 1) {


					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 500;
					enemy->Count_3++;


				}
				else if (enemy->Count_3 == 2) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 600;
					enemy->Count_3++;

				}
				else {

					for (int p = 0; p < 8; p++) {

						int k = rand() % 8;

						while (enemy->Huda_UP[k]) {

							k = rand() % 8;

							if (enemy->Huda_UP[k] == false) {

								break;

							}

						}

						if (enemy->Count_3 < 4) {


							if (enemy->Count_3 == 0) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 400;
								enemy->Count_3++;

							}
							else if (enemy->Count_3 == 1) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 500;
								enemy->Count_3++;


							}
							else if (enemy->Count_3 == 2) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 600;
								enemy->Count_3++;

							}
							else {

								return;

							}





						}


					}


				}



			}

		}


	}



	if (enemy->Jan >= 1 && enemy->Mar >= 1 && enemy->Aug >= 1) {


		for (int i = 0; i < 8; i++) {


			if (enemy->YAKU1_Storage[i] == 0) {


				if (enemy->YAKU2_Storage[0] != 0) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 400;
					enemy->Count_3++;

				}
				else {


					return;

				}


			}
			else if (enemy->YAKU1_Storage[i] == 8) {


				if (enemy->YAKU2_Storage[1] != 8) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 500;
					enemy->Count_3++;


				}
				else {

					return;


				}



			}
			else if (enemy->YAKU1_Storage[i] == 28) {


				if (enemy->YAKU2_Storage[2] != 28) {


					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 600;
					enemy->Count_3++;


				}
				else {


					return;

				}



			}




		}



	}
	else if (player->CHOKI_BLUE_2 > player->PAR_RED_0 && player->CHOKI_BLUE_2 > player->GU_GREEN_1) {


		for (int i = 0; i < 8; i++) {

			if (enemy->SUKUMI_Storage[i] == 1 && enemy->Count_3 < 4 && enemy->YAKU1_Storage[i] != 0 && enemy->YAKU1_Storage[i] != 8 && enemy->YAKU1_Storage[i] != 28) {


				if (enemy->Count_3 == 0) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 400;
					enemy->Count_3++;

				}
				else if (enemy->Count_3 == 1) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 500;
					enemy->Count_3++;


				}
				else if (enemy->Count_3 == 2) {

					enemy->Huda_UP[i] = true;
					enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[i];
					enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[i];
					enemy->cpos_x[i] = 600;
					enemy->Count_3++;


				}
				else {


					for (int p = 0; p < 8; p++) {

						int k = rand() % 8;

						while (enemy->Huda_UP[k]) {

							k = rand() % 8;

							if (enemy->Huda_UP[k] == false) {

								break;


							}

						}

						if (enemy->Count_3 < 4 && enemy->YAKU1_Storage[k] != 0 && enemy->YAKU1_Storage[k] != 8 && enemy->YAKU1_Storage[k] != 28) {


							if (enemy->Count_3 == 0) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 400;
								enemy->Count_3++;

							}
							else if (enemy->Count_3 == 1) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 500;
								enemy->Count_3++;


							}
							else if (enemy->Count_3 == 2) {

								enemy->Huda_UP[k] = true;
								enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[k];
								enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[k];
								enemy->cpos_x[k] = 600;
								enemy->Count_3++;

							}
							else {

								return;

							}





						}


					}


				}




			}


		}


	}
	else {

		for (int i = 0; i < 3; i++) {

			int k = rand() % 8;

			while (enemy->Huda_UP[k]) {

				k = rand() % 8;

				if (enemy->Huda_UP[k] == false) {

					break;


				}

			}


			if (enemy->Count_3 < 4 && enemy->YAKU1_Storage[k] != 0 && enemy->YAKU1_Storage[k] != 8 && enemy->YAKU1_Storage[k] != 28) {

				if (enemy->Count_3 == 0) {

					enemy->Huda_UP[k] = true;
					enemy->Ene_Sukim_3_Count[0] = enemy->SUKUMI_Storage[k];
					enemy->YAKU2_Storage[0] = enemy->YAKU1_Storage[k];
					enemy->cpos_x[k] = 400;
					enemy->Count_3++;

				}
				else if (enemy->Count_3 == 1) {


					enemy->Huda_UP[k] = true;
					enemy->Ene_Sukim_3_Count[1] = enemy->SUKUMI_Storage[k];
					enemy->YAKU2_Storage[1] = enemy->YAKU1_Storage[k];
					enemy->cpos_x[k] = 500;
					enemy->Count_3++;

				}
				else if (enemy->Count_3 == 2) {

					enemy->Huda_UP[k] = true;
					enemy->Ene_Sukim_3_Count[2] = enemy->SUKUMI_Storage[k];
					enemy->YAKU2_Storage[2] = enemy->YAKU1_Storage[k];
					enemy->cpos_x[k] = 600;
					enemy->Count_3++;


				}
				else {

					return;

				}




			}


		}


	}


}





//���E�����݂̃X�R�A�v�Z������(�����E�G�E�����ɍ̓_����E�łȂ��Ɣ�r�ł��Ȃ�)
void::Player::Moudules_All_Score_RETURN(Player* player, Player* enemy) {
	
	
	//�����̖��̃X�R�A�̌v�Z
	if (player->Jan == 1 && player->Mar == 1 && player->Aug == 1) {	//�O��


		player->TotalScore += 800;
		player->YAKU_Sankou = true;

	}
	else if (player->Aug == 1 && player->Sep == 1) {	//�����ň�t


		player->TotalScore += 500;
		player->YAKU_Tsukimi = true;
	}
	else if (player->Mar == 1 && player->Sep == 1) {	//�Ԍ��ň�t


		player->TotalScore += 500;
		player->YAKU_Hanami = true;

	}
	else if (player->Jul == 1 && player->Oct == 1 && player->Jun == 1) {	//������


		player->TotalScore += 500;
		player->YAKU_Inosika_chou= true;

	}
	else if (player->Jan == 1 && player->Nov == 1 && player->Dec == 1) {	//�J�~��O��

		player->TotalScore += 800;
		player->YAKU_Ameiri_Sankou = true;

	}	
	else if (player->Jan == 3) {	//�r�����a

		player->TotalScore += 300;
		player->YAKU_Jan = true;

	}
	else if (player->Feb == 3) {	//�@�����a

		player->TotalScore += 300;
		player->YAKU_Feb = true;

	}
	else if (player->Mar == 3) {	//�퐶���a

		player->TotalScore += 300;
		player->YAKU_Mar = true;

	}
	else if (player->Apr == 3) {	//�K�����a

		player->TotalScore += 300;
		player->YAKU_Apr = true;

	}
	else if (player->May == 3) {	//�H�����a

		player->TotalScore += 300;
		player->YAKU_May = true;

	}
	else if (player->Jun == 3) {	//���������a

		player->TotalScore += 300;
		player->YAKU_Jun = true;

	}
	else if (player->Jul == 3) {	//�������a

		player->TotalScore += 300;
		player->YAKU_Jul = true;

	}
	else if (player->Aug == 3) {		//�t�����a

		player->TotalScore += 300;
		player->YAKU_Aug = true;

	}
	else if (player->Sep == 3) {	//�������a

		player->TotalScore += 300;
		player->YAKU_Sep = true;

	}
	else if (player->Oct == 3) {	//�_�������a

		player->TotalScore += 300;
		player->YAKU_Oct = true;

	}
	else if (player->Nov == 3) {	//�������a

		player->TotalScore += 300;
		player->YAKU_Nov = true;

	}
	else if (player->Dec == 3) {	//�t�����a

		player->TotalScore += 300;
		player->YAKU_Dec = true;

	}
	
	
	
	//�G�̖��̃X�R�A�v�Z
	if (enemy->Jan2 == 1 && enemy->Mar2 == 1 && enemy->Aug2 == 1) {	//�O��

		enemy->TotalScore += 800;
		enemy->YAKU_Sankou = true;

	}
	else if (enemy->Aug2 == 1 && enemy->Sep2 == 1) {	//�����ň�t

		enemy->TotalScore += 500;
		enemy->YAKU_Tsukimi = true;
	}
	else if (enemy->Mar2 == 1 && enemy->Sep2 == 1) {	//�Ԍ��ň�t

		enemy->TotalScore += 500;
		enemy->YAKU_Hanami = true;

	}
	else if (enemy->Jul2 == 1 && enemy->Oct2 == 1 && enemy->Jun2 == 1) {	//������

		enemy->TotalScore += 500;
		enemy->YAKU_Inosika_chou = true;

	}
	else if (enemy->Jan2 == 1 && enemy->Nov2 == 1 && enemy->Dec2 == 1) {	//�J�~��O��

		enemy->TotalScore += 800;
		enemy->YAKU_Ameiri_Sankou = true;

	}
	else if (enemy->Jan2 == 3) {	//�r�����a

		enemy->TotalScore += 300;
		enemy->YAKU_Jan = true;

	}
	else if (enemy->Feb2 == 3) {	//�@�����a

		enemy->TotalScore += 300;
		enemy->YAKU_Feb = true;

	}
	else if (enemy->Mar2 == 3) {	//�퐶���a

		enemy->TotalScore += 300;
		enemy->YAKU_Mar = true;

	}

	else if (enemy->Apr2 == 3) {	//�K�����a

		enemy->TotalScore += 300;
		enemy->YAKU_Apr = true;

	}

	else if (enemy->May2 == 3) {	//�H�����a

		enemy->TotalScore += 300;
		enemy->YAKU_May = true;

	}

	else if (enemy->Jun2 == 3) {	//���������a

		enemy->TotalScore += 300;
		enemy->YAKU_Jun = true;

	}

	else if (enemy->Jul2 == 3) {	//�������a

		enemy->TotalScore += 300;
		enemy->YAKU_Jul = true;

	}

	else if (enemy->Aug2 == 3) {		//�t�����a

		enemy->TotalScore += 300;
		enemy->YAKU_Aug = true;

	}

	else if (enemy->Sep2 == 3) {	//�������a

		enemy->TotalScore += 300;
		enemy->YAKU_Sep = true;

	}

	else if (enemy->Oct2 == 3) {	//�_�������a

		enemy->TotalScore += 300;
		enemy->YAKU_Oct = true;

	}

	else if (enemy->Nov2 == 3) {	//�������a

		enemy->TotalScore += 300;
		enemy->YAKU_Nov = true;

	}

	else if (enemy->Dec2 == 3) {	//�t�����a

		enemy->TotalScore += 300;
		enemy->YAKU_Dec = true;

	}
	
	
	//3�����݂̃X�R�A�v�Z
	for (int i = 0; i < 3; i++) {

		switch (player->SUKUMI_Storage[i])
		{

		case 0:
			if (enemy->Ene_Sukim_3_Count[i] == 0) {


				player->Total_3_Score += 0;
				enemy->Total_3_Score += 0;

			}
			else if (enemy->Ene_Sukim_3_Count[i] == 1) {


				player->Total_3_Score += 100;


			}
			else if (enemy->Ene_Sukim_3_Count[i] == 2) {



				enemy->Total_3_Score += 100;



			}
			else if (enemy->Ene_Sukim_3_Count[i] == 99) {


				player->Total_3_Score += 0;
				enemy->Total_3_Score += 0;


			}
			break;

		case 1:
			if (enemy->Ene_Sukim_3_Count[i] == 0) {


				enemy->Total_3_Score += 100;


			}
			else if (enemy->Ene_Sukim_3_Count[i] == 1) {



				player->Total_3_Score += 0;
				enemy->Total_3_Score += 0;


			}
			else if (enemy->Ene_Sukim_3_Count[i] == 2) {


				player->Total_3_Score += 100;



			}
			else if (enemy->Ene_Sukim_3_Count[i] == 99) {


				player->Total_3_Score += 0;
				enemy->Total_3_Score += 0;


			}
			break;

		case 2:

			if (enemy->Ene_Sukim_3_Count[i] == 0) {


				player->Total_3_Score += 100;


			}
			else if (enemy->Ene_Sukim_3_Count[i] == 1) {


				enemy->Total_3_Score += 100;


			}
			else if (enemy->Ene_Sukim_3_Count[i] == 2) {


				player->Total_3_Score += 0;
				enemy->Total_3_Score += 0;


			}
			else if (enemy->Ene_Sukim_3_Count[i] == 99) {


				player->Total_3_Score += 0;
				enemy->Total_3_Score += 0;


			}
			break;



		}



	}


}

