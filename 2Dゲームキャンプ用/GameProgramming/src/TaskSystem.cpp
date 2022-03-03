// TaskSystem.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

// タスクマネージャー関連
#include "TaskManager.h"
#include "DrawTaskManager.h"


// printf_sを使用するためにインクルード
#include <iostream>
// キー入力用のインクルード
#include <Windows.h>

// サンプルインクルード
#include "SamplePlayer.h"
#include "SampleEnemy.h"


int main()
{
	//SampleEnemy* enemy = nullptr;
	SamplePlayer* player = nullptr;
	//
	//enemy = new SampleEnemy();
	player = new SamplePlayer();

	while (true)
	{
		// キー入力で敵タスクの生成
		if (GetAsyncKeyState(VK_F12) & 0x8000)
		{
			new SampleEnemy();
		}

		// タスク更新
		TaskManager::GetInstance()->Update();
		DrawTaskManager::GetInstance()->Draw();

		printf_s("\n");

		// 終了
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
			break;


		//Sleep(1500.0f);
		Sleep(1000.0f);
		//Sleep(33.0f);
		//Sleep(16.0f);

	}

	TaskManager::ReleaseInstance();
	DrawTaskManager::ReleaseInstance();
}
