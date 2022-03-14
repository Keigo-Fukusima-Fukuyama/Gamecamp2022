#include "CGameUi.h"
#include"CTaskManager.h"
#include"CPlayer.h"

extern CTexture Texture;
extern CTexture GameUI1;
extern CTexture GameUI2;

CGameUi::CGameUi()
{
	mScoreUi = 0;
	mHpUi = 0;
}

void CGameUi::Update()
{
	mHpUi=CPlayer::GetPlayerHP();

}

void CGameUi::Render()
{
}
