/*
* ������� ��
* 
<����>
� ���� n�� �ڽ��� ������ ��� ������� �հ� ������, �� ���� ��������� �Ѵ�.

���� ��� 6�� 6 = 1 + 2 + 3 ���� �������̴�.

n�� ���������� �ƴ��� �Ǵ����ִ� ���α׷��� �ۼ��϶�.

<�Է�>
�Է��� �׽�Ʈ ���̽����� �� �� �������� n�� �־�����. (2 < n < 100,000)

�Է��� �������� -1�� �־�����.

<���>
�׽�Ʈ���̽� ���� ���ٿ� �ϳ��� ����ؾ� �Ѵ�.

n�� ���������, n�� n�� �ƴ� ������� ������ ��Ÿ���� ����Ѵ�(���� ��� ����).

�̶�, ������� ������������ �����ؾ� �Ѵ�.

n�� �������� �ƴ϶�� n is NOT perfect. �� ����Ѵ�.

<���� �Է� 1>
6
12
28
-1
<���� ��� 1>
6 = 1 + 2 + 3
12 is NOT perfect.
28 = 1 + 2 + 4 + 7 + 14
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;

	cin >> N;

	while (N != -1)
	{
		vector<int> arr;
		int sum = 0;
		for (int i = 1; i < N; i++)
		{
			if (N % i == 0)
			{
				sum += i;
				arr.push_back(i);
			}
		}
		cout << N << " ";
		if (sum == N)
		{
			cout << "= ";
			for (int i = 0; i < arr.size(); i++)
			{
				if (i > 0)
				{
					cout << " + ";
				}
				cout << arr[i];
			}
		}
		else
		{
			cout << "is NOT perfect.";
		}
		cout << endl;
		cin >> N;
	}
	return 0;
}