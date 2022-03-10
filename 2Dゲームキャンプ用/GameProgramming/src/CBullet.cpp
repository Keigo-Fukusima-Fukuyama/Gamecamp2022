/*Test*/
#include "CBullet.h"
#include "CTexture.h"
//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture Texture;
//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture EnemyAttackBulTex;

//デフォルトコンストラクタ
CBullet::CBullet()
: mFx(0), mFy(0)
{
	mEnabled = false;
	w = 100;	//幅設定
	h = 50;	//高さ設定
}

//更新処理
void CBullet::Update() {
	//有効な時
	if (mEnabled) {
		//移動
		x += mFx;
		y += mFy;
		if (x > 960 || x < -960 || y > 540 || y < -540)
			mEnabled = false;
	}
}

//描画処理
void CBullet::Render() {
	////有効な時
	//if (mEnabled) {
	//	//親の描画メソッドを呼ぶ
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
