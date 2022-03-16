#ifndef CDRUVERFUKUSHIMA_H
#define CDRUVERFUKUSHIMA_H


//背景スクロールスピード
#define SCROLL_SPEED -2.0


#include"CMap.h"
#include"CEnemy.h"
#include "CBackGround.h"
#include"CTaskManager.h"
#include<time.h>
#include<stdlib.h>



class CDriverFukushima {
private:
	int mEnemyTypeRand;
	int mEnemyMakeRand;
	int mMakeRand;
	int mEy;
	int mEnemydepth;
	int mMakeTime;
public:

	void Init()
	{
		//奥の背景
		//背景クラスのメンバ変数への代入
		CBackGround* BackGround = new CBackGround();
		//スクリーンに値を設定
		BackGround->x = 0;
		BackGround->y = -25;
		//有効にする
		BackGround->mEnabled = true;

		//スクロールする手前の背景
		//背景クラスのメンバ変数への代入
		CBackGround2* BackGround2 = new CBackGround2();
		//スクリーンに値を設定
		BackGround2->x = 0;
		BackGround2->y = -125;
		BackGround2->speed = SCROLL_SPEED;
		//有効にする
		BackGround2->mEnabled = true;

		//スクロールする手前の背景
		//背景クラスのメンバ変数への代入
		CBackGround2* BackGround3 = new CBackGround2();
		//スクリーンに値を設定
		BackGround3->x = 1920;
		BackGround3->y = -125;
		BackGround3->speed = SCROLL_SPEED;
		//有効にする
		BackGround3->mEnabled = true;

		//マップの背景(ステージ)
		//背景クラスのメンバ変数への代入
		CBackGround3* BackGround4 = new CBackGround3();
		//スクリーンに値を設定
		BackGround4->x = 0;
		BackGround4->y = -100;
		BackGround4->speed = SCROLL_SPEED;
		//有効にする
		BackGround4->mEnabled = true;

		//マップの背景(ステージ)
		//背景クラスのメンバ変数への代入
		CBackGround3* BackGround5 = new CBackGround3();
		//スクリーンに値を設定
		BackGround5->x = 1920;
		BackGround5->y = -100;
		BackGround5->speed = SCROLL_SPEED;
		//有効にする
		BackGround5->mEnabled = true;

		

	}

	void Update() {
		mEnemyMakeRand = rand() % 3 + 1;
		mMakeRand = (rand() % 100) - 1;
		srand((unsigned)time(NULL));
		if (mEnemyMakeRand == 1)
		{
			mEy = -60;
			mEnemydepth = 1;
		}
		if (mEnemyMakeRand == 2)
		{
			mEy = -180;
			mEnemydepth = 2;
		}
		if (mEnemyMakeRand == 3)
		{
			mEy = -360;
			mEnemydepth = 3;
		}
			if (mMakeRand >= 0 && mMakeRand <= 33 && mMakeTime % 180 == 60) {
				//スライム
				//エネミークラスのメンバ変数への代入
				CEnemy1* Enemy = new CEnemy1();
				//乱数値=rand()%乱数値の要素数+乱数値の最小値
				srand((unsigned)time(NULL));
				mEnemyTypeRand = rand() % 3 - 1;
				Enemy->mEnemytype = mEnemyTypeRand;
				//敵に値を設定
				Enemy->x = 980;
				Enemy->y = mEy;
				Enemy->z = mEnemydepth;
				Enemy->w = 100;
				Enemy->h = 100;
				Enemy->mFx = -2;
				//有効にする
				Enemy->mEnabled = true;
			}
		
			if (mMakeRand >= 34 && mMakeRand <= 66 && mMakeTime % 210 == 70) {
				//スケルトン
				//エネミークラスのメンバ変数への代入
				CEnemy2* Enemy2 = new CEnemy2();
				//敵に値を設定
				Enemy2->x = 980;
				Enemy2->y = mEy;
				Enemy2->z = mEnemydepth;
				Enemy2->w = 160;
				Enemy2->h = 120;
				Enemy2->mFx = -2;
				//有効にする
				Enemy2->mEnabled = true;
			}
		
		
			if (mMakeRand >= 67 && mMakeRand <= 99 && mMakeTime % 270 == 90) {
				//ゾンビ
				//エネミークラスのメンバ変数への代入
				CEnemy3* Enemy3 = new CEnemy3();
				//敵に値を設定
				Enemy3->x = 980;
				Enemy3->y = mEy;
				Enemy3->z = mEnemydepth;
				Enemy3->w = 160;
				Enemy3->h = 120;
				Enemy3->mFx = -2;
				//有効にする
				Enemy3->mEnabled = true;
			}
			mMakeTime = mMakeTime + 1;
		
	}
	




	//for (int i = 0; i < 1; i++)
	//{
	//	int EnemyMap2[3][9]
	//	{
	//		{1,0,0,0,3,0,0,2,},
	//		{0,0,1,0,0,0,3,0,},
	//		{0,2,0,0,0,2,0,0,},
	//	};
	//	if (mEnemyMapRand >= 16 && mEnemyMapRand <= 32 && mEnemyMakeFlag == 0) {
	//		mEnemyTypeRand = rand() % 3 - 1;
	//		mEnemyMapRand = (rand() % 100) + 1;
	//		for (int j = 0; j < 3; j++) {
	//			for (int k = 0; k < 9; k++) {
	//				if (EnemyMap2[j][k] == 1) {
	//					//スライム
	//					//エネミークラスのメンバ変数への代入
	//					CEnemy1* Enemy4 = new CEnemy1();
	//					Enemy4->mEnemytype = mEnemyTypeRand;
	//					mEnemyMakeFlag += 1;
	//					//敵に値を設定
	//					Enemy4->x = k * 320 + 960;
	//					Enemy4->y = j * -200 - 30;
	//					Enemy4->w = 100;
	//					Enemy4->h = 100;
	//					Enemy4->mFx = -2;
	//					//有効にする
	//					Enemy4->mEnabled = true;
	//				}
	//				if (EnemyMap2[j][k] == 2) {
	//					//スケルトン
	//					//エネミークラスのメンバ変数への代入
	//					CEnemy2* Enemy5 = new CEnemy2();
	//					mEnemyMakeFlag += 1;
	//					//敵に値を設定
	//					Enemy5->x = k * 320 + 960;
	//					Enemy5->y = j * -160 - 30;
	//					Enemy5->w = 160;
	//					Enemy5->h = 120;
	//					Enemy5->mFx = -2;
	//					//有効にする
	//					Enemy5->mEnabled = true;
	//				}
	//				if (EnemyMap2[j][k] == 3) {
	//					//ゾンビ
	//					//エネミークラスのメンバ変数への代入
	//					CEnemy3* Enemy6 = new CEnemy3();
	//					mEnemyMakeFlag += 1;
	//					//敵に値を設定
	//					Enemy6->x = k * 320 + 960;
	//					Enemy6->y = j * -160 - 30;
	//					Enemy6->w = 160;
	//					Enemy6->h = 120;
	//					Enemy6->mFx = -2;
	//					//有効にする
	//					Enemy6->mEnabled = true;
	//				}
	//			}
	//		}
	//	}
	//	break;
	//	mEnemyTypeRand = rand() % 3 - 1;
	//	mEnemyMapRand = (rand() % 100) + 1;
	//}

	//for (int i = 0; i < 1; i++)
	//{
	//	int EnemyMap3[3][9]
	//	{
	//		{3,0,0,0,1,0,0,0,},
	//		{0,0,2,0,0,0,1,0,},
	//		{0,2,0,1,3,0,0,2,},
	//	};
	//	if (mEnemyMapRand >= 32 && mEnemyMapRand <= 48 && mEnemyMakeFlag == 0) {
	//		for (int j = 0; j < 3; j++) {
	//			for (int k = 0; k < 9; k++) {
	//				if (EnemyMap3[j][k] == 1) {
	//					//スライム
	//					//エネミークラスのメンバ変数への代入
	//					CEnemy1* Enemy7 = new CEnemy1();
	//					Enemy7->mEnemytype = mEnemyTypeRand;
	//					mEnemyMakeFlag += 1;
	//					//敵に値を設定
	//					Enemy7->x = k * 320 + 960;
	//					Enemy7->y = j * -200 - 30;
	//					Enemy7->w = 100;
	//					Enemy7->h = 100;
	//					Enemy7->mFx = -2;
	//					//有効にする
	//					Enemy7->mEnabled = true;
	//				}
	//				if (EnemyMap3[j][k] == 2) {
	//					//スケルトン
	//					//エネミークラスのメンバ変数への代入
	//					CEnemy2* Enemy8 = new CEnemy2();
	//					mEnemyMakeFlag += 1;
	//					//敵に値を設定
	//					Enemy8->x = k * 320 + 960;
	//					Enemy8->y = j * -160 - 30;
	//					Enemy8->w = 160;
	//					Enemy8->h = 120;
	//					Enemy8->mFx = -2;
	//					//有効にする
	//					Enemy8->mEnabled = true;
	//				}
	//				if (EnemyMap3[j][k] == 3) {
	//					//ゾンビ
	//					//エネミークラスのメンバ変数への代入
	//					CEnemy3* Enemy9 = new CEnemy3();
	//					mEnemyMakeFlag += 1;
	//					//敵に値を設定
	//					Enemy9->x = k * 320 + 960;
	//					Enemy9->y = j * -160 - 30;
	//					Enemy9->w = 160;
	//					Enemy9->h = 120;
	//					Enemy9->mFx = -2;
	//					//有効にする
	//					Enemy9->mEnabled = true;
	//				}
	//			}
	//		}

	//	}
	//	break;
	//	mEnemyTypeRand = rand() % 3 - 1;
	//	mEnemyMapRand = (rand() % 100) + 1;
	//}


	//for (int i = 0; i < 1; i++)
	//{
	//	int EnemyMap4[3][9]
	//	{
	//		{2,0,0,3,0,1,0,3,},
	//		{0,0,1,0,0,0,0,0,},
	//		{0,3,0,0,1,0,2,0,},
	//	};
	//	if (mEnemyMapRand >= 48 && mEnemyMapRand <= 64 && mEnemyMakeFlag == 0) {
	//		for (int j = 0; j < 3; j++) {
	//			for (int k = 0; k < 9; k++) {
	//				if (EnemyMap4[j][k] == 1) {
	//					CEnemy1* Enemy = new CEnemy1();
	//					//スライム
	//					//エネミークラスのメンバ変数への代入
	//					CEnemy1* Enemy10 = new CEnemy1();
	//					Enemy->mEnemytype = mEnemyTypeRand;
	//					mEnemyMakeFlag += 1;
	//					//敵に値を設定
	//					Enemy10->x = k * 320 + 960;
	//					Enemy10->y = j * -200 - 30;
	//					Enemy10->w = 100;
	//					Enemy10->h = 100;
	//					Enemy10->mFx = -2;
	//					//有効にする
	//					Enemy10->mEnabled = true;
	//				}
	//				if (EnemyMap4[j][k] == 2) {
	//					//スケルトン
	//					//エネミークラスのメンバ変数への代入
	//					CEnemy2* Enemy11 = new CEnemy2();
	//					mEnemyMakeFlag += 1;
	//					//敵に値を設定
	//					Enemy11->x = k * 320 + 960;
	//					Enemy11->y = j * -160 - 30;
	//					Enemy11->w = 160;
	//					Enemy11->h = 120;
	//					Enemy11->mFx = -2;
	//					//有効にする
	//					Enemy11->mEnabled = true;
	//				}
	//				if (EnemyMap4[j][k] == 3) {
	//					//ゾンビ
	//					//エネミークラスのメンバ変数への代入
	//					CEnemy3* Enemy12 = new CEnemy3();
	//					mEnemyMakeFlag += 1;
	//					//敵に値を設定
	//					Enemy12->x = k * 320 + 960;
	//					Enemy12->y = j * -160 - 30;
	//					Enemy12->w = 160;
	//					Enemy12->h = 120;
	//					Enemy12->mFx = -2;
	//					//有効にする
	//					Enemy12->mEnabled = true;
	//				}
	//			}
	//		}
	//	}
	//	break;
	//	mEnemyTypeRand = rand() % 3 - 1;
	//	mEnemyMapRand = (rand() % 100) + 1;
	//}
	//for (int i = 0; i < 1; i++)
	//{
	//	int EnemyMap5[3][9]
	//	{
	//		{0,2,0,3,0,0,3,0,},
	//		{2,0,0,0,3,0,0,0,},
	//		{0,0,3,0,0,3,0,0,},
	//	};
	//	if (mEnemyMapRand >= 64 && mEnemyMapRand <= 80 && mEnemyMakeFlag == 0) {
	//		for (int j = 0; j < 3; j++) {
	//			for (int k = 0; k < 9; k++) {
	//				if (EnemyMap5[j][k] == 1) {
	//					//スライム
	//					//エネミークラスのメンバ変数への代入
	//					CEnemy1* Enemy13 = new CEnemy1();
	//					Enemy13->mEnemytype = mEnemyTypeRand;
	//					mEnemyMakeFlag += 1;
	//					//敵に値を設定
	//					Enemy13->x = k * 320 + 960;
	//					Enemy13->y = j * -200 - 30;
	//					Enemy13->w = 100;
	//					Enemy13->h = 100;
	//					Enemy13->mFx = -2;
	//					//有効にする
	//					Enemy13->mEnabled = true;
	//				}
	//				if (EnemyMap5[j][k] == 2) {
	//					//スケルトン
	//					//エネミークラスのメンバ変数への代入
	//					CEnemy2* Enemy14 = new CEnemy2();
	//					mEnemyMakeFlag += 1;
	//					//敵に値を設定
	//					Enemy14->x = k * 320 + 960;
	//					Enemy14->y = j * -160 - 30;
	//					Enemy14->w = 160;
	//					Enemy14->h = 120;
	//					Enemy14->mFx = -2;
	//					//有効にする
	//					Enemy14->mEnabled = true;
	//				}
	//				if (EnemyMap5[j][k] == 3) {
	//					//ゾンビ
	//					//エネミークラスのメンバ変数への代入
	//					CEnemy3* Enemy15 = new CEnemy3();
	//					mEnemyMakeFlag += 1;
	//					//敵に値を設定
	//					Enemy15->x = k * 320 + 960;
	//					Enemy15->y = j * -160 - 30;
	//					Enemy15->w = 160;
	//					Enemy15->h = 120;
	//					Enemy15->mFx = -2;
	//					//有効にする
	//					Enemy15->mEnabled = true;
	//				}
	//			}
	//		}

	//	}
	//	break;
	//	mEnemyTypeRand = rand() % 3 - 1;
	//	mEnemyMapRand = (rand() % 100) + 1;
	//}

	//for (int i = 0; i < 1; i++)
	//{
	//	int EnemyMap6[3][9]
	//	{
	//		{0,3,0,0,0,3,0,0,},
	//		{1,0,0,2,0,0,2,0,},
	//		{0,0,2,0,0,3,0,0,},
	//	};
	//	if (mEnemyMapRand >= 80 && mEnemyMapRand <= 100 && mEnemyMakeFlag == 0) {
	//		mEnemyTypeRand = rand() % 3 - 1;
	//		mEnemyMapRand = (rand() % 100) + 1;
	//		for (int j = 0; j < 3; j++) {
	//			for (int k = 0; k < 9; k++) {
	//				if (EnemyMap6[j][k] == 1) {
	//					//スライム
	//					//エネミークラスのメンバ変数への代入
	//					CEnemy1* Enemy16 = new CEnemy1();
	//					Enemy16->mEnemytype = mEnemyTypeRand;
	//					mEnemyMakeFlag += 1;
	//					//敵に値を設定
	//					Enemy16->x = k * 320 + 960;
	//					Enemy16->y = j * -200 - 40;
	//					Enemy16->w = 100;
	//					Enemy16->h = 100;
	//					Enemy16->mFx = -2;
	//					//有効にする
	//					Enemy16->mEnabled = true;
	//				}
	//				if (EnemyMap6[j][k] == 2) {
	//					//スケルトン
	//					//エネミークラスのメンバ変数への代入
	//					CEnemy2* Enemy17 = new CEnemy2();
	//					mEnemyMakeFlag += 1;
	//					//敵に値を設定
	//					Enemy17->x = k * 320 + 960;
	//					Enemy17->y = j * -160 - 30;
	//					Enemy17->w = 160;
	//					Enemy17->h = 120;
	//					Enemy17->mFx = -2;
	//					//有効にする
	//					Enemy17->mEnabled = true;
	//				}
	//				if (EnemyMap6[j][k] == 3) {
	//					//ゾンビ
	//					//エネミークラスのメンバ変数への代入
	//					CEnemy3* Enemy18 = new CEnemy3();
	//					mEnemyMakeFlag += 1;
	//					//敵に値を設定
	//					Enemy18->x = k * 320 + 960;
	//					Enemy18->y = j * -160 - 30;
	//					Enemy18->w = 160;
	//					Enemy18->h = 120;
	//					Enemy18->mFx = -2;
	//					//有効にする
	//					Enemy18->mEnabled = true;
	//				}
	//			}
	//		}
	//	}
	//	break;
	//	mEnemyTypeRand = rand() % 3 - 1;
	//	mEnemyMapRand = (rand() % 100) + 1;
	//}


	
};
#endif 

