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
CTexture PlayerTexture1; //プレイヤー立ち絵
CTexture PlayerTexture2; //プレイヤー移動
CTexture PlayerTexture3; //プレイヤージャンプ
CTexture EnemyMoveTexture1;//スライムの移動画像
CTexture EnemyAttackTexture1; //スライムのの攻撃画像
CTexture EnemyMoveTexture2;//スケルトンの移動画像
CTexture EnemyAttackTexture2; //スケルトンの攻撃画像
CTexture EnemyMoveTexture3; //ゾンビの移動画像
CTexture EnemyAttackTexture3; //ゾンビの攻撃画像

//シーンマネージャのインスタンス
CSceneManager SceneManager;

//Init関数
//最初に一度だけ呼ばれる関数
void Init() {
	//テクスチャ画像の読み込み
	Texture.Load("res\\Image.tga");
	EnemyMoveTexture1.Load("res\\スライム移動.png");
	EnemyAttackTexture1.Load("res\\スライム攻撃.png");
	EnemyMoveTexture2.Load("res\\スケルトン移動.png");
	EnemyAttackTexture2.Load("res\\スケルトン攻撃.png");
	EnemyMoveTexture3.Load("res\\ゾンビ移動.png");
	EnemyAttackTexture3.Load("");
	PlayerTexture1.Load("res\\tatie.png");
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
