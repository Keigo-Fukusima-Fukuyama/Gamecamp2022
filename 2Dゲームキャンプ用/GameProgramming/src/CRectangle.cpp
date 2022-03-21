#include "CRectangle.h"
//vector�^�̃C���N���[�h
#include <vector>
//�^�X�N�}�l�[�W���N���X�̃C���N���[�h
#include"CTaskManager.h"
/*
�ϒ��z��̒�`
std;;vector<�z��v�f�̃f�[�^�^> �z��
*/
std::vector<CRectangle*> VectorRect;

//�f�t�H���g�R���X�g���N�^
CRectangle::CRectangle()
: mTag(EBLOCK)	//�����l�u���b�N
//37
, mEnabled(true)
, mStatus(EDISABLED)
{
	//�^�X�N���X�g�ɒǉ�
	CTaskManager::Get()->Add(this);

}


void CRectangle::DrawTriangle(int x0, int y0, int x1, int y1, int x2, int y2) {
	//�O�p�`�̕`��
	glBegin(GL_TRIANGLES);	//�O�p�`�̕`��J�n
	glVertex2d(x0, y0);		//���_�P�̍��W���w��
	glVertex2d(x1, y1);		//���_�Q�̍��W���w��
	glVertex2d(x2, y2);		//���_�R�̍��W���w��
	glEnd();	//�`��I��
}

void CRectangle::DrawRectangle(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3) {
	DrawTriangle(x0, y0, x1, y1, x2, y2);
	DrawTriangle(x0, y0, x2, y2, x3, y3);
}

void CRectangle::Render() {
	//�N���X�����o�̕ϐ�x,y,w,h���g�p���܂�
	DrawRectangle(x + w, y + h, x - w, y + h, x - w, y - h, x + w, y - h);
}

bool CRectangle::Conflict(const CRectangle& r)
{
	//X���̏d�Ȃ�𔻒�
	//���S��X���W�̋��������߂�
	int lenX = x - r.x;
	//�����̐�Βl�����߂�
	lenX = lenX < 0 ? -lenX : lenX;
	//���������̍��v���傫���Ƃ��AX���͏d�Ȃ��Ă��Ȃ�
	if (lenX > w + r.w) {
		//�d�Ȃ��ĂȂ���΁A�Փ˂��Ă��Ȃ�
		//false��Ԃ�
		return false;
	}

	if (z!=r.z) {
		//�d�Ȃ��ĂȂ���΁A�Փ˂��Ă��Ȃ�
		//false��Ԃ�
		return false;
	}

	//X���AZ���Ƃ��ɏd�Ȃ��Ă���̂ŁAtrue��Ԃ�
	return true;
}

bool CRectangle::Collision(const CRectangle &r) {
	//X���̏d�Ȃ�𔻒�
	//���S��X���W�̋��������߂�
	int lenX = x - r.x;
	//�����̐�Βl�����߂�
	lenX = lenX < 0 ? -lenX : lenX;
	//���������̍��v���傫���Ƃ��AX���͏d�Ȃ��Ă��Ȃ�
	if (lenX > w + r.w) {
		//�d�Ȃ��ĂȂ���΁A�Փ˂��Ă��Ȃ�
		//false��Ԃ�
		return false;
	}

	//Z���̏d�Ȃ蔻��
	//���S��Z���W�̋��������߂�
	int lenZ = z - r.z;
	//�����̐�Βl�����߂�
	lenZ = lenZ < 0 ? -lenZ : lenZ;
	//���������̍��v���傫���Ƃ��AZ���͏d�Ȃ��Ă��Ȃ�
	if (lenZ > z + r.z) {
		//�d�Ȃ��ĂȂ���΁A�Փ˂��Ă��Ȃ�
		//false��Ԃ�
		return false;
	}

	//X���AZ���Ƃ��ɏd�Ȃ��Ă���̂ŁAtrue��Ԃ�
	return true;
}

bool CRectangle::Collision(CRectangle *pr, int *px, int *pz) {
	//x��z��0��0����
	*px = 0;
	*pz = 0;
	//X���̏d�Ȃ�𔻒�
	//���S��X���W�̋��������߂�
	int lenX = x - pr->x;
	//�����̐�Βl�����߂�
	lenX = lenX < 0 ? -lenX : lenX;
	//���������̍��v��菬�����Ƃ��AX���͏d�Ȃ��Ă���
	if (lenX < w + pr->w) {
		//�߂��ʂ��v�Z
		if (x < pr->x) {
			//���肪�E�̎��͍��ֈړ�
			*px = lenX - w - pr->w;
		}
		else {
			//���肪���̎��͉E�ֈړ�
			*px = w + pr->w - lenX;
		}
	}
	else {
		//�d�Ȃ��ĂȂ���΁A�Փ˂��Ă��Ȃ�
		//false��Ԃ�
		return false;
	}
	//Z���̏d�Ȃ蔻��
	//���S��X���W�̋��������߂�
	int lenZ = z - pr->z;
	//�����̐�Βl�����߂�
	lenZ = lenZ < 0 ? -lenZ : lenZ;
	//���������̍��v��菬�����Ƃ��AZ���͏d�Ȃ��Ă���
	if (lenZ < z + pr->z) {
		//�߂��ʂ��v�Z
		if (z < pr->z) {
			//���肪�E�̎��͍��ֈړ�
			*pz = lenZ - h - pr->h;
		}
		else {
			//���肪���̎��͉E�ֈړ�
			*pz = h + pr->h - lenZ;
		}
	}
	else {
		//�d�Ȃ��ĂȂ���΁A�Փ˂��Ă��Ȃ�
		//false��Ԃ�
		return false;
	}

	//X���AZ���Ƃ��ɏd�Ȃ��Ă���̂ŁAtrue��Ԃ�
	return true;
}
CRectangle::~CRectangle() {
	//�^�X�N���X�g�ɒǉ�
	CTaskManager::Get()->Delete();
}