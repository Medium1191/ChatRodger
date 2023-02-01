#pragma once
#include <string>
#include "user.h"

using namespace std;



class message										
{
	
	string from;								// ����������� ���������
	string to;									// �������
	string sms;									// ����� ���������
public:
	message() = default;
	~message() = default;
	string getTo() { return to; }				// ���������� �������
	string getFrom() { return from;}			// ���������� �����������
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

class messageBox								//�������� ���� (���������)
{
	int size{};
	message* messages{};
public:
	messageBox() = default;
	~messageBox() { delete[] messages; }
	
	void addMessage(string from, string to, string sms)				// ��������� ��������� 
	{
	
		message* newMessages = new message[size + 1];
		if (size > 0)
		{
			for (int i = 0; i < size; i++)
				newMessages[i] = messages[i];
		}
		newMessages[size].setMessage(from, to, sms);
		delete[] messages;
		messages = newMessages;
		size++;
	}
	void readSms(string to)
	{

		for (int i = 0; i < size; i++)
		{
			if (messages[i].getTo() == to || messages[i].getTo() == "all" || messages[i].getFrom() == to)	messages[i].readMessage();
		}
	}
};