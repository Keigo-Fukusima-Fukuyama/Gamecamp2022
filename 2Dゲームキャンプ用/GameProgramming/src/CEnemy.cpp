#define ENEMY_ATTACKMODEL 50
#define EENEMY_COUNT 1
#define ENEMY_SYANBDYMODEL 60
#define ENEMY_FLUG_COUNT 0

#include "CEnemy.h"
#include "CTexture.h"
//extern�F���̃\�[�X�t�@�C���̊O���ϐ��ɃA�N�Z�X����錾

extern CTexture EnemyAttackTexture1; //�X���C��(�ړ�)�摜
extern CTexture EnemyMoveTexture1; //�X���C��(�U��)�摜
extern CTexture EnemyAttackTexture2; //�X�P���g��(�ړ�)�摜
extern CTexture EnemyMoveTexture2; //�X�P���g��(�U��)�摜




CEnemy1::CEnemy1()
: mFx(0.0f), mFy(0.0f),m_Hp(20), m_EnemyAttackRenderCount(ENEMY_ATTACKMODEL), m_EnemyStandbyCount(ENEMY_SYANBDYMODEL),mEnemyflug(ENEMY_FLUG_COUNT), mEnemytype(ENEMY_FLUG_COUNT)
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
			m_EnemyStandbyCount = ENEMY_SYANBDYMODEL;
			if (mEnemyflug  !=2)
			{
				mEnemyflug++;
			}
		}

		if (mEnemyflug == 2)
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
					EBullet->mTag = EENEMYBULLET;
				}
				mEnemyflug = ENEMY_FLUG_COUNT;
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
			if (mEnemyflug != 2)
			{
				if (m_EnemyStandbyCount > ENEMY_SYANBDYMODEL * 5 / 6)
				{
					CRectangle::Render(EnemyMoveTexture1, 15, 90, 90, 10);
				}
				else if (m_EnemyStandbyCount > ENEMY_SYANBDYMODEL * 4 / 6)
				{
					CRectangle::Render(EnemyMoveTexture1, 110, 190, 90, 10);
				}
				else if (m_EnemyStandbyCount > ENEMY_SYANBDYMODEL * 3 / 6)
				{
					CRectangle::Render(EnemyMoveTexture1, 215, 300, 90, 10);
				}
				else if (m_EnemyStandbyCount > ENEMY_SYANBDYMODEL * 2 / 6)
				{
					CRectangle::Render(EnemyMoveTexture1, 310, 395, 90, 10);
				}
				else if (m_EnemyStandbyCount > ENEMY_SYANBDYMODEL * 1 / 6)
				{
					CRectangle::Render(EnemyMoveTexture1, 410, 495, 90, 10);

				}
				else
				{
					CRectangle::Render(EnemyMoveTexture1, 15, 90, 90, 10);
				}

			}


			if (mEnemyflug == 2)
			{
				if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 4 / 5)
				{
					CRectangle::Render(EnemyAttackTexture1, 0, 512, 512, 0);
				}
				else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 3 / 5)
				{
					CRectangle::Render(EnemyAttackTexture1, 670, 1190, 512, 0);
				}
				else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 2 / 5)
				{
					CRectangle::Render(EnemyAttackTexture1, 1365, 1850, 512, 0);
				}
				else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 1 / 5)
				{
					CRectangle::Render(EnemyAttackTexture1, 1970, 2510, 512, 0);
				}
				else
				{
					CRectangle::Render(EnemyAttackTexture1, 2550, 3200, 512, 0);

				}
			}
			break;
		}
		case 2: {
			if (mEnemyflug != 2)
			{
				if (m_EnemyStandbyCount > ENEMY_SYANBDYMODEL * 5 / 6)
				{
					CRectangle::Render(EnemyMoveTexture1, 15, 90, 180, 100);
				}
				else if (m_EnemyStandbyCount > ENEMY_SYANBDYMODEL * 4 / 6)
				{
					CRectangle::Render(EnemyMoveTexture1, 110, 190, 180, 100);
				}
				else if (m_EnemyStandbyCount > ENEMY_SYANBDYMODEL * 3 / 6)
				{
					CRectangle::Render(EnemyMoveTexture1, 215, 300, 180, 100);
				}
				else if (m_EnemyStandbyCount > ENEMY_SYANBDYMODEL * 2 / 6)
				{
					CRectangle::Render(EnemyMoveTexture1, 310, 395, 180, 100);
				}
				else if (m_EnemyStandbyCount > ENEMY_SYANBDYMODEL * 1 / 6)
				{
					CRectangle::Render(EnemyMoveTexture1, 410, 495, 180, 100);

				}
				else
				{
					CRectangle::Render(EnemyMoveTexture1, 15, 90, 180, 100);
				}

			}


			if (mEnemyflug == 2)
			{
				if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 4 / 5)
				{
					CRectangle::Render(EnemyAttackTexture1, 0, 512, 1200, 680);
				}
				else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 3 / 5)
				{
					CRectangle::Render(EnemyAttackTexture1, 670, 1190, 1200, 680);
				}
				else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 2 / 5)
				{
					CRectangle::Render(EnemyAttackTexture1, 1365, 1850, 1200, 680);
				}
				else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 1 / 5)
				{
					CRectangle::Render(EnemyAttackTexture1, 1970, 2510, 1200, 680);
				}
				else
				{
					CRectangle::Render(EnemyAttackTexture1, 2550, 3200, 1200, 680);

				}
			}
			break;
		}
		case 3: {
			if (mEnemyflug != 2)
			{
				if (m_EnemyStandbyCount > ENEMY_SYANBDYMODEL * 5 / 6)
				{
					CRectangle::Render(EnemyMoveTexture1, 15, 90, 278, 205);
				}
				else if (m_EnemyStandbyCount > ENEMY_SYANBDYMODEL * 4 / 6)
				{
					CRectangle::Render(EnemyMoveTexture1, 110, 190, 278, 205);
				}
				else if (m_EnemyStandbyCount > ENEMY_SYANBDYMODEL * 3 / 6)
				{
					CRectangle::Render(EnemyMoveTexture1, 215, 300, 278, 205);
				}
				else if (m_EnemyStandbyCount > ENEMY_SYANBDYMODEL * 2 / 6)
				{
					CRectangle::Render(EnemyMoveTexture1, 310, 395, 278, 205);
				}
				else if (m_EnemyStandbyCount > ENEMY_SYANBDYMODEL * 1 / 6)
				{
					CRectangle::Render(EnemyMoveTexture1, 410, 495, 278, 205);

				}
				else
				{
					CRectangle::Render(EnemyMoveTexture1, 15, 90, 278, 205);
				}

			}


			if (mEnemyflug == 2)
			{
				if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 4 / 5)
				{
					CRectangle::Render(EnemyAttackTexture1, 0, 512, 1900, 1360);
				}
				else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 3 / 5)
				{
					CRectangle::Render(EnemyAttackTexture1, 670, 1190, 1900, 1360);
				}
				else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 2 / 5)
				{
					CRectangle::Render(EnemyAttackTexture1, 1365, 1850, 1900, 1360);
				}
				else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 1 / 5)
				{
					CRectangle::Render(EnemyAttackTexture1, 1970, 2510, 1900, 1360);
				}
				else
				{
					CRectangle::Render(EnemyAttackTexture1, 2550, 3200, 1900, 1360);

				}
				break;
			}
		}


		}
	}
}

//36
void CEnemy1::Collision(CRectangle *i, CRectangle *y) {
	Collision(*y);
}

CEnemy2::CEnemy2()
	: mFx(0.0f), mFy(0.0f),m_Hp(20),m_EnemyAttackRenderCount(ENEMY_ATTACKMODEL), m_EnemyStandbyCount(ENEMY_SYANBDYMODEL), mEnemyflug(ENEMY_FLUG_COUNT)
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
		m_EnemyStandbyCount = ENEMY_SYANBDYMODEL;
		if (mEnemyflug != 2)
		{
			mEnemyflug++;
		}
	}

	if (mEnemyflug == 2)
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
				EBullet->mTag = EENEMYBULLET;
			}
			mEnemyflug = ENEMY_FLUG_COUNT;
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
		if (mEnemyflug != 2)
		{
			if (m_EnemyStandbyCount > ENEMY_SYANBDYMODEL * 4 / 5)
			{
				CRectangle::Render(EnemyMoveTexture2, 23, 80, 120, 20);
			}
			else if (m_EnemyStandbyCount > ENEMY_SYANBDYMODEL * 3 / 5)
			{
				CRectangle::Render(EnemyMoveTexture2, 120, 178, 120, 20);
			}
			else if (m_EnemyStandbyCount > ENEMY_SYANBDYMODEL * 2 / 5)
			{
				CRectangle::Render(EnemyMoveTexture2, 215, 280, 120, 20);
			}
			else if (m_EnemyStandbyCount > ENEMY_SYANBDYMODEL * 1 / 5)
			{
				CRectangle::Render(EnemyMoveTexture2, 313, 386, 120, 20);
			}
			else
			{
				CRectangle::Render(EnemyMoveTexture2, 23, 80, 120, 20);
			}

		}
		if (mEnemyflug == 2)
		{
			if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 5 / 6)
			{
				CRectangle::Render(EnemyAttackTexture2, 28, 120, 180, 20);
			}
			else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 4 / 6)
			{
				CRectangle::Render(EnemyAttackTexture2, 160, 255, 180, 20);
			}
			else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 3 / 6)
			{
				CRectangle::Render(EnemyAttackTexture2, 290, 400, 180, 20);
			}
			else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 2 / 6)
			{
				CRectangle::Render(EnemyAttackTexture2, 450, 542, 180, 20);
			}
			else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 1 / 6)
			{
				CRectangle::Render(EnemyAttackTexture2, 542, 675, 180, 20);

			}
			else
			{
				CRectangle::Render(EnemyAttackTexture2, 28, 120, 180, 20);
			}
		}
	}
}

//36
void CEnemy2::Collision(CRectangle* i, CRectangle* y) {
	Collision(*y);
}

CEnemy3::CEnemy3()
	: mFx(0.0f), mFy(0.0f),m_Hp(20), m_EnemyAttackRenderCount(ENEMY_ATTACKMODEL)
{
	mTag = EENEMY;
}

void CEnemy3::Update() {
	//mEnabled��false�Ȃ�߂�
	if (!mEnabled) return;
	

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
			EBullet->mTag = EENEMYBULLET;
		}
		
		m_EnemyAttackRenderCount = ENEMY_ATTACKMODEL;
	}

	x += mFx;
	y += mFy;

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
		if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 4 / 5)
		{
			CRectangle::Render();
		}
		else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 3 / 5)
		{
			
		}
		else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 2 / 5)
		{
			
		}
		else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 1 / 5)
		{
			
		}
		else
		{
			
		}

		
	}
}

//36
void CEnemy3::Collision(CRectangle* i, CRectangle* y) {
	Collision(*y);
}