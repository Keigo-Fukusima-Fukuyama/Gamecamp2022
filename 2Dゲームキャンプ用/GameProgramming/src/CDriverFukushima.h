#ifndef CDRUVERFUKUSHIMA_H
#define CDRUVERFUKUSHIMA_H

#include"CEnemy.h"
#include "CBackGround.h"

class CDriverFukshima 
{
public:
	void Init() 
	{
		////スクリーン一枚目
		////スクリーンクラスのメンバ変数への代入
		//CBackGround* BackGround = new CBackGround();
		////スクリーンに値を設定
		//BackGround->x = 0;
		//BackGround->y = 200;
		////有効にする
		//BackGround->mEnabled = true;

		//エネミークラスのメンバ変数への代入
		CEnemy* Enemy = new CEnemy();
		//敵に値を設定
		Enemy->x = 0;
		Enemy->y = 0;
		Enemy->w = 200;
		Enemy->h = 200;
		Enemy->mFx = -1;
		//有効にする
		Enemy->mEnabled = true;
	}


};


#endif 

