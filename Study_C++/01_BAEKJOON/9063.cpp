/*
* ����
*
<����>
 �Ӿ��� 1950 �� �ѱ��������� ���� ���ظ� �� ����� �� �ϳ���. ���� �뿡 ���غ��� ���� ����� ��� ������ ���� �״� 6.25 �� �Ͼ�� ���� �ص� ��û�� ���濡 ���� ������ ������ ū ���ڿ���. ������ ���� �Ӿ��� �������� �� ������ �͵鸸 ì�ܼ� �Ϻ����� �ǳ��� ������ �ǳ� �߿� �׸� �������� �Ҿ������ ����. ������ ���� �Ŀ� �Ӿ��� ���� �̹� �ٸ� ������� ������ �Ǿ� �־���, �Ӿ��� ���� ��ã���� ������ ������ ������ ���� ���� �Ͱ� �ٸ� �� ������. �̷��ٰ� �Ӿ��� ��ٴڿ� ���ɰ� �����.

�̶�, �Ӿ����� ���� ������ ���ö����� �ٷ� �ڽ��� ����ó�� �� ������ ���� ǥ���� �س��Ҵ� ����̴�. �Ӿ��� ������ ������ �ڽ��� ������ �ŴҴٰ� ���� ���� ���� �ڽ��� �̸��� ������ �������� ������Ҵ� ���̴�. ��, � �������� ���� �̸��� ���� �������� ���´ٸ� �� ������ ������ �Ӿ��� ���̾��ٴ� ���� �����ϴ� ���̴�.

�Ӿ��� ��� �λ�Ҽ��� ���� �ڽ��� ���� ã���� �߰� �������� �ٰŸ� ��� �������� ������ ������ ���� �ڽ��� ���� �� �����̾��ٴ� ���� �����Ͽ� �ᱹ ����ǻ縦 �����ϴ� ���� �����Ͽ���. ����ǻ�� ������ ���� �ǰ��� ���ȴ�. �� 6.25 ������ ���μ��� �������� 99%�� ����, ���� �������� ������ ���簢�� ����̾����Ƿ�, �Ӿ��� �̸��� ������ �������� ������ ��� ������ �����ϴ� ���� ���� ����, ���� �������� ������ ���� ���� ���簢���� ������ �Ӿ��� ������ �����Ѵ�.�� �Ӿ��� ���� ���ظ� ���� �������� �� �̻��� �䱸�� ���� �ٰŰ� ������ ������ �� �ǰ��� ������� �ߴ�.

�Ӿ��� �̸��� ������ �������� ��ġ N ���� �־��� ����, �Ӿ����� ���ư� ������ ���̸� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ��, �������� ��ġ�� 2 ���� ���� ��ǥ�� �־����� �������� ���� ��ġ�� ���� ���� �߰ߵ� ���� ������, x ���� ���ǹ����� ����, y ���� ���ǹ����� �����̶�� �����Ѵ�.

���� ��� ���� ���� (2, 1), (3, 2), (5, 2), (3, 4) �� ������ �������� �߰��Ͽ��ٸ�, �Ӿ����� ���ư� ������ (2, 1), (5, 1), (2, 4), (5, 4)�� �� ���������� �ϴ� ���簢���̸�, ���̴� (5 - 2) �� (4 - 1) = 9 �� �ȴ�.

<�Է�>
ù° �ٿ��� ���� ���� N (1 �� N �� 100,000) �� �־�����. �̾����� N �ٿ��� �� ���� ��ǥ�� �� ���� ������ �� �ٿ� �ϳ��� �־�����. ������ ��ǥ�� -10,000 �̻� 10,000 ������ �����̴�.

<���>
ù° �ٿ� N ���� ���� �ѷ��δ� �ּ� ũ���� ���簢���� ���̸� ����Ͻÿ�.

<���� �Է� 1>
3
20 24
40 21
10 12
<���� ��� 1>
360
<���� �Է� 2>
1
15 13
<���� ��� 2>
0
*/

#include <iostream>
using namespace std;

int main()
{
	int N;
	int min_X = 100001;
	int min_Y = 100001;
	int max_X = -100001;
	int max_Y = -100001;
	cin >> N;

	if (N <= 1)
	{
		cout << 0;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			int x, y;
			cin >> x >> y;

			if (x < min_X)
			{
				min_X = x;
			}
			if (x > max_X)
			{
				max_X = x;
			}
			if (y < min_Y)
			{
				min_Y = y;
			}
			if (y > max_Y)
			{
				max_Y = y;
			}
		}

		cout << (max_X - min_X) * (max_Y - min_Y);
	}
	return 0;
}