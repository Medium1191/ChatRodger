#include "chat.h"

//new

void chat::startMenu()								//��������� ����
{
	
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
		cout << "�� ��������!" << endl;
		inChat = false;
		break;
	}
}

void chat::userMenu()					//���� ������������ ����� �����
{
	int op;
	cout << "1 - ��������� ���������\n2 - �������� ���������\n3 - ���������� ������ ������������� \n4 - ����� � ������� ����\n ";
	cin >> op;
	switch (op)
	{
	case 1:
		cout << "============================================================" << endl;
		chatMessages.readSms(UserLogin);
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
	cout << "������� ����� ";
	cin >> login;
	cout << "������� ��� ��� ";
	cin >> name;
	cout << "������� ������ ";
	cin >> pass;
	try
	{
		chatUsers.addUser(login, name, pass);
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
	cout << "������� ���� ����� ";
	cin >> login;
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
	cout << "����������� " << UserLogin << endl;
	userMenu();

}

void chat::writeSms()
{
	bool userInBase = false;
	string to,sms;
	cout << "������� ������������ �������� ������ ��������� ��������� ��� ������� all ����� ��������� ��������� ��� ����\n ";
	cin >> to;
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
		throw "������������ � ����� ����� ��� � ����� ���� =(";
	}
	cout << "������� ��������� - ";
	getline(cin, sms);  //� �������� getline �������� �� �����������
	getline(cin, sms);
	//cin >> sms;
	chatMessages.addMessage(UserLogin, to, sms);

	
}