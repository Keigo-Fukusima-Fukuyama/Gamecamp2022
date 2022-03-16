#include"CBackGround.h"

#include"CTexture.h"

//�w�i�̃|�C���^
CBackGround* CBackGround::spInstance = nullptr;

CBackGround::CBackGround()
{
	mpBackGround.Load("res\\�����^�񒆂Q.png");
	spInstance = this;
	w = 980;
	h = 590;
	mTag = EBUCKGROUND;
	mPriority = 11;
	CTaskManager::Get()->Remove(this);
	CTaskManager::Get()->Add(this);
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
	mBackGround2.Load("res\\�����^��.png");
	spInstance = this;
	w = 980;
	h = 590;
	mTag = EBUCKGROUND;
	mPriority = 10;
	CTaskManager::Get()->Remove(this);
	CTaskManager::Get()->Add(this);
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

//�w�i�̃|�C���^
CBackGround3* CBackGround3::spInstance = nullptr;

CBackGround3::CBackGround3()
{
	mBackGround3.Load("res\\�������.png");
	spInstance = this;
	w = 980;
	h = 400;
	mTag = EBUCKGROUND;
	mPriority = 9;
	CTaskManager::Get()->Remove(this);
	CTaskManager::Get()->Add(this);
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






