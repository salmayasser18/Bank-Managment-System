#pragma once
#include <fstream>
#include "Parser.h"
//parser
using namespace std;

class fileshelper {
public:
	static void saveLast(string fileName, int id) {
		fstream file;
		file.open(fileName, ios::out);
		file << id;
		file.close();
	}
	static int getLast(string fileName) {
		string id;
		int ID;
		fstream file;
		file.open(fileName, ios::in);
		file >> id;
		file.close();
		return ID = stoi(id);
	}
	static void saveEmployee(string lastIdFile, Employee e) {
		fstream file;
		file.open("Employees.txt", ios::app);
		file << e.getId() << "," << e.getName() << "," << e.getPassword() << "," << e.getsalary() << endl;
		file.close();
		saveLast(lastIdFile, e.getId());
	}
	static void saveClient(string lastIdFile, client c) {
		fstream file;
		file.open("Clients.txt", ios::app);
		file << c.getId() << "," << c.getName() << "," << c.getPassword() << "," << c.getbalance() << endl;
		file.close();
		saveLast(lastIdFile, c.getId());
	}
	static void saveAdmin(string lastIdFile, Admin a) {
		fstream file;
		file.open("admins.txt", ios::app);
		file << a.getId() << "," << a.getName() << "," << a.getPassword() << "," << a.getsalary() << endl;
		file.close();
		saveLast(lastIdFile, a.getId());
	}
	static void getClients() {
		fstream file;
		file.open("Clients.txt", ios::in);
		string line;
		while (getline(file, line))
		{
			client c = parser::parsetoclient(line);
			clientlist.push_back(c);
		}
		file.close();
	}
	static void getEmployees() {
		fstream file;
		file.open("Employees.txt", ios::in);
		string line;
		while (getline(file, line))
		{
			Employee e = parser::parsetoemployee(line);
			employeelist.push_back(e);
		}
		file.close();
	}
	static void getAdmins() {
		fstream file;
		file.open("admins.txt", ios::in);
		string line;
		while (getline(file, line))
		{
			Admin a = parser::parsetoadmin(line);
			adminlist.push_back(a);
		}
		file.close();
	}
	static void clearFile(string fileName, string lastIdFile, char rank) {
		fstream file;
		file.open(fileName, ios::out);
		file.close();
		file.open(lastIdFile, ios::out);
		if (rank == 'c')
			file << 102029;
		else if (rank == 'e')
			file << 1009;
		else if (rank == 'a')
			file << 99;
		file.close();
	}
};