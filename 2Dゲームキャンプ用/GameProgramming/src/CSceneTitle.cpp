#include "CSceneTitle.h"
#include "CKey.h"

extern CTexture Texture;
extern CTexture Title;

void CSceneTitle::Init() {
	//�V�[���̐ݒ�
	mScene = ETITLE;

}

//�X�V�����̃I�[�o�[���C�h
void CSceneTitle::Update() {
	//������̕`��
	/*CText::DrawString("TITLE", -200, 0, 50, 50);
	CText::DrawString("Push ENTER Key",
		-200, -100, 16, 16);*/
	CText::DrawString("res\\taitoru.png", 0, 1920, 1080, 0);
	if (CKey::Once(VK_RETURN)) {
		//���̃V�[���̓Q�[��
		mScene = EGAME;
	}
}
//���̃V�[���̎擾
CScene::EScene CSceneTitle::GetNextScene() {
	return mScene;
}
