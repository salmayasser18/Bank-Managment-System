#pragma once
#include "ClientManager.h"
#include "Screen.h"
using namespace std;

class EmployeeManager {
private:
	static void EmployeeMenu()
	{
		system("cls");
		cout << "1- Display My INFO\n";
		cout << "2- Add new client\n";
		cout << "3- Search for client\n";
		cout << "4- List all clients\n";
		cout << "5- Edit client info\n";
		cout << "6- Logout\n";
	}
public:
	static void AddClient(Employee* employee)
	{
		int id;
		string password, name;
		double balance;
		client c;
		cout << "Enter client's name : \n";
		cin >> name;
		c.setName(name);
		cout << "Enter client's password : \n";
		cin >> password;
		c.setPassword(password);
		cout << "Enter initial balance:\n";
		cin >> balance;
		c.setBalance(balance);
		cout << "Your ID is: ";
		id = fileshelper::getLast("clientid.txt");
		id++;
		cout << id << endl;
		c.setId(id);
		employee->addclient(c);
		fileshelper::saveLast("clientid.txt", id);
		cout << "Operation successful \n ";
	}
	static void SearchForClient(Employee* employee)
	{
		int id;
		cout << "Enter client's ID : \n";
		cin >> id;
		if (employee->searchforclient(id) == NULL)
		{
			cout << "No client found with the provided ID\n";
		}
		else
		{
			employee->searchforclient(id)->display();
		}
	}
	static void EditClientInfo(Employee* employee)
	{
		int id;
		cout << "Enter client ID : \n";
		cin >> id;
		if (employee->searchforclient(id) == NULL)
		{
			cout << "No client found with the provided ID\n";
		}
		else
		{
			employee->searchforclient(id)->display();
			string name, password;
			double balance;
			cout << "Enter new name: \n";
			cin >> name;
			cout << "Enter new password: \n";
			cin >> password;
			cout << "Enter new balance: \n";
			cin >> balance;
			employee->editclient(id, name, password, balance);
			cout << "Info updated\n";
		}
	}
	static Employee* login(int id, string password)
	{
		for (empIT = employeelist.begin(); empIT < employeelist.end(); empIT++)
		{
			if (empIT[0].getId() == id && empIT[0].getPassword() == password)
			{
				return empIT._Ptr;
			}
		}
		return NULL;
	}
	static bool EmployeeOptions(Employee* employee)
	{
		EmployeeMenu();
		cout << "What do you want to do,"<<employee->getName()<< "? \n";
		int choice;
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			employee->display();
			break;
		case 2:
			AddClient(employee);
			break;
		case 3:
			SearchForClient(employee);
			break;
		case 4:
		{
			cout << "Clients : \n";
			employee->listclients();
			break;
		}
		case 5:
			EditClientInfo(employee);
			break;
		case 6:
			return false;
			break;
		default:
			EmployeeOptions(employee);
			return true;
			break;
		}
		system("pause");
		return true;
	}
};