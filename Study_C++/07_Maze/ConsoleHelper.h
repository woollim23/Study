#pragma once
#include <Windows.h>
#include "Types.h"

enum class ConsoleColor
{
	BLACK = 0,
	RED = FOREGROUND_RED,
	GREEN = FOREGROUND_GREEN,
	BLUE = FOREGROUND_BLUE,
	YELLOOW = RED | GREEN,
	WHITE = RED | GREEN | BLUE,

};

class ConsoleHelper
{
public:
	// 깜박깜박 거리는 커서
	static void SetCursorPosition(int32 x, int32 y);
	// 커서 색깔 지정
	static void SetCursorColor(ConsoleColor color);
	// 커서를 보여줄지 안보여줄지 지정하는 함수
	static void ShowConsoleCursor(bool flag);
};

