#define INIT_GAMETIME 1
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
// テクスチャクラスのインクルード
#include "CTexture.h"


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

	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();

	EScene GetNextScene();
	//デストラクタの宣言
	~CSceneGame();

private:
	bool GameTime;
	//残り時間（30秒）
	int Time = INIT_TIME;
	//プレイヤー残機数
	bool Remain = INIT_REMAIN;
	float val;

};

#endif
