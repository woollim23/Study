/*
* ���簢������ Ż��
*
<����>
�Ѽ��� ���� (x, y)�� �ִ�. ���簢���� �� ���� ��ǥ�࿡ �����ϰ�, ���� �Ʒ� �������� (0, 0), ������ �� �������� (w, h)�� �ִ�. ���簢���� ��輱���� ���� �Ÿ��� �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

<�Է�>
ù° �ٿ� x, y, w, h�� �־�����.

<���>
ù° �ٿ� ������ ������ ����Ѵ�.

<����>
1 �� w, h �� 1,000
1 �� x �� w-1
1 �� y �� h-1
x, y, w, h�� ����

<���� �Է� 1>
6 2 10 3
<���� ��� 1>
1
*/

#include<iostream>
using namespace std;

int main()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int min = x - 0;

	if (min > y - 0)
	{
		min = y - 0;
	}
	if (min > w - x)
	{
		min = w - x;
	}
	if (min > h - y)
	{
		min = h - y;
	}

	cout << min;
	return 0;
}