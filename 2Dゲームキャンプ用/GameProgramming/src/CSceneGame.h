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
	CDriverFukshima mDF;
	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();

	EScene GetNextScene();
	//�f�X�g���N�^�̐錾
	~CSceneGame();

private:
	//�c�莞�ԁi30�b�j
	int Time = INIT_TIME;
	//�v���C���[�c�@��
	bool Remain = INIT_REMAIN;
	float val;

};

#endif
