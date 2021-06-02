#include "DxLib.h"
#include "../library/t2klib.h"
#include "../support/Support.h"
#include "00.SceneMgr.h"
#include "02.Chapter.h"


//�摜
static int BackImage;	//�w�i
static int CHAPTER_Lock_Image[5] = { 0 };	//�`���v�^�[���b�N�p�̉摜
static int CHAPTER_Image_[5] = {0};	 //�`���v�^�[�I���摜5��
static int CHAPTER_Image_Select[5] = { 0 };	//�`���v�^�[�I�����Ɍ��点�邽�߂̉摜

static int GoBack_Title;	//�^�C�g���ɖ߂��p�̉摜
static int backimage_ = 0;
static int Setumei_Box;

//BGM��SE
static int ENTER_SE;	//���莞SE
static int Title_BGM = 0;	//�^�C�g��BGM�E�`���v�^�[�ƃR���t�B�O��������
static int Change_SE;	//�V�t�g�L�[�ړ���SE


//����pbool
static bool init = false;	//�������p
static bool Finalize = false;	//	�I������
static int MUSIC_STOP;

static bool CHAPTER_Select_b[5] = { 1,0,0,0,0 };	//�`���v�^�[�I�𒆂̓u�����h���[�h�Ŕ���

//�Z�[�u�f�[�^�Ǘ�
save_deta_t save_data;
FILE* fp;
char* name = "sava_data.dat";



//�`���v�^�[�������
Chapter_Key Key;


//�I���ړ��p�ϐ�
enum {
	eChapter_0,
	eChapter_1,
	eChapter_2,
	eChapter_3,
	eChapter_4,
	eChapter_Num,

};

static int NowSelect = eChapter_0;



//������
void Chapter_Initialize() {
		
		BackImage = LoadGraph("graphics/chapter_back.png"); //�w�i�摜�̏�����
		Setumei_Box = LoadGraph("graphics/wafuu1.png");
	
		//�`���v�^�[�摜
		CHAPTER_Image_[0] = LoadGraph("graphics/Chapter_1.png");
		CHAPTER_Image_[1] = LoadGraph("graphics/Chapter_2.png");
		CHAPTER_Image_[2] = LoadGraph("graphics/Chapter_3.png");
		CHAPTER_Image_[3] = LoadGraph("graphics/Chapter_4.png");
		CHAPTER_Image_[4] = LoadGraph("graphics/Chapter_5.png");



		for (int i = 0; i < 5; i++) {	//�I���������p�摜

			CHAPTER_Image_Select[i] = LoadGraph("graphics/Chapter_1_select.png");

		}

		for (int i = 0; i < 5; i++) {	//�A�����b�N�p�摜

			CHAPTER_Lock_Image[i] = LoadGraph("graphics/Chapter_1_lock.png");

		}

		


		//BGM
		ENTER_SE = LoadSoundMem("sound/DECISION_SE.mp3");
		Title_BGM = LoadSoundMem("sound/TITLE_CHAPTER_BGM.mp3");
		Change_SE = LoadSoundMem("sound/MOVE_CULSOL_SE.mp3");	

		PlaySoundMem(Title_BGM,DX_PLAYTYPE_LOOP);

		//backimage_ = LoadGraph("graphics/Backimage_0909.png");

	
		//�t�@�C�����e����f�[�^�����[�h
		if ((fp = fopen(name, "rb")) == NULL) {

			printf("�t�@�C���I�[�v���G���[");

		}
		else {

			//�t�@�C������f�[�^��ǂݍ���
			fread(&save_data, sizeof(save_deta_t), 1, fp);
			fclose(fp);	//���
						
			printf("chapter 1 = %d\n", save_data.s_Chapter_Unlock[1]);
			printf("chapter 1 = %d\n", save_data.s_Chapter_Unlock[2]);
			printf("chapter 1 = %d\n", save_data.s_Chapter_Unlock[3]);
			printf("chapter 1 = %d\n", save_data.s_Chapter_Unlock[4]);
			

		}

		for (int i = 0; i < 5; i++) {

			if (save_data.s_Chapter_Unlock[i]) {

				Key.Chapter_Unlock[i] = true;

			}


		}





		
		
}

//�I������
void Chapter_Finalize() {

		for (int i = 0; i < 5; i++) {

		DeleteGraph(CHAPTER_Image_[i]);
		DeleteGraph(CHAPTER_Image_Select[i]);
		DeleteGraph(CHAPTER_Lock_Image[i]);	

		}

		DeleteSoundMem(Title_BGM);
		DeleteGraph(BackImage);
		DeleteGraph(Title_BGM);
		DeleteGraph(Change_SE);
		DeleteGraph(ENTER_SE);
	
	
}


//�X�V�E�v�Z����

	//�E�Ɉړ�
void Chapter_Update() {

	DrawRotaGraph(512, 350, 1.0f, 0, backimage_, true);
	
	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RIGHT)) {
					
		NowSelect = (NowSelect + 1) % eChapter_Num;
		PlaySoundMem(Change_SE, DX_PLAYTYPE_BACK);
		
		for(int i = 0; i < 5; i++) {	//�I�𒆂̃`���v�^�[�����点��

			if (NowSelect == i) {

				CHAPTER_Select_b[i] = true;

			}
			else {

				CHAPTER_Select_b[i] = false;

			}

		}

	}

	//���Ɉړ�
	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_LEFT)) {
	
		NowSelect = (NowSelect + (eChapter_Num - 1)) % eChapter_Num;
		PlaySoundMem(Change_SE, DX_PLAYTYPE_BACK);
		
		for (int i = 0; i < 5; i++) {

			if (NowSelect == i) {

				CHAPTER_Select_b[i] = true;

			}
			else {

				CHAPTER_Select_b[i] = false;

			}

		}

		
	}

	//�I�𒆂̔ԍ����G���^�[������A���̃V�[���ֈڍs����B
	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_RETURN)) {

		PlaySoundMem(ENTER_SE, DX_PLAYTYPE_BACK);

		switch (NowSelect)	
		{
		case eChapter_0:
				SceneMgr_ChangeScene(Novel_0);	//�v�����[�O�̂��߁A��ɉ��
				DeleteSoundMem(Title_BGM);
				MUSIC_STOP = 0;
				Finalize = true;
				break;

		case eChapter_1:
			
			if (Key.Chapter_Unlock[eChapter_1]) {	//�`���v�^�[0�Ǘ��ŉ��
				
				SceneMgr_ChangeScene(Game_1);
				DeleteSoundMem(Title_BGM);
				MUSIC_STOP = 0;
				Finalize = true;

			}
				break;

		case eChapter_2:
			
			if (Key.Chapter_Unlock[eChapter_2]) {	//�`���v�^�[1�Ǘ��ŉ��
				SceneMgr_ChangeScene(Novel_2);
				MUSIC_STOP = 0;
				Finalize = true;			
			}
				break;
			
		case eChapter_3:
			
			if (Key.Chapter_Unlock[eChapter_3]) {	//�`���v�^�[2�Ǘ��ŉ��
				
				SceneMgr_ChangeScene(Novel_3);
				MUSIC_STOP = 0;
				Finalize = true;

			}			
				break;

		case eChapter_4:
			
			if (Key.Chapter_Unlock[eChapter_4]) {	//�`���v�^�[3�Ǘ��ŉ��
				SceneMgr_ChangeScene(Novel_4);
				MUSIC_STOP = 0;
				Finalize = true;
			}			
				break;


		}


	}

	//�o�b�N�X�y�[�X�L�[�������ꂽ��^�C�g���ֈړ�
	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_BACK)) {

		SceneMgr_ChangeScene(Title);
		Finalize = true;

	}





}
//�X�V-�`���v�^�[��������p�֐�
void Chapter_Unlock(int *chapter_NUM) {		//�����N���A����ɌĂяo���A�Y���`���v�^�[�ւ̐����������

	int Num = *chapter_NUM;

	for (int i = 0; i < 5; i++) {

		if (i== Num) {

			Key.Chapter_Unlock[i] = true;
			save_data.s_Chapter_Unlock[i] = true;

		}

	}
	
	if ((fp = fopen(name, "wb")) == NULL) {
		printf("�t�@�C���I�[�v���G���[\n");
	}
	else {
		fwrite(&save_data, sizeof(save_deta_t), 1, fp);
		fclose(fp);
	}

	
	
	




}


//�`��
void Chapter_Draw() {

		int pos_x = 100;	//�`���v�^�[�摜���W�����p
		int pos_y = 200;

		DrawRotaGraph(512, 384, 0.95f, 0, BackImage,true);	//�w�i�摜
		DrawRotaGraph(512, 630, 1.0f, 0, Setumei_Box, true);	//�w�i�摜
		

		
	for (int i = 0; i < 5; i++) {	//�`���v�^�[�摜�`��

		if (i % 2 != 0) {		//CHAPTER i �����������

			pos_y = 400;	//y�̈ʒu�𒲐�

		}
		else {

			pos_y = 200;

		}

		//�I�𒆂ł���ꍇ�͌��点��
		if (CHAPTER_Select_b[i]) {	

			if (CHAPTER_Select_b[0]) {

				DrawStringEx(200, 600, -1, "�����n�܂�̏́i�V�i���I�̂݁j����");
				DrawStringEx(200, 630, -1, "���@���@�ړ��Ń`���v�^�[��I���ł��܂��B");
				DrawStringEx(200, 650, -1, "ENTER�L�[�ł��̏͂ɍs���܂��B");
				DrawStringEx(200, 670, -1, "�^�C�g���̖߂�ꍇ�́ABackSpece�L�[�������Ă��������B");



			}

			if (CHAPTER_Select_b[1]) {

				DrawStringEx(200, 600, -1, "������́i�����̂݁j����");
				DrawStringEx(200, 630, -1, "��������F�w�n�܂�̏́x���N���A");
				DrawStringEx(200, 650, -1, "�ԎD�ɏ�������Ǝ����Z�[�u������܂��B");
				



			}

			if (CHAPTER_Select_b[2]) {

				DrawStringEx(200, 600, -1, "�����Q�́i�V�i���I�E�ԎD�j����");
				DrawStringEx(200, 630, -1, "��������F�w��́x���N���A");
				DrawStringEx(200, 650, -1, "�ԎD�ɏ�������Ǝ����Z�[�u������܂��B");

				



			}

			if (CHAPTER_Select_b[3]) {

				DrawStringEx(200, 600, -1, "�����l�́i�V�i���I�E�ԎD�j����");
				DrawStringEx(200, 630, -1, "��������F�w�Q�́x���N���A");
				DrawStringEx(200, 650, -1, "�ԎD�ɏ�������Ǝ����Z�[�u������܂��B");



			}

			if (CHAPTER_Select_b[4]) {

				DrawStringEx(200, 600, -1, "�����ŏI�́i�V�i���I�E�ԎD�j����");
				DrawStringEx(200, 630, -1, "��������F�w�l�́x���N���A");
				DrawStringEx(200, 650, -1, "�ԎD�ɏ�������Ǝ����Z�[�u������܂��B");



			}





				SetDrawBlendMode(DX_BLENDMODE_ADD, 120);
				DrawRotaGraph(pos_x + (i * 200), pos_y, 1.05f, 0, CHAPTER_Image_Select[i], true);


				
				


									
		}

		//	�摜�̕\��
		if (Key.Chapter_Unlock[i]) {
			
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 250);
				DrawRotaGraph(pos_x + (i * 200), pos_y, 1.0f, 0, CHAPTER_Image_[i], true);
									
		}
		else {

		//�A�����b�N�摜			
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 250);
				DrawRotaGraph(pos_x + (i * 200), pos_y, 1.0f, 0, CHAPTER_Image_[i], true);

				DrawRotaGraph(pos_x + (i * 200), pos_y, 1.0f, 0, CHAPTER_Lock_Image[i], true);
			
		}
		
	
				
	}




}