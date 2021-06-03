#pragma once

//---------------------------------------------
//ノベルシーンで使用するモジュール（画像/関数）をまとめたクラス
//---------------------------------------------

class NovelModules {
public:

	//主人公・千歳・立ち絵・H（通常）、S（笑顔）、I（怒り）、O（驚き）、K（悲しみ）、A（焦り）
	int Tatie_00_H;
	int Tatie_00_S;
	int Tatie_00_I_1;
	int Tatie_00_I_2;
	int Tatie_00_O;
	int Tatie_00_A;

	//涼花
	int Tatie_01_H; 
	int Tatie_01_I;
	int Tatie_01_K;
	int Tatie_01_S;

	//文香・秋
	int Tatie_02_H;
	int Tatie_02_I;
	int Tatie_02_K;
	int Tatie_02_S;
	
	//冬音（ふゆね）・仮面
	int Tatie_03_H_kamen;
		
	//冬音（ふゆね）・通常
	int Tatie_03_H;
	int Tatie_03_I;
	int Tatie_03_O;
	int Tatie_03_S;
	int Tatie_03_S_2;
	
	//華鈴（かりん）・冬
	int Tatie_04_H;
	int Tatie_04_H_2;
	int Tatie_04_K;

	//華凛・狐版
	int Tatie_04_02_H;
	int Tatie_04_02_H_2;
	int Tatie_04_02_K;
		
	//狐
	int Tatie_05; 
	//モブ
	int Tatie_MOBU_H;

	//BGM
	int BGM1;	//通常・ハッピー
	int BGM2;	//不穏1
	int BGM3;	//不穏2
	int BGM4;	//ラスボス登場
	int BGM5;	//最後

	//背景
	int Back_01;
	int Back_02;
	int Back_03;
	int Back_04;
	int Back_05;

	//会話ボックス
	int kaiwabokkusu;
	int namae;

	//【関数】初期化関数
	void Novel_Init(NovelModules* novel);

	//【関数】初期化関数
	void Novel_Fin(NovelModules* novel);

	//【関数】会話ボックスに入るようにセリフを入れる関数・セリフを関数で渡して表示
	void Novel(std::string a, std::string b, std::string c, std::string d);

	//【関数】
	void Tatie_LEFT(int tatie);

	//【関数】
	void Tatie_CENTER(int tatie);

	//【関数】
	void Tatie_Right(int tatie);
	
	//【関数】
	void Tatie_BACKIMAGE(int tatie);

};
