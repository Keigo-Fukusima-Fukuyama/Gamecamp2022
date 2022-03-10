#ifndef CBACKGROUND_H
#define CBACKGROUND_H

#include "CRectangle.h"
//#include "CSceneGame.h"

class CBackGround : public CRectangle{
public:

	void Render();
	CBackGround();
	int speed;
	static CBackGround* spInstance;

private:
	CTexture mpBackGround;
};

class CBackGround2 : public CRectangle {
public:

	void Render();
	void Update();
	CBackGround2();
	int speed;
	static CBackGround2* spInstance;

private:
	CTexture mBackGround2;
};

class CBackGround3 : public CRectangle {
public:

	void Render();
	void Update();
	CBackGround3();
	int speed;
	static CBackGround3* spInstance;

private:
	CTexture mBackGround3;
};

#endif //èIóπ


