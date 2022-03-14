#ifndef CGAMEUI_H
#define CGAMEUI_H

#include "CRectangle.h"

class CGameUi : public CRectangle {
public:
	CGameUi();
	void Update();
	void Render();
private:
	int mScoreUi, mHpUi;
};

#endif
