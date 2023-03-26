#include <iostream>
#include <string>
#include <Windows.h>
#include "chat.h"
#include "user.h"
#include "message.h"

using namespace std;

int main()
{
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