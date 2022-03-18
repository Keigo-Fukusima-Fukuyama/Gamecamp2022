#define INIT_TIME 30 * 60
#define INIT_REMAIN 3

#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
#include "CKey.h"
#include "CRectangle.h"
#include "CBullet.h"
#include "CPlayer.h"
#include "CEnemy.h"
#include "CText.h"
#include "CMap.h"
#include "CBackGround.h"
#include"CDriverFukushima.h"
#include "CDriverSatou.h"
#include "CDriverKawahara.h"
// テクスチャクラスのインクルード
#include "CTexture.h"
//#include "CGameUi.h"

/*
ゲームのシーン
*/
//CSceneクラスを継承する
class CSceneGame : public CScene {
public:
	//37
	//CTexture Texture; //マップの画像
	//CPlayer Player;
	//CMap Map[48];
	//int MapSize;
	//CBullet Bullet[10];
	//int FireCount = 10;
	//CEnemy Enemy[10];
	//37

	//デストラクタの宣言
	~CSceneGame();

private:
	//残り時間（30秒）
	int Time = INIT_TIME;
	//プレイヤー残機数
	bool Remain = INIT_REMAIN;
	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();
	CDriverFukushima mDf;
	CDriverSatou mDs;
	CDriverKawahara mDk;
	EScene GetNextScene();
};

#endif
