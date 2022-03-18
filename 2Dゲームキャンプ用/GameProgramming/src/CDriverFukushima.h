#ifndef CDRUVERFUKUSHIMA_H
#define CDRUVERFUKUSHIMA_H


//�w�i�X�N���[���X�s�[�h
#define SCROLL_SPEED -2.0
//1���ڂ̔w�i
#define BACKGROUND1_X 0
//2���ڂ̔w�i
#define BACKGROUND2_X 3840
//���̔w�iY���W
#define BACKGROUND1_Y 25
//�^�񒆂̔w�iY���W
#define BACKGROUND2_Y -125


#include"CDriverFukushima.h"
#include"CEnemy.h"
#include "CBackground.h"
#include"CTaskManager.h"
#include<time.h>
#include<stdlib.h>



class CDriverFukushima {
private:
	int mSceneDrawCount;
	int mEnemyTypeRand;
	int mEnemyMakeRand;
	int mMakeRand;
	int mEy;
	int mEnemydepth;
	int mMakeTime;
public:

	void Init()
	{
		//���̔w�i
		//�w�i�N���X�̃����o�ϐ��ւ̑��
		CBackground* Background = new CBackground();
		//�X�N���[���ɒl��ݒ�
		Background->x = BACKGROUND1_X;
		Background->y = BACKGROUND1_Y;
		//�L���ɂ���
		Background->mEnabled = true;


		//�X�N���[�������O�̔w�i
		//�w�i�N���X�̃����o�ϐ��ւ̑��
		CBackground2* Background2 = new CBackground2();
		//�X�N���[���ɒl��ݒ�
		Background2->x = BACKGROUND1_X;
		Background2->y = BACKGROUND2_Y;
		Background2->speed = SCROLL_SPEED;
		//�L���ɂ���
		Background2->mEnabled = true;

		//�X�N���[�������O�̔w�i
		//�w�i�N���X�̃����o�ϐ��ւ̑��
		CBackground2* Background3 = new CBackground2();
		//�X�N���[���ɒl��ݒ�
		Background3->x = BACKGROUND2_X;
		Background3->y = BACKGROUND2_Y;
		Background3->speed = SCROLL_SPEED;
		//�L���ɂ���
		Background3->mEnabled = true;

		//�}�b�v�̔w�i(�X�e�[�W)
		//�w�i�N���X�̃����o�ϐ��ւ̑��
		CBackground3* Background4 = new CBackground3();
		//�X�N���[���ɒl��ݒ�
		Background4->x = BACKGROUND1_X;
		Background4->y = BACKGROUND2_Y;
		Background4->speed = SCROLL_SPEED;
		//�L���ɂ���
		Background4->mEnabled = true;

		//�}�b�v�̔w�i(�X�e�[�W)
		//�w�i�N���X�̃����o�ϐ��ւ̑��
		CBackground3* Background5 = new CBackground3();
		//�X�N���[���ɒl��ݒ�
		Background5->x = BACKGROUND2_X;
		Background5->y = BACKGROUND2_Y;
		Background5->speed = SCROLL_SPEED;
		//�L���ɂ���
		Background5->mEnabled = true;
		

	}

	void Update() {
		mEnemyMakeRand = rand() % 3 + 1;
		mMakeRand = (rand() % 100) - 1;
		srand((unsigned)time(NULL));
		if (mEnemyMakeRand == 1)
		{
			mEy = -60;
			mEnemydepth = 1;
		}
		if (mEnemyMakeRand == 2)
		{
			mEy = -180;
			mEnemydepth = 2;
		}
		if (mEnemyMakeRand == 3)
		{
			mEy = -360;
			mEnemydepth = 3;
		}
			if (mMakeRand >= 0 && mMakeRand <= 33 && mMakeTime % 120 == 60) {
				//�X���C��
				//�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
				for (int i = 0; i < 1; i++)
				{
				CEnemy1* Enemy = new CEnemy1();
				//�����l=rand()%�����l�̗v�f��+�����l�̍ŏ��l
				srand((unsigned)time(NULL));
				mEnemyTypeRand = rand() % 3 - 1;
				Enemy->mEnemytype = mEnemyTypeRand;
				//�G�ɒl��ݒ�
				Enemy->x = 980;
				Enemy->y = mEy;
				Enemy->z = mEnemydepth;
				Enemy->w = 100;
				Enemy->h = 100;
				Enemy->mFx = -2;
				//�L���ɂ���
				Enemy->mEnabled = true;
				break;
				}
			}
		
			if (mMakeRand >= 34 && mMakeRand <= 66 && mMakeTime % 210 == 70) {
				//�X�P���g��
				for (int i = 0; i < 1; i++)
				{
					//�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
					CEnemy2* Enemy2 = new CEnemy2();
					//�G�ɒl��ݒ�
					Enemy2->x = 980;
					Enemy2->y = mEy;
					Enemy2->z = mEnemydepth;
					Enemy2->w = 160;
					Enemy2->h = 120;
					Enemy2->mFx = -2;
					//�L���ɂ���
					Enemy2->mEnabled = true;
					break;
				}
			}
		
		
			if (mMakeRand >= 67 && mMakeRand <= 99 && mMakeTime % 270 == 90) {
				//�]���r
				//�G�l�~�[�N���X�̃����o�ϐ��ւ̑��
				for (int i = 0; i < 1; i++)
				{
					CEnemy3* Enemy3 = new CEnemy3();
					//�G�ɒl��ݒ�
					Enemy3->x = 980;
					Enemy3->y = mEy;
					Enemy3->z = mEnemydepth;
					Enemy3->w = 160;
					Enemy3->h = 120;
					Enemy3->mFx = -2;
					//�L���ɂ���
					Enemy3->mEnabled = true;
					break;
				}
			}
			mMakeTime = mMakeTime + 1;
		
	}
	






	
};
#endif 

