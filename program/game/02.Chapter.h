#pragma once

//---------------------------------------------
//�`���v�^�[�V�[���̊Ǘ��N���X
//---------------------------------------------

//�`���v�^�[�A�����b�N�̐���N���X
class Chapter_Key {
public:

	bool Chapter_Unlock[5] = { 1,0,0,0,0 };	//�`���v�^�[����p

};

enum eChapter_Unlock {

	eUnlock_Chpter_0,	//�`���v�^�[0�b�E�v�����[�O�̂��ߍŏ�������
	eUnlock_Chpter_1,	//�`���v�^�[1�b�A0�b�Ǘ����������
	eUnlock_Chpter_2,	//�`���v�^�[2�b�A1�b�ł̉ԎD�̐퓬�ŏ������������
	eUnlock_Chpter_3,	//�`���v�^�[3�b�A2�b�ł̉ԎD�̐퓬�ŏ������������
	eUnlock_Chpter_4,	//�`���v�^�[�ŏI�b�A3�b�ł̉ԎD�̐퓬�ŏ������������

};


//�Z�[�u�f�[�^�Ǘ�
struct save_deta_t {

	bool s_Chapter_Unlock[5] = {1,0,0,0,0};


};






//������
void Chapter_Initialize();

//�I������
void Chapter_Finalize();


//�X�V
void Chapter_Update();

	//�X�V-�`���v�^�[��������p�֐�
	void Chapter_Unlock(int *chapter_NUM);


//�`��
void Chapter_Draw();


