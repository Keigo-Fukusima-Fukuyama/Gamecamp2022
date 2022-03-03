#include "SampleEnemy.h"

// printf_s���g�p���邽�߂ɃC���N���[�h
#include <iostream>
// �L�[���͗p
#include <Windows.h>

SampleEnemy::SampleEnemy() :
	Task(UpdatePriority::Enemy, "SampleEnemy"),
	m_Hp(10),
	m_IsDrawPause(false),
	m_IsDrawPriority(false)
{
	// �`��^�X�N�ɓo�^
	m_Draw.RegistDraw(this, (DrawFunc)&SampleEnemy::Draw, DrawPriority::Transparent, "SampleEnemy");
	m_DrawOpacity.RegistDraw(this, (DrawFunc)&SampleEnemy::DrawOpacity, DrawPriority::Opacity, "SampleEnemyOpacity");
}

SampleEnemy::~SampleEnemy()
{
}

void SampleEnemy::Update()
{
	// HP���Z
	if (GetAsyncKeyState(VK_F1) & 0x8000)
	{
		m_Hp++;
	}
	// HP���Z
	if (GetAsyncKeyState(VK_F2) & 0x8000)
	{
		m_Hp--;
	}

	// �`��|�[�Y�؂�ւ�
	if (GetAsyncKeyState(VK_F5) & 0x8000)
	{
		m_IsDrawPause = !m_IsDrawPause;
		m_Draw.SetPause(m_IsDrawPause);
		m_DrawOpacity.SetPause(m_IsDrawPause);
	}

	// �`��D��x�؂�ւ�
	if (GetAsyncKeyState(VK_F9) & 0x8000)
	{
		// �v���C�I���e�B�����݂ɕς���

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

	// �`��^�X�N�o�^����
	if (GetAsyncKeyState(VK_DELETE) & 0x8000)
	{
		// �o�^����
		m_Draw.Remove();
	}

	// �`��^�X�N�ēo�^
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		// �`��^�X�N���o�^����Ă��Ȃ��ꍇ�ɍēo�^����
		if (!m_Draw.IsRegist())
		{
			m_Draw.RegistDraw(this, (DrawFunc)&SampleEnemy::Draw, DrawPriority::Transparent, "SampleEnemy");
		}
	}

	// HP��0�ȉ��ɂȂ����ꍇ�͍폜
	if (m_Hp <= 0)
	{
		// �폜
		Kill();
	}

	printf_s("Update �G�l�~�[HP : %d\n", m_Hp);
}

void SampleEnemy::Draw()
{
	printf_s("Draw (Transparent)�G�l�~�[HP : %d\n", m_Hp);
}

void SampleEnemy::DrawOpacity()
{
	printf_s("Draw (Opacity)�G�l�~�[HP : %d\n", m_Hp);
}
