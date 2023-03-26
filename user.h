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
	string login;								//�����
	string name;								//���
	string pass;								//������
public:
	user() = default;
	user(string& login, string& name, string& pass):login(login),name(name),pass(pass){}
	~user() = default;
	
	void setUser(string& login, string& name, string& pass)		
	{
		this->login = login;
		this->name = name;
		this->pass = pass;
	}
	const string getlogin() { return login; }					//�������
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
		os << "������������ - " << other.login << ", ��� - " << other.name << endl;
		return os;
	}
	
};

