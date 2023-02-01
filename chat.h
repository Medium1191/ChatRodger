#pragma once
#include <string>
#include <iostream>
#include "user.h"
#include "message.h"

class chat
{
	string UserLogin;
	bool inChat = true;
	userBox chatUsers;
	messageBox chatMessages;
public:
	bool getInChat() { return inChat; }
	chat() = default;
	void startMenu();
	void userMenu();
	void registerUser();
	void signUp();
	//void readSms();
	void writeSms();

};

