#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <fstream>
#include <ctype.h>
#include <windows.h>

#define MAXSTRLÅN 80

using namespace std;

struct COLOR
{
	short text;
	short back;
};
enum ConsoleColor
{
	Black = 0, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
	LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};



void _setCursorPosition(int x, int y);


void _SetColor(COLOR Color);

COLOR _GetColor();
WORD _GetColorWord();

void _InsertCh(char* str, int buffer_size, int& cursor, int& term, char symb);
void _DeleteCh(char* str, int& cursor, int& term);
void _Clear(int x, int y, long cnt);

COORD _getConsoleSize();
void _showcursor(bool flag);