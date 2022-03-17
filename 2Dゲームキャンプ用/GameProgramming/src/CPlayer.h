#ifndef CPLAYER_H
#define CPLAYER_H

#include "CRectangle.h"
#include <assert.h>

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
	static int GetPlayerHP();

	static CPlayer* spInstance;

private:
	int mHp;
	/*
	現在なんのモーションをしているか
	0 立ち絵,1 走る,2 ジャンプ,3 攻撃,4 被弾
	*/
	int mPlayerMotion;
	int mMotionCnt;
	int mLoopCnt;
	int mJumpFlag;
	int mJumpCnt;

	int mGRAVITY = -15;
	int mV = 75;

};

#endif
