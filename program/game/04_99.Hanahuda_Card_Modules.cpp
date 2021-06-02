#include "DxLib.h"
#include "../library/t2klib.h"
#include "../support/Support.h"
#include "00.SceneMgr.h"
#include "02.Chapter.h"
#include "04_01.HanahudaMgr.h"
#include "04_99.Hanahuda_Card_Modules.h"
#include "04_99.Hanahuda_battle_Modules.h"
#include "04_99.Hanahuda_Score_Modules.h"


//花札の初期化
void Hanahuda_Card::Card_Modules_Initialize() {

	for (int i = 0; i < 2; i++) {

		for (int p = 0; p < 3; p++) {


			for (int k = 0; k < 48; k++) {


				if (i == 0) {


					if (p == 0) {	//赤（パー）

						if (k == 0) {

							Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_1_1-min.png");

						}
						if (k == 1) {

							Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_1_2-min.png");


						}
						if (k == 2) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_1_3-min.png");
							}

						}
						if (k == 3) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_1_4-min.png");
							}

						}
						if (k == 4) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_2_1-min.png");
							}


						}

						if (k == 5) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_2_2-min.png");
							}


						}

						if (k == 6) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_2_3-min.png");
							}


						}

						if (k == 7) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_2_4-min.png");
							}


						}

						if (k == 8) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_3_1-min.png");
							}


						}

						if (k == 9) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_3_2-min.png");
							}


						}

						if (k == 10) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_3_3-min.png");
							}


						}

						if (k == 11) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_3_4-min.png");
							}


						}

						if (k == 12) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_4_1-min.png");
							}


						}

						if (k == 13) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_4_2-min.png");
							}


						}

						if (k == 14) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_4_3-min.png");
							}


						}

						if (k == 15) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_4_4-min.png");
							}


						}

						if (k == 16) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_5_1-min.png");
							}


						}

						if (k == 17) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_5_2-min.png");
							}


						}

						if (k == 18) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_5_3-min.png");
							}


						}

						if (k == 19) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_5_4-min.png");
							}


						}

						if (k == 20) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_6_1-min.png");
							}


						}

						if (k == 21) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_6_2-min.png");
							}


						}

						if (k == 22) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_6_3-min.png");
							}


						}

						if (k == 23) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_6_4-min.png");
							}


						}

						if (k == 24) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_7_1-min.png");
							}


						}

						if (k == 25) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_7_2-min.png");
							}


						}

						if (k == 26) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_7_3-min.png");
							}


						}

						if (k == 27) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_7_4-min.png");
							}


						}

						if (k == 28) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_8_1-min.png");
							}


						}

						if (k == 29) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_8_2-min.png");
							}


						}

						if (k == 30) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_8_3-min.png");
							}


						}

						if (k == 31) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_8_4-min.png");
							}


						}

						if (k == 32) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_9_1-min.png");
							}


						}

						if (k == 33) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_9_2-min.png");
							}


						}

						if (k == 34) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_9_3-min.png");
							}


						}

						if (k == 35) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_9_4-min.png");
							}


						}

						if (k == 36) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_10_1-min.png");
							}


						}

						if (k == 37) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_10_2-min.png");
							}


						}

						if (k == 38) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_10_3-min.png");
							}


						}

						if (k == 39) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_10_4-min.png");
							}


						}

						if (k == 40) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_11_1-min.png");
							}


						}

						if (k == 41) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_11_2-min.png");
							}


						}

						if (k == 42) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_11_3-min.png");
							}


						}

						if (k == 43) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_11_4-min.png");
							}


						}

						if (k == 44) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_12_1-min.png");
							}


						}

						if (k == 45) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_12_2-min.png");
							}


						}

						if (k == 46) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_12_3-min.png");
							}


						}

						if (k == 47) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_1RED_PAR_12_4-min.png");
							}


						}

					}
					if (p == 1) {	//グー

						if (k == 0) {

							Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_1_1-min.png");

						}
						if (k == 1) {

							Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_1_2-min.png");


						}
						if (k == 2) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_1_3-min.png");
							}

						}
						if (k == 3) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_1_4-min.png");
							}

						}
						if (k == 4) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_2_1-min.png");
							}


						}

						if (k == 5) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_2_2-min.png");
							}


						}

						if (k == 6) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_2_3-min.png");
							}


						}

						if (k == 7) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_2_4-min.png");
							}


						}

						if (k == 8) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_3_1-min.png");
							}


						}

						if (k == 9) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_3_2-min.png");
							}


						}

						if (k == 10) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_3_3-min.png");
							}


						}

						if (k == 11) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_3_4-min.png");
							}


						}

						if (k == 12) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_4_1-min.png");
							}


						}

						if (k == 13) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_4_2-min.png");
							}


						}

						if (k == 14) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_4_3-min.png");
							}


						}

						if (k == 15) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_4_4-min.png");
							}


						}

						if (k == 16) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_5_1-min.png");
							}


						}

						if (k == 17) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_5_2-min.png");
							}


						}

						if (k == 18) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_5_3-min.png");
							}


						}

						if (k == 19) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_5_4-min.png");
							}


						}

						if (k == 20) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_6_1-min.png");
							}


						}

						if (k == 21) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_6_2-min.png");
							}


						}

						if (k == 22) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_6_3-min.png");
							}


						}

						if (k == 23) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_6_4-min.png");
							}


						}

						if (k == 24) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_7_1-min.png");
							}


						}

						if (k == 25) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_7_2-min.png");
							}


						}

						if (k == 26) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_7_3-min.png");
							}


						}

						if (k == 27) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_7_4-min.png");
							}


						}

						if (k == 28) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_8_1-min.png");
							}


						}

						if (k == 29) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_8_2-min.png");
							}


						}

						if (k == 30) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_8_3-min.png");
							}


						}

						if (k == 31) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_8_4-min.png");
							}


						}

						if (k == 32) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_9_1-min.png");
							}


						}

						if (k == 33) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_9_2-min.png");
							}


						}

						if (k == 34) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_9_3-min.png");
							}


						}

						if (k == 35) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_9_4-min.png");
							}


						}

						if (k == 36) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_10_1-min.png");
							}


						}

						if (k == 37) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_10_2-min.png");
							}


						}

						if (k == 38) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_10_3-min.png");
							}


						}

						if (k == 39) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_10_4-min.png");
							}


						}

						if (k == 40) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_11_1-min.png");
							}


						}

						if (k == 41) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_11_2-min.png");
							}


						}

						if (k == 42) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_11_3-min.png");
							}


						}

						if (k == 43) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_11_4-min.png");
							}


						}

						if (k == 44) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_12_1-min.png");
							}


						}

						if (k == 45) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_12_2-min.png");
							}


						}

						if (k == 46) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_12_3-min.png");
							}


						}

						if (k == 47) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_2GREEN_GU_12_4-min.png");
							}


						}


					}
					if (p == 2) {	//チョキ


						if (k == 0) {

							Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_1_1-min.png");

						}
						if (k == 1) {

							Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_1_2-min.png");


						}
						if (k == 2) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_1_3-min.png");
							}

						}
						if (k == 3) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_1_4-min.png");
							}

						}
						if (k == 4) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_2_1-min.png");
							}


						}

						if (k == 5) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_2_2-min.png");
							}


						}

						if (k == 6) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_2_3-min.png");
							}


						}

						if (k == 7) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_2_4-min.png");
							}


						}

						if (k == 8) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_3_1-min.png");
							}


						}

						if (k == 9) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_3_2-min.png");
							}


						}

						if (k == 10) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_3_3-min.png");
							}


						}

						if (k == 11) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_3_4-min.png");
							}


						}

						if (k == 12) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_4_1-min.png");
							}


						}

						if (k == 13) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_4_2-min.png");
							}


						}

						if (k == 14) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_4_3-min.png");
							}


						}

						if (k == 15) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_4_4-min.png");
							}


						}

						if (k == 16) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_5_1-min.png");
							}


						}

						if (k == 17) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_5_2-min.png");
							}


						}

						if (k == 18) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_5_3-min.png");
							}


						}

						if (k == 19) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_5_4-min.png");
							}


						}

						if (k == 20) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_6_1-min.png");
							}


						}

						if (k == 21) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_6_2-min.png");
							}


						}

						if (k == 22) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_6_3-min.png");
							}


						}

						if (k == 23) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_6_4-min.png");
							}


						}

						if (k == 24) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_7_1-min.png");
							}


						}

						if (k == 25) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_7_2-min.png");
							}


						}

						if (k == 26) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_7_3-min.png");
							}


						}

						if (k == 27) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_7_4-min.png");
							}


						}

						if (k == 28) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_8_1-min.png");
							}


						}

						if (k == 29) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_8_2-min.png");
							}


						}

						if (k == 30) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_8_3-min.png");
							}


						}

						if (k == 31) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_8_4-min.png");
							}


						}

						if (k == 32) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_9_1-min.png");
							}


						}

						if (k == 33) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_9_2-min.png");
							}


						}

						if (k == 34) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_9_3-min.png");
							}


						}

						if (k == 35) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_9_4-min.png");
							}


						}

						if (k == 36) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_10_1-min.png");
							}


						}

						if (k == 37) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_10_2-min.png");
							}


						}

						if (k == 38) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_10_3-min.png");
							}


						}

						if (k == 39) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_10_4-min.png");
							}


						}

						if (k == 40) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_11_1-min.png");
							}


						}

						if (k == 41) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_11_2-min.png");
							}


						}

						if (k == 42) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_11_3-min.png");
							}


						}

						if (k == 43) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_11_4-min.png");
							}


						}

						if (k == 44) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_12_1-min.png");
							}


						}

						if (k == 45) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_12_2-min.png");
							}


						}

						if (k == 46) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_12_3-min.png");
							}


						}

						if (k == 47) {


							{
								Card[i][k][p] = LoadGraph("graphics/Card_A/Card_3BLUE_CHOKI_12_4-min.png");
							}


						}


					}

				}
				else if (i == 1) {

					{
						Card[i][k][p] = LoadGraph("graphics/Card_A/Card_4_ura.png");
					}


				}




			}

		}




	}


}

//花札の終了処理
void Hanahuda_Card::Card_Modules_Finalize() {

	for (int i = 0; i < 2; i++) {


		for (int k = 0; k < 5; k++) {



			for (int p = 0; p < 3; p++) {



				DeleteGraph(Card[i][k][p]);


			}



		}




	}







}