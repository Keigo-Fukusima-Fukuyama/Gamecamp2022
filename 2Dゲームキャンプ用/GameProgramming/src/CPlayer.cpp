#define PLAYER_SPEED_X 10
#define PLAYER_SPEED_Y 10
#define PLAYER_SHOTTIME 10
#define PLAYER_COOLTIME_MAX 15 //��U���̃N�[���^�C�� ��
#define PLAYER_COOLTIME_MIN 5 //���U���̃N�[���^�C�� ��
#define PLAYER_HP_MAX 100 //��

#include "CPlayer.h"
#include "CKey.h"
#include"CTaskManager.h"
#include "CBullet.h"

//extern�F���̃\�[�X�t�@�C���̊O���ϐ��ɃA�N�Z�X����錾
extern CTexture Texture;

CPlayer::CPlayer()
: mFx(1.0f), mFy(0.0f)
, FireCount(0)
{
	 x = -900;
	 y = -270;
	 w = 25;
	 h = 25;
	 mHp = PLAYER_HP_MAX;
	mTag = EPLAYER;
}

void CPlayer::Update() {

	//static���\�b�h�͂ǂ�����ł��Ăׂ�
	if (CKey::Push('A')) {
		
		x -= PLAYER_SPEED_X;
		mFx = -1;
		mFy = 0;
		if (x - w < -960) {
			x = -960 + w;
		}
	}
	if (CKey::Push('D')) {
		x += PLAYER_SPEED_X;
		mFx = 1;
		mFy = 0;
		if (x + w > 960) {
			x = 960 - w;
		}
	}
	if (CKey::Push('W')) {
		y += PLAYER_SPEED_Y;
		mFx = 0;
		mFy = 1;
		if (y + h > 0) {
			y = 0 - h;
		}
	}
	if (CKey::Push('S')) {
		y -= PLAYER_SPEED_Y;
		mFx = 0;
		mFy = -1;
		if (y - h < -515) {
			y = -515 + h;
		}
	}
	//37
	//�X�y�[�X�L�[�Œe����
	//0���傫���Ƃ�1���Z����
	if (FireCount > 0) {
		FireCount--;
	}
	//FireCont��0�ŁA���A�X�y�[�X�L�[�Œe����
	else if( CKey::Once(' ')) {
		CBullet *Bullet = new CBullet();
		//���ˈʒu�̐ݒ�
		Bullet->x = x;
		Bullet->y = y;
		//�ړ��̒l��ݒ�
		Bullet->mFx = mFx * 5;
		Bullet->mFy = mFy * 5;
		//�L���ɂ���
		Bullet->mEnabled = true;
		//�v���C���[�̒e��ݒ�
		Bullet->mTag =EPLAYERBULLET;
		FireCount = PLAYER_SHOTTIME;
	}
	//37
}

void CPlayer::Render() {
	CRectangle::Render(Texture, 146 - 16, 146 + 16, 146 + 16, 146 - 16);
}


//36
void CPlayer::Collision(CRectangle *ri, CRectangle *ry) //�u���b�N�ɂԂ������Ƃ�
{
	if (ry->mTag == EBLOCK) {
		int mx, my;
		if (CRectangle::Collision(ry, &mx, &my)) {
			//abs(x) x�̐�Βl�����߂�
			//�ړ��ʂ����Ȃ����������ړ�������
			if (abs(mx) < abs(my)) {
				//Rect��x�����ړ�����
				x += mx;
			}
			else {
				//Rect��y�����ړ�����
				y += my;
			}
		}
	}
}
void CPlayer::Collision(const CRectangle& r) //�U�����ꂽ�Ƃ�
{
	if (CRectangle::Collision(r)) {
		switch (r.mTag) {

		case EENEMYBULLET:
			//�G�l�~�[�̒e�ɓ�����ƁAHP��10����
			mHp -= 10;
			break;
		}
	}
}
