#ifndef CDRUVERFUKUSHIMA_H
#define CDRUVERFUKUSHIMA_H

#include"CEnemy.h"
#include "CBackGround.h"

class CDriverFukushima 
{
public:


	void Init() 
	{

		//�X�N���[�����鉜�̔w�i
		//�w�i�N���X�̃����o�ϐ��ւ̑��
		CBackGround* BackGround = new CBackGround();
		//�X�N���[���ɒl��ݒ�
		BackGround->x = 0;
		BackGround->y = 25;
		//�L���ɂ���
		BackGround->mEnabled = true;

		//�X�N���[�������O�̔w�i
		//�w�i�N���X�̃����o�ϐ��ւ̑��
		CBackGround2* BackGround2 = new CBackGround2();
		//�X�N���[���ɒl��ݒ�
		BackGround2->x = 0;
		BackGround2->y = -25;
		//�L���ɂ���
		BackGround2->mEnabled = true;

		//�}�b�v�̔w�i(�X�e�[�W)
		//�w�i�N���X�̃����o�ϐ��ւ̑��
		CBackGround3* BackGround3 = new CBackGround3();
		//�X�N���[���ɒl��ݒ�
		BackGround3->x = 0;
		BackGround3->y = -25;
		//�L���ɂ���
		BackGround3->mEnabled = true;

		//�X���C��
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

		//�X�P���g��
		//�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
		CEnemy2* Enemy2 = new CEnemy2();
		//�G�ɒl��ݒ�
		Enemy2->x = 790;
		Enemy2->y = -210;
		Enemy2->w = 100;
		Enemy2->h = 130;
		//�L���ɂ���
		Enemy2->mEnabled = true;

		//�]���r
		//�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
		CEnemy3* Enemy3 = new CEnemy3();
		//�G�ɒl��ݒ�
		Enemy3->x = 790;
		Enemy3->y = -350;
		Enemy3->w = 80;
		Enemy3->h = 130;
		//�L���ɂ���
		Enemy3->mEnabled = true;
	}


};


#endif 

