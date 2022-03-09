#define PLAYER_SPEED_X 10
#define PLAYER_SPEED_Y 10
#define PLAYER_SHOTTIME 10
#define PLAYER_COOLTIME_MAX 15 //��U���̃N�[���^�C�� ��
#define PLAYER_COOLTIME_MIN 5 //���U���̃N�[���^�C�� ��

#include "CPlayer.h"
#include "CKey.h"
#include"CTaskManager.h"
#include "CBullet.h"

//extern�F���̃\�[�X�t�@�C���̊O���ϐ��ɃA�N�Z�X����錾
extern CTexture Texture;
extern CTexture PlayerTe3xture1;
extern CTexture PlayerTexture2;
extern CTexture PlayerTexture3;
//�v���C���[�̃|�C���^
CPlayer* CPlayer::spInstance = nullptr;

CPlayer::CPlayer()
: mFx(1.0f), mFy(0.0f)
, FireCount(0)
{
	 x = -900;
	 y = -270;
	 w = 75;
	 h = 75;
	 mHp = 100;
	mTag = EPLAYER;
	spInstance = this;
	mPlayerMotion = 0;
	mMotionCnt = 0;
	mLoopCnt = 0;
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
		if (mPlayerMotion != 2) {
			mPlayerMotion = 1;
		}
	}
	if (CKey::Push('D')) {
		x += PLAYER_SPEED_X;
		mFx = 1;
		mFy = 0;
		if (x + w > 960) {
			x = 960 - w;
		}
		if (mPlayerMotion != 2) {
			mPlayerMotion = 1;
		}

	}
	if (CKey::Push('W')) {
		y += PLAYER_SPEED_Y;
		mFx = 0;
		mFy = 1;
		if (y + h > 0) {
			y = 0 - h;
		}
		if (mPlayerMotion != 2) {
			mPlayerMotion = 1;
		}
	}

	if (CKey::Push('S')) {
		y -= PLAYER_SPEED_Y;
		mFx = 0;
		mFy = -1;
		if (y - h < -515) {
			y = -515 + h;
		}
		if (mPlayerMotion != 2) {
			mPlayerMotion = 1;
		}
	}
	//37
	//�X�y�[�X�L�[�Œe����
	//0���傫���Ƃ�1���Z����
	if (FireCount > 0) {
		FireCount--;
	}
	//FireCont��0�ŁA���A�X�y�[�X�L�[�Œe����
	else if (CKey::Once('K')) {
		CBullet* Bullet = new CBullet();
		//���ˈʒu�̐ݒ�
		Bullet->x = x;
		Bullet->y = y;
		//�ړ��̒l��ݒ�
		Bullet->mFx = mFx * 5;
		Bullet->mFy = mFy * 5;
		//�L���ɂ���
		Bullet->mEnabled = true;
		//�v���C���[�̒e��ݒ�
		Bullet->mTag = EPLAYERBULLET;
		FireCount = PLAYER_SHOTTIME;
	}
	if (CKey::Once('J')) //�W�����v
	{
		mPlayerMotion = 2;
	}
}
void CPlayer::Render() {
	switch (mPlayerMotion)
	{
	case 0:
		CRectangle::Render(PlayerTexture1, 0, 512, 512, 0);
		break;
	case 1:
		CRectangle::Render(PlayerTexture2, mMotionCnt * 1912, (mMotionCnt + 1) * 1912, 3680, 0);
		if (mLoopCnt == 5) {
			mMotionCnt = (mMotionCnt + 1) % 4;
			mLoopCnt = 0;
		}
		else {
			mLoopCnt += 1;
		}

		break;
	case 2:

		CRectangle::Render(PlayerTexture3, mMotionCnt * 512, (mMotionCnt + 1) * 512, 512, 0);

		if (mLoopCnt == 40) {
			mPlayerMotion = 0;
			mLoopCnt = 0;
		}
		else if (mLoopCnt % 10 == 0 && mLoopCnt != 0) {
			mMotionCnt = (mMotionCnt + 1) % 4;
			mLoopCnt += 1;
		}
		else {
			mLoopCnt += 1;
		}
		break;

	case 3:

		break;
	case 4:

		break;
	case 5:

		break;
	}

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
	if(mPlayerMotion!=2){
		if (CRectangle::Collision(r)) {
			switch (r.mTag) {

			case EENEMYBULLET:
				//�G�l�~�[�̒e�ɓ�����ƁAHP��10����
				mHp -= 10;
				break;
			}
		}
	}
}
