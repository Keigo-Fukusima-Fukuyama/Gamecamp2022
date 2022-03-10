/*Test*/
#include "CBullet.h"
#include "CTexture.h"
//extern�F���̃\�[�X�t�@�C���̊O���ϐ��ɃA�N�Z�X����錾
extern CTexture Texture;
//extern�F���̃\�[�X�t�@�C���̊O���ϐ��ɃA�N�Z�X����錾
extern CTexture EnemyAttackBulTex;

//�f�t�H���g�R���X�g���N�^
CBullet::CBullet()
: mFx(0), mFy(0)
{
	mEnabled = false;
	w = 100;	//���ݒ�
	h = 50;	//�����ݒ�
}

//�X�V����
void CBullet::Update() {
	//�L���Ȏ�
	if (mEnabled) {
		//�ړ�
		x += mFx;
		y += mFy;
		if (x > 960 || x < -960 || y > 540 || y < -540)
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
		case ESLIMEBULLET: {
			CRectangle::Render(EnemyAttackBulTex, 28, 101, 78, 38);
			break;
		}
		case EPLAYERBULLET: {
			CRectangle::Render(Texture, 192, 207, 112, 97);
			break;
		}
		case ESKELETONBULLET: {

			break;
		}
		case EZOMIBIEBULLET: {

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
