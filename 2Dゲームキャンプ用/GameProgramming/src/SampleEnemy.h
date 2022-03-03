#ifndef INCLUDE_SAMPLE_ENEMY
#define INCLUDE_SAMPLE_ENEMY

#include "TaskInclude.h"
#include "SampleProperty.h"

class SampleEnemy : public Task
{
private:
	int m_Hp;				// HP
	bool m_IsDrawPause;		// 描画ポーズ
	bool m_IsDrawPriority;	// 描画順番入れ替えフラグ

	DrawTask m_Draw;		// 描画タスク操作クラス
	DrawTask m_DrawOpacity;	// 描画タスク操作クラス

public:
	SampleEnemy();
	~SampleEnemy();

private:
	// 更新関数
	void Update();

	// 描画関数
	void Draw();
	// 描画関数
	void DrawOpacity();
};
#endif // !INCLUDE_SAMPLE_ENEMY
