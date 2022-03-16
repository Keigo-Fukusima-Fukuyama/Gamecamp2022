#ifndef CENEMY_H
#define CENEMY_H

#include "CRectangle.h"
#include "CBullet.h"



class CEnemy1 : public CRectangle {
public:
	int mFx; //X�������̈ړ� -1:�� 0:�ړ����Ȃ� 1:�E�ֈړ�
	int mFy; //Y�������̈ړ� -1:�� 0:�ړ����Ȃ� 1:��ֈړ�
	int mEnemytype;
	

	void Update();
	bool Collision(const CRectangle &r);
	void Render();

	//36
	void Collision(CRectangle *i, CRectangle *y);
	CEnemy1();
private:
	int m_EnemyDrawCount;
	int m_Hp; //HP
	int m_EnemyStandbyCount;//�G�̑ҋ@���[�V�����̃J�E���^
	int m_EnemyAttackRenderCount;//�G�̍U�����[�V�����̃J�E���^
	int mEnemyflag; //�G�̃A�j���[�V�����̃J�E���g�t���O

};

class CEnemy2 : public CRectangle {

public:
	int mFx; //X�������̈ړ� -1:�� 0:�ړ����Ȃ� 1:�E�ֈړ�
	int mFy; //Y�������̈ړ� -1:�� 0:�ړ����Ȃ� 1:��ֈړ�
	

	void Update();
	bool Collision(const CRectangle& r);
	void Render();

	//36
	void Collision(CRectangle* i, CRectangle* y);
	CEnemy2();
private:
	int m_EnemyDrawCount;
	int m_Hp; //HP
	int m_EnemyStandbyCount;//�G�̑ҋ@���[�V�����̃J�E���^
	int m_EnemyAttackRenderCount;//�G�̍U�����[�V�����̃J�E���^
	int mEnemyflag; //�G�̃A�j���[�V�����̃J�E���g�t���O
};

class CEnemy3 : public CRectangle {

public:
	int mFx; //X�������̈ړ� -1:�� 0:�ړ����Ȃ� 1:�E�ֈړ�
	int mFy; //Y�������̈ړ� -1:�� 0:�ړ����Ȃ� 1:��ֈړ�
	

	void Update();
	bool Collision(const CRectangle& r);
	void Render();

	//36
	void Collision(CRectangle* i, CRectangle* y);
	CEnemy3();
private:
	int m_EnemyDrawCount;
	int m_Hp; //HP
	int m_EnemyStandbyCount;//�G�̑ҋ@���[�V�����̃J�E���^
	int m_EnemyAttackRenderCount;//�G�̍U�����[�V�����̃J�E���^
	int mEnemyflag; //�G�̃A�j���[�V�����̃J�E���g�t���O
};
#endif
