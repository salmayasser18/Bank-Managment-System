#pragma once
#include <sstream>
#include "Admin.h"
using namespace std;

//id,name,password,balance

class parser {
public:
	static vector<string> split(string fulline) {
		vector<string>info;
		stringstream line(fulline);
		string part;
		while (getline(line, part, ',')) {
			info.push_back(part);
		}
		return info;
	}
	static client parsetoclient(string line) {
		vector <string> clientline = split(line);
		client c;
		c.setId(stoi(clientline[0]));
		c.setName(clientline[1]);
		c.setPassword(clientline[2]);
		c.setBalance(stod(clientline[3]));
		return c;
	}
	static Employee parsetoemployee(string fulline) {
		//func that gets line
		vector <string> empline = split(fulline);
		Employee e;
		e.setId(stoi(empline[0]));
		e.setName(empline[1]);
		e.setPassword(empline[2]);
		e.setsalary(stod(empline[3]));
		return e;
	}
	static Admin parsetoadmin(string line) {
		//func that gets line
		vector <string> adminline = split(line);
		Admin a;
		a.setId(stoi(adminline[0]));
		a.setName(adminline[1]);
		a.setPassword(adminline[2]);
		a.setsalary(stod(adminline[3]));
		return a;
	}
};