#ifndef CDRUVERFUKUSHIMA_H
#define CDRUVERFUKUSHIMA_H

#include "CBackGround.h"

class CDriverFukshima 
{
public:
	void init() 
	{
		//�X�N���[���ꖇ��
		//�X�N���[���N���X�̃����o�ϐ��ւ̑��
		CBackGround* BackGround = new CBackGround();
		//�X�N���[���ɒl��ݒ�
		BackGround->x = 0;
		BackGround->y = 200;
		//�L���ɂ���
		BackGround->mEnabled = true;
	}



};


#endif 

