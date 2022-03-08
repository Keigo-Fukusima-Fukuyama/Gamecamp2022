#define ENEMY_SHOTTIME 60
#define ENEMY_MODEL 20
#define EENEMY_COUNT 1

#include "CEnemy.h"
#include "CTexture.h"
//extern�F���̃\�[�X�t�@�C���̊O���ϐ��ɃA�N�Z�X����錾
extern CTexture EnemyTexture1;

CEnemy::CEnemy()
: mFx(1.0f), mFy(0.0f), mFireCount(ENEMY_SHOTTIME),i(0),m_Hp(20),m_EnemyRenderCount(ENEMY_MODEL)
{
	//37
//	mEnabled = true;
			//�G�ɒl��ݒ�
	mTag = EENEMY;
}




void CEnemy::Update() {
	//mEnabled��false�Ȃ�߂�
	if (!mEnabled) return;
	//60�t���[����1�񔭎�
	if (mFireCount > 0) {
		mFireCount--;
	}
	else {
		//37s
		//�e��4���l���֔��˂���
		for (int i = 0; i < 4; i++) {
			CBullet *EBullet = new CBullet();
			//���W�ݒ�
			EBullet->x = x;
			EBullet->y = y;
			//�ړ��ʐݒ�
			EBullet->mFx = (i - 2) % 2 * 2;
			EBullet->mFy = (i - 1) % 2 * 2;
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
bool CEnemy::Collision(const CRectangle &r) {
	//mEnabled��false�Ȃ�߂�
	if (!mEnabled) return false;
	//�e��Collision���\�b�h���Ăяo��
	if (CRectangle::Collision(r)) {
		switch (r.mTag) {
		case EBLOCK:
			//�Փ˂��Ă���Δ��]
			mFx *= -1;
			mFy *= -1;
			break;
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

void CEnemy::Render() {
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

		/*CRectangle::Render(EnemyTexture1,);*/
	}
}

//36
void CEnemy::Collision(CRectangle *i, CRectangle *y) {
	Collision(*y);
}
