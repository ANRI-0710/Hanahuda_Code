#pragma once

//---------------------------------------------
//�ԎD�Q�[���Ɏg�p���郂�W���[���i�摜�E���o�E�֐��j���W�񂵂��N���X
//---------------------------------------------

//�ԎD�̕\�Ɨ��̊Ǘ�
typedef enum {
	eCard_Omote,
	eCard_URA,
	eCard_OU_NUM,
}Card_UR;


//3������
typedef enum {
	eJanken_RED,//�p�[
	eJanken_GREEN,	//�O�[
	eJanken_BLUE,
	eJanken_NUM,	//�`���L

}Janken_3sukumi;

//�ԎD�̖�
typedef enum {
	eCard_Jan_1,
	eCard_Mar_1,
	eCard_Sep_1,
	eCard_Nov_1,
	eCard_Dec_1,
	eCard_NUM,

}Card_type;

//�Q�[�����V�[���J��
typedef enum {	

	Progress0,
	Progress1,
	Progress2,
	Progress3,
	Progress4,
	Progress5,
	Progress6,
	Progress7,
	Progress8,
	Progress9,
	Progress10,
	Progress11,

}Progress;

//�����y�ѓG��HP
typedef enum {

	MAXHP_1 = 5000,

}MAXHP;


//�v���C���[�N���X
class Player {
public:

	//�V�[���Ǘ�
	int MainScene_ = Progress0;
	
	//HP�Ǘ�
	int HP = 0;
	float HP_now;
	int HP_var = 0;

	//�U������_���i���j
	int TotalScore = 0;

	//�U������_���i3�����݁j
	int Total_3_Score = 0;

	int Back_Image = 0;

	//�U���p�����G
	int Attack_Image = 0;
	int Attack_Effect[8] = {0};
	int Attck_E_anim = 0;
	int Attck_Sound = 0;
	float Attack_E_time =  0;

	//�t�H���g
	int Font_Meicho = 0;
	int Font_Meicho_big = 0;

	//�U���p�����G���W�Ǘ�
	int AT_pos_x = 30;
	int AT_pos_y = 700;

	//�U���p�����G�J�E���^�[�Ɛ���
	int AT_counter = 0;
	int AT_speed_1 = 50;
	int AT_speed_2 = 60;
	bool AT_Wait[3] = { 0 };

	//�U���E�񕜃��j���[
	int NowSelect_M = 0;
	int pos_x_M = 0;
	int pos_y_M = 0;
	
	int NowSelect_Kaihuku = 0;
	int Kihuku_small = 3;
	int Kihuku_Midium = 1;
	int Kihuku_Big = 1;

	int pos_x_Kaihuku = 0;
	int pos_y_Kaihuku = 0;
	
	//���W�Ǘ�
	int cpos_x[8] = { 0 };
	int cpos_y[8] = { 0 };
	
	//�ԎD�̔z�񏈗��p
	int uraomote = 0;	
	int cYaku_Num = 0;	
	int cYaku_NUM2 = 0;
	int c3_Num1 = 0;	//����񂯂�

	//�����z��i�[
	int YAKU_R[8] = {0};
	int Sukumi_R[8] = {0};
	int YAKU_S[8] = { 0 };

	//�������p����
	bool init = false;
	int Progress_S = 0;
	
	//�ԎD��3���ȏ�o���Ȃ��悤�ɂ��邽�߂̐���
	bool Game_Start = false;
	int Count_3 = 0; //����ɏo���D��3���܂łɂ��邽�߂̃J�E���g
	
	//�ԎD�𕑑�ɏo���Ă��邩�̊m�F�E����p
	bool Huda_UP[8] = { 0 };
	
	//�o���ԎD�̔z����̋L�^�ꏊ�E99�̏ꍇ�́A���̎D���オ���ĂȂ��A�X�R�A�v�Z���珜�O�����
	int UR_Storage[8] = { 99,99,99,99,99,99,99,99 };
	int YAKU1_Storage[8] = { 99,99,99,99,99,99,99,99 };
	int YAKU2_Storage[8] = { 99,99,99,99,99,99,99,99 };
	int SUKUMI_Storage[8] = { 99,99,99,99,99,99,99,99 };

	int Ene_Sukim_3_Count[3] = { 99,99,99 }; //��

	//���̓��_�W�v�p�ϐ�
	int Jan = 0;
	int Feb = 0;
	int Mar = 0;
	int Apr = 0;
	int May = 0;
	int Jun = 0;
	int Jul = 0;
	int Aug = 0;
	int Sep = 0;
	int Oct = 0;
	int Nov = 0;
	int Dec = 0;

	//���̓��_�W�v�p�ϐ�
	int Jan2 = 0;
	int Feb2 = 0;
	int Mar2 = 0;
	int Apr2 = 0;
	int May2 = 0;
	int Jun2 = 0;
	int Jul2 = 0;
	int Aug2 = 0;
	int Sep2 = 0;
	int Oct2 = 0;
	int Nov2 = 0;
	int Dec2 = 0;

	//���̐����E�U�����[�V��������p
	bool YAKU_Ari = false;
	bool YAKU_Sankou = false;
	bool YAKU_Ameiri_Sankou = false;
	bool YAKU_Inosika_chou = false;
	bool YAKU_Akatan = false;
	bool YAKU_Aotan = false;
	bool YAKU_Tsukimi = false;
	bool YAKU_Hanami = false;
	
	bool YAKU_Jan = false;
	bool YAKU_Feb = false;
	bool YAKU_Mar = false;
	bool YAKU_Apr = false;
	bool YAKU_May = false;
	bool YAKU_Jun = false;
	bool YAKU_Jul = false;
	bool YAKU_Aug = false;
	bool YAKU_Sep = false;
	bool YAKU_Oct = false;
	bool YAKU_Nov = false;
	bool YAKU_Dec = false;

	//�𖼕\���p�ϐ�
	int YAKU_Sankou_image = 0;
	int YAKU_Ameiri_Sankou_image = 0;
	int YAKU_Inosika_chou_image = 0;
	int YAKU_Tsukimi_image = 0;
	int YAKU_Hanami_image = 0;
	
	int YAKU_ImageJan = 0;
	int YAKU_ImageFeb = 0;
	int YAKU_ImageMar = 0;
	int YAKU_ImageApr = 0;
	int YAKU_ImageMay = 0;
	int YAKU_ImageJun = 0;
	int YAKU_ImageJul = 0;
	int YAKU_ImageAug = 0;
	int YAKU_ImageSep = 0;
	int YAKU_ImageOct = 0;
	int YAKU_ImageNov = 0;
	int YAKU_ImageDec = 0;


	//3�����݂̍��v�X�R�A�W�v�p�ϐ�
	int PAR_RED_0 = 0;
	int GU_GREEN_1 = 0;
	int CHOKI_BLUE_2 = 0;


	//�J�n�֘A�̕ϐ�
	int Start_time = 0;
	int VS_player_img = 0;
	int VS_enemy_img = 0;
	int start_image = 0;
	int start_BGM[2] = { 0 };

	
	//�I���֘A�̕ϐ�
	int fin_image = 0;
	
	int Finish_time[3] = { 0 };		//�I���摜�E�����摜���o���Ƃ��̃J�E���g����
	
	int Finish_win_image = 0;
	int Finish_win_SE = 0;

	int Finish_lose_image = 0;
	int Finish_lose_SE = 0;

	//�w���v�p����
	int HelpImage = 0;
	int HelpImage2 = 0;
	bool Helpbool = 0;

	int Help_Scene_1 = 0;	//�w���v�y�[�W��p�ϐ�

	//���ꗗ���X�g�̕\��
	int YakuList = 0;

	//���ꗗ
	int YAKU_page = 0;

	//�߂�
	int GoBack_Num = 0;

	//���񂷂��݂̉摜�\��
	int Sansukumi;
		
	//�y�֐��z�摜�E�G�t�F�N�g����������(�Q�[���i���o�[�̐��Ŋe�Q�[���V�[�����ƂɈႤ�摜�̊���U�������)
	void Init_Battle(Player* player, Player* enemy,int GameNum);
	
	//�y�֐��z�I��������
	void Finalize_Battle(Player* player);
	
	
	//�y�֐��z�V�X�e�����b�Z�[�W�Ǘ�
	void System_Messeage(Player* player, Player* enemy);


	//�y�֐��z�U���E�񕜂̃��j���[�\��
	void Card_Modules_Menu(Player* player);

	//�񕜃��j���[�̕\��
	void Card_Modules_Recovery_Menu(Player* player);

	//�񕜏����E1�Ȃ�Ώ��A2�Ȃ�Β��A3�Ȃ����w��
	void Card_Modules_HP_Recovery(Player* player,int kaihukuNum);

	//�w���v��ʂ̕\��
	void Card_Modules_Help(Player* player,int nowscene);

	//���ꗗ���X�g�̕\��
	void Card_Modules_YakuList(Player* player, int nowscene);

	//�Q�[����r�����E�i�߂�j�ꍇ
	void Card_Modules_Back_Menu(Player* player);
	
	//�y�֐��z���������z�u
	void Card_Moudules_First_Place(Player* player);

	//�y�֐��z�����V���b�t���E�d���i�V�i�ԎD�̎�ށj
	void Card_Modules_YAKU_shuffle(Player* player, int size);

	//�y�֐��z�����V���b�t���E�d���A���i����񂯂�j
	void Card_Modules_3_shuffle(Player* player,int size);
	
	//�y�֐��z����ɏo�����D�̂݃V���b�t��������E�܂��m�������̂��߁AYAKUNUM�̔ԍ��ɂ���āA3����1�̊m���ŃL�����̃e�[�}�ɍ��킹�������łĂ���ݒ�
	void Card_Moudules_YAKU_Reshaffle(Player* player, int size,int YAKUNUM);

	//�y�֐��z�����̖��X�R�A�̌v�Z
	void Moudules_Myplayer_YAKUScore_RETURN(Player*);

	//�y�֐��z�G�̖��X�R�A�̌v�Z
	void Moudules_Enemy_YAKUScore_RETURN(Player* enemy);

	//�y�֐��z�G�̖��Ǝ�����3�����݂̌v�Z�����A�J�[�h���o���E���������f��
	void Moudules_Enemy_Card_Place(Player* player, Player* enemy);

	//�y�֐��z�G�̖��Ǝ�����3�����݂̌v�Z�����A�J�[�h���o���E�����Ɉ�t
	void Moudules_Enemy_Card_Place_2(Player* player, Player* enemy);

	//�y�֐��z�G�̖��Ǝ�����3�����݂̌v�Z�����A�J�[�h���o���E�J�~��O��
	void Moudules_Enemy_Card_Place_3(Player* player, Player* enemy);

	//�y�֐��z�G�̖��Ǝ�����3�����݂̌v�Z�����A�J�[�h���o���E�O��
	void Moudules_Enemy_Card_Place_4(Player* player, Player* enemy);

	//�y�֐��z���v���C���[�̍U������,TF�́A0��������3�����݂̃X�R�A�A1����������̃X�R�A�̍U���������s��
	void Moudules_Player_Attack(Player* player, Player* enemy,int TF);

	//�y�֐��z�G�̍U�������E0��������3�����݂̃X�R�A�A1����������̃X�R�A�̍U���������s��
	void Moudules_Enemy_Attack(Player* player, Player* enemy,int TF);

	//�y�֐��z3�����݃X�R�A�̌v�Z������
	void Moudules_All_Score_RETURN(Player* player, Player* enemy);

	//�y�֐��z�U�����[�V�����i�����݁j
	void Modules_Attack_Motion(Player* player,Player* enemy,int scene);

	//�y�֐��z�U�����[�V�����i���j
	void Modules_Attack_Motion_YAKU(Player* player, Player*, int scene);

	//�y�֐��z�U�����[�V��������������
	void Modules_Attack_init(Player* player, Player*);

	//�y�֐��z�����J�n�֐�
	void Modules_Battle_Start(Player* player);
	
	//�y�֐��z��������̃��U���g���ʂ��o��
	void Modules_Result(Player* player, Player* enemy,int UNLOCKNUM);

};