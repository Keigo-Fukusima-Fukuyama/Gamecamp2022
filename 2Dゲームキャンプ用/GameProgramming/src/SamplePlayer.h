#ifndef INCLUDE_SAMPLE_PLAYER
#define INCLUDE_SAMPLE_PLAYER

#include "TaskInclude.h"
#include "SampleProperty.h"

class SamplePlayer : public Task
{
private:
	int m_Hp;				// HP
	bool m_IsDrawPause;		// 描画ポーズ
	bool m_IsDrawPriority;	// 描画順番入れ替えフラグ

	DrawTask m_Draw;		// 描画タスク操作クラス

public:
	SamplePlayer();
	~SamplePlayer();
	
private:
	// 更新関数
	void Update();

	// 描画関数
	void Draw();

};
#endif // !INCLUDE_SAMPLE_PLAYER
