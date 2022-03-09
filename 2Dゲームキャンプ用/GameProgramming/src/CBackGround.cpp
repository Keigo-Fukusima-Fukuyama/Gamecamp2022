#include"CBackGround.h"

#include"CTexture.h"

//”wŒi‚Ìƒ|ƒCƒ“ƒ^
CBackGround* CBackGround::spInstance = nullptr;

CBackGround::CBackGround()
{
	mpBackGround.Load("res\\ƒQ[ƒ€”wŒi’‹‚PŒã‚ë.png");
	spInstance = this;
	w = 960;
	h = 500;
	mTag = EBUCKGROUND;
}

void CBackGround::Render()
{
	if (mEnabled)
	{
		CRectangle::Render(mpBackGround, 0, 1920, 1080, 0);
	}
}
//”wŒi‚Ìƒ|ƒCƒ“ƒ^
CBackGround2* CBackGround2::spInstance = nullptr;

CBackGround2::CBackGround2()
{
	mBackGround2.Load("res\\ƒQ[ƒ€”wŒi’‹‚P^‚ñ’†.png");
	spInstance = this;
	w = 960;
	h = 500;
	mTag = EBUCKGROUND;
}

void CBackGround2::Render()
{
	if (mEnabled)
	{
		CRectangle::Render(mBackGround2, 0, 1920, 1080, 0);
	}
}

//”wŒi‚Ìƒ|ƒCƒ“ƒ^
CBackGround3* CBackGround3::spInstance = nullptr;

CBackGround3::CBackGround3()
{
	mBackGround3.Load("res\\ƒQ[ƒ€ƒXƒe[ƒW’‹.png");
	spInstance = this;
	w = 960;
	h = 500;
	mTag = EBUCKGROUND;
}

void CBackGround3::Render()
{
	if (mEnabled)
	{
		CRectangle::Render(mBackGround3, 0, 1920, 1080, 0);
	}
}






