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

	static int GetPlayerHP();

	static CPlayer* spInstance;
	int mHp;
private:
	void Update();
	void Render();
	void Collision(CRectangle* i, CRectangle* y);
	void Collision(const CRectangle& r);

	/*
	���݂Ȃ�̃��[�V���������Ă��邩
	0 �����G,1 ����,2 �W�����v,3 �U��,4 ��e
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
