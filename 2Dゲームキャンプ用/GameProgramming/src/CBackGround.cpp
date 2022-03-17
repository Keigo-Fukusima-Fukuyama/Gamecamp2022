#include"CBackground.h"

#include"CTexture.h"

#define BACKGROUND1_W 960
#define BACKGROUND2_W 1920
#define BACKGROUND1_H 590
#define BACKGROUND2_H 400


//�w�i�̃|�C���^
CBackground* CBackground::spInstance = nullptr;

CBackground::CBackground()
{
	mpBackground1.Load("res\\�Q�[���w�i���P���.png");
	mpBackground2.Load("res\\�����^�񒆂Q.png");
	mpBackground3.Load("res\\�Q�[���w�i��P.png");
	mpBackground4.Load("res\\���w�i.png");
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
//�w�i�̃|�C���^
CBackground2* CBackground2::spInstance = nullptr;

CBackground2::CBackground2()
{
	mpBackground5.Load("res\\�Q�[���w�i.png");
	mpBackground6.Load("res\\���^��.png");
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

//�w�i�̃|�C���^
CBackground3* CBackground3::spInstance = nullptr;

CBackground3::CBackground3()
{
	mpBackground7.Load("res\\�������.png");
	mpBackground8.Load("res\\��X�e�[�W�P.png");
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






