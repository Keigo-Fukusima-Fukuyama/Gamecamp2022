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
CTexture EnemyTexture1; //�G�P�̉摜
CTexture PlayerTexture1; //�v���C���[�����G
CTexture PlayerTexture2; //�v���C���[�ړ�
//CTexture PlayerTexture3; //�v���C���[�W�����v
//�V�[���}�l�[�W���̃C���X�^���X
CSceneManager SceneManager;

//Init�֐�
//�ŏ��Ɉ�x�����Ă΂��֐�
void Init() {
	EnemyTexture1.Load("res\\�X���C��.png");
	//�e�N�X�`���摜�̓ǂݍ���
	Texture.Load("res\\Image.tga");
	PlayerTexture1.Load("res\\�����G.png");
	PlayerTexture2.Load("res\\�ړ����[�V����.png");
//	PlayerTexture3.Load("res\\�W�����v���[�V����.png");
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
