#include "DxLib.h"
#include "../library/t2klib.h"
#include "../support/Support.h"
#include "00.SceneMgr.h"
#include "01.TitleMgr.h"
#include "02.Chapter.h"
#include "03.Novel_1.h"
#include "03.Novel_2.h"
#include "03.Novel_3.h"
#include "03.Novel_4.h"
#include "03.Novel_5.h"
#include "04_01.HanahudaMgr.h"
#include "04_02.HanahudaMgr.h"
#include "04_03.HanahudaMgr.h"
#include "04_04.HanahudaMgr.h"

static eScene mNextScene = None;	//	���̃V�[���̊Ǘ��ϐ�
static eScene mScene = Title;	//	�V�[���̊Ǘ��ϐ�

static void SceneMgr_InitalizeModule(eScene scene);	//	�w�胂�W���[���̏������������s��
static void SceneMgr_FinalizeModule(eScene scene);	//�w��̃��W���[���̏I���������s��


//������
void SceneMgr_Initialize() {

	SceneMgr_InitalizeModule(mScene);	//�O�V�[���̏I���������邽�߁A�\�񏈗�
}

//�I������
void SceneMgr_Finalize() {

	SceneMgr_FinalizeModule(mScene);	//�O�V�[���̏I���������邽�߁A�\�񏈗�

}

//�X�V����
void SceneMgr_Update() {

	if (mNextScene != None) {

		SceneMgr_FinalizeModule(mScene);	//���݂̃V�[���̏I�������̎��s�E���������͂ł��Ȃ�
		mScene = mNextScene;	//���̃V�[�������݂̃V�[����
		mNextScene = None; //���̃V�[�������N���A
		SceneMgr_InitalizeModule(mScene);	//�ڍs�������V�[��������������

	}

	switch (mScene)	{	//�V�[���ɂ���čX�V�����𕪊�
		
	case Title:	//���݃V�[�����^�C�g���̏ꍇ
		Title_Update();	//�e�V�[���̍X�V������A�ȉ��ȗ�
		break;
	case Chapter:
		Chapter_Update();
		break;
	case Novel_0:
		Novel_CH_1_Update();
		break;
	case Novel_1:
		//Novel_CH_1_Update();
		break;

	case Novel_2:
		Novel_CH_2_Update();
		break;

	case Novel_3:
		Novel_CH_3_Update();
		break;

	case Novel_4:
		Novel_CH_4_Update();
		break;

	case Novel_5:
		Novel_CH_5_Update();
		break;

	case Game_1:
		HanahudaMgr_Update();
		break;

	case Game_2:
		HanahudaMgr_Update_2();
		break;

	case Game_3:
		HanahudaMgr_Update_3();
		break;

	case Game_4:
		HanahudaMgr_Update_4();
		break;

	case Config:
		//Config_Update();
		break;		
	}

}

//�`�揈��
void SceneMgr_Draw() {

	switch (mScene) {	//�V�[���ɂ���čX�V�����𕪊�

	case Title:	//���݃V�[�����^�C�g���̏ꍇ
		Title_Draw();	//�e�V�[���̍X�V������A�ȉ��ȗ�
		break;
	case Chapter:
		Chapter_Draw();
		break;
	case Novel_0:	//�m�x��0�b�i�v�����[�O�j
		Novel_CH_1_Draw();
		break;
	
	case Novel_1:
		//Novel_CH_1_Draw();
		break;

	case Novel_2:
		Novel_CH_2_Draw();
		break;

	case Novel_3:
		Novel_CH_3_Draw();
		break;

	case Novel_4:
		Novel_CH_4_Draw();
		break;
	
	case Novel_5:
		Novel_CH_5_Draw();
		break;

	case Game_1:
		HanahudaMgr_Draw();
		break;

	case Game_2:
		HanahudaMgr_Draw_2();
		break;

	case Game_3:
		HanahudaMgr_Draw_3();
		break;

	case Game_4:
		HanahudaMgr_Draw_4();
		break;

	case Config:
		//Config_Draw();
		break;
	}

}

//���� nextScene�ɃV�[����ύX����
void SceneMgr_ChangeScene(eScene nextScene) {

	mNextScene = nextScene;

}


//�w�胂�W���[��������������
static void SceneMgr_InitalizeModule(eScene scene) {
	
		switch (scene) {	//�V�[���ɂ���čX�V�����𕪊�

		case Title:	//���݃V�[�����^�C�g���̏ꍇ			
			Title_Initialize();//�e�V�[���̏�����������A�ȉ��ȗ�
			break;
		case Chapter:
			Chapter_Initialize();
			break;
		case Novel_0:
			Novel_CH_1_Initialize();
			break;
		case Novel_1:
			//Novel_CH_1_Initialize();
			break;

		case Novel_2:
			Novel_CH_2_Initialize();
			break;

		case Novel_3:
			Novel_CH_3_Initialize();
			break;

		case Novel_4:
			Novel_CH_4_Initialize();
			break;

		case Novel_5:
			Novel_CH_5_Initialize();
			break;

		case Game_1:
			HanahudaMgr_Initialize();
			break;

		case Game_2:
			HanahudaMgr_Initialize_2();
			break;

		case Game_3:
			HanahudaMgr_Initialize_3();
			break;

		case Game_4:
			HanahudaMgr_Initialize_4();
			break;

		case Config:
			//Config_Initialize();
			break;
		}
}

static void SceneMgr_FinalizeModule(eScene scene) {

	
	switch (scene) {

	case Title:	//���݃V�[�����^�C�g���̏ꍇ
		Title_Finalize();	//�e�V�[���̏�����������A�ȉ��ȗ�
		break;
	case Chapter:
		Chapter_Finalize();
		break;
	case Novel_0:
		Novel_CH_1_Finalize();
		break;
	case Novel_1:
		//Novel_CH_1_Finalize();
		break;

	case Novel_2:
		Novel_CH_2_Finalize();
		break;

	case Novel_3:
		Novel_CH_3_Finalize();
		break;

	case Novel_4:
		Novel_CH_4_Finalize();
		break;

	case Novel_5:
		Novel_CH_5_Finalize();
		break;

	case Game_1:
		HanahudaMgr_Finalize();
		break;

	case Game_2:
		HanahudaMgr_Finalize_2();
		break;

	case Game_3:
		HanahudaMgr_Finalize_3();
		break;

	case Game_4:
		HanahudaMgr_Finalize_4();
		break;

	case Config:
		//Config_Finalize();
		break;
	}

}

