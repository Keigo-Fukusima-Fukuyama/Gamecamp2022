#ifndef CGAMEUI_H
#define CGAMEUI_H

#include "CRectangle.h"

class CScoreUi : public CRectangle {
public:
	CScoreUi();
	void Update();
	void Render();
private:
	int mScoreUi;
};
class CHpUi : public CRectangle {
public:
	CHpUi();
	void Update();
	void Render();
private:
	int mHpUi;
};

#endif
