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
	

	//�N���X�̃����o�ϐ��ւ̑��
//37
	CPlayer* Player = new CPlayer();

	Player->mEnabled = true;



	//37

	int map[6][45] =
	{
		{ 0, 0, 0, 0, 0, 0, 0, 0 ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0, 0, 0, 0, 0, 0, 0,0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0, 0, 0, 0, 0, 0, 0,0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0, 0, 0, 0, 0, 0, 0,0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0, 0, 0, 0, 0, 0, 0,0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0, 0, 0, 0, 0, 0, 0,0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0, 0,0, 0, 0, 0, 0,0 },
	};
	//37	MapSize = 0;	//0��������
	for (int j = 0; j < 6; j++) {
		for (int i = 0; i < 45; i++) {
			//map�̗v�f��1�̎��A�l�p�`�z�u
			if (map[j][i] == 1) {
				//37
				CMap* Map = new CMap();
				//�l�p�`�ɒl��ݒ�
				Map->mEnabled = true;
				Map->x = i * 100 - 350;
				Map->y = j * -100 + 250;
				Map->w = 50;
				Map->h = 50;
				//37
			}


		}

	}
	
}

void CSceneGame::Update() {

	mDs.Update();








	/*
	�z��̗v�f���J��Ԃ�
	�z��.size()
	�z��̗v�f�����擾����
	*/
	for (int i = 0; i < VectorRect.size(); i++) {
		/*
		�z��̎Q��
		�z��[�Y����]
		�ʏ�̔z�񓯗l�ɓY�����ŗv�f�ɃA�N�Z�X�ł���
		*/
		//�X�V����
		VectorRect[i]->Update();
	}
	for (int i = 0; i < VectorRect.size() - 1; i++) {
		//�Փˏ���
		for (int j = i + 1; j < VectorRect.size(); j++) {
			VectorRect[i]->Collision(VectorRect[i], VectorRect[j]);
			VectorRect[j]->Collision(VectorRect[j], VectorRect[i]);
		}
	}

	//���X�g����폜����
	//�C�e���[�^�̐���
	std::vector<CRectangle*>::iterator itr;
	//�C�e���[�^��擪
	itr = VectorRect.begin();
	//�Ō�܂ŌJ��Ԃ�
	while (itr != VectorRect.end()) {
		if ((*itr)->mEnabled) {
			//����
			itr++;
		}
		else {
			//false�̃C���X�^���X���폜
			delete* itr;
			//���X�g������폜
			itr = VectorRect.erase(itr);
		}
	}

	for (int i = 0; i < VectorRect.size(); i++) {
		//�`�揈��
		VectorRect[i]->Render();
	}

	//�^�X�N�}�l�[�W���̍X�V
	TaskManager.Update();
	//�^�X�N���X�g�̍폜
	TaskManager.Delete();
	//�^�X�N�}�l�[�W���̕`��
	TaskManager.Render();

//	CText::DrawChar('S', -350, 250, 16, 16);
//	CText::DrawChar('c', -350 + 32, 250, 16, 16);
//	CText::DrawChar('o', -350 + 32 * 2, 250, 16, 16);
//	CText::DrawChar('r', -350 + 32 * 3, 250, 16, 16);
//	CText::DrawChar('e', -350 + 32 * 4, 250, 16, 16);
//
//	CText::DrawChar('P', 150, -250, 16, 16);
//	CText::DrawChar('l', 150 + 32, -250, 16, 16);
//	CText::DrawChar('a', 150 + 32 * 2, -250, 16, 16);
//	CText::DrawChar('y', 150 + 32 * 3, -250, 16, 16);
//	CText::DrawChar('e', 150 + 32 * 4, -250, 16, 16);
//	CText::DrawChar('r', 150 + 32 * 5, -250, 16, 16);
//
//	//������̕`��
//	CText::DrawString("Time", 150, 250, 16, 16);
//	if (Time > 0) {
//		Time--;
//	}
//	//�����𕶎���ɕϊ�����
//	char buf[10];//9�����܂�OK
//	sprintf(buf, "%d", Time / 60);
//	CText::DrawString(buf, 300, 250, 16, 16);
//
//	sprintf(buf, "%d", Remain);
//	CText::DrawString(buf, 150 + 32 * 7, -250, 16, 16);
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
