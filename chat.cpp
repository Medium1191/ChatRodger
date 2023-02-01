#include "chat.h"

//new

void chat::startMenu()								//начальное меню
{
	
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
		cout << "До свидания!" << endl;
		inChat = false;
		break;
	}
}

void chat::userMenu()					//меню пользователя после входа
{
	int op;
	cout << "1 - Прочитать сообщения\n2 - Написать сообщение\n3 - Посмотреть список пользователей \n4 - Выход в главное меню\n ";
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

void chat::registerUser()							//регистрация пользователя
{
	string login, name, pass;
	cout << "Введите логин ";
	cin >> login;
	cout << "Введите своё имя ";
	cin >> name;
	cout << "Введите пароль ";
	cin >> pass;
	try
	{
		chatUsers.addUser(login, name, pass);
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
	cout << "Введите свой логин ";
	cin >> login;
	cout << "Введите свой пароль ";
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
	cout << "Приветствую " << UserLogin << endl;
	userMenu();

}

void chat::writeSms()
{
	bool userInBase = false;
	string to,sms;
	cout << "Введите пользователя которому хотите отправить сообщение или введите all чтобы отправить сообщение для всех\n ";
	cin >> to;
	if (UserLogin == to) throw "вы не можете отправить сообщение самому себе!";
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
		throw "Пользователя с таким ником нет в нашем чате =(";
	}
	cout << "Введите сообщение - ";
	getline(cin, sms);  //в одиночку getline почемуто не срабатывает
	getline(cin, sms);
	//cin >> sms;
	chatMessages.addMessage(UserLogin, to, sms);

	
}