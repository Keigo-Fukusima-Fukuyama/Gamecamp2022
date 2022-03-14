#include "CGameUi.h"
#include"CTaskManager.h"
#include"CPlayer.h"

extern CTexture Texture;
extern CTexture GameUI1;
extern CTexture GameUI2;

CGameUi::CGameUi()
{
	h = 20;
	w = 20;
	x = 550;
	y = 900;
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
