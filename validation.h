#pragma once
#include <string>
using namespace std;

class validate {
public:
	static bool nameValid(string name) {
		bool flag = 1;
		if (name.length() < 5 || name.length() > 20) {
			return flag = 0;
		}
		else {
			for (char i : name) {
				if ((i < 65 && i>90) || (i >= 97 && i < 122)) {
					return flag = 0;
				}
				else {
					return flag = 1;
				}
			}
		}
	}
	static bool passValid(string password) {
		bool flag = 0;
		//el condition hena kan && bs I think it should be ||
		if (password.size() < 8 || password.size() > 20) {
			return flag = false;
		}
		else
		{
			return flag = true;
		}
	}
	static bool balanceValid(double balance) {
		bool flag = 0;
		if (balance < 1500) {
			return flag;
		}
		else
		{
			return true;
		}
	}
	static bool validateamount(double amount, double balance) {
		if (amount > balance) {
			return false;
		}
		else
			return true;
	}
	static bool validatesalary(double salary) {
		if (salary >= 5000) {
			return true;
		}
		else
			return false;
	}
};