#ifndef CSCENETITLE_H
#define CSCENETITLE_H

#include "CScene.h"
#include "CText.h"

class CSceneTitle : public CScene {
public:
	int x, w, y, h;

	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();
	void Render();

	virtual void Render(const CTexture& t, int left, int right
		, int bottom, int top) {
		t.DrawImage(x - w, x + w, y - h, y + h
			, left, right, bottom, top);
	}

	//���̃V�[���̎擾
	EScene GetNextScene();
};

#endif
