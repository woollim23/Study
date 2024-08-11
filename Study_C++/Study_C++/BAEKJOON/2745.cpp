/*
<문제>
B진법 수 N이 주어진다.이 수를 10진법으로 바꿔 출력하는 프로그램을 작성하시오.
10진법을 넘어가는 진법은 숫자로 표시할 수 없는 자리가 있다.이런 경우에는 다음과 같이 알파벳 대문자를 사용한다.
A: 10, B : 11, ..., F : 15, ..., Y : 34, Z : 35

<입력>
첫째 줄에 N과 B가 주어진다. (2 ≤ B ≤ 36)
B진법 수 N을 10진법으로 바꾸면, 항상 10억보다 작거나 같다.

<출력>
첫째 줄에 B진법 수 N을 10진법으로 출력한다.

<예제 입력 1>
ZZZZZ 36
<예제 출력 1>
60466175
*/


#include <iostream>
#include <string>
using namespace std;

int func(int B, int cnt)
{
	if (cnt == 0)
		return 1;
	return B * func(B, cnt-1);
}

int main()
{
	int B;
	string N;
	int res = 0;
	int cnt = 0;

	cin >> N >> B;

	for (int i = (N.length()-1); i >= 0; i--)
	{
		if (isalpha(N[i]))
		{
			res += ((N[i] - 55) * func(B, cnt));
		}
		else
		{
			res += ((N[i] - '0') * func(B, cnt));
		}
		cnt++;
	}

	cout << res;

	return 0;
}