#define ENEMY_ATTACKMODEL 50
#define EENEMY_COUNT 1
#define ENEMY_SYANBDYMODEL 60
#define ENEMY_FLUG_COUNT 0

#include "CEnemy.h"
#include "CTexture.h"
//extern：他のソースファイルの外部変数にアクセスする宣言

extern CTexture EnemyAttackTexture1; //スライム(移動)画像
extern CTexture EnemyMoveTexture1; //スライム(攻撃)画像
extern CTexture EnemyAttackTexture2; //スケルトン(移動)画像
extern CTexture EnemyMoveTexture2; //スケルトン(攻撃)画像
//extern CTexture EnemyAttackTexture3; //ゾンビ(移動)画像
extern CTexture EnemyMoveTexture3; //ゾンビ(攻撃)画像



CEnemy1::CEnemy1()
: mFx(0.0f), mFy(0.0f),m_Hp(20), m_EnemyAttackRenderCount(ENEMY_ATTACKMODEL), m_EnemyStandbyCount(ENEMY_SYANBDYMODEL),mEnemyflug(ENEMY_FLUG_COUNT), mEnemytype(ENEMY_FLUG_COUNT)
{
	mTag = EENEMY;
}

void CEnemy1::Update() {
	//mEnabledがfalseなら戻る
	if (!mEnabled) return;


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
					EBullet->mTag = ESLIMEBULLET;
				}
				mEnemyflug = ENEMY_FLUG_COUNT;
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
		switch (mEnemytype) {
		case 1: {
			if (mEnemyflug != 3)
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
			

			if (mEnemyflug == 3)
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
		
		}
		case 2: {
			if (mEnemyflug != 3)
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
			if (mEnemyflug == 3)
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
			if (mEnemyflug != 3)
			{
				if (m_EnemyStandbyCount > ENEMY_SYANBDYMODEL * 5 / 6)
				{
					CRectangle::Render(EnemyMoveTexture1, 15, 90, 278, 200);
				}
				else if (m_EnemyStandbyCount > ENEMY_SYANBDYMODEL * 4 / 6)
				{
					CRectangle::Render(EnemyMoveTexture1, 110, 190, 278, 200);
				}
				else if (m_EnemyStandbyCount > ENEMY_SYANBDYMODEL * 3 / 6)
				{
					CRectangle::Render(EnemyMoveTexture1, 215, 300, 278, 200);
				}
				else if (m_EnemyStandbyCount > ENEMY_SYANBDYMODEL * 2 / 6)
				{
					CRectangle::Render(EnemyMoveTexture1, 310, 395, 278, 200);
				}
				else if (m_EnemyStandbyCount > ENEMY_SYANBDYMODEL * 1 / 6)
				{
					CRectangle::Render(EnemyMoveTexture1, 410, 495, 278, 200);

				}
				else
				{
					CRectangle::Render(EnemyMoveTexture1, 15, 90, 278, 200);
				}

			}


			if (mEnemyflug == 3)
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
	//mEnabledがfalseなら戻る
	if (!mEnabled) return;

	//移動
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
				EBullet->mTag = ESKELETONBULLET;
			}
			mEnemyflug = ENEMY_FLUG_COUNT;
			m_EnemyAttackRenderCount = ENEMY_ATTACKMODEL;
		}
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
		if (mEnemyflug != 2)
		{
			if (m_EnemyStandbyCount > ENEMY_SYANBDYMODEL * 4 / 5)
			{
				CRectangle::Render(EnemyMoveTexture2, 0, 104, 185, 6);
			}
			else if (m_EnemyStandbyCount > ENEMY_SYANBDYMODEL * 3 / 5)
			{
				CRectangle::Render(EnemyMoveTexture2, 170, 277, 185, 6);
			}
			else if (m_EnemyStandbyCount > ENEMY_SYANBDYMODEL * 2 / 5)
			{
				CRectangle::Render(EnemyMoveTexture2, 342, 455, 185, 6);
			}
			else if (m_EnemyStandbyCount > ENEMY_SYANBDYMODEL * 1 / 5)
			{
				CRectangle::Render(EnemyMoveTexture2, 522, 650, 185, 6);
			}
			else
			{
				CRectangle::Render(EnemyMoveTexture2, 0, 104, 185, 6);
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
				CRectangle::Render(EnemyAttackTexture2, 435, 542, 180, 20);
			}
			else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 1 / 6)
			{
				CRectangle::Render(EnemyAttackTexture2, 562, 675, 180, 20);

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
	: mFx(0.0f), mFy(0.0f),m_Hp(20), m_EnemyAttackRenderCount(ENEMY_ATTACKMODEL), m_EnemyStandbyCount(ENEMY_SYANBDYMODEL), mEnemyflug(ENEMY_FLUG_COUNT)
{
	mTag = EENEMY;
}

void CEnemy3::Update() {
	//mEnabledがfalseなら戻る
	if (!mEnabled) return;
	
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
				EBullet->mTag = EZOMIBIEBULLET;
			}
			mEnemyflug = ENEMY_FLUG_COUNT;
			m_EnemyAttackRenderCount = ENEMY_ATTACKMODEL;
		}
	}
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
		if (mEnemyflug != 2)
		{
			if (m_EnemyStandbyCount > ENEMY_SYANBDYMODEL * 4 / 5)
			{
				CRectangle::Render(EnemyMoveTexture3, 28, 78, 127, 20);
			}
			else if (m_EnemyStandbyCount > ENEMY_SYANBDYMODEL * 3 / 5)
			{
				CRectangle::Render(EnemyMoveTexture3, 129, 179, 127, 20);
			}
			else if (m_EnemyStandbyCount > ENEMY_SYANBDYMODEL * 2 / 5)
			{
				CRectangle::Render(EnemyMoveTexture3, 242, 292, 127, 20);
			}
			else if (m_EnemyStandbyCount > ENEMY_SYANBDYMODEL * 1 / 5)
			{
				CRectangle::Render(EnemyMoveTexture3, 352, 401, 127, 20);
			}
			else
			{
				CRectangle::Render(EnemyMoveTexture3, 28, 78, 127, 20);
			}

		}
		//if (mEnemyflug == 2)
		//{
		//	if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 5 / 6)
		//	{
		//		CRectangle::Render(EnemyAttackTexture3, 28, 120, 180, 20);
		//	}
		//	else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 4 / 6)
		//	{
		//		CRectangle::Render(EnemyAttackTexture3, 160, 255, 180, 20);
		//	}
		//	else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 3 / 6)
		//	{
		//		CRectangle::Render(EnemyAttackTexture3, 290, 400, 180, 20);
		//	}
		//	else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 2 / 6)
		//	{
		//		CRectangle::Render(EnemyAttackTexture3, 435, 542, 180, 20);
		//	}
		//	else if (m_EnemyAttackRenderCount > ENEMY_ATTACKMODEL * 1 / 6)
		//	{
		//		CRectangle::Render(EnemyAttackTexture3, 562, 675, 180, 20);

		//	}
		//	else
		//	{
		//		CRectangle::Render(EnemyAttackTexture3, 28, 120, 180, 20);
		//	}
		//}
	}
}

//36
void CEnemy3::Collision(CRectangle* i, CRectangle* y) {
	Collision(*y);
}