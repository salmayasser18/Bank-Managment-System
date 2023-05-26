#pragma once
#include <string>
#include "FileManager.h"
#include "client.h"
using namespace std;

class ClientManager {
private:
	//private 34an only client options can call it
	static void PrintClientMenu()
	{
		system("cls");
		cout << "1- Display My INFO\n";
		cout << "2- Check Balance\n";
		cout << "3- Withdraw Amount\n";
		cout << "4- Deposit Amount\n";
		cout << "5- Transfer Amount\n";
		cout << "6- Logout\n";
	}
public:
	static client* login(int id, string password)
	{
		for (clientIT=clientlist.begin(); clientIT < clientlist.end(); clientIT++)
		{
			if (clientIT[0].getId() == id && clientIT[0].getPassword() == password)
			{
				return clientIT._Ptr;
			}
		}
		return NULL;
	}
	static bool ClientOptions(client* client)
	{
		PrintClientMenu();
		cout << "What do you want to do, "<<client->getName()<< "? \n";
		int choice, id;
		double amount;
		Employee e;
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			client->display();
			break;
		case 2:
			client->checkBalance();
			break;
		case 3:
			client->withdraw();
			break;
		case 4:
			client->deposit();
			break;
		case 5:
		{
			cout << "Enter ID of the person you want to transfer to: \n";
			cin >> id;
			while (e.searchforclient(id) == NULL)
			{
				cout << "Invalid id.\n";
				cout << "Receiver's ID : \n";
				cin >> id;
			}
			client->transferTo(*e.searchforclient(id));
			break;
		}
		case 6:
			return false;
			break;
		default:
		{
			cout << "Invalid entry, Please try again...\n";
			ClientOptions(client);
			return true;
		}
		}
		system("pause");
		return true;
	}
};