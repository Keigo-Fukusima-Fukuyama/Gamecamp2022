#include"SamplePlayer.h"

// printf_sを使用するためにインクルード
#include <iostream>
// キー入力用
#include <Windows.h>

SamplePlayer::SamplePlayer() :
	Task(UpdatePriority::Player,"SamplePlayer"),
	m_Hp(10),
	m_IsDrawPause(false),
	m_IsDrawPriority(false)
{
	// 描画タスクに登録
	m_Draw.RegistDraw(this, (DrawFunc)&SamplePlayer::Draw, DrawPriority::Transparent, "SamplePlayer");
}

SamplePlayer::~SamplePlayer()
{
}

void SamplePlayer::Update()
{
	// HP加算
	if (GetAsyncKeyState(VK_F3) & 0x8000)
	{
		m_Hp++;
	}
	// HP減算
	if (GetAsyncKeyState(VK_F4) & 0x8000)
	{
		m_Hp--;
	}

	// 描画ポーズ切り替え
	if (GetAsyncKeyState(VK_F6) & 0x8000)
	{
		m_IsDrawPause = !m_IsDrawPause;
		m_Draw.SetPause(m_IsDrawPause);
	}

	// 描画優先度切り替え(一例)
	if (GetAsyncKeyState(VK_F8) & 0x8000)
	{
		// プライオリティを交互に変える

		m_IsDrawPriority = !m_IsDrawPriority;

		if (m_IsDrawPriority)
		{
			m_Draw.ChangePriority(DrawPriority::Opacity);
		}
		else
		{
			m_Draw.ChangePriority(DrawPriority::Transparent);
		}
	}

	// HPが0以下になった場合は削除
	if (m_Hp <= 0)
	{
		// タスク削除
		Kill();
	}

	printf_s("Update プレイヤーHP : %d\n", m_Hp);

}

void SamplePlayer::Draw()
{
	printf_s("Draw (Transparent)プレイヤーHP : %d\n", m_Hp);
}