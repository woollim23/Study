#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Vector
{
public:
	Vector()
	{
	}

	~Vector()
	{
		if (_data)
			delete[] _data;
	}

	// 데이터 삽입 함수
	void push_back(const T& value)
	{
		if (_size == _capacity)
		{
			// 증설 작업
			int newCapacity = static_cast<int>(_capacity * 1.5);
			// _capacity가 0이나 1일 경우 체크
			if (newCapacity == _capacity)
				newCapacity++;

			reserve(newCapacity);
		}

		// 데이터 저장
		_data[_size] = value;
		// 데이터 개수 증가
		_size++;
	}

	// 저장 공간 증설 함수
	void reserve(int capacity)
	{
		if (_capacity >= capacity)
		{
			return;
		}

		_capacity = capacity;

		T* newData = new T[_capacity];

		// 데이터 복사
		for (int i = 0; i < _size; i++)
		{
			newData[i] = _data[i];
		}

		if (_data)
			delete[] _data;

		// 교체
		_data = newData;

	}

	T& operator[](const int pos) { return _data[pos]; }
	int size() { return _size; }
	int capacity() { return _capacity; }

	void clear()
	{
		if (_data)
		{
			delete[] _data;
			_data = new T[_capacity];
		}
		 
		_size = 0;
	}

private:
	T* _data = nullptr;
	int _size = 0;
	int _capacity = 0;
};

int main()
{
	vector<int> v;

	// resize를 조정, capacity도 같이 10으로 증가
	v.resize(10);
	cout << v.size() << " " << v.capacity() << endl;
	// capacity 만 조정
	v.reserve(100);
	cout << v.size() << " " << v.capacity() << endl;

	for (int i = 0; i < 200; i++)
	{
		v.push_back(i);
		cout << v.size() << " " << v.capacity() << endl;
	}

	v.resize(10);
	cout << v.size() << " " << v.capacity() << endl;

	v.clear();

	cout << v.size() << " " << v.capacity() << endl;
} 