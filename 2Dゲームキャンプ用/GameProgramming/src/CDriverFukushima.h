#ifndef CDRUVERFUKUSHIMA_H
#define CDRUVERFUKUSHIMA_H

#include"CEnemy.h"
#include "CBackGround.h"

class CDriverFukshima 
{
public:
	void Init() 
	{
		////�X�N���[���ꖇ��
		////�X�N���[���N���X�̃����o�ϐ��ւ̑��
		//CBackGround* BackGround = new CBackGround();
		////�X�N���[���ɒl��ݒ�
		//BackGround->x = 0;
		//BackGround->y = 200;
		////�L���ɂ���
		//BackGround->mEnabled = true;

		//�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
		CEnemy* Enemy = new CEnemy();
		//�G�ɒl��ݒ�
		Enemy->x = 0;
		Enemy->y = 0;
		Enemy->w = 200;
		Enemy->h = 200;
		Enemy->mFx = -1;
		//�L���ɂ���
		Enemy->mEnabled = true;
	}


};


#endif 

