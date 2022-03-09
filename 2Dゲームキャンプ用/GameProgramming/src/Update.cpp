#include "glut.h"
#include "CKey.h"
#include "CRectangle.h"
#include "CBullet.h"
#include "CPlayer.h"
#include "CEnemy.h"
#include "CText.h"
#include "CSceneManager.h"

// �e�N�X�`���N���X�̃C���N���[�h
#include "CTexture.h"
CTexture Texture; //�}�b�v�̉摜
CTexture PlayerTexture1; //�v���C���[�����G
CTexture PlayerTexture2; //�v���C���[�ړ�
CTexture PlayerTexture3; //�v���C���[�W�����v
CTexture EnemyMoveTexture1;//�X���C���̈ړ��摜
CTexture EnemyAttackTexture1; //�X���C���̂̍U���摜
CTexture EnemyMoveTexture2;//�X�P���g���̈ړ��摜
CTexture EnemyAttackTexture2; //�X�P���g���̍U���摜

//�V�[���}�l�[�W���̃C���X�^���X
CSceneManager SceneManager;

//Init�֐�
//�ŏ��Ɉ�x�����Ă΂��֐�
void Init() {
	//�e�N�X�`���摜�̓ǂݍ���
	Texture.Load("res\\Image.tga");
	EnemyMoveTexture1.Load("res\\�X���C���ړ�.png");
	EnemyAttackTexture1.Load("res\\�X���C���U��.png");
	EnemyMoveTexture2.Load("res\\�X�P���g���ړ�.png");
	EnemyAttackTexture2.Load("res\\�X�P���g���U��.png");
	PlayerTexture1.Load("res\\�����G.png");
	PlayerTexture2.Load("res\\�ړ����[�V����.png");
	PlayerTexture3.Load("res\\������.png");
	//�����摜�̓ǂݍ���
	CText::mFont.Load("res\\font.tga");
	//�V�[���}�l�[�W���̏�����
	SceneManager.Init();
}
//Update�֐�
//�v���O�����̎��s���A�J��Ԃ��Ă΂��֐�
void Update() {
	//�V�[���}�l�[�W���̍X�V
	SceneManager.Update();
}
