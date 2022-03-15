#include"CBackGround.h"

#include"CTexture.h"

//背景のポインタ
CBackGround* CBackGround::spInstance = nullptr;

CBackGround::CBackGround()
{
	mpBackGround.Load("res\\お昼真ん中２.png");
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
//背景のポインタ
CBackGround2* CBackGround2::spInstance = nullptr;

CBackGround2::CBackGround2()
{
	mBackGround2.Load("res\\お昼真ん中.png");
	spInstance = this;
	w = 980;
	h = 590;
	mTag = EBUCKGROUND;
}

void CBackGround2::Update()
{

	x += speed;
	if (x == -1920)
		x = 1920;
}

void CBackGround2::Render()
{
	if (mEnabled)
	{
		CRectangle::Render(mBackGround2, 0, 3840, 1080, 10);
	}
}

//背景のポインタ
CBackGround3* CBackGround3::spInstance = nullptr;

CBackGround3::CBackGround3()
{
	mBackGround3.Load("res\\お昼後ろ.png");
	spInstance = this;
	w = 980;
	h = 400;
	mTag = EBUCKGROUND;
}

void CBackGround3::Update()
{

	x += speed;
	if (x == -1920)
		x = 1920;
}

void CBackGround3::Render()
{
	if (mEnabled)
	{
		CRectangle::Render(mBackGround3, 0, 3840, 1080, 10);
	}
}






