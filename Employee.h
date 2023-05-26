#pragma once
#include "client.h"
using namespace std;
 
class Employee :public person {
protected:
	double salary;
public:
	Employee() {}
	Employee(string name, int id, string password, double salary) : person(id, name, password) {
		setsalary(salary);
	}
	void setsalary(double salary) {
		if (validate::validatesalary(salary)) {
			this->salary = salary;
		}
		else
			cout << "Insufficient salary, minimum salary is 5000.\n";
	}
	double getsalary() {
		return salary;
	}
	//searchclients
	client* searchforclient(int searchID) {
		bool found = false;
		for (clientIT = clientlist.begin(); clientIT < clientlist.end(); clientIT++) {
			if (searchID == clientIT[0].getId()) {
				return clientIT._Ptr;
			}
		}
		if (!(found)) {
			return NULL;
		}
	}
	//addclient
	void addclient(client c) {
		clientlist.push_back(c);
	}
	//listclients done
	void listclients() {
		for (clientIT = clientlist.begin(); clientIT < clientlist.end(); clientIT++) {
			clientIT->display();
			cout << "==========\n";
		}
	}
	//edit client
	void editclient(int id, string name,string password,double balance) {
		searchforclient(id)->setName(name);
		searchforclient(id)->setPassword(password);
		searchforclient(id)->setBalance(balance);
	}
	//display
	void display() {
		person::display();
		cout << "Salary:   " << salary << endl;
	}
};
static vector<Employee>employeelist;
static vector<Employee>::iterator empIT;