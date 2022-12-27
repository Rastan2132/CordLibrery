#include "Header.h"

#define MAXSTRLÅN 80

using namespace std;


void _setCursorPosition(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}


void _SetColor(COLOR Color)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, (WORD)(Color.back << 4 | Color.text));
}
COLOR _GetColor()
{
	COLOR Color;
	WORD word = _GetColorWord();
	Color.back = (int)(word >> 4);
	Color.text = (int)word - (Color.back << 4);
	return Color;
}
WORD _GetColorWord()
{
	WORD text_atribute;
	CONSOLE_SCREEN_BUFFER_INFO info;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hOut, &info);
	text_atribute = info.wAttributes;
	return text_atribute;
}

void _InsertCh(char* str, int buffer_size, int& cursor, int& term, char symb)
{
	if (cursor == buffer_size - 1) return;
	if (term != buffer_size - 1) term++;
	for (int i = term - 1; i > cursor; i--)
		str[i] = str[i - 1];

	str[cursor++] = symb;
	str[term] = '\0';
}
void _DeleteCh(char* str, int& cursor, int& term)
{
	if (cursor < 1) return;



	for (int i = cursor-- - 1; i < term; i++)
		str[i] = str[i + 1];



	str[term--] = ' ';
}
void _Clear(int x, int y, long cnt)
{
	_showcursor(false);
	_setCursorPosition(x, y);
	for (int i = 0; i < cnt; i++)
		std::cout << " ";
	_setCursorPosition(x, y);
	_showcursor(true);
}

COORD _getConsoleSize()
{
	COORD size;
	_CONSOLE_SCREEN_BUFFER_INFO info;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hOut, &info);
	size.X = info.srWindow.Right - info.srWindow.Left + 1;
	size.Y = info.srWindow.Bottom - info.srWindow.Top + 1;
	return size;
}
void _showcursor(bool flag)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo(hOut, &info);
	// info.dwSize = 20;
	info.bVisible = flag;
	SetConsoleCursorInfo(hOut, &info);
}