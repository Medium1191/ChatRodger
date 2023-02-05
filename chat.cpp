#include "chat.h"
#include <Windows.h>
#include <conio.h>
#include <stdio.h>


//new
void chat::startMenu()								//��������� ����
{
	SetConsoleTextAttribute(hConsole, 14);
	cout << "����� ���������� � ������������ ���! �������� ���� �� ������������ ���������" << endl;
	SetConsoleTextAttribute(hConsole, 13);
	cout << "1 - ����" << endl;
	cout << "2 - �����������" << endl;
	cout << "3 - �����" << endl;
	int op;
	cin >> op;
	switch (op)
	{
	case 1: 
		signUp();
		break;
	case 2:
		registerUser();
		break;
	case 3:
		SetConsoleTextAttribute(hConsole, 10);
		cout << "�� ��������!" << endl;
		inChat = false;
		break;
	}
}

void chat::userMenu()					//���� ������������ ����� �����
{
	int op;
	SetConsoleTextAttribute(hConsole, 3);
	cout << "1 - ��������� ���������\n2 - �������� ���������\n3 - ���������� ������ ������������� \n4 - ����� � ������� ����\n ";
	cin >> op;
	switch (op)
	{
	case 1:
		SetConsoleTextAttribute(hConsole, 16);
		cout << "============================================================" << endl;
		chatMessages.readSms(UserLogin);
		SetConsoleTextAttribute(hConsole, 16);
		cout << "============================================================" << endl;
		userMenu();
		break;
	case 2:
		try
		{
			writeSms();
		}
		catch (const char* ex)
		{
			cout << ex << endl;
			userMenu();
		}
		
		userMenu();
		break;
	case 3:
		chatUsers.showUsers();
		userMenu();
	case 4:
		cout << endl;
			UserLogin = "";
			startMenu();
	}
}

void chat::registerUser()							//����������� ������������
{
	string login, name, pass;
	SetConsoleTextAttribute(hConsole, 2);
	cout << "������� ����� ";
	cin >> login;
	SetConsoleTextAttribute(hConsole, 2);
	cout << "������� ��� ��� ";
	cin >> name;
	SetConsoleTextAttribute(hConsole, 2);
	cout << "������� ������ ";
	cin >> pass;
	try
	{
		chatUsers.addUser(login, name, pass);
		SetConsoleTextAttribute(hConsole, 10);
		cout << "�� ������� ������������������" << endl;
		startMenu();
	}
	catch (const char* ex)
	{
		cout << ex << endl;
		startMenu();
	}
}

void chat::signUp()							//���� 
{
	string login, pass;
	SetConsoleTextAttribute(hConsole, 2);
	cout << "������� ���� ����� ";
	cin >> login;
	SetConsoleTextAttribute(hConsole, 2);
	cout << "������� ���� ������ ";
	cin >> pass;
	try
	{
		UserLogin = chatUsers.enterUser(login, pass);
	}
	catch (const char* n)
	{
		cout << n<<endl;
		startMenu();
	}
	UserLogin = login;
	SetConsoleTextAttribute(hConsole, 14);
	cout << "����������� " << UserLogin << endl;
	userMenu();

}

void chat::writeSms()
{
	bool userInBase = false;
	string to,sms;
	SetConsoleTextAttribute(hConsole, 11);
	cout << "������� ������������ �������� ������ ��������� ��������� ��� ������� all ����� ��������� ��������� ��� ����\n ";
	cin >> to;
	SetConsoleTextAttribute(hConsole, 12);
	if (UserLogin == to) throw "�� �� ������ ��������� ��������� ������ ����!";
	for (int i = 0; i < chatUsers.getSize(); i++)
	{
		
		if(chatUsers[i].getlogin() != to && to != "all") userInBase = false;
		else
		{
			userInBase = true;
			break;
		}
	}
	if (userInBase == false)
	{
		SetConsoleTextAttribute(hConsole, 12);
		throw "������������ � ����� ����� ��� � ����� ���� =(";
	}
	SetConsoleTextAttribute(hConsole, 11);
	cout << "������� ��������� - ";
	getline(cin, sms);  //� �������� getline �������� �� �����������
	getline(cin, sms);
	//cin >> sms;
	chatMessages.addMessage(UserLogin, to, sms);
}