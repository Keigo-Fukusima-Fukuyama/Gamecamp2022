#ifndef CBACKGROUND_H
#define CBACKGROUND_H

#include "CRectangle.h"
//#include "CSceneGame.h"

class CBackGround : public CRectangle{
public:

	void Render();

	CBackGround();

	static CBackGround* spInstance;

private:
	CTexture mpBackGround;
};

class CBackGround2 : public CRectangle {
public:

	void Render();

	CBackGround2();

	static CBackGround2* spInstance;

private:
	CTexture mBackGround2;
};

class CBackGround3 : public CRectangle {
public:

	void Render();

	CBackGround3();

	static CBackGround3* spInstance;

private:
	CTexture mBackGround3;
};

#endif //èIóπ


