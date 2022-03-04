#include"CBackGround.h"

#include"CTexture.h"

//�w�i�̃|�C���^
CBackGround* CBackGround::spInstance = nullptr;

CBackGround::CBackGround()
{
	mpBackGround.Load("res\\���G.png");
	spInstance = this;
	w = 960;
	h = 540;
	mTag = EBUCKGROUND;
}

void CBackGround::Render()
{
	if (mEnabled)
	{
		CRectangle::Render(mpBackGround, 0, 450, 150, 0);
	}
}
