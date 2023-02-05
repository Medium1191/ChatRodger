#pragma once
#include <iostream>
#include <ostream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>

using namespace std;


class user
{
	string login;								//логин
	string name;								//им€
	string pass;								//пароль
public:
	user() = default;
	~user() = default;
	
	void setUser(string& login, string& name, string& pass)		
	{
		this->login = login;
		this->name = name;
		this->pass = pass;
	}
	const string getlogin() { return login; }					//геттеры
	const string getPass() { return pass; }
	const string getName() { return name; }

	const user& operator = (user& other)
	{
		this->login = other.login;
		this->name = other.name;
		this->pass = other.pass;
		return other;
	}
	
	friend ostream& operator <<(ostream& os, user& other)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 6);
		os << "ѕользователь - " << other.login << ", им€ - " << other.name << endl;
		return os;
	}
	
};

class userBox
{
	int size{};
	user* users{};
public:
	userBox() = default;
	~userBox() { delete[] users; }
	int getSize() { return size; }
	user& operator[](int i)
	{
		return users[i];
	}
	
	void addUser(string& login, string& name, string& pass)			//добавление пользовател€ при регистрации
	{
		for (int i = 0; i < size; i++)					// проверка логина на уникальность
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 12);
			if (users[i].getlogin() == login) throw "ѕользователь с таким логином уже существует!";
		}

		user* newUsers = new user[size + 1]{};
		if (size > 0)
		{
			for (int i = 0; i < size; i++)
			{
				 newUsers[i]=users[i];
			}
		}
		newUsers[size].setUser(login, name, pass);
		delete[] users;
		users = newUsers;
		
		size++;		
	}
	void showUsers()								// вывод списка пользователей в базе
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 22);
		cout << "============================================================" << endl;
		cout << "—писок пользователей " << endl;
		cout << "============================================================" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << users[i];
		}
		cout << "============================================================" << endl;
	}
	const string getNameByLogin(string& login)
	{
		for (int i = 0; i < size; i++)
		{
			if (users[i].getlogin() == login) return users[i].getName();
			break;
		}
	}
	string enterUser (string& login, string& pass)		//вход по логину и паролю
	{
		for (int i = 0; i < size; i++)					//проверка логина и парол€
		{
			if (users[i].getlogin() == login && users[i].getPass() == pass)
			{
				return login;
				
			}
		}
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 12);
		throw "Ќеверный логин или пароль!";
	}
};