#define ENEMY_SHOTTIME 60
#define ENEMY_MODEL 20
#define EENEMY_COUNT 1

#include "CEnemy.h"
#include "CTexture.h"
//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture EnemyTexture1;

CEnemy::CEnemy()
: mFx(1.0f), mFy(0.0f), mFireCount(ENEMY_SHOTTIME),i(0),m_Hp(20),m_EnemyRenderCount(ENEMY_MODEL)
{
	//37
//	mEnabled = true;
			//敵に値を設定
	mTag = EENEMY;
}




void CEnemy::Update() {
	//mEnabledがfalseなら戻る
	if (!mEnabled) return;
	//60フレームに1回発射
	if (mFireCount > 0) {
		mFireCount--;
	}
	else {
		//37s
		//弾を4発四方へ発射する
		for (int i = 0; i < 4; i++) {
			CBullet *EBullet = new CBullet();
			//座標設定
			EBullet->x = x;
			EBullet->y = y;
			//移動量設定
			EBullet->mFx = (i - 2) % 2 * 2;
			EBullet->mFy = (i - 1) % 2 * 2;
			//有効にする
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
親のCollisionをオーバーライドする
衝突すると移動方向を反対にする
*/
bool CEnemy::Collision(const CRectangle &r) {
	//mEnabledがfalseなら戻る
	if (!mEnabled) return false;
	//親のCollisionメソッドを呼び出す
	if (CRectangle::Collision(r)) {
		switch (r.mTag) {
		case EBLOCK:
			//衝突していれば反転
			mFx *= -1;
			mFy *= -1;
			break;
		case EPLAYERBULLET:
			//プレイヤーの弾に当たると、無効にする
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
		if (m_EnemyRenderCount > ENEMY_MODEL * 5 / 6)
		{
			i = 1;
		}
		else if (m_EnemyRenderCount > ENEMY_MODEL * 4 / 6)
		{
			i = 2;
		}
		else if (m_EnemyRenderCount > ENEMY_MODEL * 3 / 6)
		{
			i = 3;
		}
		else if (m_EnemyRenderCount > ENEMY_MODEL * 2 / 6)
		{
			i = 4;
		}
		else
		{
			i = 5;
		}

		CRectangle::Render(EnemyTexture1, 0 + 860 * i, (4700 / 5) * i, 765 + i / 5, 765 * (i - 1) / 5);
	}
}

//36
void CEnemy::Collision(CRectangle *i, CRectangle *y) {
	Collision(*y);
}
