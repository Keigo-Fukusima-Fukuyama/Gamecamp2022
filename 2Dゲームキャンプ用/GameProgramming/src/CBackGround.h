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
#endif //èIóπ


