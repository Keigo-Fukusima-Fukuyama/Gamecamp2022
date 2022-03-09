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
	���݂Ȃ�̃��[�V���������Ă��邩
	0 �����G,1 ����,2 �W�����v,3 �U����,4 �U����,5 ��e
	*/
	int mPlayerMotion;
	int mMotionCnt;
	int mLoopCnt;
};

#endif
