#ifndef CDRIVERSATOU_H
#define CDRIVERSATOU_H

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

class CDriverSatou{

public :
	int mRight, mLeft,mBottom,mTop;

	void Init()
	{
		
		//��ʔ͈͉E�̐ݒ�
		mRight = mLeft + WINDOW_WIDTH;
		//��ʉ��̐ݒ�
		//mBottom = CPlayer::spInstance->y - HEIGHT / 2;
		mBottom = -500;
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
		gluOrtho2D(-950, 950, -500, 500);
	}
	void Update() {
		//��ʔ͈͍��̐ݒ�
		if (3300 > mLeft) {

			mLeft++;

		}
	}
};















#endif //�I��

