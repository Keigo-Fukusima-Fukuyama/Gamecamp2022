#ifndef CSCENETITLE_H
#define CSCENETITLE_H

#include "CScene.h"
#include "CText.h"

class CSceneTitle : public CScene {
public:
	int x, w, y, h;

	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();
	void Render();

	virtual void Render(const CTexture& t, int left, int right
		, int bottom, int top) {
		t.DrawImage(x - w, x + w, y - h, y + h
			, left, right, bottom, top);
	}

	//次のシーンの取得
	EScene GetNextScene();
};

#endif
