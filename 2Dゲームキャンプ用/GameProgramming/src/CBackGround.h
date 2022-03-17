#ifndef CBACKGROUND_H
#define CBACKGROUND_H

#include "CRectangle.h"
#include"CTexture.h"

class CBackground : public CRectangle{
public:


	CBackground();
	int speed;
	static CBackground* spInstance;

private:
	CTexture mpBackground1;
	CTexture mpBackground2;
	CTexture mpBackground3;
	CTexture mpBackground4;
	void Render();
};

class CBackground2 : public CRectangle{
public:

	
	CBackground2();
	int speed;
	static CBackground2* spInstance;

private:
	void Render();
	void Update();
	CTexture mpBackground5;
	CTexture mpBackground6;
};

class CBackground3 : public CRectangle{
public:


	CBackground3();
	int speed;
	static CBackground3* spInstance;

private:
	void Render();
	void Update();
	CTexture mpBackground7;
	CTexture mpBackground8;
};

#endif //èIóπ


