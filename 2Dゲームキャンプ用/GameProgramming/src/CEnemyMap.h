#ifndef CENEMYMAP_H
#define CENEMYMAP_H

#include"CEnemy.h"
/*
CEnemyMap
�G�̃}�b�v�N���X
*/

class CEnemyMap{
public:
	CEnemyMap();
	void Update();

private:
	int mEnemyMapRand;
	int mEnemyFlag;
	int mEnemyTypeRand;
	
};
#endif

