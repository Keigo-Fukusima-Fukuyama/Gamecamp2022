#define PLAYER_SPEED_X 10
#define PLAYER_SPEED_Y 10
#define PLAYER_SHOTTIME 10
#define PLAYER_COOLTIME_MAX 15 //大攻撃のクールタイム 仮
#define PLAYER_COOLTIME_MIN 5 //少攻撃のクールタイム 仮

#include "CPlayer.h"
#include "CKey.h"
#include"CTaskManager.h"
#include "CBullet.h"

//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture Texture;
extern CTexture PlayerTexture0;
extern CTexture PlayerTexture1;
extern CTexture PlayerTexture2;
extern CTexture PlayerTexture3;
extern CTexture PlayerTexture4;
//プレイヤーのポインタ
CPlayer* CPlayer::spInstance = nullptr;

CPlayer::CPlayer()
: mFx(1.0f), mFy(0.0f)
, FireCount(0)
{
	 x = -900;
	 y = -270;
	 w = 175;
	 h = 175;
	 mHp = 5;
	mTag = EPLAYER;
	spInstance = this;
	mPlayerMotion = 0;
	mMotionCnt = 0;
	mLoopCnt = 0;
}

void CPlayer::Update() {

	//staticメソッドはどこからでも呼べる
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
		if (y + h > 100) {
			y = 100 - h;
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
	//スペースキーで弾発射
	//0より大きいとき1減算する
	if (FireCount > 0) {
		FireCount--;
	}
	//FireContが0で、かつ、スペースキーで弾発射
	else if (CKey::Once('K')) {
		CBullet* Bullet = new CBullet();
		//発射位置の設定
		Bullet->x = x;
		Bullet->y = y;
		//移動の値を設定
		Bullet->mFx = mFx * 5;
		Bullet->mFy = mFy * 5;
		//有効にする
		Bullet->mEnabled = true;
		//プレイヤーの弾を設定
		Bullet->mTag = EPLAYERBULLET;
		FireCount = PLAYER_COOLTIME_MAX;
	}
	if (CKey::Once('J')) //ジャンプ
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
		CRectangle::Render(PlayerTexture2, mMotionCnt * 512, (mMotionCnt + 1) * 512, 512, 0);
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
			mPlayerMotion = 1;
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
void CPlayer::Collision(CRectangle *ri, CRectangle *ry) //ブロックにぶつかったとき
{
	if (ry->mTag == EBLOCK) {
		int mx, my;
		if (CRectangle::Collision(ry, &mx, &my)) {
			//abs(x) xの絶対値を求める
			//移動量が少ない方向だけ移動させる
			if (abs(mx) < abs(my)) {
				//Rectをxだけ移動する
				x += mx;
			}
			else {
				//Rectをyだけ移動する
				y += my;
			}
		}
	}
}
void CPlayer::Collision(const CRectangle& r) //攻撃されたとき
{
	if(mPlayerMotion!=2){
		if (CRectangle::Collision(r)) {
			switch (r.mTag) {

			case ESLIMEBULLET:
				//エネミーの弾に当たると、HPが10減る
				mHp -= 1;
				break;
			}
		}
	}
}

int CPlayer::GetPlayerHP()
{
	return mHp;
}
