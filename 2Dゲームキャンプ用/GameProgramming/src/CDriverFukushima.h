#ifndef CDRUVERFUKUSHIMA_H
#define CDRUVERFUKUSHIMA_H

//背景スクロールスピード
#define SCROLL_SPEED1 -3.0
//背景スクロールスピード
#define SCROLL_SPEED2 -2.0
//背景スクロールスピード
#define SCROLL_SPEED3 -1.0

#include"CEnemy.h"
#include "CBackGround.h"

class CDriverFukushima 
{
public:


	void Init()
	{

		//スクロールする奥の背景
		//背景クラスのメンバ変数への代入
		CBackGround* BackGround = new CBackGround();
		//スクリーンに値を設定
		BackGround->x = 960;
		BackGround->y = -25;
		BackGround->speed = SCROLL_SPEED1;
		//有効にする
		BackGround->mEnabled = true;

		//スクロールする奥の背景
		//背景クラスのメンバ変数への代入
		CBackGround* BackGround2 = new CBackGround();
		//スクリーンに値を設定
		BackGround2->x = 4800;
		BackGround2->y = -25;
		BackGround2->speed = SCROLL_SPEED1;
		//有効にする
		BackGround2->mEnabled = true;

		//スクロールする手前の背景
		//背景クラスのメンバ変数への代入
		CBackGround2* BackGround3 = new CBackGround2();
		//スクリーンに値を設定
		BackGround3->x = 960;
		BackGround3->y = -125;
		BackGround3->speed = SCROLL_SPEED2;
		//有効にする
		BackGround3->mEnabled = true;

		//スクロールする手前の背景
		//背景クラスのメンバ変数への代入
		CBackGround2* BackGround4 = new CBackGround2();
		//スクリーンに値を設定
		BackGround4->x = 4800;
		BackGround4->y = -125;
		BackGround4->speed = SCROLL_SPEED2;
		//有効にする
		BackGround4->mEnabled = true;

		//マップの背景(ステージ)
		//背景クラスのメンバ変数への代入
		CBackGround3* BackGround5 = new CBackGround3();
		//スクリーンに値を設定
		BackGround5->x = 960;
		BackGround5->y = -100;
		BackGround5->speed = SCROLL_SPEED3;
		//有効にする
		BackGround5->mEnabled = true;

		//マップの背景(ステージ)
		//背景クラスのメンバ変数への代入
		CBackGround3* BackGround6 = new CBackGround3();
		//スクリーンに値を設定
		BackGround6->x = 4800;
		BackGround6->y = -100;
		BackGround6->speed = SCROLL_SPEED3;
		//有効にする
		BackGround6->mEnabled = true;

		//	//スライム
		//	//エネミークラスのメンバ変数への代入
		//	CEnemy1* Enemy = new CEnemy1();
		//	Enemy->mEnemytype = 3;
		//	//敵に値を設定
		//	Enemy->x = 790;
		//	Enemy->y = -100;
		//	Enemy->w = 100;
		//	Enemy->h = 100;
		//	//有効にする
		//	Enemy->mEnabled = true;

		//	//スケルトン
		//	//エネミークラスのメンバ変数への代入
		//	CEnemy2* Enemy2 = new CEnemy2();
		//	//敵に値を設定
		//	Enemy2->x = 790;
		//	Enemy2->y = -210;
		//	Enemy2->w = 100;
		//	Enemy2->h = 130;
		//	//有効にする
		//	Enemy2->mEnabled = true;

		//	//ゾンビ
		//	//エネミークラスのメンバ変数への代入
		//	CEnemy3* Enemy3 = new CEnemy3();
		//	//敵に値を設定
		//	Enemy3->x = 790;
		//	Enemy3->y = -350;
		//	Enemy3->w = 80;
		//	Enemy3->h = 130;
		//	//有効にする
		//	Enemy3->mEnabled = true;
		//
	}

};


#endif 

