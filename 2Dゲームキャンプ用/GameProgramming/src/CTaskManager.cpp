#include "CTaskManager.h"
//�^�X�N�}�l�[�W���̊O���ϐ�
CTaskManager TaskManager;
//�^�X�N�}�l�[�W���̃C���X�^���X
CTaskManager* CTaskManager::mpInstance = nullptr;

//�C���X�^���X�̎擾
CTaskManager* CTaskManager::Get()
{
	//�C���X�^���X���������
	if (mpInstance == nullptr)
	{
		//�C���X�^���X�𐶐�����
		mpInstance = new CTaskManager();
	}
	return mpInstance;
}
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
//�Փˏ���
void CTaskManager::Collision() {
	//���݈ʒu��擪�ɂ���
	CRectangle* task = (CRectangle*)mHead.mpNext;
	//�Ō�܂ł�����I������
	while (task->mpNext) {
		//���݈ʒu�̎������߂�
		CRectangle* next = (CRectangle*)task->mpNext;
		//�����O�ɂȂ�����I��
		while (next->mpNext) {
			//�e�̏Փ˔�����Ăяo��
			//�����̏Փˏ���
		task->Collision(task, next);
			//����̏Փˏ���
		next->Collision(next, task);
			//�������߂�
			next = (CRectangle*)next->mpNext;

		}
		//���݈ʒu�����ɂ���
		task = (CRectangle*)task->mpNext;
	}

}
//���X�g����폜
//Remove(�^�X�N�̃|�C���^)
void CTaskManager::Remove(CTask* task) {
	//�^�X�N�̑O�̎����A�^�X�N�̎��ɂ���
	task->mpPrev->mpNext = task->mpNext;
	//�^�X�N�̎��̑O���A�^�X�N�̑O�ɂ���
	task->mpNext->mpPrev = task->mpPrev;
}
//�`��
void CTaskManager::Render() {
	//�擪����Ō�܂ŌJ��Ԃ�
	CTask* task = mHead.mpNext;
	while (task->mpNext) {
		//�X�V�������Ă�
		task->Render();
		//����
		task = task->mpNext;
	}
}
//�^�X�N�̍폜
void CTaskManager::Delete() {
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