#include "SampleEnemy.h"

// printf_sを使用するためにインクルード
#include <iostream>
// キー入力用
#include <Windows.h>

SampleEnemy::SampleEnemy() :
	Task(UpdatePriority::Enemy, "SampleEnemy"),
	m_Hp(10),
	m_IsDrawPause(false),
	m_IsDrawPriority(false)
{
	// 描画タスクに登録
	m_Draw.RegistDraw(this, (DrawFunc)&SampleEnemy::Draw, DrawPriority::Transparent, "SampleEnemy");
	m_DrawOpacity.RegistDraw(this, (DrawFunc)&SampleEnemy::DrawOpacity, DrawPriority::Opacity, "SampleEnemyOpacity");
}

SampleEnemy::~SampleEnemy()
{
}

void SampleEnemy::Update()
{
	// HP加算
	if (GetAsyncKeyState(VK_F1) & 0x8000)
	{
		m_Hp++;
	}
	// HP減算
	if (GetAsyncKeyState(VK_F2) & 0x8000)
	{
		m_Hp--;
	}

	// 描画ポーズ切り替え
	if (GetAsyncKeyState(VK_F5) & 0x8000)
	{
		m_IsDrawPause = !m_IsDrawPause;
		m_Draw.SetPause(m_IsDrawPause);
		m_DrawOpacity.SetPause(m_IsDrawPause);
	}

	// 描画優先度切り替え
	if (GetAsyncKeyState(VK_F9) & 0x8000)
	{
		// プライオリティを交互に変える

		m_IsDrawPriority = !m_IsDrawPriority;

		if (m_IsDrawPriority)
		{
			m_Draw.ChangePriority(DrawPriority::Opacity);
			m_DrawOpacity.ChangePriority(DrawPriority::Transparent);
		}
		else
		{
			m_Draw.ChangePriority(DrawPriority::Transparent);
			m_DrawOpacity.ChangePriority(DrawPriority::Opacity);
		}
	}

	// 描画タスク登録解除
	if (GetAsyncKeyState(VK_DELETE) & 0x8000)
	{
		// 登録解除
		m_Draw.Remove();
	}

	// 描画タスク再登録
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		// 描画タスクが登録されていない場合に再登録する
		if (!m_Draw.IsRegist())
		{
			m_Draw.RegistDraw(this, (DrawFunc)&SampleEnemy::Draw, DrawPriority::Transparent, "SampleEnemy");
		}
	}

	// HPが0以下になった場合は削除
	if (m_Hp <= 0)
	{
		// 削除
		Kill();
	}

	printf_s("Update エネミーHP : %d\n", m_Hp);
}

void SampleEnemy::Draw()
{
	printf_s("Draw (Transparent)エネミーHP : %d\n", m_Hp);
}

void SampleEnemy::DrawOpacity()
{
	printf_s("Draw (Opacity)エネミーHP : %d\n", m_Hp);
}
