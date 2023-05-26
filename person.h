#pragma once
#include <iostream>
#include "validation.h"
using namespace std;

class person {
protected:
	int id;
	string name, password;
public:
	person() {}
	person(int id, string name, string password) {
		this->id = id;
		//name
		if (validate::nameValid(name)) {
			this->name = name;
		}
		else
		{
			cout << "min size 5 char and max size 20" << endl;
			cout << "must enter alphabetic chars" << endl;
		}
		//password
		if (validate::passValid(password) == 1) {
			this->password = password;
		}
		else
		{
			cout << "password must be with in 8 to 20 charcters" << endl;
		}
	}
	void setId(int id) {
		this->id = id;
	}
	void setName(string name) {
		if (validate::nameValid(name) == 1) {
			this->name = name;
		}
		else
		{
			cout << "min size 5 char and max size 20" << endl;
			cout << "must enter alphabetic chars" << endl;
		}
	}
	void setPassword(string password) {
		if (validate::passValid(password) == 1) {
			this->password = password;
		}
		else
		{
			cout << "password must be with in 8 to 20 charcters" << endl;
		}
	}
	string getName() {
		return name;
	}
	string getPassword() {
		return password;
	}
	int getId() {
		return id;
	}
	void display() {
		cout << "Name:     " << name << endl;
		cout << "ID:       " << id << endl;
		cout << "Password: " << password << endl;
	}
};