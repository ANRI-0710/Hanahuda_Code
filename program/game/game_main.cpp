#include "DxLib.h"
#include "../library/t2klib.h"
#include "../support/Support.h"
#include "game_main.h"
#include "00.SceneMgr.h"


bool init = false;
int r = 0;

//シーン遷移の際、音楽が連続再生しないように制御する終了処理
//void Fin_test() {
//
//    SceneMgr_Finalize();
//
// }


void gameMain(float deltatime) {
 
    if (init == false) {
        
        SceneMgr_Initialize();
        init = true;
    }
    
    SceneMgr_Update();       
    SceneMgr_Draw();
 
 }

  


    




    

