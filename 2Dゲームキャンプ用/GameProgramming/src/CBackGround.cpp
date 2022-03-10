#include"CBackGround.h"

#include"CTexture.h"

//�w�i�̃|�C���^
CBackGround* CBackGround::spInstance = nullptr;

CBackGround::CBackGround()
{
	mpBackGround.Load("res\\�Q�[���w�i���P���.png");
	spInstance = this;
	w = 980;
	h = 590;
	mTag = EBUCKGROUND;
}

void CBackGround::Render()
{
	if (mEnabled)
	{
		CRectangle::Render(mpBackGround, 0, 1920, 1080, 0);
	}
}
//�w�i�̃|�C���^
CBackGround2* CBackGround2::spInstance = nullptr;

CBackGround2::CBackGround2()
{
	mBackGround2.Load("res\\�Q�[���w�i���P�^��.png");
	spInstance = this;
	w = 980;
	h = 590;
	mTag = EBUCKGROUND;
}

void CBackGround2::Update()
{

	x += speed;
	if (x == -2880)
		x = 4800;
}

void CBackGround2::Render()
{
	if (mEnabled)
	{
		CRectangle::Render(mBackGround2, 0, 1920, 1080, 0);
	}
}

//�w�i�̃|�C���^
CBackGround3* CBackGround3::spInstance = nullptr;

CBackGround3::CBackGround3()
{
	mBackGround3.Load("res\\�Q�[���X�e�[�W��.png");
	spInstance = this;
	w = 980;
	h = 400;
	mTag = EBUCKGROUND;
}

void CBackGround3::Update()
{

	x += speed;
	if (x == -2880)
		x = 4800;
}

void CBackGround3::Render()
{
	if (mEnabled)
	{
		CRectangle::Render(mBackGround3, 0, 1920, 1080, 0);
	}
}






