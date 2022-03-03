#include"SamplePlayer.h"

// printf_s���g�p���邽�߂ɃC���N���[�h
#include <iostream>
// �L�[���͗p
#include <Windows.h>

SamplePlayer::SamplePlayer() :
	Task(UpdatePriority::Player,"SamplePlayer"),
	m_Hp(10),
	m_IsDrawPause(false),
	m_IsDrawPriority(false)
{
	// �`��^�X�N�ɓo�^
	m_Draw.RegistDraw(this, (DrawFunc)&SamplePlayer::Draw, DrawPriority::Transparent, "SamplePlayer");
}

SamplePlayer::~SamplePlayer()
{
}

void SamplePlayer::Update()
{
	// HP���Z
	if (GetAsyncKeyState(VK_F3) & 0x8000)
	{
		m_Hp++;
	}
	// HP���Z
	if (GetAsyncKeyState(VK_F4) & 0x8000)
	{
		m_Hp--;
	}

	// �`��|�[�Y�؂�ւ�
	if (GetAsyncKeyState(VK_F6) & 0x8000)
	{
		m_IsDrawPause = !m_IsDrawPause;
		m_Draw.SetPause(m_IsDrawPause);
	}

	// �`��D��x�؂�ւ�(���)
	if (GetAsyncKeyState(VK_F8) & 0x8000)
	{
		// �v���C�I���e�B�����݂ɕς���

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

	// HP��0�ȉ��ɂȂ����ꍇ�͍폜
	if (m_Hp <= 0)
	{
		// �^�X�N�폜
		Kill();
	}

	printf_s("Update �v���C���[HP : %d\n", m_Hp);

}

void SamplePlayer::Draw()
{
	printf_s("Draw (Transparent)�v���C���[HP : %d\n", m_Hp);
}