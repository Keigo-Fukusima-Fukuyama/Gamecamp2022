#define ENEMY_SHOTTIME 60
#define ENEMY_ATTACKMODEL 40
#define EENEMY_COUNT 1
#define ENEMY_SYANBDYMODEL 60
#define ENEMY_FLUG_COUNT 0

#include "CEnemy.h"
#include "CTexture.h"
//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture EnemyTexture1;

CEnemy1::CEnemy1()
: mFx(0.0f), mFy(0.0f), mFireCount(ENEMY_SHOTTIME),m_Hp(20), m_EnemyAttackRenderCount(ENEMY_ATTACKMODEL), m_EnemyStandbyCount(ENEMY_SYANBDYMODEL),mEnemyflug(ENEMY_FLUG_COUNT)
{
	mTag = EENEMY;
}

void CEnemy1::Update() {
	//mEnabledがfalseなら戻る
	if (!mEnabled) return;
	//60フレームに1回発射
	if (mFireCount > 0) {
		mFireCount--;
	}

		//移動
		x += mFx;
		y += mFy;
		if (--m_EnemyStandbyCount < 0)
		{
			m_EnemyStandbyCount = ENEMY_SYANBDYMODEL;
			if (mEnemyflug  !=3)
			{
				mEnemyflug++;
			}
			

		}

		if (mEnemyflug == 3)
		{
			if (--m_EnemyAttackRenderCount < 0) {
				//弾を4発四方へ発射する
				for (int i = 0; i < 1; i++) {
					CBullet* EBullet = new CBullet();
					//座標設定
					EBullet->x = x;
					EBullet->y = y;
					//移動量設定
					EBullet->mFx = -5;
					EBullet->mFy = 0;
					//有効にする
					EBullet->mEnabled = true;
					EBullet->mTag = EENEMYBULLET;
				}
				mEnemyflug = ENEMY_FLUG_COUNT;
				mFireCount = ENEMY_SHOTTIME;
				m_EnemyAttackRenderCount = ENEMY_ATTACKMODEL;
			}
		}



}
/*
親のCollisionをオーバーライドする
衝突すると移動方向を反対にする
*/
bool CEnemy1::Collision(const CRectangle &r) {
	//mEnabledがfalseなら戻る
	if (!mEnabled) return false;
	//親のCollisionメソッドを呼び出す
	if (CRectangle::Collision(r)) {
		switch (r.mTag) {
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

void CEnemy1::Render() {
	if (mEnabled) {

			if (m_EnemyStandbyCount > ENEMY_ATTACKMODEL * 4 / 5)
			{
				CRectangle::Render(EnemyTexture1, 0, 512, 512, 0);
			}
			else if (m_EnemyStandbyCount > ENEMY_ATTACKMODEL * 3 / 5)
			{
				CRectangle::Render(EnemyTexture1, 570, 1060, 512, 0);
			}
			else if (m_EnemyStandbyCount > ENEMY_ATTACKMODEL * 2 / 5)
			{
				CRectangle::Render(EnemyTexture1, 1175, 1650, 512, 0);
			}
			else if (m_EnemyStandbyCount > ENEMY_ATTACKMODEL * 1 / 5)
			{
				CRectangle::Render(EnemyTexture1, 1765, 2250, 512, 0);
			}
			else
			{
				CRectangle::Render(EnemyTexture1, 2370, 2930, 512, 0);

			}

			if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 4 / 5)
			{
				CRectangle::Render(EnemyTexture1, 0, 512, 512, 0);
			}
			else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 3 / 5)
			{
				CRectangle::Render(EnemyTexture1, 570, 1060, 512, 0);
			}
			else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 2 / 5)
			{
				CRectangle::Render(EnemyTexture1, 1175, 1650, 512, 0);
			}
			else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 1 / 5)
			{
				CRectangle::Render(EnemyTexture1, 1765, 2250, 512, 0);
			}
			else
			{
				CRectangle::Render(EnemyTexture1, 2370, 2930, 512, 0);

			}


		
	}
}

//36
void CEnemy1::Collision(CRectangle *i, CRectangle *y) {
	Collision(*y);
}

CEnemy2::CEnemy2()
	: mFx(0.0f), mFy(0.0f), mFireCount(ENEMY_SHOTTIME),m_Hp(20), m_EnemyAttackRenderCount(ENEMY_ATTACKMODEL)
{
	mTag = EENEMY;
}

void CEnemy2::Update() {
	//mEnabledがfalseなら戻る
	if (!mEnabled) return;
	//60フレームに1回発射
	if (mFireCount > 0) {
		mFireCount--;
	}

	//移動
	x += mFx;
	y += mFy;
	if (--m_EnemyAttackRenderCount < 0) {
		//弾を4発四方へ発射する
		for (int i = 0; i < 1; i++) {
			CBullet* EBullet = new CBullet();
			//座標設定
			EBullet->x = x;
			EBullet->y = y;
			//移動量設定
			EBullet->mFx = -5;
			EBullet->mFy = 0;
			//有効にする
			EBullet->mEnabled = true;
			EBullet->mTag = EENEMYBULLET;
		}
		mFireCount = ENEMY_SHOTTIME;
		m_EnemyAttackRenderCount = ENEMY_ATTACKMODEL;
	}




}
/*
親のCollisionをオーバーライドする
衝突すると移動方向を反対にする
*/
bool CEnemy2::Collision(const CRectangle& r) {
	//mEnabledがfalseなら戻る
	if (!mEnabled) return false;
	//親のCollisionメソッドを呼び出す
	if (CRectangle::Collision(r)) {
		switch (r.mTag) {
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

void CEnemy2::Render() {
	if (mEnabled) {
		if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 4 / 5)
		{
			CRectangle::Render(EnemyTexture1, 0, 512, 512, 0);
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
void CEnemy2::Collision(CRectangle* i, CRectangle* y) {
	Collision(*y);
}

CEnemy3::CEnemy3()
	: mFx(0.0f), mFy(0.0f), mFireCount(ENEMY_SHOTTIME),m_Hp(20), m_EnemyAttackRenderCount(ENEMY_ATTACKMODEL)
{
	mTag = EENEMY;
}

void CEnemy3::Update() {
	//mEnabledがfalseなら戻る
	if (!mEnabled) return;
	//60フレームに1回発射
	if (mFireCount > 0) {
		mFireCount--;
	}
	

	if (--m_EnemyAttackRenderCount < 0) {
		//弾を4発四方へ発射する
		for (int i = 0; i < 1; i++) {
			CBullet* EBullet = new CBullet();
			//座標設定
			EBullet->x = x;
			EBullet->y = y;
			//移動量設定
			EBullet->mFx = -5;
			EBullet->mFy = 0;
			//有効にする
			EBullet->mEnabled = true;
			EBullet->mTag = EENEMYBULLET;
		}
		mFireCount = ENEMY_SHOTTIME;
		m_EnemyAttackRenderCount = ENEMY_ATTACKMODEL;
	}

	x += mFx;
	y += mFy;

}
/*
親のCollisionをオーバーライドする
衝突すると移動方向を反対にする
*/
bool CEnemy3::Collision(const CRectangle& r) {
	//mEnabledがfalseなら戻る
	if (!mEnabled) return false;
	//親のCollisionメソッドを呼び出す
	if (CRectangle::Collision(r)) {
		switch (r.mTag) {
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

void CEnemy3::Render() {
	if (mEnabled) {
		if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 4 / 5)
		{
			CRectangle::Render(EnemyTexture1, 0, 512, 512, 0);
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