#include"CBackGround.h"

#include"CTexture.h"

//�w�i�̃|�C���^
CBackGround* CBackGround::spInstance = nullptr;

CBackGround::CBackGround()
{
	mpBackGround.Load("res\\�Q�[���C���[�W.jpg");
	spInstance = this;
	w = 960;
	h = 990;
	mTag = EBUCKGROUND;
}

void CBackGround::Render()
{
	if (mEnabled)
	{
		CRectangle::Render(mpBackGround, 0, 1920, 1080, 0);
	}
}






