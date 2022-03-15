#ifndef CDRUVERFUKUSHIMA_H
#define CDRUVERFUKUSHIMA_H


//�w�i�X�N���[���X�s�[�h
#define SCROLL_SPEED -2.0

#include"CMap.h"
#include"CEnemy.h"
#include "CBackGround.h"
#include<time.h>
#include<stdlib.h>



class CDriverFukushima {
private:
	int mEnemyTypeRand;
public:

	void Init()
	{
		//���̔w�i
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
		BackGround3->x = 1920;
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
		BackGround5->x = 1920;
		BackGround5->y = -100;
		BackGround5->speed = SCROLL_SPEED;
		//�L���ɂ���
		BackGround5->mEnabled = true;

		////�X���C��
		////�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
		//CEnemy1* Enemy = new CEnemy1();
		//Enemy->mEnemytype = 1;
		////�G�ɒl��ݒ�
		//Enemy->x = 790;
		//Enemy->y = -100;
		//Enemy->w = 90;
		//Enemy->h = 90;
		////�L���ɂ���
		//Enemy->mEnabled = true;

		////�X�P���g��
		////�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
		//CEnemy2* Enemy2 = new CEnemy2();
		////�G�ɒl��ݒ�
		//Enemy2->x = 790;
		//Enemy2->y = -210;
		//Enemy2->w = 80;
		//Enemy2->h = 110;
		////�L���ɂ���
		//Enemy2->mEnabled = true;

		////�]���r
		////�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
		//CEnemy3* Enemy3 = new CEnemy3();
		////�G�ɒl��ݒ�
		//Enemy3->x = 790;
		//Enemy3->y = -350;
		//Enemy3->w = 60;
		//Enemy3->h = 120;
		////�L���ɂ���
		//Enemy3->mEnabled = true;


	}

	void Update() {
		if (mEnemyMakeFlag == 0) {
			int EnemyMap1[3][9]
			{
				{1,0,0,0,0,2,0,1,},
				{0,1,2,0,0,0,0,0,},
				{3,0,0,1,0,0,3,0,},
			};
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 9; k++) {
					if (EnemyMap1[j][k] == 1) {
						//�X���C��
						//�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
						CEnemy1* Enemy = new CEnemy1();
						//�����l=rand()%�����l�̗v�f��+�����l�̍ŏ��l
						srand((unsigned)time(NULL));
						mEnemyTypeRand = rand() % 3 - 1;
						Enemy->mEnemytype = mEnemyTypeRand;
						mEnemyMakeFlag += 1;
						//�G�ɒl��ݒ�
						Enemy->x = k * 320 + 960;
						Enemy->y = j * -150 - 100;
						Enemy->w = 100;
						Enemy->h = 100;
						Enemy->mFx = -2;
						//�L���ɂ���
						Enemy->mEnabled = true;
					}
					if (EnemyMap1[j][k] == 2) {
						//�X�P���g��
						//�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
						CEnemy2* Enemy2 = new CEnemy2();
						mEnemyMakeFlag += 1;
						//�G�ɒl��ݒ�
						Enemy2->x = k * 320 + 960;
						Enemy2->y = j * -160 - 30;
						Enemy2->w = 160;
						Enemy2->h = 120;
						Enemy2->mFx = -2;
						//�L���ɂ���
						Enemy2->mEnabled = true;
					}
					if (EnemyMap1[j][k] == 3) {
						//�]���r
						//�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
						CEnemy3* Enemy3 = new CEnemy3();
						mEnemyMakeFlag += 1;
						//�G�ɒl��ݒ�
						Enemy3->x = k * 320 + 960;
						Enemy3->y = j * -160 - 30;
						Enemy3->w = 160;
						Enemy3->h = 120;
						Enemy3->mFx = -2;
						//�L���ɂ���
						Enemy3->mEnabled = true;
					}
				}
			}
		}
		
	

			//for (int i = 0; i < 1; i++)
			//{
			//	int EnemyMap2[3][9]
			//	{
			//		{1,0,0,0,3,0,0,2,},
			//		{0,0,1,0,0,0,3,0,},
			//		{0,2,0,0,0,2,0,0,},
			//	};
			//	if (mEnemyMapRand >= 16 && mEnemyMapRand <= 32 && mEnemyMakeFlag == 0) {
			//		mEnemyTypeRand = rand() % 3 - 1;
			//		mEnemyMapRand = (rand() % 100) + 1;
			//		for (int j = 0; j < 3; j++) {
			//			for (int k = 0; k < 9; k++) {
			//				if (EnemyMap2[j][k] == 1) {
			//					//�X���C��
			//					//�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
			//					CEnemy1* Enemy4 = new CEnemy1();
			//					Enemy4->mEnemytype = mEnemyTypeRand;
			//					mEnemyMakeFlag += 1;
			//					//�G�ɒl��ݒ�
			//					Enemy4->x = k * 320 + 960;
			//					Enemy4->y = j * -200 - 30;
			//					Enemy4->w = 100;
			//					Enemy4->h = 100;
			//					Enemy4->mFx = -2;
			//					//�L���ɂ���
			//					Enemy4->mEnabled = true;
			//				}
			//				if (EnemyMap2[j][k] == 2) {
			//					//�X�P���g��
			//					//�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
			//					CEnemy2* Enemy5 = new CEnemy2();
			//					mEnemyMakeFlag += 1;
			//					//�G�ɒl��ݒ�
			//					Enemy5->x = k * 320 + 960;
			//					Enemy5->y = j * -160 - 30;
			//					Enemy5->w = 160;
			//					Enemy5->h = 120;
			//					Enemy5->mFx = -2;
			//					//�L���ɂ���
			//					Enemy5->mEnabled = true;
			//				}
			//				if (EnemyMap2[j][k] == 3) {
			//					//�]���r
			//					//�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
			//					CEnemy3* Enemy6 = new CEnemy3();
			//					mEnemyMakeFlag += 1;
			//					//�G�ɒl��ݒ�
			//					Enemy6->x = k * 320 + 960;
			//					Enemy6->y = j * -160 - 30;
			//					Enemy6->w = 160;
			//					Enemy6->h = 120;
			//					Enemy6->mFx = -2;
			//					//�L���ɂ���
			//					Enemy6->mEnabled = true;
			//				}
			//			}
			//		}
			//	}
			//	break;
			//	mEnemyTypeRand = rand() % 3 - 1;
			//	mEnemyMapRand = (rand() % 100) + 1;
			//}

			//for (int i = 0; i < 1; i++)
			//{
			//	int EnemyMap3[3][9]
			//	{
			//		{3,0,0,0,1,0,0,0,},
			//		{0,0,2,0,0,0,1,0,},
			//		{0,2,0,1,3,0,0,2,},
			//	};
			//	if (mEnemyMapRand >= 32 && mEnemyMapRand <= 48 && mEnemyMakeFlag == 0) {
			//		for (int j = 0; j < 3; j++) {
			//			for (int k = 0; k < 9; k++) {
			//				if (EnemyMap3[j][k] == 1) {
			//					//�X���C��
			//					//�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
			//					CEnemy1* Enemy7 = new CEnemy1();
			//					Enemy7->mEnemytype = mEnemyTypeRand;
			//					mEnemyMakeFlag += 1;
			//					//�G�ɒl��ݒ�
			//					Enemy7->x = k * 320 + 960;
			//					Enemy7->y = j * -200 - 30;
			//					Enemy7->w = 100;
			//					Enemy7->h = 100;
			//					Enemy7->mFx = -2;
			//					//�L���ɂ���
			//					Enemy7->mEnabled = true;
			//				}
			//				if (EnemyMap3[j][k] == 2) {
			//					//�X�P���g��
			//					//�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
			//					CEnemy2* Enemy8 = new CEnemy2();
			//					mEnemyMakeFlag += 1;
			//					//�G�ɒl��ݒ�
			//					Enemy8->x = k * 320 + 960;
			//					Enemy8->y = j * -160 - 30;
			//					Enemy8->w = 160;
			//					Enemy8->h = 120;
			//					Enemy8->mFx = -2;
			//					//�L���ɂ���
			//					Enemy8->mEnabled = true;
			//				}
			//				if (EnemyMap3[j][k] == 3) {
			//					//�]���r
			//					//�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
			//					CEnemy3* Enemy9 = new CEnemy3();
			//					mEnemyMakeFlag += 1;
			//					//�G�ɒl��ݒ�
			//					Enemy9->x = k * 320 + 960;
			//					Enemy9->y = j * -160 - 30;
			//					Enemy9->w = 160;
			//					Enemy9->h = 120;
			//					Enemy9->mFx = -2;
			//					//�L���ɂ���
			//					Enemy9->mEnabled = true;
			//				}
			//			}
			//		}

			//	}
			//	break;
			//	mEnemyTypeRand = rand() % 3 - 1;
			//	mEnemyMapRand = (rand() % 100) + 1;
			//}


			//for (int i = 0; i < 1; i++)
			//{
			//	int EnemyMap4[3][9]
			//	{
			//		{2,0,0,3,0,1,0,3,},
			//		{0,0,1,0,0,0,0,0,},
			//		{0,3,0,0,1,0,2,0,},
			//	};
			//	if (mEnemyMapRand >= 48 && mEnemyMapRand <= 64 && mEnemyMakeFlag == 0) {
			//		for (int j = 0; j < 3; j++) {
			//			for (int k = 0; k < 9; k++) {
			//				if (EnemyMap4[j][k] == 1) {
			//					CEnemy1* Enemy = new CEnemy1();
			//					//�X���C��
			//					//�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
			//					CEnemy1* Enemy10 = new CEnemy1();
			//					Enemy->mEnemytype = mEnemyTypeRand;
			//					mEnemyMakeFlag += 1;
			//					//�G�ɒl��ݒ�
			//					Enemy10->x = k * 320 + 960;
			//					Enemy10->y = j * -200 - 30;
			//					Enemy10->w = 100;
			//					Enemy10->h = 100;
			//					Enemy10->mFx = -2;
			//					//�L���ɂ���
			//					Enemy10->mEnabled = true;
			//				}
			//				if (EnemyMap4[j][k] == 2) {
			//					//�X�P���g��
			//					//�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
			//					CEnemy2* Enemy11 = new CEnemy2();
			//					mEnemyMakeFlag += 1;
			//					//�G�ɒl��ݒ�
			//					Enemy11->x = k * 320 + 960;
			//					Enemy11->y = j * -160 - 30;
			//					Enemy11->w = 160;
			//					Enemy11->h = 120;
			//					Enemy11->mFx = -2;
			//					//�L���ɂ���
			//					Enemy11->mEnabled = true;
			//				}
			//				if (EnemyMap4[j][k] == 3) {
			//					//�]���r
			//					//�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
			//					CEnemy3* Enemy12 = new CEnemy3();
			//					mEnemyMakeFlag += 1;
			//					//�G�ɒl��ݒ�
			//					Enemy12->x = k * 320 + 960;
			//					Enemy12->y = j * -160 - 30;
			//					Enemy12->w = 160;
			//					Enemy12->h = 120;
			//					Enemy12->mFx = -2;
			//					//�L���ɂ���
			//					Enemy12->mEnabled = true;
			//				}
			//			}
			//		}
			//	}
			//	break;
			//	mEnemyTypeRand = rand() % 3 - 1;
			//	mEnemyMapRand = (rand() % 100) + 1;
			//}
			//for (int i = 0; i < 1; i++)
			//{
			//	int EnemyMap5[3][9]
			//	{
			//		{0,2,0,3,0,0,3,0,},
			//		{2,0,0,0,3,0,0,0,},
			//		{0,0,3,0,0,3,0,0,},
			//	};
			//	if (mEnemyMapRand >= 64 && mEnemyMapRand <= 80 && mEnemyMakeFlag == 0) {
			//		for (int j = 0; j < 3; j++) {
			//			for (int k = 0; k < 9; k++) {
			//				if (EnemyMap5[j][k] == 1) {
			//					//�X���C��
			//					//�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
			//					CEnemy1* Enemy13 = new CEnemy1();
			//					Enemy13->mEnemytype = mEnemyTypeRand;
			//					mEnemyMakeFlag += 1;
			//					//�G�ɒl��ݒ�
			//					Enemy13->x = k * 320 + 960;
			//					Enemy13->y = j * -200 - 30;
			//					Enemy13->w = 100;
			//					Enemy13->h = 100;
			//					Enemy13->mFx = -2;
			//					//�L���ɂ���
			//					Enemy13->mEnabled = true;
			//				}
			//				if (EnemyMap5[j][k] == 2) {
			//					//�X�P���g��
			//					//�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
			//					CEnemy2* Enemy14 = new CEnemy2();
			//					mEnemyMakeFlag += 1;
			//					//�G�ɒl��ݒ�
			//					Enemy14->x = k * 320 + 960;
			//					Enemy14->y = j * -160 - 30;
			//					Enemy14->w = 160;
			//					Enemy14->h = 120;
			//					Enemy14->mFx = -2;
			//					//�L���ɂ���
			//					Enemy14->mEnabled = true;
			//				}
			//				if (EnemyMap5[j][k] == 3) {
			//					//�]���r
			//					//�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
			//					CEnemy3* Enemy15 = new CEnemy3();
			//					mEnemyMakeFlag += 1;
			//					//�G�ɒl��ݒ�
			//					Enemy15->x = k * 320 + 960;
			//					Enemy15->y = j * -160 - 30;
			//					Enemy15->w = 160;
			//					Enemy15->h = 120;
			//					Enemy15->mFx = -2;
			//					//�L���ɂ���
			//					Enemy15->mEnabled = true;
			//				}
			//			}
			//		}

			//	}
			//	break;
			//	mEnemyTypeRand = rand() % 3 - 1;
			//	mEnemyMapRand = (rand() % 100) + 1;
			//}

			//for (int i = 0; i < 1; i++)
			//{
			//	int EnemyMap6[3][9]
			//	{
			//		{0,3,0,0,0,3,0,0,},
			//		{1,0,0,2,0,0,2,0,},
			//		{0,0,2,0,0,3,0,0,},
			//	};
			//	if (mEnemyMapRand >= 80 && mEnemyMapRand <= 100 && mEnemyMakeFlag == 0) {
			//		mEnemyTypeRand = rand() % 3 - 1;
			//		mEnemyMapRand = (rand() % 100) + 1;
			//		for (int j = 0; j < 3; j++) {
			//			for (int k = 0; k < 9; k++) {
			//				if (EnemyMap6[j][k] == 1) {
			//					//�X���C��
			//					//�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
			//					CEnemy1* Enemy16 = new CEnemy1();
			//					Enemy16->mEnemytype = mEnemyTypeRand;
			//					mEnemyMakeFlag += 1;
			//					//�G�ɒl��ݒ�
			//					Enemy16->x = k * 320 + 960;
			//					Enemy16->y = j * -200 - 40;
			//					Enemy16->w = 100;
			//					Enemy16->h = 100;
			//					Enemy16->mFx = -2;
			//					//�L���ɂ���
			//					Enemy16->mEnabled = true;
			//				}
			//				if (EnemyMap6[j][k] == 2) {
			//					//�X�P���g��
			//					//�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
			//					CEnemy2* Enemy17 = new CEnemy2();
			//					mEnemyMakeFlag += 1;
			//					//�G�ɒl��ݒ�
			//					Enemy17->x = k * 320 + 960;
			//					Enemy17->y = j * -160 - 30;
			//					Enemy17->w = 160;
			//					Enemy17->h = 120;
			//					Enemy17->mFx = -2;
			//					//�L���ɂ���
			//					Enemy17->mEnabled = true;
			//				}
			//				if (EnemyMap6[j][k] == 3) {
			//					//�]���r
			//					//�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
			//					CEnemy3* Enemy18 = new CEnemy3();
			//					mEnemyMakeFlag += 1;
			//					//�G�ɒl��ݒ�
			//					Enemy18->x = k * 320 + 960;
			//					Enemy18->y = j * -160 - 30;
			//					Enemy18->w = 160;
			//					Enemy18->h = 120;
			//					Enemy18->mFx = -2;
			//					//�L���ɂ���
			//					Enemy18->mEnabled = true;
			//				}
			//			}
			//		}
			//	}
			//	break;
			//	mEnemyTypeRand = rand() % 3 - 1;
			//	mEnemyMapRand = (rand() % 100) + 1;
			//}
	}
};
#endif 

