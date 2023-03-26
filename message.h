#pragma once
#include <string>
#include "user.h"

using namespace std;



class message										
{
	
	string from;								// Отправитель сообщения
	string to;									// Адресат
	string sms;									// Текст сообщения
public:
	message() = default;
	message(string from, string to, string sms):from(from),to(to),sms(sms){}
	~message() = default;
	string getTo() { return to; }				// Возвращает адресат
	string getFrom() { return from;}			// Возвращает отправителя
	void setMessage(string from, string to, string sms)
	{
		this->from = from;
		this->to = to;
		this->sms = sms;
	}
	void readMessage()
	{
		cout << from << " : " << sms << endl;
	}
	
};

