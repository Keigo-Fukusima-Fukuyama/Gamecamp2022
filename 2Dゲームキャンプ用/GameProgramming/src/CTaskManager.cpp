#include "CTaskManager.h"
//�^�X�N�}�l�[�W���̊O���ϐ�
CTaskManager TaskManager;
//�f�t�H���g�R���X�g���N�^
CTaskManager::CTaskManager()
{
	mHead.mpNext = &mTail;
	mTail.mpPrev = &mHead;
}
CTaskManager::~CTaskManager(){}
//���X�g�ɒǉ�
//Add(�^�X�N�̃|�C���^)
void CTaskManager::Add(CTask * addTask) 
{
	//�ŏI�|�C���^(mTail)�̑O�ɒǉ�
	CTask* task = &mTail;
	//�ǉ��|�C���^(addTask)�̎����^�X�N�̃|�C���^(task)����
	addTask->mpNext = task;
	//�ǉ��|�C���^(addTask)�̑O���^�X�N�̃|�C���^(Task)�̑O��
	addTask->mpPrev = task->mpPrev;
	//�ǉ��|�C���^(addTask)�̑O�����̒ǉ��|�C���^(addTask)�ɑ��
	addTask->mpPrev->mpNext = addTask;
	//�^�X�N�̃|�C���^(task)�̑O��ǉ��|�C���^(addTask)��
	task->mpPrev = addTask;
}
//���X�g����폜
//Remove(�^�X�N�̃|�C���^)
void CTaskManager::Remove(CTask* task) 
{
	//�^�X�N�̑O�̎����A�^�X�N�̎��ɂ���
	task->mpPrev->mpNext = task->mpNext;
	//�^�X�N�̎��̑O���A�^�X�N�̑O�ɂ���
	task->mpNext->mpPrev = task->mpPrev;
}
//�^�X�N�̍폜
void CTaskManager::Delete() 
{
	//�擪����Ō�܂ŌJ��Ԃ�
	CTask* task = mHead.mpNext;
	while (task->mpNext)
	{
		CTask* del = task;
		//����
		task = task->mpNext;
		//mEnabled��false�Ȃ�폜
		if (del->mEnabled == false)
		{
			delete del;
		}
	}
}

//�X�V����
void CTaskManager::Update()
{
	//�擪����Ō�܂ŌJ��Ԃ�
	CTask* task = mHead.mpNext;
	while (task->mpNext)
	{
		//�X�V�������Ă�
		task->Update();
		//����
		task = task->mpNext;
	}
}

//�`�揈��
void CTaskManager::Render(){}
