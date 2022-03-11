#include"CEnemyMap.h"

CEnemyMap::CEnemyMap()
:mEnemyMapRand(0), mEnemyFlag(0), mEnemyTypeRand(0)
{

}

void CEnemyMap::Update()
{

	mEnemyTypeRand = rand() % 3 - 1;
	mEnemyMapRand = (rand() % 100) + 1;
	if (mEnemyMapRand >= 0 && mEnemyMapRand <= 16 && mEnemyFlag == 0) {
		for (int i = 0; i < 1; i++)
		{
			int EnemyMap1[3][9]
			{
				{1,0,0,0,0,2,0,1,},
				{0,0,2,0,0,0,0,0,},
				{3,0,0,1,0,0,3,0,},
			};
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 9; k++) {
					if (EnemyMap1[j][k] == 1) {
						//スライム
						//エネミークラスのメンバ変数への代入
						CEnemy1* Enemy = new CEnemy1();
						Enemy->mEnemytype = mEnemyTypeRand;
						//敵に値を設定
						Enemy->x = k * 160 + 960;
						Enemy->y = j * 113 - 340;
						Enemy->w = 80;
						Enemy->h = 80;
						Enemy->mTag = CRectangle::EENEMY;
						//有効にする
						Enemy->mEnabled = true;
						mEnemyFlag += 1;
					}
					if (EnemyMap1[i][j] == 2) {
						//スケルトン
						//エネミークラスのメンバ変数への代入
						CEnemy2* Enemy2 = new CEnemy2();
						//敵に値を設定
						Enemy2->x = k * 160 + 960;
						Enemy2->y = j * 113 - 340;
						Enemy2->w = 80;
						Enemy2->h = 110;
						Enemy2->mFx = -2;
						//有効にする
						Enemy2->mEnabled = true;
						Enemy2->mTag = CRectangle::EENEMY;
						mEnemyFlag += 1;
					}
					if (EnemyMap1[i][j] == 3) {
						//ゾンビ
						//エネミークラスのメンバ変数への代入
						CEnemy3* Enemy3 = new CEnemy3();
						//敵に値を設定
						Enemy3->x = k * 160 + 960;
						Enemy3->y = j * 113 - 340;
						Enemy3->w = 60;
						Enemy3->h = 120;
						Enemy3->mFx = -2;
						//有効にする
						Enemy3->mEnabled = true;
						Enemy3->mTag = CRectangle::EENEMY;
						mEnemyFlag += 1;
					}
				}
			}
			break;
		}
		
	}
	
	if (mEnemyMapRand >= 16 && mEnemyMapRand <= 32 && mEnemyFlag == 0) {
		for (int i = 0; i < 1; i++)
		{
			int EnemyMap2[3][9]
			{
				{1,0,0,0,3,0,0,2,},
				{0,0,1,0,0,0,3,0,},
				{0,2,0,0,0,2,0,0,},
			};
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 9; k++) {
					if (EnemyMap2[j][k] == 1) {
						CEnemy1* Enemy = new CEnemy1();
						//スライム
						//エネミークラスのメンバ変数への代入
						CEnemy1* Enemy4 = new CEnemy1();
						Enemy4->mEnemytype = mEnemyTypeRand;
						//敵に値を設定
						Enemy4->x = k * 160 + 960;
						Enemy4->y = j * 113 - 340;
						Enemy4->w = 80;
						Enemy4->h = 80;
						Enemy4->mFx = -2;
						//有効にする
						Enemy4->mEnabled = true;
						Enemy4->mTag = CRectangle::EENEMY;
						mEnemyFlag += 1;
					}
					if (EnemyMap2[i][j] == 2) {
						//スケルトン
						//エネミークラスのメンバ変数への代入
						CEnemy2* Enemy5 = new CEnemy2();
						//敵に値を設定
						Enemy5->x = k * 160 + 960;
						Enemy5->y = j * 113 - 340;
						Enemy5->w = 80;
						Enemy5->h = 110;
						Enemy5->mFx = -2;
						//有効にする
						Enemy5->mEnabled = true;
						Enemy5->mTag = CRectangle::EENEMY;
						mEnemyFlag += 1;
					}
					if (EnemyMap2[i][j] == 3) {
						//ゾンビ
						//エネミークラスのメンバ変数への代入
						CEnemy3* Enemy6 = new CEnemy3();
						//敵に値を設定
						Enemy6->x = k * 160 + 960;
						Enemy6->y = j * 113 - 340;
						Enemy6->w = 60;
						Enemy6->h = 120;
						Enemy6->mFx = -2;
						//有効にする
						Enemy6->mEnabled = true;
						Enemy6->mTag = CRectangle::EENEMY;
						mEnemyFlag += 1;
					}
				}
			}
			break;
		}
	}

	if (mEnemyMapRand >= 32 && mEnemyMapRand <= 48 && mEnemyFlag == 0) {
		for (int i = 0; i < 1; i++)
		{
			int EnemyMap3[3][9]
			{
				{3,0,0,0,1,0,0,0,},
				{0,0,2,0,0,0,1,0,},
				{0,2,0,0,3,0,0,2,},
			};
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 9; k++) {
					if (EnemyMap3[j][k] == 1) {
						//スライム
						//エネミークラスのメンバ変数への代入
						CEnemy1* Enemy7 = new CEnemy1();
						Enemy7->mEnemytype = mEnemyTypeRand;
						//敵に値を設定
						Enemy7->x = k * 160 + 960;
						Enemy7->y = j * 113 - 340;
						Enemy7->w = 80;
						Enemy7->h = 80;
						Enemy7->mFx = -2;
						//有効にする
						Enemy7->mEnabled = true;
						Enemy7->mTag = CRectangle::EENEMY;
						mEnemyFlag += 1;
					}
					if (EnemyMap3[j][k] == 2) {
						//スケルトン
						//エネミークラスのメンバ変数への代入
						CEnemy2* Enemy8 = new CEnemy2();
						//敵に値を設定
						Enemy8->x = k * 160 + 960;
						Enemy8->y = j * 113 - 340;
						Enemy8->w = 80;
						Enemy8->h = 110;
						Enemy8->mFx = -2;
						//有効にする
						Enemy8->mEnabled = true;
						Enemy8->mTag = CRectangle::EENEMY;
						mEnemyFlag += 1;
					}
					if (EnemyMap3[j][k] == 3) {
						//ゾンビ
						//エネミークラスのメンバ変数への代入
						CEnemy3* Enemy9 = new CEnemy3();
						//敵に値を設定
						Enemy9->x = k * 160 + 960;
						Enemy9->y = j * 113 - 340;
						Enemy9->w = 60;
						Enemy9->h = 120;
						Enemy9->mFx = -2;
						//有効にする
						Enemy9->mEnabled = true;
						Enemy9->mTag = CRectangle::EENEMY;
						mEnemyFlag += 1;
					}
				}
			}
		}
	}
	if (mEnemyMapRand >= 48 && mEnemyMapRand <= 64 && mEnemyFlag == 0) {
		int EnemyMap4[3][9]
		{
			{2,0,0,3,0,1,0,3,},
			{0,0,1,0,0,0,0,0,},
			{0,3,0,0,1,0,2,0,},
		};
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 9; j++) {
				if (EnemyMap4[i][j] == 1) {
					CEnemy1* Enemy = new CEnemy1();
					//スライム
					//エネミークラスのメンバ変数への代入
					CEnemy1* Enemy10 = new CEnemy1();
					Enemy->mEnemytype = mEnemyTypeRand;
					//敵に値を設定
					Enemy10->x = j * 160 + 960;
					Enemy10->y = i * 113 - 340;
					Enemy10->w = 80;
					Enemy10->h = 80;
					Enemy10->mFx = -2;
					//有効にする
					Enemy10->mEnabled = true;
					Enemy10->mTag = CRectangle::EENEMY;
					mEnemyFlag += 1;
				}
				if (EnemyMap4[i][j] == 2) {
					//スケルトン
					//エネミークラスのメンバ変数への代入
					CEnemy2* Enemy11 = new CEnemy2();
					//敵に値を設定
					Enemy11->x = j * 160 + 960;
					Enemy11->y = i * 113 - 340;
					Enemy11->w = 80;
					Enemy11->h = 110;
					Enemy11->mFx = -2;
					//有効にする
					Enemy11->mEnabled = true;
					Enemy11->mTag = CRectangle::EENEMY;
					mEnemyFlag += 1;
				}
				if (EnemyMap4[i][j] == 3) {
					//ゾンビ
					//エネミークラスのメンバ変数への代入
					CEnemy3* Enemy12 = new CEnemy3();
					//敵に値を設定
					Enemy12->x = j * 160 + 960;
					Enemy12->y = i * 113 - 340;
					Enemy12->w = 60;
					Enemy12->h = 120;
					Enemy12->mFx = -2;
					//有効にする
					Enemy12->mEnabled = true;
					Enemy12->mTag = CRectangle::EENEMY;
					mEnemyFlag++;
				}
			}
		}
	}
	if (mEnemyMapRand >= 64 && mEnemyMapRand <= 80 && mEnemyFlag == 0) {
		int EnemyMap5[3][9]
		{
			{0,2,0,3,0,0,3,0,},
			{2,0,0,0,3,0,0,0,},
			{0,0,3,0,0,3,0,0,},
		};
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 9; j++) {
				if (EnemyMap5[i][j] == 1) {
					CEnemy1* Enemy13 = new CEnemy1();
					//スライム
					//エネミークラスのメンバ変数への代入
					CEnemy1* Enemy = new CEnemy1();
					Enemy->mEnemytype = mEnemyTypeRand;
					//敵に値を設定
					Enemy13->x = j * 160 + 960;
					Enemy13->y = i * 113 - 340;
					Enemy13->w = 80;
					Enemy13->h = 80;
					Enemy13->mFx = -2;
					//有効にする
					Enemy13->mEnabled = true;
					Enemy13->mTag = CRectangle::EENEMY;
					mEnemyFlag += 1;
				}
				if (EnemyMap5[i][j] == 2) {
					//スケルトン
					//エネミークラスのメンバ変数への代入
					CEnemy2* Enemy14 = new CEnemy2();
					//敵に値を設定
					Enemy14->x = j * 160 + 960;
					Enemy14->y = i * 113 - 340;
					Enemy14->w = 80;
					Enemy14->h = 110;
					Enemy14->mFx = -2;
					//有効にする
					Enemy14->mEnabled = true;
					Enemy14->mTag = CRectangle::EENEMY;
					mEnemyFlag += 1;
				}
				if (EnemyMap5[i][j] == 3) {
					//ゾンビ
					//エネミークラスのメンバ変数への代入
					CEnemy3* Enemy15 = new CEnemy3();
					//敵に値を設定
					Enemy15->x = j * 160 + 960;
					Enemy15->y = i * 113 - 340;
					Enemy15->w = 60;
					Enemy15->h = 120;
					Enemy15->mFx = -2;
					//有効にする
					Enemy15->mEnabled = true;
					Enemy15->mTag = CRectangle::EENEMY;
					mEnemyFlag += 1;
				}
			}
		}
	}
	if (mEnemyMapRand >= 80 && mEnemyMapRand <= 100 && mEnemyFlag == 0) {
		int EnemyMap6[3][9]
		{
			{0,3,0,0,0,3,0,0,},
			{1,0,0,2,0,0,2,0,},
			{0,0,2,0,0,3,0,0,},
		};
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 9; j++) {
				if (EnemyMap6[i][j] == 1) {
					CEnemy1* Enemy = new CEnemy1();
					//スライム
					//エネミークラスのメンバ変数への代入
					CEnemy1* Enemy16 = new CEnemy1();
					Enemy->mEnemytype = mEnemyTypeRand;
					//敵に値を設定
					Enemy16->x = j * 160 + 960;
					Enemy16->y = i * 113 - 340;
					Enemy16->w = 80;
					Enemy16->h = 80;
					Enemy16->mFx = -2;
					//有効にする
					Enemy16->mEnabled = true;
					Enemy16->mTag = CRectangle::EENEMY;
					mEnemyFlag += 1;
				}
				if (EnemyMap6[i][j] == 2) {
					//スケルトン
					//エネミークラスのメンバ変数への代入
					CEnemy2* Enemy17 = new CEnemy2();
					//敵に値を設定
					Enemy17->x = j * 160 + 960;
					Enemy17->y = i * 113 - 340;
					Enemy17->w = 80;
					Enemy17->h = 110;
					Enemy17->mFx = -2;
					//有効にする
					Enemy17->mEnabled = true;
					Enemy17->mTag = CRectangle::EENEMY;
					mEnemyFlag += 1;
				}
				if (EnemyMap6[i][j] == 3) {
					//ゾンビ
					//エネミークラスのメンバ変数への代入
					CEnemy3* Enemy18 = new CEnemy3();
					//敵に値を設定
					Enemy18->x = j * 160 + 960;
					Enemy18->y = i * 113 - 340;
					Enemy18->w = 60;
					Enemy18->h = 120;
					Enemy18->mFx = -2;
					//有効にする
					Enemy18->mEnabled = true;
					Enemy18->mTag = CRectangle::EENEMY;
					mEnemyFlag += 1;
				}
			}
		}
	}
}