#pragma once

//---------------------------------------------
//花札ゲームに使用するモジュール（画像・演出・関数）を集約したクラス
//---------------------------------------------

//花札の表と裏の管理
typedef enum {
	eCard_Omote,
	eCard_URA,
	eCard_OU_NUM,
}Card_UR;


//3すくみ
typedef enum {
	eJanken_RED,//パー
	eJanken_GREEN,	//グー
	eJanken_BLUE,
	eJanken_NUM,	//チョキ

}Janken_3sukumi;

//花札の役
typedef enum {
	eCard_Jan_1,
	eCard_Mar_1,
	eCard_Sep_1,
	eCard_Nov_1,
	eCard_Dec_1,
	eCard_NUM,

}Card_type;

//ゲーム内シーン遷移
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

//自分及び敵のHP
typedef enum {

	MAXHP_1 = 5000,

}MAXHP;


//プレイヤークラス
class Player {
public:

	//シーン管理
	int MainScene_ = Progress0;
	
	//HP管理
	int HP = 0;
	float HP_now;
	int HP_var = 0;

	//攻撃する点数（役）
	int TotalScore = 0;

	//攻撃する点数（3すくみ）
	int Total_3_Score = 0;

	int Back_Image = 0;

	//攻撃用立ち絵
	int Attack_Image = 0;
	int Attack_Effect[8] = {0};
	int Attck_E_anim = 0;
	int Attck_Sound = 0;
	float Attack_E_time =  0;

	//フォント
	int Font_Meicho = 0;
	int Font_Meicho_big = 0;

	//攻撃用立ち絵座標管理
	int AT_pos_x = 30;
	int AT_pos_y = 700;

	//攻撃用立ち絵カウンターと制御
	int AT_counter = 0;
	int AT_speed_1 = 50;
	int AT_speed_2 = 60;
	bool AT_Wait[3] = { 0 };

	//攻撃・回復メニュー
	int NowSelect_M = 0;
	int pos_x_M = 0;
	int pos_y_M = 0;
	
	int NowSelect_Kaihuku = 0;
	int Kihuku_small = 3;
	int Kihuku_Midium = 1;
	int Kihuku_Big = 1;

	int pos_x_Kaihuku = 0;
	int pos_y_Kaihuku = 0;
	
	//座標管理
	int cpos_x[8] = { 0 };
	int cpos_y[8] = { 0 };
	
	//花札の配列処理用
	int uraomote = 0;	
	int cYaku_Num = 0;	
	int cYaku_NUM2 = 0;
	int c3_Num1 = 0;	//じゃんけん

	//乱数配列格納
	int YAKU_R[8] = {0};
	int Sukumi_R[8] = {0};
	int YAKU_S[8] = { 0 };

	//初期化用制御
	bool init = false;
	int Progress_S = 0;
	
	//花札を3枚以上出さないようにするための制御
	bool Game_Start = false;
	int Count_3 = 0; //舞台に出す札を3枚までにするためのカウント
	
	//花札を舞台に出しているかの確認・制御用
	bool Huda_UP[8] = { 0 };
	
	//出す花札の配列情報の記録場所・99の場合は、その札が上がってなく、スコア計算から除外される
	int UR_Storage[8] = { 99,99,99,99,99,99,99,99 };
	int YAKU1_Storage[8] = { 99,99,99,99,99,99,99,99 };
	int YAKU2_Storage[8] = { 99,99,99,99,99,99,99,99 };
	int SUKUMI_Storage[8] = { 99,99,99,99,99,99,99,99 };

	int Ene_Sukim_3_Count[3] = { 99,99,99 }; //役

	//役の得点集計用変数
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

	//役の得点集計用変数
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

	//役の成立・攻撃モーション判定用
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

	//役名表示用変数
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


	//3すくみの合計スコア集計用変数
	int PAR_RED_0 = 0;
	int GU_GREEN_1 = 0;
	int CHOKI_BLUE_2 = 0;


	//開始関連の変数
	int Start_time = 0;
	int VS_player_img = 0;
	int VS_enemy_img = 0;
	int start_image = 0;
	int start_BGM[2] = { 0 };

	
	//終了関連の変数
	int fin_image = 0;
	
	int Finish_time[3] = { 0 };		//終了画像・勝利画像を出すときのカウント処理
	
	int Finish_win_image = 0;
	int Finish_win_SE = 0;

	int Finish_lose_image = 0;
	int Finish_lose_SE = 0;

	//ヘルプ用文言
	int HelpImage = 0;
	int HelpImage2 = 0;
	bool Helpbool = 0;

	int Help_Scene_1 = 0;	//ヘルプページ専用変数

	//役一覧リストの表示
	int YakuList = 0;

	//役一覧
	int YAKU_page = 0;

	//戻る
	int GoBack_Num = 0;

	//さんすくみの画像表示
	int Sansukumi;
		
	//【関数】画像・エフェクト初期化処理(ゲームナンバーの数で各ゲームシーンごとに違う画像の割り振りをする)
	void Init_Battle(Player* player, Player* enemy,int GameNum);
	
	//【関数】終了化処理
	void Finalize_Battle(Player* player);
	
	
	//【関数】システムメッセージ管理
	void System_Messeage(Player* player, Player* enemy);


	//【関数】攻撃・回復のメニュー表示
	void Card_Modules_Menu(Player* player);

	//回復メニューの表示
	void Card_Modules_Recovery_Menu(Player* player);

	//回復処理・1ならば小、2ならば中、3なら大を指す
	void Card_Modules_HP_Recovery(Player* player,int kaihukuNum);

	//ヘルプ画面の表示
	void Card_Modules_Help(Player* player,int nowscene);

	//役一覧リストの表示
	void Card_Modules_YakuList(Player* player, int nowscene);

	//ゲームを途中離脱（戻る）場合
	void Card_Modules_Back_Menu(Player* player);
	
	//【関数】乱数初期配置
	void Card_Moudules_First_Place(Player* player);

	//【関数】乱数シャッフル・重複ナシ（花札の種類）
	void Card_Modules_YAKU_shuffle(Player* player, int size);

	//【関数】乱数シャッフル・重複アリ（じゃんけん）
	void Card_Modules_3_shuffle(Player* player,int size);
	
	//【関数】舞台に出した札のみシャッフルをする・また確率調整のため、YAKUNUMの番号によって、3分の1の確率でキャラのテーマに合わせた役がでてくる設定
	void Card_Moudules_YAKU_Reshaffle(Player* player, int size,int YAKUNUM);

	//【関数】自分の役スコアの計算
	void Moudules_Myplayer_YAKUScore_RETURN(Player*);

	//【関数】敵の役スコアの計算
	void Moudules_Enemy_YAKUScore_RETURN(Player* enemy);

	//【関数】敵の役と自分の3すくみの計算をし、カードを出す・猪鹿蝶モデル
	void Moudules_Enemy_Card_Place(Player* player, Player* enemy);

	//【関数】敵の役と自分の3すくみの計算をし、カードを出す・月見に一杯
	void Moudules_Enemy_Card_Place_2(Player* player, Player* enemy);

	//【関数】敵の役と自分の3すくみの計算をし、カードを出す・雨降り三光
	void Moudules_Enemy_Card_Place_3(Player* player, Player* enemy);

	//【関数】敵の役と自分の3すくみの計算をし、カードを出す・三光
	void Moudules_Enemy_Card_Place_4(Player* player, Player* enemy);

	//【関数】自プレイヤーの攻撃処理,TFは、0だったら3すくみのスコア、1だったら役のスコアの攻撃処理を行う
	void Moudules_Player_Attack(Player* player, Player* enemy,int TF);

	//【関数】敵の攻撃処理・0だったら3すくみのスコア、1だったら役のスコアの攻撃処理を行う
	void Moudules_Enemy_Attack(Player* player, Player* enemy,int TF);

	//【関数】3すくみスコアの計算をする
	void Moudules_All_Score_RETURN(Player* player, Player* enemy);

	//【関数】攻撃モーション（すくみ）
	void Modules_Attack_Motion(Player* player,Player* enemy,int scene);

	//【関数】攻撃モーション（役）
	void Modules_Attack_Motion_YAKU(Player* player, Player*, int scene);

	//【関数】攻撃モーション初期化処理
	void Modules_Attack_init(Player* player, Player*);

	//【関数】試合開始関数
	void Modules_Battle_Start(Player* player);
	
	//【関数】勝負ありのリザルト結果を出す
	void Modules_Result(Player* player, Player* enemy,int UNLOCKNUM);

};