#include "CGameUi.h"

extern CTexture Texture;
extern CTexture GameUI1;
extern CTexture GameUI2;

CScoreUi::CScoreUi()
{
	y = 0;
	x = -0;
	mScoreCnt = 0;
	mScoreUi = 0;
	//CTaskManager::Get()->Remove(this);
	//CTaskManager::Get()->Add(this);
}

void CScoreUi::Update()
{

}

void CScoreUi::Render()
{
	CRectangle::Render(GameUI1, mScoreCnt * 30, (mScoreCnt + 1) * 30, 30, 0);
}



CHpUi::CHpUi()
{
	mHpCnt = 0;
	mHpUi = 0;
	y = 0;
	x = 0;
	h = 50;
	w = 50;
	mEnabled = true;
	mTag = EUI;
	//mPriority = 7;
	//CTaskManager::Get()->Remove(this);
	//CTaskManager::Get()->Add(this);
}

void CHpUi::Update()
{
	mHpUi = GetPlayerHP();
	for (int i = 0; i < 5; i++)
	{

		
	}

}

void CHpUi::Render()
{
	if (mEnabled) {
		CRectangle::Render(GameUI2, mHpCnt * 345, (mHpCnt + 1) * 345, 345, 0);
	}
}