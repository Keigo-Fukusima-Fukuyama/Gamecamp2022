#ifndef CMAP_H
#define CMAP_H

#include "CRectangle.h"

extern CTexture Texture;

class CMap : public CRectangle {
public:
	CMap();
	void Init();
	void Update();
};

//class CBlock : public CRectangle {
//public:
//	CBlock();
//};
//
//class CJunpAria : public CRectangle {
//public:
//	CJunpAria();
//};
//
//class CRail : public CRectangle {
//public:
//	CRail();
//};

#endif
