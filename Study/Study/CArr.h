#pragma once
/*-----클래스 버전 가변 배열-----*/

class CArr
{
private:
	int* m_pInt;
	int m_iCount;
	int m_iMaxCount;

public:
	void Push_Back(int _Data);
	void Resize(int _iResizeCount); // 재할당 함수, 공간 칸수를 받음
	
	int& operator[] (int idx); // 배열처럼 쓸수 있도록, 인덱스 받는 함수

public:
	CArr();
	~CArr();
};