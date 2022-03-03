#ifndef INCLUDE_SAMPLE_ENEMY
#define INCLUDE_SAMPLE_ENEMY

#include "TaskInclude.h"
#include "SampleProperty.h"

class SampleEnemy : public Task
{
private:
	int m_Hp;				// HP
	bool m_IsDrawPause;		// �`��|�[�Y
	bool m_IsDrawPriority;	// �`�揇�ԓ���ւ��t���O

	DrawTask m_Draw;		// �`��^�X�N����N���X
	DrawTask m_DrawOpacity;	// �`��^�X�N����N���X

public:
	SampleEnemy();
	~SampleEnemy();

private:
	// �X�V�֐�
	void Update();

	// �`��֐�
	void Draw();
	// �`��֐�
	void DrawOpacity();
};
#endif // !INCLUDE_SAMPLE_ENEMY
