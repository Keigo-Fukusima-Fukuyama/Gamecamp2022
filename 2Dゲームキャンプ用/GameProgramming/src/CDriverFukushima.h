#ifndef CDRUVERFUKUSHIMA_H
#define CDRUVERFUKUSHIMA_H

#include"CEnemy.h"
#include "CBackGround.h"

class CDriverFukushima 
{
public:


	void Init() 
	{

		//�X�N���[�����̔w�i
		//�w�i�N���X�̃����o�ϐ��ւ̑��
		CBackGround* BackGround = new CBackGround();
		//�X�N���[���ɒl��ݒ�
		BackGround->x = 0;
		BackGround->y = 25;
		//�L���ɂ���
		BackGround->mEnabled = true;

		//�X�N���[����O�̔w�i
		//�w�i�N���X�̃����o�ϐ��ւ̑��
		CBackGround2* BackGround2 = new CBackGround2();
		//�X�N���[���ɒl��ݒ�
		BackGround2->x = 0;
		BackGround2->y = -25;
		//�L���ɂ���
		BackGround2->mEnabled = true;

		//�}�b�v�̔w�i
		//�w�i�N���X�̃����o�ϐ��ւ̑��
		CBackGround3* BackGround3 = new CBackGround3();
		//�X�N���[���ɒl��ݒ�
		BackGround3->x = 0;
		BackGround3->y = -25;
		//�L���ɂ���
		BackGround3->mEnabled = true;

		//�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
		CEnemy1* Enemy = new CEnemy1();
		Enemy->mEnemytype = 3;
		//�G�ɒl��ݒ�
		Enemy->x = 790;
		Enemy->y = -100;
		Enemy->w = 100;
		Enemy->h = 100;
		//�L���ɂ���
		Enemy->mEnabled = true;
	}


};


#endif 

