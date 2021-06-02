#include "DxLib.h"
#include "../library/t2klib.h"
#include "../support/Support.h"
#include "00.SceneMgr.h"
#include"02.Chapter.h"
#include "03.Novel_1.h"
#include "03.Novel_2.h"
#include "03.Novel_3.h"
#include "03.Novel_4.h"
#include "03.Novel_99_Modules.h"

//【関数】会話ボックスに入るようにセリフを入れる関数・セリフを関数で渡して表示
void::NovelModules::Novel(std::string a, std::string b, std::string c, std::string d) {

	std::string ss1 = a;	//名前
	std::string sss[] = { b,c,d };	//一行30行まで	
	DrawStringEx(230, 475, -1, "%s", ss1.c_str());

	for (int i = 0; i < 3; i++) {

		DrawStringEx(200, 540 + (i * 30), -1, "%s", sss[i].c_str());
	}

}

void::NovelModules::Novel_Init(NovelModules* novel) {

	
	//立ち絵
	novel->Tatie_00_H = LoadGraph("graphics/Tatie/Tatie_00_H-min.png");
	novel->Tatie_00_S = LoadGraph("graphics/Tatie/Tatie_00_S-min.png");
	novel->Tatie_00_I_1 = LoadGraph("graphics/Tatie/Tatie_00_I_1-min.png");
	novel->Tatie_00_I_2 = LoadGraph("graphics/Tatie/Tatie_00_I_2-min.png");
	novel->Tatie_00_A = LoadGraph("graphics/Tatie/Tatie_00_A-min.png");


	novel->Tatie_01_H = LoadGraph("graphics/Tatie/Tatie_01_H-min.png");
	novel->Tatie_01_I = LoadGraph("graphics/Tatie/Tatie_01_I-min.png");
	novel->Tatie_01_K = LoadGraph("graphics/Tatie/Tatie_01_K-min.png");
	novel->Tatie_01_S = LoadGraph("graphics/Tatie/Tatie_01_S-min.png");


	novel->Tatie_02_H = LoadGraph("graphics/Tatie/Tatie_02_H-min.png");
	novel->Tatie_02_I = LoadGraph("graphics/Tatie/Tatie_02_I-min.png");
	novel->Tatie_02_K = LoadGraph("graphics/Tatie/Tatie_02_K-min.png");
	novel->Tatie_02_S = LoadGraph("graphics/Tatie/Tatie_02_S-min.png");
	novel->Tatie_03_H_kamen = LoadGraph("graphics/Tatie/Tatie_03_H_kamen-min.png");


	novel->Tatie_03_H = LoadGraph("graphics/Tatie/Tatie_03_H-min.png");
	novel->Tatie_03_I = LoadGraph("graphics/Tatie/Tatie_03_I_kamen-min.png");
	novel->Tatie_03_O = LoadGraph("graphics/Tatie/Tatie_03_O-min.png");
	novel->Tatie_03_S = LoadGraph("graphics/Tatie/Tatie_03_S-min.png");
	novel->Tatie_03_S_2 = LoadGraph("graphics/Tatie/Tatie_03_S_2-min.png");

	novel->Tatie_04_H = LoadGraph("graphics/Tatie/Tatie_04_H-min.png");
	novel->Tatie_04_H_2 = LoadGraph("graphics/Tatie/Tatie_04_H_2-min.png");
	novel->Tatie_04_K = LoadGraph("graphics/Tatie/Tatie_04_K-min.png");


	novel->Tatie_05 = LoadGraph("graphics/Tatie/Tatie_07_K-min.png");

	novel->Tatie_MOBU_H = LoadGraph("graphics/Tatie/Tatie_MOBU_H-min.png");



	
	//背景
	novel->Back_01 = LoadGraph("graphics/bg_haikei_gakkou.png");

	
	//BGM
	novel->Tatie_00_H = LoadGraph("graphics/Tatie/Tatie_00_H-min.png");
	novel->Tatie_00_S = LoadGraph("graphics/Tatie/Tatie_00_S-min.png");
	novel->Tatie_00_I_1 = LoadGraph("graphics/Tatie/Tatie_00_I_1-min.png");
	novel->Tatie_00_I_2 = LoadGraph("graphics/Tatie/Tatie_00_I_2-min.png");
	novel->Tatie_00_A = LoadGraph("graphics/Tatie/Tatie_00_A-min.png");


	novel->Tatie_01_H = LoadGraph("graphics/Tatie/Tatie_01_H-min.png");
	novel->Tatie_01_I = LoadGraph("graphics/Tatie/Tatie_01_I-min.png");
	novel->Tatie_01_K = LoadGraph("graphics/Tatie/Tatie_01_K-min.png");
	novel->Tatie_01_S = LoadGraph("graphics/Tatie/Tatie_01_S-min.png");


	novel->Tatie_02_H = LoadGraph("graphics/Tatie/Tatie_02_H-min.png");
	novel->Tatie_02_I = LoadGraph("graphics/Tatie/Tatie_02_I-min.png");
	novel->Tatie_02_K = LoadGraph("graphics/Tatie/Tatie_02_K-min.png");
	novel->Tatie_02_S = LoadGraph("graphics/Tatie/Tatie_02_S-min.png");


	novel->Tatie_03_H_kamen = LoadGraph("graphics/Tatie/Tatie_03_H_kamen-min.png");


	novel->Tatie_03_H = LoadGraph("graphics/Tatie/Tatie_03_H-min.png");
	novel->Tatie_03_I = LoadGraph("graphics/Tatie/Tatie_03_I_kamen-min.png");
	novel->Tatie_03_O = LoadGraph("graphics/Tatie/Tatie_03_O-min.png");
	novel->Tatie_03_S = LoadGraph("graphics/Tatie/Tatie_03_S-min.png");
	novel->Tatie_03_S_2 = LoadGraph("graphics/Tatie/Tatie_03_S_2-min.png");

	novel->Tatie_04_H = LoadGraph("graphics/Tatie/Tatie_04_H-min.png");
	novel->Tatie_04_H_2 = LoadGraph("graphics/Tatie/Tatie_04_H_2-min.png");
	novel->Tatie_04_K = LoadGraph("graphics/Tatie/Tatie_04_K-min.png");

	novel->Tatie_04_02_H = LoadGraph("graphics/Tatie/Tatie_04_02_H-min.png");
	novel->Tatie_04_02_H_2 = LoadGraph("graphics/Tatie/Tatie_04_02_H_2-min.png");
	novel->Tatie_04_02_K = LoadGraph("graphics/Tatie/Tatie_04_02_K-min.png");


	novel->Tatie_05 = LoadGraph("graphics/Tatie/Tatie_07_K-min.png");

	novel->Tatie_MOBU_H = LoadGraph("graphics/Tatie/Tatie_MOBU_H-min.png");


	novel->Back_01 = LoadGraph("graphics/Background/bg_haikei_gakkou-min.png");
	novel->Back_02 = LoadGraph("graphics/Background/bg_haikei_tika-min.png");
	novel->Back_03 = LoadGraph("graphics/Background/bg_haikei_kyousitu-min.png");
	novel->Back_04 = LoadGraph("graphics/Background/bg_haikei_rouka-min.png");
	novel->Back_05 = LoadGraph("graphics/Background/bg_haikei_sakura-min.png");


	novel->BGM1 = LoadSoundMem("sound/BGM1.mp3");
	novel->BGM2 = LoadSoundMem("sound/BGM2.mp3");
	novel->BGM3 = LoadSoundMem("sound/BGM3.mp3");
	novel->BGM4 = LoadSoundMem("sound/BGM4.mp3");
	novel->BGM5 = LoadSoundMem("sound/BGM5.mp3");


}


void::NovelModules::Novel_Fin(NovelModules* novel) {

	DeleteGraph(novel->Tatie_00_H);
	DeleteGraph(novel->Tatie_00_S);
	DeleteGraph(novel->Tatie_00_I_1);
	DeleteGraph(novel->Tatie_00_I_2);
	DeleteGraph(novel->Tatie_00_A);

	DeleteGraph(novel->Tatie_01_H);
	DeleteGraph(novel->Tatie_01_I);
	DeleteGraph(novel->Tatie_01_K);
	DeleteGraph(novel->Tatie_01_S);


	DeleteGraph(novel->Tatie_02_H);
	DeleteGraph(novel->Tatie_02_I);
	DeleteGraph(novel->Tatie_02_K);
	DeleteGraph(novel->Tatie_02_S);

	DeleteGraph(novel->Tatie_03_H_kamen);

	DeleteGraph(novel->Tatie_03_H);
	DeleteGraph(novel->Tatie_03_I);
	DeleteGraph(novel->Tatie_03_O);
	DeleteGraph(novel->Tatie_03_S);
	DeleteGraph(novel->Tatie_03_S_2);
	

	DeleteGraph(novel->Tatie_04_H);
	DeleteGraph(novel->Tatie_04_H_2);
	DeleteGraph(novel->Tatie_04_K);

	DeleteGraph(novel->Tatie_04_02_H);
	DeleteGraph(novel->Tatie_04_02_H_2);
	DeleteGraph(novel->Tatie_04_02_K);


	DeleteGraph(novel->Tatie_05);
	DeleteGraph(novel->Tatie_MOBU_H);


	DeleteGraph(novel->Back_01);
	DeleteGraph(novel->Back_02);
	DeleteGraph(novel->Back_03);
	DeleteGraph(novel->Back_04);
	DeleteGraph(novel->Back_05);


	DeleteSoundMem(novel->BGM1);
	DeleteSoundMem(novel->BGM2);
	DeleteSoundMem(novel->BGM3);
	DeleteSoundMem(novel->BGM4);
	DeleteSoundMem(novel->BGM5);






}



void::NovelModules::Tatie_LEFT(int tatie) {


	DrawRotaGraph(200, 450, 1.0f, 0, tatie, true);


}

void::NovelModules::Tatie_CENTER(int tatie) {



	DrawRotaGraph(500, 450, 1.0f, 0, tatie, true);


}

void::NovelModules::Tatie_Right(int tatie) {


	DrawRotaGraph(800, 450, 1.0f, 0, tatie, true);


}

void::NovelModules::Tatie_BACKIMAGE(int tatie) {


	DrawRotaGraph(600, 150, 1.0f, 0, tatie, true);


}
