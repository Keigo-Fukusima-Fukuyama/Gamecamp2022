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
	static int mHp;
	/*
	���݂Ȃ�̃��[�V���������Ă��邩
	0 �����G,1 ����,2 �W�����v,3 �U��,4 ��e
	*/
	int mPlayerMotion;
	int mMotionCnt;
	int mLoopCnt;
	int mJumpFlag;
	int mJumpCnt;

	int mGRAVITY = -1;
	int mV = 5;


};

#endif
