#define ENEMY_ATTACKMODEL 50
#define EENEMY_COUNT 1
#define ENEMY_MOVEMODEL 60
#define ENEMY_FLUG_COUNT 0

#include "CEnemy.h"
#include "CTexture.h"
//extern�F���̃\�[�X�t�@�C���̊O���ϐ��ɃA�N�Z�X����錾

extern CTexture EnemyAttackTexture1; //�X���C��(�U��)�摜
extern CTexture EnemyMoveTexture1; //�X���C��(�ړ�)�摜
extern CTexture EnemyAttackTexture2; //�X�P���g��(�U��)�摜
extern CTexture EnemyMoveTexture2; //�X�P���g��(�ړ�)�摜
extern CTexture EnemyAttackTexture3; //�]���r(�U��)�摜
extern CTexture EnemyMoveTexture3; //�]���r(�U��)�摜



CEnemy1::CEnemy1()
: mFx(0.0f), mFy(0.0f),m_Hp(20), m_EnemyAttackRenderCount(ENEMY_ATTACKMODEL), m_EnemyStandbyCount(ENEMY_MOVEMODEL),mEnemyflag(ENEMY_FLUG_COUNT), mEnemytype(ENEMY_FLUG_COUNT),m_EnemyDrawCount(ENEMY_FLUG_COUNT)
{
	mTag = EENEMY;
}

void CEnemy1::Update() {
	//mEnabled��false�Ȃ�߂�
	if (!mEnabled) return;


		//�ړ�
		x += mFx;
		y += mFy;
		if (--m_EnemyStandbyCount < 0)
		{
			m_EnemyStandbyCount = ENEMY_MOVEMODEL;
			if (mEnemyflag  !=3)
			{
				mEnemyflag++;
			}
		}

		if (mEnemyflag == 3)
		{
			if (--m_EnemyAttackRenderCount < 0) {
				//�e��4���l���֔��˂���
				for (int i = 0; i < 1; i++) {
					CBullet* EBullet = new CBullet();
					//���W�ݒ�
					EBullet->x = x;
					EBullet->y = y;
					//�ړ��ʐݒ�
					EBullet->mFx = -5;
					EBullet->mFy = 0;
					//�L���ɂ���
					EBullet->mEnabled = true;
					EBullet->mTag = ESLIMEBULLET;
				}
				mEnemyflag = ENEMY_FLUG_COUNT;
				m_EnemyAttackRenderCount = ENEMY_ATTACKMODEL;
			}
		}



}
/*
�e��Collision���I�[�o�[���C�h����
�Փ˂���ƈړ������𔽑΂ɂ���
*/
bool CEnemy1::Collision(const CRectangle &r) {
	//mEnabled��false�Ȃ�߂�
	if (!mEnabled) return false;
	//�e��Collision���\�b�h���Ăяo��
	if (CRectangle::Collision(r)) {
		switch (r.mTag) {
		case EPLAYERBULLET:
			//�v���C���[�̒e�ɓ�����ƁA�����ɂ���
			mEnabled = false;
			break;
		case EPLAYER:
			mEnabled = false;
			break;
		}
		return true;
	}
	return false;
}

void CEnemy1::Render() {
	if (mEnabled) {
		switch (mEnemytype) {
		case 1: {
			if (mEnemyflag != 3)
			{
				if (m_EnemyStandbyCount > ENEMY_MOVEMODEL * 4 / 5)
				{
					m_EnemyDrawCount = 1;
				}
				else if (m_EnemyStandbyCount > ENEMY_MOVEMODEL * 3 / 5)
				{
					m_EnemyDrawCount = 2;
				}
				else if (m_EnemyStandbyCount > ENEMY_MOVEMODEL * 2 / 5)
				{
					m_EnemyDrawCount = 3;
				}
				else if (m_EnemyStandbyCount > ENEMY_MOVEMODEL * 1 / 5)
				{
					m_EnemyDrawCount = 4;
				}
				if (mEnabled) {
					CRectangle::Render(EnemyMoveTexture1, m_EnemyDrawCount * 512, (m_EnemyDrawCount + 1) * 512, 512, 0);
				}
			}
			

			if (mEnemyflag == 3)
			{
				if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 4 / 5)
				{
					m_EnemyDrawCount = 1;
				}
				else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 3 / 5)
				{
					m_EnemyDrawCount = 2;
				}
				else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 2 / 5)
				{
					m_EnemyDrawCount = 3;
				}
				else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 1 / 5)
				{
					m_EnemyDrawCount = 4;
				}
				if (mEnabled) {
						CRectangle::Render(EnemyAttackTexture1, m_EnemyDrawCount * 512, (m_EnemyDrawCount + 1) * 512, 512, 0);
				}
			}
			break;
		}
		case 2: {
			if (mEnemyflag != 3)
			{
				if (m_EnemyStandbyCount > ENEMY_MOVEMODEL * 4 / 5)
				{
					m_EnemyDrawCount = 1;
				}
				else if (m_EnemyStandbyCount > ENEMY_MOVEMODEL * 3 / 5)
				{
					m_EnemyDrawCount = 2;
				}
				else if (m_EnemyStandbyCount > ENEMY_MOVEMODEL * 2 / 5)
				{
					m_EnemyDrawCount = 3;
				}
				else if (m_EnemyStandbyCount > ENEMY_MOVEMODEL * 1 / 5)
				{
					m_EnemyDrawCount = 4;
				}
				if (mEnabled) {
					CRectangle::Render(EnemyMoveTexture1, m_EnemyDrawCount * 512, (m_EnemyDrawCount + 1) * 512, 1024, 512);
				}
			}
			if (mEnemyflag == 3)
			{
				if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 4 / 5)
				{
					m_EnemyDrawCount = 1;
				}
				else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 3 / 5)
				{
					m_EnemyDrawCount = 2;
				}
				else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 2 / 5)
				{
					m_EnemyDrawCount = 3;
				}
				else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 1 / 5)
				{
					m_EnemyDrawCount = 4;
				}
				if (mEnabled) {
					CRectangle::Render(EnemyAttackTexture1, m_EnemyDrawCount * 512, (m_EnemyDrawCount + 1) * 512, 1024, 512);
				}
			}
			break;
		}
		case 3: {
			if (mEnemyflag != 3)
			{
				if (m_EnemyStandbyCount > ENEMY_MOVEMODEL * 4 / 5)
				{
					m_EnemyDrawCount = 1;
				}
				else if (m_EnemyStandbyCount > ENEMY_MOVEMODEL * 3 / 5)
				{
					m_EnemyDrawCount = 2;
				}
				else if (m_EnemyStandbyCount > ENEMY_MOVEMODEL * 2 / 5)
				{
					m_EnemyDrawCount = 3;
				}
				else if (m_EnemyStandbyCount > ENEMY_MOVEMODEL * 1 / 5)
				{
					m_EnemyDrawCount = 4;
				}
				if (mEnabled) {
					CRectangle::Render(EnemyMoveTexture1, m_EnemyDrawCount * 512, (m_EnemyDrawCount + 1) * 512, 1538, 1024);
				}


			}


			if (mEnemyflag == 3)
			{
				if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 4 / 5)
				{
					m_EnemyDrawCount = 1;
				}
				else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 3 / 5)
				{
					m_EnemyDrawCount = 2;
				}
				else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 2 / 5)
				{
					m_EnemyDrawCount = 3;
				}
				else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 1 / 5)
				{
					m_EnemyDrawCount = 4;
				}
				if (mEnabled) {
					CRectangle::Render(EnemyAttackTexture1, m_EnemyDrawCount * 512, (m_EnemyDrawCount + 1) * 512, 1538, 1024);
				}
			}
			break;
		}


		}
	}
}

//36
void CEnemy1::Collision(CRectangle *i, CRectangle *y) {
	Collision(*y);
}

CEnemy2::CEnemy2()
	: mFx(0.0f), mFy(0.0f),m_Hp(20),m_EnemyAttackRenderCount(ENEMY_ATTACKMODEL), m_EnemyStandbyCount(ENEMY_MOVEMODEL), mEnemyflag(ENEMY_FLUG_COUNT)
{
	mTag = EENEMY;
}

void CEnemy2::Update() {
	//mEnabled��false�Ȃ�߂�
	if (!mEnabled) return;

	//�ړ�
	x += mFx;
	y += mFy;
	if (--m_EnemyStandbyCount < 0)
	{
		m_EnemyStandbyCount = ENEMY_MOVEMODEL;
		if (mEnemyflag != 2)
		{
			mEnemyflag++;
		}
	}

	if (mEnemyflag == 2)
	{
		if (--m_EnemyAttackRenderCount < 0) {
			//�e��4���l���֔��˂���
			for (int i = 0; i < 1; i++) {
				CBullet* EBullet = new CBullet();
				//���W�ݒ�
				EBullet->x = x;
				EBullet->y = y;
				//�ړ��ʐݒ�
				EBullet->mFx = -5;
				EBullet->mFy = 0;
				//�L���ɂ���
				EBullet->mEnabled = true;
				EBullet->mTag = ESKELETONBULLET;
			}
			mEnemyflag = ENEMY_FLUG_COUNT;
			m_EnemyAttackRenderCount = ENEMY_ATTACKMODEL;
		}
	}




}
/*
�e��Collision���I�[�o�[���C�h����
�Փ˂���ƈړ������𔽑΂ɂ���
*/
bool CEnemy2::Collision(const CRectangle& r) {
	//mEnabled��false�Ȃ�߂�
	if (!mEnabled) return false;
	//�e��Collision���\�b�h���Ăяo��
	if (CRectangle::Collision(r)) {
		switch (r.mTag) {
		case EPLAYERBULLET:
			//�v���C���[�̒e�ɓ�����ƁA�����ɂ���
			mEnabled = false;
			break;
		case EPLAYER:
			mEnabled = false;
			break;
		}
		return true;
	}
	return false;
}

void CEnemy2::Render() {
	if (mEnabled) {
		if (mEnemyflag != 2)
		{
			if (m_EnemyStandbyCount > ENEMY_MOVEMODEL * 3 / 4)
			{
				m_EnemyDrawCount = 1;
			}
			else if (m_EnemyStandbyCount > ENEMY_MOVEMODEL * 2 / 4)
			{
				m_EnemyDrawCount = 2;
			}
			else if (m_EnemyStandbyCount > ENEMY_MOVEMODEL * 1 / 4)
			{
				m_EnemyDrawCount = 3;
			}
			if (mEnabled) {
				CRectangle::Render(EnemyMoveTexture1, m_EnemyDrawCount * 512, (m_EnemyDrawCount + 1) * 512, 512, 0);
			}

		}
		if (mEnemyflag == 2)
		{
			if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 2 / 3)
			{
				m_EnemyDrawCount = 1;
			}
			else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 1 / 3)
			{
				m_EnemyDrawCount = 2;
			}
			if (mEnabled) {
				CRectangle::Render(EnemyMoveTexture1, m_EnemyDrawCount * 512, (m_EnemyDrawCount + 1) * 512, 512, 0);
			}

		}
	}
}

//36
void CEnemy2::Collision(CRectangle* i, CRectangle* y) {
	Collision(*y);
}

CEnemy3::CEnemy3()
	: mFx(0.0f), mFy(0.0f),m_Hp(20), m_EnemyAttackRenderCount(ENEMY_ATTACKMODEL), m_EnemyStandbyCount(ENEMY_MOVEMODEL), mEnemyflag(ENEMY_FLUG_COUNT)
{
	mTag = EENEMY;
}

void CEnemy3::Update() {
	//mEnabled��false�Ȃ�߂�
	if (!mEnabled) return;
	
	x += mFx;
	y += mFy;

	if (--m_EnemyStandbyCount < 0)
	{
		m_EnemyStandbyCount = ENEMY_MOVEMODEL;
		if (mEnemyflag != 2)
		{
			mEnemyflag++;
		}
	}

	if (mEnemyflag == 2)
	{
		if (--m_EnemyAttackRenderCount < 0) {
			//�e��4���l���֔��˂���
			for (int i = 0; i < 1; i++) {
				CBullet* EBullet = new CBullet();
				//���W�ݒ�
				EBullet->x = x;
				EBullet->y = y;
				//�ړ��ʐݒ�
				EBullet->mFx = -5;
				EBullet->mFy = 0;
				//�L���ɂ���
				EBullet->mEnabled = true;
				EBullet->mTag = EZOMIBIEBULLET;
			}
			mEnemyflag = ENEMY_FLUG_COUNT;
			m_EnemyAttackRenderCount = ENEMY_ATTACKMODEL;
		}
	}
}
/*
�e��Collision���I�[�o�[���C�h����
�Փ˂���ƈړ������𔽑΂ɂ���
*/
bool CEnemy3::Collision(const CRectangle& r) {
	//mEnabled��false�Ȃ�߂�
	if (!mEnabled) return false;
	//�e��Collision���\�b�h���Ăяo��
	if (CRectangle::Collision(r)) {
		switch (r.mTag) {
		case EPLAYERBULLET:
			//�v���C���[�̒e�ɓ�����ƁA�����ɂ���
			mEnabled = false;
			break;
		case EPLAYER:
			mEnabled = false;
			break;
		}
		return true;
	}
	return false;
}

void CEnemy3::Render() {
	if (mEnabled) {
		if (mEnemyflag != 2)
		{
			if (m_EnemyStandbyCount > ENEMY_MOVEMODEL * 3 / 4)
			{
				m_EnemyDrawCount = 1;
			}
			else if (m_EnemyStandbyCount > ENEMY_MOVEMODEL * 2 / 4)
			{
				m_EnemyDrawCount = 2;
			}
			else if (m_EnemyStandbyCount > ENEMY_MOVEMODEL * 1 / 4)
			{
				m_EnemyDrawCount = 3;
			}
			if (mEnabled) {
				CRectangle::Render(EnemyMoveTexture1, m_EnemyDrawCount * 512, (m_EnemyDrawCount + 1) * 512, 512, 0);
			}


		}
		if (mEnemyflag == 2)
		{
			if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 2 / 3)
			{
				m_EnemyDrawCount = 1;
			}
			else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 1 / 3)
			{
				m_EnemyDrawCount = 2;
			}if (mEnabled) {
				CRectangle::Render(EnemyMoveTexture1, m_EnemyDrawCount * 512, (m_EnemyDrawCount + 1) * 512, 512, 0);
			}
		}
	}
}

//36
void CEnemy3::Collision(CRectangle* i, CRectangle* y) {
	Collision(*y);
}