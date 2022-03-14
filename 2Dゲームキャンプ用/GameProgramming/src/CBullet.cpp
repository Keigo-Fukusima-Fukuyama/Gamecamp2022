/*Test*/
#include "CBullet.h"
#include "CTexture.h"

//extern�F���̃\�[�X�t�@�C���̊O���ϐ��ɃA�N�Z�X����錾
extern CTexture Texture;
//extern�F���̃\�[�X�t�@�C���̊O���ϐ��ɃA�N�Z�X����錾
extern CTexture PlayerAttack;
extern CTexture EnemyAttackBulTex1;
extern CTexture EnemyAttackBulTex2;
extern CTexture EnemyAttackBulTex3;


//�f�t�H���g�R���X�g���N�^
CBullet::CBullet()
: mFx(0), mFy(0)
{
	mPlayerBullertCnt = 0;
	mPlayerBullert = 0;
	mEnabled = false;
	w = 50;	//���ݒ�
	h = 50;	//�����ݒ�
	
}

//�X�V����
void CBullet::Update() {
	//�L���Ȏ�
	if (mEnabled) {
		//�ړ�
		x += mFx;
		y += mFy;
		mPlayerBullertCnt += mPlayerBullert;
		if (x > 960 || x < -960 || y > 590 || y < -590||mPlayerBullertCnt>192)
			mEnabled = false;
	}
}

//�`�揈��
void CBullet::Render() {
	////�L���Ȏ�
	//if (mEnabled) {
	//	//�e�̕`�惁�\�b�h���Ă�
	//	CRectangle::Render(Texture, 192, 207, 112, 97);
	//}
	if (mEnabled) {
		switch (mTag) {
		case EPLAYERBULLET: {
			CRectangle::Render(PlayerAttack, mMotionCnt * 512, (mMotionCnt + 1) * 512, 512, 0);
			if (mLoopCnt == 5) {
				mMotionCnt = (mMotionCnt + 1) % 4;
				mLoopCnt = 0;
			}
			else {
				mLoopCnt += 1;
			}
			break;
		}
		case ESLIMEBULLET: {
			if (mEnemyTipeBul == 0)
			{
				CRectangle::Render(EnemyAttackBulTex1, 0, 512, 512, 0);
			}
			if (mEnemyTipeBul == 1)
			{
				CRectangle::Render(EnemyAttackBulTex1, 0, 512, 1024, 512);
			}
			if (mEnemyTipeBul == 2)
			{
				CRectangle::Render(EnemyAttackBulTex1, 0, 512, 1536, 1024);
			}
			break;
		}
		case ESKELETONBULLET: {
			CRectangle::Render(EnemyAttackBulTex2, mMotionCnt * 512, (mMotionCnt + 1) * 512, 512, 0);
			if (mLoopCnt == 5) {
				mMotionCnt = (mMotionCnt + 1) % 4;
				mLoopCnt = 0;
			}
			else {
				mLoopCnt += 1;
			}
			break;
		}
		case EZOMIBIEBULLET: {
			CRectangle::Render(EnemyAttackBulTex3, mMotionCnt * 512, (mMotionCnt + 1) * 512, 512, 0);
			if (mLoopCnt == 5) {
				mMotionCnt = (mMotionCnt + 1) % 4;
				mLoopCnt = 0;
			}
			else {
				mLoopCnt += 1;
			}
			break;
		}
		}
	}
}

//36
void CBullet::Collision(CRectangle *i, CRectangle *y) {
	if (i->mEnabled && y->mEnabled) {
		if (y->mTag == EBLOCK) {
			if (i->Collision(*y)) {
				mEnabled = false;
				return;
			}
		}
		if (i->mTag == ESLIMEBULLET && y->mTag == EPLAYER) {
			if (i->Collision(*y)) {
				mEnabled = false;
				return;
			}
		}
		if (i->mTag == ESKELETONBULLET && y->mTag == EPLAYER) {
			if (i->Collision(*y)) {
				mEnabled = false;
				return;
			}
		}
		if (i->mTag == EZOMIBIEBULLET && y->mTag == EPLAYER) {
			if (i->Collision(*y)) {
				mEnabled = false;
				return;
			}
		}
		if (i->mTag == EPLAYERBULLET && y->mTag == EENEMY) {
			if (i->Collision(*y)) {
				mEnabled = false;
				return;
			}

		}
	}
}
