#pragma once
#include <vector>
#include <iterator>
#include "person.h"
using namespace std;

class client :public person {
protected:
	double balance;
public:
	client() {}
	client(int id, string name, string password, double balance) :person(id, name, password) {
		setBalance(balance);
	}
	void setBalance(double balance) {
		if (validate::balanceValid(balance)) {
			this->balance = balance;
		}
		else
		{
			cout << "Insufficient balance, the allowed minimum is 1500 EGP.\n";
		}
	}
	double getbalance() {
		return balance;
	}
	void checkBalance() {
		cout << "Current balance: " << balance << endl;
	}
	void deposit() {
		double amount;
		cout << "How much do you want to deposit: "; cin >> amount;
		this->balance += amount;
		cout << "Successful Deposit.\n";
		checkBalance();
	}
	void withdraw() {
		double amount;
		cout << "How much do you want to withdraw: "; cin >> amount;
		if (validate::validateamount(amount, balance)) {
			this->balance -= amount;
			cout << "Successful withdraw.\n";
			checkBalance();
		}
		else
			cout << "Insufficient balance, try again with smaller amount\n";
	}
	void transferTo(client& recipient) {
		double amount;
		cout << "How much do you want to transfer: "; cin >> amount;
		if (validate::validateamount(amount, balance)) {
			this->balance -= amount;
			recipient.balance += amount;
			cout << "Successful transfer.\n";
			checkBalance();
		}
		else
			cout << "Insufficient balance, try again with smaller amount\n";
	}
	void display() {
		person::display();
		cout << "Balance:  " << balance << endl;
	}
};
static vector<client>clientlist;
static vector<client>::iterator clientIT;
