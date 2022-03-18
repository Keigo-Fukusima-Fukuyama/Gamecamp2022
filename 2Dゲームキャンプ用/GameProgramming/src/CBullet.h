#ifndef CBULLET_H
#define CBULLET_H

#include "CRectangle.h"
/*
CBullet
�e�N���X
CRectangle�N���X���p������
�e�FCRectangle�N���X
�q�FCBullet�N���X
*/
class CBullet : public CRectangle {
public:
	//�f�t�H���g�R���X�g���N�^
	CBullet();
	int mFx, mFy;	//�ړ���
	int mEnemyTipeBul;//�G�l�~�[�̒e�̎��

	
private:
	int mPlayerBullertCnt = 0;
	int mPlayerBullert;
	int mMotionCnt = 0;
	int mLoopCnt = 0;
	//�X�V����
	void Update();
	//�`�揈��
	void Render();
	//�Փˏ���
	void Collision(CRectangle* i, CRectangle* y);
};

#endif
