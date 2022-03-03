#ifndef INCLUDE_SAMPLE_PLAYER
#define INCLUDE_SAMPLE_PLAYER

#include "TaskInclude.h"
#include "SampleProperty.h"

class SamplePlayer : public Task
{
private:
	int m_Hp;				// HP
	bool m_IsDrawPause;		// �`��|�[�Y
	bool m_IsDrawPriority;	// �`�揇�ԓ���ւ��t���O

	DrawTask m_Draw;		// �`��^�X�N����N���X

public:
	SamplePlayer();
	~SamplePlayer();
	
private:
	// �X�V�֐�
	void Update();

	// �`��֐�
	void Draw();

};
#endif // !INCLUDE_SAMPLE_PLAYER
