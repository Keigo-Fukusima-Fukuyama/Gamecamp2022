#include "CSceneTitle.h"
#include "CKey.h"
#include "CRectangle.h"

extern CTexture Title;


void CSceneTitle::Init() {
	//�V�[���̐ݒ�
	mScene = ETITLE;


}



//void CSceneTitle::Render() {
//	
//	Draw(Title,0,1920, 1080,0,0,0,0);
//
//}







//�X�V�����̃I�[�o�[���C�h
void CSceneTitle::Update() {
	Title.Draw(-1000, 1000, -520, 520, 0, 1920, 1080, 0);
	//������̕`��
	/*CText::DrawString("TITLE", -200, 0, 50, 50);
	CText::DrawString("Push ENTER Key",
		-200, -100, 16, 16);*/
	
	
	if (CKey::Once(VK_RETURN)) {
		//���̃V�[���̓Q�[��
		mScene = EGAME;
	}
}




//���̃V�[���̎擾
CScene::EScene CSceneTitle::GetNextScene() {
	return mScene;
}
