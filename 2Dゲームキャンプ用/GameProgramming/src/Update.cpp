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
CTexture PlayerTexture0; //�v���C���[�����G
CTexture PlayerTexture1; //�v���C���[�ړ�
CTexture PlayerTexture2; //�v���C���[�W�����v
CTexture PlayerTexture3; //�v���C���[�U��
CTexture PlayerTexture4; //�v���C���[��e
CTexture PlayerAttack; //�v���C���[ �e
CTexture EnemyMoveTexture1;//�X���C���̈ړ��摜
CTexture EnemyAttackTexture1; //�X���C���̍U���摜
CTexture EnemyAttackBulTex; //�X���C���̒e�摜
CTexture EnemyMoveTexture2;//�X�P���g���̈ړ��摜
CTexture EnemyAttackTexture2; //�X�P���g���̍U���摜
CTexture EnemyMoveTexture3; //�]���r�̈ړ��摜
CTexture EnemyAttackTexture3; //�]���r�̍U���摜
CTexture GameUI1; //�Q�[��UI����
CTexture GameUI2; //�Q�[��UIHP

//�V�[���}�l�[�W���̃C���X�^���X
CSceneManager SceneManager;

//Init�֐�
//�ŏ��Ɉ�x�����Ă΂��֐�
void Init() {
	//�e�N�X�`���摜�̓ǂݍ���
	Texture.Load("res\\Image.tga");
	EnemyMoveTexture1.Load("res\\�X���C���ړ�.png");
	EnemyAttackTexture1.Load("res\\�X���C���U��.png");
	EnemyAttackBulTex.Load("res\\�X���C���������U��.png");
	EnemyMoveTexture2.Load("res\\�X�P���g���ړ�.png");
	EnemyAttackTexture2.Load("res\\�X�P���g���U��.png");
	EnemyMoveTexture3.Load("res\\�]���r�ړ�.png");
	/*EnemyAttackTexture3.Load("");*/
	PlayerTexture0.Load("res\\tatie.png"); //0 �����G
	PlayerTexture1.Load("res\\�v���C���[�ړ�.png"); //1 ����
	PlayerTexture2.Load("res\\�W�����v���[�V����.png");  //2 �W�����v
	PlayerTexture3.Load("res\\�U�����[�V����.png");  //3 �U��
	PlayerTexture4.Load("res\\��g���[�V����.png");  //4 ��e
	PlayerAttack.Load("res\\�����@.png");  //�v���C���[ �e
	GameUI1.Load("res\\����.png"); //����
	GameUI2.Load("res\\HP.png"); //HP
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
