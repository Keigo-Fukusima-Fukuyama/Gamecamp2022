#ifndef CDRIVERSATOU_H
#define CDRIVERSATOU_H
#include "CScene.h"
#include"CPlayer.h"
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

extern CTexture Texture;



class CDriverSatou{

public :
	int mRight, mLeft,mBottom,mTop; 
	int buf;
	int mScene;
	

	void Init()
	{

		//��ʔ͈͉E�̐ݒ�
		mRight = mLeft + WINDOW_WIDTH;
		//��ʉ��̐ݒ�
		//mBottom = CPlayer::spInstance->y - HEIGHT / 2;
		mBottom = -590;
		//��ʔ͈͏�̐ݒ�
		mTop = mBottom + WINDOW_HEIGHT;

		/*��ʂ̓��e�ύX�J�n*/
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();//�s��i�ݒ�j��������
		//2D�̓��e�͈͂̐ݒ�
		gluOrtho2D(mLeft, mRight, mBottom, mTop);
		for (int i = 0; i < VectorRect.size(); i++) {
			//�`�揈��
			VectorRect[i]->Render();
		}
		glLoadIdentity();//�s��i�ݒ�j��������
	//2D�̓��e�͈͂�ݒ�
		gluOrtho2D(-960, 960, -590, 590);

		 
		//enum EScene {
		//	EGAME,	//�Q�[��
		//	ETITLE, //�^�C�g��
		//};


		//char buf[10];
		//CText::DrawString(buf, 300, 250, 16, 16);
		//if (BOSS::m_Hp == 0) {

		//	CText::DrawString("GAME CLEAR", 0 + 0 * 7, 0, 16, 16);

		//	if (CKey::Once(VK_RETURN)) {

		//		//���̃V�[���̓Q�[��
		//		 mScene =  ETITLE;



		//		//if (CEnemy1::m_Hp == 0) {
		//		//	CText::DrawString("Next Game", 0 + 0 * 7, 0, 16, 16);

		//		//	if (CKey::Once(VK_RETURN)) {

		//		//		//���̃V�[���̓Q�[��
		//		//		->mScene = ->EGAME;

		//		//	}
		//	}
		//		else {
		//			CText::DrawString(buf, 150 + 32 * 7, -250, 16, 16);
		//			if (CPlayer::mHp == 0) {

		//				CText::DrawString("GAME OVER", 0 + 0 * 7, 0, 16, 16);

		//				if (CKey::Once(VK_RETURN)) {
		//					//���̃V�[���̓Q�[��
		//					mScene = ETITLE;

		//				}
		//			}
		//		}
		//}
	}








	void Update() {
		//��ʔ͈͍��̐ݒ�
		if (3300 > mLeft) {

			mLeft++;

		}
	}
};















#endif //�I��

