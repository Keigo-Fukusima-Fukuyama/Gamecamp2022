#ifndef CDRUVERFUKUSHIMA_H
#define CDRUVERFUKUSHIMA_H

//�w�i�X�N���[���X�s�[�h
#define SCROLL_SPEED1 -3.0
//�w�i�X�N���[���X�s�[�h
#define SCROLL_SPEED2 -2.0
//�w�i�X�N���[���X�s�[�h
#define SCROLL_SPEED3 -1.0

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
		BackGround->x = 960;
		BackGround->y = -25;
		BackGround->speed = SCROLL_SPEED1;
		//�L���ɂ���
		BackGround->mEnabled = true;

		//�X�N���[�����鉜�̔w�i
		//�w�i�N���X�̃����o�ϐ��ւ̑��
		CBackGround* BackGround2 = new CBackGround();
		//�X�N���[���ɒl��ݒ�
		BackGround2->x = 4800;
		BackGround2->y = -25;
		BackGround2->speed = SCROLL_SPEED1;
		//�L���ɂ���
		BackGround2->mEnabled = true;

		//�X�N���[�������O�̔w�i
		//�w�i�N���X�̃����o�ϐ��ւ̑��
		CBackGround2* BackGround3 = new CBackGround2();
		//�X�N���[���ɒl��ݒ�
		BackGround3->x = 960;
		BackGround3->y = -125;
		BackGround3->speed = SCROLL_SPEED2;
		//�L���ɂ���
		BackGround3->mEnabled = true;

		//�X�N���[�������O�̔w�i
		//�w�i�N���X�̃����o�ϐ��ւ̑��
		CBackGround2* BackGround4 = new CBackGround2();
		//�X�N���[���ɒl��ݒ�
		BackGround4->x = 4800;
		BackGround4->y = -125;
		BackGround4->speed = SCROLL_SPEED2;
		//�L���ɂ���
		BackGround4->mEnabled = true;

		//�}�b�v�̔w�i(�X�e�[�W)
		//�w�i�N���X�̃����o�ϐ��ւ̑��
		CBackGround3* BackGround5 = new CBackGround3();
		//�X�N���[���ɒl��ݒ�
		BackGround5->x = 960;
		BackGround5->y = -100;
		BackGround5->speed = SCROLL_SPEED3;
		//�L���ɂ���
		BackGround5->mEnabled = true;

		//�}�b�v�̔w�i(�X�e�[�W)
		//�w�i�N���X�̃����o�ϐ��ւ̑��
		CBackGround3* BackGround6 = new CBackGround3();
		//�X�N���[���ɒl��ݒ�
		BackGround6->x = 4800;
		BackGround6->y = -100;
		BackGround6->speed = SCROLL_SPEED3;
		//�L���ɂ���
		BackGround6->mEnabled = true;

		//	//�X���C��
		//	//�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
		//	CEnemy1* Enemy = new CEnemy1();
		//	Enemy->mEnemytype = 3;
		//	//�G�ɒl��ݒ�
		//	Enemy->x = 790;
		//	Enemy->y = -100;
		//	Enemy->w = 100;
		//	Enemy->h = 100;
		//	//�L���ɂ���
		//	Enemy->mEnabled = true;

		//	//�X�P���g��
		//	//�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
		//	CEnemy2* Enemy2 = new CEnemy2();
		//	//�G�ɒl��ݒ�
		//	Enemy2->x = 790;
		//	Enemy2->y = -210;
		//	Enemy2->w = 100;
		//	Enemy2->h = 130;
		//	//�L���ɂ���
		//	Enemy2->mEnabled = true;

		//	//�]���r
		//	//�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
		//	CEnemy3* Enemy3 = new CEnemy3();
		//	//�G�ɒl��ݒ�
		//	Enemy3->x = 790;
		//	Enemy3->y = -350;
		//	Enemy3->w = 80;
		//	Enemy3->h = 130;
		//	//�L���ɂ���
		//	Enemy3->mEnabled = true;
		//
	}

};


#endif 

