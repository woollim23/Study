#pragma once
// - �����迭�� ������ ��� �̸� Ȯ���ϰ� �����͸� ����

typedef struct _tabArr
{
	int* pInt;
	int iCount;
	int iMaxCount;
}tArr;

// �迭 �ʱ�ȭ �Լ�
void InitArr(tArr* _pArr);

// ������ �߰� �Լ�
void PushBack(tArr* _pArr, int _iData);

// �迭 �޸� ���� �Լ�
void ReleaseArr(tArr* _pArr);

// ����, ������ �Լ��� ����
void Sort(tArr* _pArr, void(*SortFunc)(int*, int));