#ifndef CDRUVERFUKUSHIMA_H
#define CDRUVERFUKUSHIMA_H


//背景スクロールスピード
#define SCROLL_SPEED -2.0


#include"CEnemy.h"
#include "CBackGround.h"

class CDriverFukushima {
public:
	void Init()
	{
		//スクロールする奥の背景
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
		BackGround3->x = 1960;
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
		BackGround5->x = 1960;
		BackGround5->y = -100;
		BackGround5->speed = SCROLL_SPEED;
		//有効にする
		BackGround5->mEnabled = true;

			//スライム
			//エネミークラスのメンバ変数への代入
			CEnemy1* Enemy = new CEnemy1();
			Enemy->mEnemytype = 3;
			//敵に値を設定
			Enemy->x = 790;
			Enemy->y = -100;
			Enemy->w = 80;
			Enemy->h = 80;
			//有効にする
			Enemy->mEnabled = true;

			//スケルトン
			//エネミークラスのメンバ変数への代入
			CEnemy2* Enemy2 = new CEnemy2();
			//敵に値を設定
			Enemy2->x = 790;
			Enemy2->y = -210;
			Enemy2->w = 80;
			Enemy2->h = 110;
			//有効にする
			Enemy2->mEnabled = true;

			//ゾンビ
			//エネミークラスのメンバ変数への代入
			CEnemy3* Enemy3 = new CEnemy3();
			//敵に値を設定
			Enemy3->x = 790;
			Enemy3->y = -350;
			Enemy3->w = 60;
			Enemy3->h = 120;
			//有効にする
			Enemy3->mEnabled = true;
		
	}

};


#endif 

