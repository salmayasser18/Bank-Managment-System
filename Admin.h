#pragma once
#include "Employee.h"
using namespace std;

class Admin : public Employee {
public:
	Admin() {}
	Admin(string name, int id, string password, double salary) :Employee(name, id, password, salary) { }
	//searchemployees
	Employee* searchforemployee(int searchID) {
		bool found = true;
		for (empIT = employeelist.begin(); empIT < employeelist.end(); empIT++) {
			if (searchID == empIT[0].getId()) {
				return empIT._Ptr;
			}
		}
		if (found) {
			cout << "Employee does not exist, check if the ID you've entered is correct.\n";
			return NULL;
		}
	}
	//add employee
	void addemployee(Employee e) {
		employeelist.push_back(e);
	}
	//list employees 
	void listemployees() {
		for (empIT = employeelist.begin(); empIT < employeelist.end(); empIT++) {
			empIT[0].display();
			cout << "==========\n";
		}
	}
	//edit employee
	void editemployee(int id, string name, string password, double salary) {
		searchforemployee(id)->setName(name);
		searchforemployee(id)->setPassword(password);
		searchforemployee(id)->setsalary(salary);
	}
};
static vector<Admin>adminlist;
static vector<Admin>::iterator admnIT;
