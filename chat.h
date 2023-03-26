#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "user.h"
#include "message.h"

class chat
{
	string UserLogin;
	bool inChat = true;
	vector <user> chatUsers;
	vector <message> chatMessages;
public:
	string enterUser(string login, string pass);
	
	bool getInChat() { return inChat; }
	chat() = default;
	void startMenu();
	void userMenu();
	void registerUser();
	void signUp();
	void readSms(string login);
	void writeSms();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
};

