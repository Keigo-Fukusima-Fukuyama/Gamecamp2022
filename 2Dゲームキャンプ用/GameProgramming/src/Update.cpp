#include "glut.h"
#include "CKey.h"
#include "CRectangle.h"
#include "CBullet.h"
#include "CPlayer.h"
#include "CEnemy.h"
#include "CText.h"
#include "CSceneManager.h"

// テクスチャクラスのインクルード
#include "CTexture.h"
CTexture Texture; //マップの画像
CTexture EnemyTexture1; //敵１の画像
CTexture PlayerTexture1; //プレイヤー立ち絵
CTexture PlayerTexture2; //プレイヤー移動
CTexture PlayerTexture3; //プレイヤージャンプ
CTexture EnemyAttackTexture1; //敵１の攻撃画像
CTexture EnemyStandbyTexture1;//敵1の待機画像
//シーンマネージャのインスタンス
CSceneManager SceneManager;

//Init関数
//最初に一度だけ呼ばれる関数
void Init() {
	EnemyTexture1.Load("res\\スライム.png");
	//テクスチャ画像の読み込み
	Texture.Load("res\\Image.tga");
	EnemyStandbyTexture1.Load("res\\スライム移動.png");
	EnemyAttackTexture1.Load("res\\スライム攻撃.png");
	PlayerTexture1.Load("res\\立ち絵.png");
	PlayerTexture2.Load("res\\移動モーション.png");
	PlayerTexture3.Load("res\\じゃんぷ.png");
	//文字画像の読み込み
	CText::mFont.Load("res\\font.tga");
	//シーンマネージャの初期化
	SceneManager.Init();
}
//Update関数
//プログラムの実行中、繰り返し呼ばれる関数
void Update() {
	//シーンマネージャの更新
	SceneManager.Update();
}
