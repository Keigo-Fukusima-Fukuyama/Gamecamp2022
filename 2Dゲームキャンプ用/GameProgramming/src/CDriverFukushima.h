#ifndef CDRUVERFUKUSHIMA_H
#define CDRUVERFUKUSHIMA_H

#include "CBackGround.h"

class CDriverFukshima 
{
public:
	void init() 
	{
		//スクリーン一枚目
		//スクリーンクラスのメンバ変数への代入
		CBackGround* BackGround = new CBackGround();
		//スクリーンに値を設定
		BackGround->x = 0;
		BackGround->y = 200;
		//有効にする
		BackGround->mEnabled = true;
	}



};


#endif 

