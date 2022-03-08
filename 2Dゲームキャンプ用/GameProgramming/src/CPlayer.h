#ifndef CPLAYER_H
#define CPLAYER_H

#include "CRectangle.h"

class CPlayer : public CRectangle {
public:
	int mFx, mFy;
	//37
	int FireCount;
	CPlayer();
	void Update();
	void Render();

	//36
	void Collision(CRectangle *i, CRectangle *y);
	void Collision(const CRectangle& r);

	static CPlayer* spInstance;
private:
	int mHp;
	/*
	現在なんのモーションをしているか
	0 立ち絵,1 走る,2 ジャンプ,3 攻撃大,4 攻撃小,5 被弾
	*/
	int mPlayerMotion;
	int mMotionCnt;
	int mLoopCnt;
};

#endif
