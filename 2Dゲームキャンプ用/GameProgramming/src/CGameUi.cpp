#include "CGameUi.h"
#include"CTaskManager.h"
#include"CPlayer.h"

extern CTexture Texture;
extern CTexture GameUI1;
extern CTexture GameUI2;

CScoreUi::CScoreUi()
{
	mScoreUi = 0;
}

void CScoreUi::Update()
{

}

void CScoreUi::Render()
{

}



CHpUi::CHpUi()
{
	mHpUi = 0;
}

void CHpUi::Update()
{
	mHpUi=CPlayer::GetPlayerHP();
}

void CHpUi::Render()
{

}
