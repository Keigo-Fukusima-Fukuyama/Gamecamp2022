#ifndef CENEMY_H
#define CENEMY_H

#include "CRectangle.h"
#include "CBullet.h"

class CEnemy : public CRectangle {

public:
	int mFx; //X²•ûŒü‚ÌˆÚ“® -1:¶ 0:ˆÚ“®‚µ‚È‚¢ 1:‰E‚ÖˆÚ“®
	int mFy; //Y²•ûŒü‚ÌˆÚ“® -1:‰º 0:ˆÚ“®‚µ‚È‚¢ 1:ã‚ÖˆÚ“®
	

	void Update();
	bool Collision(const CRectangle &r);
	void Render();

	//36
	void Collision(CRectangle *i, CRectangle *y);
	CEnemy();
private:
	
	int mFireCount;
	int m_Hp; //HP
	int m_EnemyRenderCount;
	int i;
};
#endif
