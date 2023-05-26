#pragma once
#include <Windows.h>
#include "AdminManager.h"
using namespace std;

class screens {
public:
	static void bankName() {
		string s = "XXX BANK";
		for (int i = 0; i < s.size(); i++) {
			cout << s[i];
			Sleep(300);
		}
		cout << "\n";
		Sleep(600);
	}
	static void welcome()
	{
		string s = "Welcome!";
		for (int i = 0; i < s.size(); i++) {
			cout << s[i];
			Sleep(300);
		}
		Sleep(600);
		cout << "\n";
	}
	static void loginOptions()
	{
		cout << "Login As : \n";
		cout << "1-Admin \n";
		cout << "2-Employee\n";
		cout << "3-Client \n";
	}
	static int LoginAs()
	{
		loginOptions();
		int choice;
		cin >> choice;
		if (choice == 1 || choice == 2 || choice == 3)
		{
			return choice;
		}
		else
		{

			LoginAs();
		}
	}
	static void Invalid(int c)
	{
		cout << "Invalid Entry, Please try again\n";
		LoginScreen(c);
	}
	static bool logout()
	{
		char again;
		cout << "Are you sure you want to log out? (y/n)\n";
		for (int i = 0; i < 3; i++) {
			cout << ".";
			Sleep(400);
		}
		cout << "\n";
		cin >> again;
		while (again != 'Y' && again != 'y' && again != 'N' && again != 'n')
		{
			cout << "  Invalid character, Please choose character from the options:  ";  cin >> again;
			break;
		}
		if (again == 'Y' || again == 'y')
		{
			return true;
		}
		else if (again == 'n' || again == 'N')
		{
			cout << "goodbye\n";
		}
	}
	static void LoginScreen(int c)
	{
		int id;
		string password;
		system("cls");
		cout << "Enter ID : ";
		cin >> id;
		cout << "Enter password : ";
		cin >> password;
		switch (c)
		{
		case 1:
		{
			if (AdminManager::login(id, password) != NULL)
			{
				while (AdminManager::AdminOptions(AdminManager::login(id, password)) != false);
				logout();
			}
			else Invalid(1);
			break;
		}
		case 2:
		{
			if (EmployeeManager::login(id, password) != NULL)
			{
				while (EmployeeManager::EmployeeOptions(EmployeeManager::login(id, password)) != false);
				logout();
			}
			else Invalid(2);
			break;
		}
		case 3:
		{
			if (ClientManager::login(id, password) != NULL)
			{
				while (ClientManager::ClientOptions(ClientManager::login(id, password)) != false);
				logout();
			}
			else Invalid(3);
			break;
		}

		default:
			loginOptions();
		}
	}
	static void runapp()
	{
		filemanager::getdata();
		bankName();
		welcome();
		system("pause");
		system("cls");
		LoginScreen(LoginAs());
		filemanager::refill_all();
	}
};