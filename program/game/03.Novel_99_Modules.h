#pragma once

//---------------------------------------------
//�m�x���V�[���Ŏg�p���郂�W���[���i�摜/�֐��j���܂Ƃ߂��N���X
//---------------------------------------------

class NovelModules {
public:

	//��l���E��΁E�����G�EH�i�ʏ�j�AS�i�Ί�j�AI�i�{��j�AO�i�����j�AK�i�߂��݁j�AA�i�ł�j
	int Tatie_00_H;
	int Tatie_00_S;
	int Tatie_00_I_1;
	int Tatie_00_I_2;
	int Tatie_00_O;
	int Tatie_00_A;

	//����
	int Tatie_01_H; 
	int Tatie_01_I;
	int Tatie_01_K;
	int Tatie_01_S;

	//�����E�H
	int Tatie_02_H;
	int Tatie_02_I;
	int Tatie_02_K;
	int Tatie_02_S;
	
	//�~���i�ӂ�ˁj�E����
	int Tatie_03_H_kamen;
		
	//�~���i�ӂ�ˁj�E�ʏ�
	int Tatie_03_H;
	int Tatie_03_I;
	int Tatie_03_O;
	int Tatie_03_S;
	int Tatie_03_S_2;

	
	//�ؗ�i�����j�E�~
	int Tatie_04_H;
	int Tatie_04_H_2;
	int Tatie_04_K;

	//�ؙz�E�ϔ�
	int Tatie_04_02_H;
	int Tatie_04_02_H_2;
	int Tatie_04_02_K;
		
	//��
	int Tatie_05; 
	//���u
	int Tatie_MOBU_H;

	//BGM
	int BGM1;	//�ʏ�E�n�b�s�[
	int BGM2;	//�s��1
	int BGM3;	//�s��2
	int BGM4;	//���X�{�X�o��
	int BGM5;	//�Ō�

	//�w�i
	int Back_01;
	int Back_02;
	int Back_03;
	int Back_04;
	int Back_05;

	//��b�{�b�N�X
	int kaiwabokkusu;
	int namae;

	//�y�֐��z�������֐�
	void Novel_Init(NovelModules* novel);

	//�y�֐��z�������֐�
	void Novel_Fin(NovelModules* novel);


	//�y�֐��z��b�{�b�N�X�ɓ���悤�ɃZ���t������֐��E�Z���t���֐��œn���ĕ\��
	void Novel(std::string a, std::string b, std::string c, std::string d);

	//�y�֐��z
	void Tatie_LEFT(int tatie);

	//�y�֐��z
	void Tatie_CENTER(int tatie);

	//�y�֐��z
	void Tatie_Right(int tatie);
	
	//�y�֐��z
	void Tatie_BACKIMAGE(int tatie);







};