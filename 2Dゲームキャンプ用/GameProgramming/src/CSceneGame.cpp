#include "CSceneGame.h"
#include <stdio.h>
#include<stdlib.h>
//�^�X�N�}�l�[�W���N���X�̃C���N���[�h
#include "CTaskManager.h"


void CSceneGame::Init() {
	//�V�[���̐ݒ�
	mScene = EGAME;
	mDf.Init();
	mDs.Init();
	mDk.Init();

	//�N���X�̃����o�ϐ��ւ̑��
//37
	CPlayer* Player = new CPlayer();
	Player->mEnabled = true;

	

	


	
}

void CSceneGame::Update() {
	//�^�X�N�}�l�[�W���̍X�V
	CTaskManager::Get()->Update();
	//�R���W�����}�l�[�W���̍X�V
	CTaskManager::Get()->Collision();

	mDs.Update();
	mDf.Update();









	//�^�X�N���X�g�̍폜
	CTaskManager::Get()->Delete();
	//�^�X�N�}�l�[�W���̕`��	
	CTaskManager::Get()->Render();



}

	


//���̃V�[���̎擾
CScene::EScene CSceneGame::GetNextScene() {
	
	return mScene;
}
//�f�X�g���N�^
CSceneGame::~CSceneGame() {
	//�S�ẴC���X�^���X���폜���܂�
	for (int i = 0; i < VectorRect.size(); i++) {
		//�C���X�^���X�̍폜
		delete VectorRect[i];
	}
	//�ϒ��z��̃N���A
	VectorRect.clear();
}
