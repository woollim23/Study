#include "pch.h"
#include <iostream>
#include "ConsoleHelper.h"

int main()
{
	uint64 lastTick = 0;
	while (true)
	{
#pragma region ������ ����
		const uint64 currentTick = ::GetTickCount64();
		const uint64 deltaTick = currentTick - lastTick;
		lastTick = currentTick;
#pragma endregion
		// �Է�

		// ����

		// ������
		
		// �ֻ�� ������ Ŀ�� ��ġ
		ConsoleHelper::SetCursorPosition(0, 0);
		// �����̴� Ŀ�� ��
		ConsoleHelper::ShowConsoleCursor(false);
		// Ŀ�� ���� ��������
		ConsoleHelper::SetCursorColor(ConsoleColor::RED);
		
		const char* TILE = "��";

		for (int32 y = 0; y < 25; y++)
		{
			for (int32 x = 0; x < 25; x++)
			{
				cout << TILE;
			}
			cout << endl;
		}
	}
}