#define GAMETIME 1
#define TIME 30 * 60
#define REMAIN 3

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
// �e�N�X�`���N���X�̃C���N���[�h
#include "CTexture.h"


/*
�Q�[���̃V�[��
*/
//CScene�N���X���p������
class CSceneGame : public CScene {
public:
	//37
	//CTexture Texture; //�}�b�v�̉摜
	//CPlayer Player;
	//CMap Map[48];
	//int MapSize;
	//CBullet Bullet[10];
	//int FireCount = 10;
	//CEnemy Enemy[10];
	//37

	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();

	EScene GetNextScene();
	//�f�X�g���N�^�̐錾
	~CSceneGame();

private:
	bool GameTime;
	//�c�莞�ԁi30�b�j
	bool Time = TIME;
	//�v���C���[�c�@��
	bool Remain = REMAIN;
	float val;

};

#endif
