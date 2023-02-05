#include <iostream>
#include <string>
#include < Windows.h >
#include "chat.h"
#include "user.h"
#include "message.h"
#include <conio.h>
#include <stdio.h>

using namespace std;

HANDLE hConsole;

int main()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 3);
	setlocale(LC_ALL, "");
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	chat a;

	do
	{
		a.startMenu();
	} while (a.getInChat());

	return 0;
}