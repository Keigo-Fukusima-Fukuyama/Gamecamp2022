#ifndef CPLAYER_H
#define CPLAYER_H

#include "CRectangle.h"
#include <assert.h>

class CPlayer : public CRectangle {
public:
	int mFx, mFy;
	//37
	
	CPlayer();


	//36

	int GetPlayerHP();

	static CPlayer* spInstance;

private:
	void Update();
	void Render();
	void Collision(const CRectangle& r);
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
	int FireCount;
	int mGRAVITY = -15;
	int mV = 75;

};

#endif
