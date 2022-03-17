#include"CBackground.h"

#include"CTexture.h"

#define BACKGROUND1_W 960
#define BACKGROUND2_W 1920
#define BACKGROUND1_H 590
#define BACKGROUND2_H 400


//”wŒi‚Ìƒ|ƒCƒ“ƒ^
CBackground* CBackground::spInstance = nullptr;

CBackground::CBackground()
{
	mpBackground1.Load("res\\ƒQ[ƒ€”wŒi’‹‚PŒã‚ë.png");
	mpBackground2.Load("res\\‚¨’‹^‚ñ’†‚Q.png");
	mpBackground3.Load("res\\ƒQ[ƒ€”wŒi–é‚P.png");
	mpBackground4.Load("res\\–é•æ”wŒi.png");
	spInstance = this;
	w = BACKGROUND1_W;
	h = BACKGROUND1_H;
	mTag = EBUCKGROUND;
	mPriority = 11;
	CTaskManager::Get()->Remove(this);
	CTaskManager::Get()->Add(this);
}

void CBackground::Render()
{
	if (mEnabled)
	{
		CRectangle::Render(mpBackground1, 0, 1920, 1080, 0);
	}
}
//”wŒi‚Ìƒ|ƒCƒ“ƒ^
CBackground2* CBackground2::spInstance = nullptr;

CBackground2::CBackground2()
{
	mpBackground5.Load("res\\ƒQ[ƒ€”wŒi.png");
	mpBackground6.Load("res\\–é•æ^‚ñ’†.png");
	spInstance = this;
	w = BACKGROUND2_W;
	h = BACKGROUND1_H;
	mTag = EBUCKGROUND;
	mPriority = 10;
	CTaskManager::Get()->Remove(this);
	CTaskManager::Get()->Add(this);
}

void CBackground2::Update()
{

	x += speed;
	if (x == -3840)
		x = 3840;
}

void CBackground2::Render()
{
	if (mEnabled)
	{
		CRectangle::Render(mpBackground5, 0, 3840, 1080, 10);
	}
}

//”wŒi‚Ìƒ|ƒCƒ“ƒ^
CBackground3* CBackground3::spInstance = nullptr;

CBackground3::CBackground3()
{
	mpBackground7.Load("res\\‚¨’‹Œã‚ë.png");
	mpBackground8.Load("res\\–éƒXƒe[ƒW‚P.png");
	spInstance = this;
	w = BACKGROUND2_W;
	h = BACKGROUND2_H;
	mTag = EBUCKGROUND;
	mPriority = 9;
	CTaskManager::Get()->Remove(this);
	CTaskManager::Get()->Add(this);
}

void CBackground3::Update()
{

	x += speed;
	if (x == -3840)
		x = 3840;
}

void CBackground3::Render()
{
	if (mEnabled)
	{
		CRectangle::Render(mpBackground7, 0, 3840, 1080, 10);
	}
}






