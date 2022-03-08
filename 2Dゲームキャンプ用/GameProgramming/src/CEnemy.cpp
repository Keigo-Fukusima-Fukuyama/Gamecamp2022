#define ENEMY_SHOTTIME 60
#define ENEMY_MODEL 20
#define EENEMY_COUNT 1

#include "CEnemy.h"
#include "CTexture.h"
//extern�F���̃\�[�X�t�@�C���̊O���ϐ��ɃA�N�Z�X����錾
extern CTexture EnemyTexture1;

CEnemy1::CEnemy1()
: mFx(0.0f), mFy(0.0f), mFireCount(ENEMY_SHOTTIME),i(0),m_Hp(20),m_EnemyRenderCount(ENEMY_MODEL)
{
	mTag = EENEMY;
}

void CEnemy1::Update() {
	//mEnabled��false�Ȃ�߂�
	if (!mEnabled) return;
	//60�t���[����1�񔭎�
	if (mFireCount > 0) {
		mFireCount--;
	}
	else {
		//�e��4���l���֔��˂���
		for (int i = 0; i < 1; i++) {
			CBullet *EBullet = new CBullet();
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
		mFireCount = ENEMY_SHOTTIME;

	}
	//�L���Ȏ�
	if (mEnabled) {
		//�ړ�
		x += mFx * 0;
		y += mFy * 1;
	}

	if (--m_EnemyRenderCount < 0) {
		
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
		if (m_EnemyRenderCount > ENEMY_MODEL * 4 / 5)
		{
			i = 1;
		}
		else if (m_EnemyRenderCount > ENEMY_MODEL * 3 / 5)
		{
			i = 2;
		}
		else if (m_EnemyRenderCount > ENEMY_MODEL * 2 / 5)
		{
			i = 3;
		}
		else if (m_EnemyRenderCount > ENEMY_MODEL * 1 / 5)
		{
			i = 4;
		}
		else
		{
			i = 5;
		}

		/*CRectangle::Render(EnemyTexture1, -500 + 500 * i, 500 * i, 20, 0);*/
	}
}

//36
void CEnemy1::Collision(CRectangle *i, CRectangle *y) {
	Collision(*y);
}

CEnemy2::CEnemy2()
	: mFx(0.0f), mFy(0.0f), mFireCount(ENEMY_SHOTTIME), i(0), m_Hp(20), m_EnemyRenderCount(ENEMY_MODEL)
{
	mTag = EENEMY;
}

void CEnemy2::Update() {
	//mEnabled��false�Ȃ�߂�
	if (!mEnabled) return;
	//60�t���[����1�񔭎�
	if (mFireCount > 0) {
		mFireCount--;
	}
	else {
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
		mFireCount = ENEMY_SHOTTIME;

	}
	//�L���Ȏ�
	if (mEnabled) {
		//�ړ�
		x += mFx * 0;
		y += mFy * 1;
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
		if (m_EnemyRenderCount > ENEMY_MODEL * 4 / 5)
		{
			i = 1;
		}
		else if (m_EnemyRenderCount > ENEMY_MODEL * 3 / 5)
		{
			i = 2;
		}
		else if (m_EnemyRenderCount > ENEMY_MODEL * 2 / 5)
		{
			i = 3;
		}
		else if (m_EnemyRenderCount > ENEMY_MODEL * 1 / 5)
		{
			i = 4;
		}
		else
		{
			i = 5;
		}

		/*CRectangle::Render(EnemyTexture1, -500 + 500 * i, 500 * i, 20, 0);*/
	}
}

//36
void CEnemy2::Collision(CRectangle* i, CRectangle* y) {
	Collision(*y);
}

CEnemy3::CEnemy3()
	: mFx(0.0f), mFy(0.0f), mFireCount(ENEMY_SHOTTIME), i(0), m_Hp(20), m_EnemyRenderCount(ENEMY_MODEL)
{
	mTag = EENEMY;
}

void CEnemy3::Update() {
	//mEnabled��false�Ȃ�߂�
	if (!mEnabled) return;
	//60�t���[����1�񔭎�
	if (mFireCount > 0) {
		mFireCount--;
	}
	else {
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
		mFireCount = ENEMY_SHOTTIME;

	}
	x += mFx;
	y += mFy;

	if (--m_EnemyRenderCount < 0) {

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
		if (m_EnemyRenderCount > ENEMY_MODEL * 4 / 5)
		{
			i = 1;
		}
		else if (m_EnemyRenderCount > ENEMY_MODEL * 3 / 5)
		{
			i = 2;
		}
		else if (m_EnemyRenderCount > ENEMY_MODEL * 2 / 5)
		{
			i = 3;
		}
		else if (m_EnemyRenderCount > ENEMY_MODEL * 1 / 5)
		{
			i = 4;
		}
		else
		{
			i = 5;
		}

		/*CRectangle::Render(EnemyTexture1, -500 + 500 * i, 500 * i, 20, 0);*/
	}
}

//36
void CEnemy3::Collision(CRectangle* i, CRectangle* y) {
	Collision(*y);
}