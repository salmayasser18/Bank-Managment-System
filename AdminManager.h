#pragma once
#include "EmployeeManager.h"
using namespace std;

class AdminManager {
private:
	static void AdminMenu(Admin* admin)
	{
		system("cls");
		cout << "1- Add new client \n";
		cout << "2- Search for a client\n";
		cout << "3- Edit a client\n";
		cout << "4- Remove existing client\n";
		cout << "5- List all clients\n";
		cout << "6- Add new employee\n";
		cout << "7- Search for an employee\n";
		cout << "8- Edit an employee\n";
		cout << "9- Remove an existing employee\n";
		cout << "10- List all employees\n";
		cout << "11- Assign new admin\n";
		cout << "12- Display my info \n";
		cout << "13- Clear Clients' file \n";
		cout << "14- Clear Employees' file \n";
		cout << "15- Logout\n";
	}
public:
	static void AddAdmin(Admin* admin)
	{
		int id;
		string password, name;
		double salary;
		Admin a;
		cout << "Enter Admin's name : \n";
		cin >> name;
		a.setName(name);
		cout << "Enter Admin's password : \n";
		cin >> password;
		a.setPassword(password);
		cout << "Enter initial salary:\n";
		cin >> salary;
		a.setsalary(salary);
		cout << "Admin's ID is: ";
		id = fileshelper::getLast("adminid.txt");
		id++;
		cout << id << endl;
		a.setId(id);
		adminlist.push_back(a);
		fileshelper::saveLast("adminid.txt",id);
		cout << "Operation successful \n ";
	}
	static void AddEmployee(Admin* admin)
	{
		int id;
		string password, name;
		double salary;
		Employee e;
		cout << "Enter employee's name : \n";
		cin >> name;
		e.setName(name);
		cout << "Enter employee's password : \n";
		cin >> password;
		e.setPassword(password);
		cout << "Enter initial salary:\n";
		cin >> salary;
		e.setsalary(salary);
		cout << "Employee's ID is: ";
		id = fileshelper::getLast("employeeid.txt");
		id++;
		cout << id << endl;
		e.setId(id);
		admin->addemployee(e);
		fileshelper::saveLast("employeeid.txt", id);
		cout << "Operation successful \n ";
	}
	static void SearchForEmployee(Admin* admin)
	{
		int id;
		cout << "Enter Employee's ID : \n";
		cin >> id;
		if (admin->searchforemployee(id) == NULL)
		{
			cout << "No employee found with the provided ID\n";
		}
		else
		{
			admin->searchforemployee(id)->display();
		}
	}
	static void EditEmployee(Admin* admin)
	{
		int id;
		cout << "Enter employee's ID : \n";
		cin >> id;
		if (admin->searchforemployee(id) == NULL)
		{
			cout << "No employee found with the provided ID\n";
		}
		else
		{
			string name, password;
			double salary;
			admin->searchforemployee(id)->display();
			cout << "Enter new name: \n";
			cin >> name;
			cout << "Enter new password: \n";
			cin >> password;
			cout << "Enter new salary: \n";
			cin >> salary;
			admin->editemployee(id, name, password, salary);
			cout << "Info updated\n";
		}
	}
	static Admin* login(int id, string password)
	{
		for (int i = 0; i < adminlist.size(); i++)
		{
			if (adminlist[i].getId() == id && adminlist[i].getPassword() == password)
			{
				return &adminlist[i];
			}
		}
		return NULL;
	}
	static void deleteclient(Admin* admin) {
		int id;
		char yes;
		bool found=true;
		cout << "Enter ID of client you want to delete: "; cin >> id;
		for (clientIT = clientlist.begin(); clientIT < clientlist.end(); clientIT++) {
			if (id == clientIT[0].getId()) {
				found = false;
				cout << "Client found:\n";
				clientIT[0].display();
				cout << "===========\n";
				cout << "Are you aure you want to delete this client?(y/n)\n";
				cin >> yes;
				if (yes == 'y' || yes == 'Y')
				{
					clientlist.erase(clientIT);
					cout << "Client deleted successfully.\n";
					break;
				}
				else
					break;
			}
		}
		if (found) {
			cout << "Client doesn't exist...\n";
		}
	}
	static void deleteEmployee(Admin* admin) {
		int id;
		char yes;
		bool found = true;
		cout << "Enter ID of employee you want to delete: "; cin >> id;
		for (empIT = employeelist.begin(); empIT < employeelist.end(); empIT++) {
			if (id == empIT[0].getId()) {
				found = false;
				cout << "Employee found:\n";
				empIT[0].display();
				cout << "===========";
				cout << "Are you aure you want to delete this employee?(y/n)\n";
				cin >> yes;
				if (yes == 'y' || yes == 'Y')
				{
					employeelist.erase(empIT);
					break;
				}
				else
					break;
			}
		}
		if (found) {
			cout << "Employee doesn't exist...\n";
		}
	}
	static bool AdminOptions(Admin* admin)
	{
		AdminMenu(admin);
		cout << "What do you want to do, "<<admin->getName()<< "? \n";
		int choice;
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
		{
			EmployeeManager::AddClient(admin);
			break;
		}
		case 2:
		{
			EmployeeManager::SearchForClient(admin);
			break;
		}
		case 3:
		{
			EmployeeManager::EditClientInfo(admin);
			break;
		}
		case 4:
		{
			deleteclient(admin);
			filemanager::refillclients();
			break;
		}
		case 5:
		{
			admin->listclients();
			break;
		}
		case 6:
		{
			AddEmployee(admin);
			break;
		}
		case 7:
		{
			SearchForEmployee(admin);
			break;
		}
		case 8:
		{
			EditEmployee(admin);
			break;
		}
		case 9:
		{
			deleteEmployee(admin);
			break;
		}
		case 10:
		{
			cout << "Employees: \n";
			admin->listemployees();
			break;
		}
		case 11:
		{
			AddAdmin(admin);
			break;
		}
		case 12:
		{
			admin->display();
			break;
		}
		case 13:
		{
			filemanager::removeAllClients();
			break;
		}
		case 14:
		{
			filemanager::removeAllEmployees();
			break;
		}
		case 15:
		{
			return false;
			break;
		}
		default:
		{
			AdminOptions(admin);
			return true;
			break;
		}
		}
		system("pause");
		return true;
	}
};