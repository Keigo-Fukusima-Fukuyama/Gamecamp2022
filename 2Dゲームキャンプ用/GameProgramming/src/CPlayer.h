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
	Œ»İ‚È‚ñ‚Ìƒ‚[ƒVƒ‡ƒ“‚ğ‚µ‚Ä‚¢‚é‚©
	0 —§‚¿ŠG,1 ‘–‚é,2 ƒWƒƒƒ“ƒv,3 UŒ‚,4 ”í’e
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
