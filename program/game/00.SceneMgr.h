#pragma once

//---------------------------------------------
//�V�[���J�ڂ̊Ǘ��N���X
//---------------------------------------------

typedef enum {

	Title, //���j���[���
	Chapter,	//���C���`���v�^�[���
	Novel_0,
	Novel_1,
	Novel_2,
	Novel_3,
	Novel_4,
	Novel_5,	//�ŏI�����N���A��̃G���f�B���O�V�i���I

	Game_1,
	Game_2,
	Game_3,
	Game_4,
	Config,
	None,

}eScene;

	
	void SceneMgr_Music();	//	���y�Ǘ�

	void SceneMgr_Initialize();	//������

	void SceneMgr_Finalize();	//�I������

	void SceneMgr_Update();	//�X�V����

	void SceneMgr_Draw();	//�`�揈��

	void SceneMgr_ChangeScene(eScene nextScene); //���� nextScene�ɃV�[����ύX����