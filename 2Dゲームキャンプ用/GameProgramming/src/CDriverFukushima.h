#ifndef CDRUVERFUKUSHIMA_H
#define CDRUVERFUKUSHIMA_H


//�w�i�X�N���[���X�s�[�h
#define SCROLL_SPEED -2.0


#include"CEnemy.h"
#include "CBackGround.h"

class CDriverFukushima {
public:
	void Init()
	{
		//�X�N���[�����鉜�̔w�i
		//�w�i�N���X�̃����o�ϐ��ւ̑��
		CBackGround* BackGround = new CBackGround();
		//�X�N���[���ɒl��ݒ�
		BackGround->x = 0;
		BackGround->y = -25;
		//�L���ɂ���
		BackGround->mEnabled = true;

		//�X�N���[�������O�̔w�i
		//�w�i�N���X�̃����o�ϐ��ւ̑��
		CBackGround2* BackGround2 = new CBackGround2();
		//�X�N���[���ɒl��ݒ�
		BackGround2->x = 0;
		BackGround2->y = -125;
		BackGround2->speed = SCROLL_SPEED;
		//�L���ɂ���
		BackGround2->mEnabled = true;

		//�X�N���[�������O�̔w�i
		//�w�i�N���X�̃����o�ϐ��ւ̑��
		CBackGround2* BackGround3 = new CBackGround2();
		//�X�N���[���ɒl��ݒ�
		BackGround3->x = 1960;
		BackGround3->y = -125;
		BackGround3->speed = SCROLL_SPEED;
		//�L���ɂ���
		BackGround3->mEnabled = true;

		//�}�b�v�̔w�i(�X�e�[�W)
		//�w�i�N���X�̃����o�ϐ��ւ̑��
		CBackGround3* BackGround4 = new CBackGround3();
		//�X�N���[���ɒl��ݒ�
		BackGround4->x = 0;
		BackGround4->y = -100;
		BackGround4->speed = SCROLL_SPEED;
		//�L���ɂ���
		BackGround4->mEnabled = true;

		//�}�b�v�̔w�i(�X�e�[�W)
		//�w�i�N���X�̃����o�ϐ��ւ̑��
		CBackGround3* BackGround5 = new CBackGround3();
		//�X�N���[���ɒl��ݒ�
		BackGround5->x = 1960;
		BackGround5->y = -100;
		BackGround5->speed = SCROLL_SPEED;
		//�L���ɂ���
		BackGround5->mEnabled = true;

			//�X���C��
			//�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
			CEnemy1* Enemy = new CEnemy1();
			Enemy->mEnemytype = 3;
			//�G�ɒl��ݒ�
			Enemy->x = 790;
			Enemy->y = -100;
			Enemy->w = 80;
			Enemy->h = 80;
			//�L���ɂ���
			Enemy->mEnabled = true;

			//�X�P���g��
			//�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
			CEnemy2* Enemy2 = new CEnemy2();
			//�G�ɒl��ݒ�
			Enemy2->x = 790;
			Enemy2->y = -210;
			Enemy2->w = 80;
			Enemy2->h = 110;
			//�L���ɂ���
			Enemy2->mEnabled = true;

			//�]���r
			//�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
			CEnemy3* Enemy3 = new CEnemy3();
			//�G�ɒl��ݒ�
			Enemy3->x = 790;
			Enemy3->y = -350;
			Enemy3->w = 60;
			Enemy3->h = 120;
			//�L���ɂ���
			Enemy3->mEnabled = true;
		
	}

};


#endif 

