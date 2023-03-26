#include "chat.h"
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include "message.h"


//new
void chat::startMenu()								//начальное меню
{
	SetConsoleTextAttribute(hConsole, 14);
	cout << "Добро пожаловать в таинственный чат! Выберете один из предложенных сценариев" << endl;
	SetConsoleTextAttribute(hConsole, 13);
	cout << "1 - Вход" << endl;
	cout << "2 - Регистрация" << endl;
	cout << "3 - Выход" << endl;
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
		cout << "До свидания!" << endl;
		inChat = false;
		break;
	}
}

void chat::userMenu()					//меню пользователя после входа
{
	int op;
	SetConsoleTextAttribute(hConsole, 3);
	cout << "1 - Прочитать сообщения\n2 - Написать сообщение\n3 - Посмотреть список пользователей \n4 - Выход в главное меню\n ";
	cin >> op;
	switch (op)
	{
	case 1:
		SetConsoleTextAttribute(hConsole, 16);
		cout << "============================================================" << endl;
		readSms(UserLogin);
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
		for (int i = 0; i < chatUsers.size(); i++)
			cout << chatUsers[i];
		userMenu();
	case 4:
		cout << endl;
			UserLogin = "";
			startMenu();
	}
}

void chat::registerUser()							//регистрация пользователя
{
	string login, name, pass;
	SetConsoleTextAttribute(hConsole, 2);
	cout << "Введите логин ";
	cin >> login;
	SetConsoleTextAttribute(hConsole, 2);
	cout << "Введите своё имя ";
	cin >> name;
	SetConsoleTextAttribute(hConsole, 2);
	cout << "Введите пароль ";
	cin >> pass;
	try
	{
		user x(login, name, pass);
		chatUsers.push_back(x);
		SetConsoleTextAttribute(hConsole, 10);
		cout << "Вы успешно зарегистрировались" << endl;
		startMenu();
	}
	catch (const char* ex)
	{
		cout << ex << endl;
		startMenu();
	}
}

void chat::signUp()							//вход 
{
	string login, pass;
	SetConsoleTextAttribute(hConsole, 2);
	cout << "Введите свой логин ";
	cin >> login;
	SetConsoleTextAttribute(hConsole, 2);
	cout << "Введите свой пароль ";
	cin >> pass;
	try
	{

		UserLogin = enterUser(login, pass);
	}
	catch (const char* n)
	{
		cout << n<<endl;
		startMenu();
	}
	UserLogin = login;
	SetConsoleTextAttribute(hConsole, 14);
	cout << "Приветствую " << UserLogin << endl;
	userMenu();

}

void chat::readSms(string login)
{
	vector<message>::iterator it = chatMessages.begin();
	for (int i =0; it!= chatMessages.end();it++)
	{
		if (it[i].getFrom() == login)
			it[i].readMessage();
	}
}

void chat::writeSms()
{
	bool userInBase = false;
	string to,sms;
	SetConsoleTextAttribute(hConsole, 11);
	cout << "Введите пользователя которому хотите отправить сообщение или введите all чтобы отправить сообщение для всех\n ";
	cin >> to;
	SetConsoleTextAttribute(hConsole, 12);
	if (UserLogin == to) throw "вы не можете отправить сообщение самому себе!";
	for (int i = 0; i < chatUsers.size(); i++)
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
		throw "Пользователя с таким ником нет в нашем чате =(";
	}
	SetConsoleTextAttribute(hConsole, 11);
	cout << "Введите сообщение - ";
	getline(cin, sms);  //в одиночку getline почемуто не срабатывает
	getline(cin, sms);
	//cin >> sms;
	message x(UserLogin, to, sms);
	chatMessages.push_back(x);
	//chatMessages.push_back(UserLogin, to, sms);
}

string chat::enterUser(string login, string pass)
{
	for (int i = 0; i < chatUsers.size(); i++)
	{
		if (chatUsers[i].getlogin() == login)
			if (chatUsers[i].getPass() == pass)
				return login;
			else throw "Неверный пароль!";
	}
	throw "Такого пользователя нет!";
}