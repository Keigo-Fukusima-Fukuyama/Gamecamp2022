#ifndef CSCENETITLE_H
#define CSCENETITLE_H

#include "CScene.h"
#include "CText.h"

class CSceneTitle : public CScene {
public:
	int Title;

	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();
	void Render();
	void Draw(float left, float right, float bottom, float top, float tleft, float tright, float tbottom, float ttop) const;
	

	//���̃V�[���̎擾
	EScene GetNextScene();
};

#endif
