#ifndef CDRIVERSATOU_H
#define CDRIVERSATOU_H
#include "CPlayer.h"


class CDriverSatou
{
public:
	int mRight;

	void Init()
	{

		
	//	//画面範囲右の設定
	//	mRight = mLeft + WTDTH;
	//	//画面下の設定
	//	//mBottom = CPlayer::spInstance->y - HEIGHT / 2;
	//	mBottom = -500;
	//	//画面範囲上の設定
	//	mTop = mBottom + HEIGHT;

	//	/*画面の投影変更開始*/
	//	glMatrixMode(GL_PROJECTION);
	//	glLoadIdentity();//行列（設定）を初期化
	//	//2Dの投影範囲の設定
	//	gluOrtho2D(mLeft, mRight, mBottom, mTop);
	//	for (int i = 0; i < VectorRect.size(); i++) {
	//		//描画処理
	//		VectorRect[i]->Render();
	//	}
	//	glLoadIdentity();//行列（設定）を初期化
	////2Dの投影範囲を設定
	//	gluOrtho2D(-950, 950, -500, 500);
	};
	void Update() {

		//if (mLeft + 30 > CPlayer::spInstance->x) {
		//	CPlayer::spInstance->x = mLeft + 30;
		//};
	}
};















#endif //終了

