#pragma once
/*-----Ŭ���� ���� ���� �迭-----*/

class CArr
{
private:
	int* m_pInt;
	int m_iCount;
	int m_iMaxCount;

public:
	void Push_Back(int _Data);
	void Resize(int _iResizeCount); // ���Ҵ� �Լ�, ���� ĭ���� ����
	
	int& operator[] (int idx); // �迭ó�� ���� �ֵ���, �ε��� �޴� �Լ�

public:
	CArr();
	~CArr();
};