#pragma once
#include "DataSourceInterface.h"
#include "FileHelper.h"
using namespace std;

class filemanager : public datasourceinterface {
public:
	static void addClient(client c) {
		fileshelper::saveClient("clientid.txt", c);
	}
	static void addEmployee(Employee e) {
		fileshelper::saveEmployee("employeeid.txt", e);
	}
	static void addAdmin(Admin a) {
		fileshelper::saveAdmin("adminid.txt", a);
	}
	static void getAllClients() {
		fileshelper::getClients();
	}
	static void getAllEmployees() {
		fileshelper::getEmployees();
	}
	static void getAllAdmins() {
		fileshelper::getAdmins();
	}
	static void removeAllClients() {
		fileshelper::clearFile("Clients.txt", "clientid.txt", 'c');
	}
	static void removeAllEmployees() {
		fileshelper::clearFile("Employees.txt", "employeeid.txt", 'e');
	}
	static void removeAllAdmins() {
		fileshelper::clearFile("admins.txt", "adminid.txt", 'a');
	}
	static void getdata() {
		getAllAdmins();
		getAllEmployees();
		getAllClients();
	}
	//tested and working
	static void refilladmins(){
		removeAllAdmins();
		for (admnIT = adminlist.begin(); admnIT < adminlist.end(); admnIT++)
			addAdmin(admnIT[0]);
	}
	static void refillclients(){
		removeAllClients();
		for (clientIT = clientlist.begin(); clientIT < clientlist.end(); clientIT++)
			addClient(*clientIT);
	}
	static void refillemployees(){
		removeAllEmployees();
		for (empIT = employeelist.begin(); empIT < employeelist.end(); empIT++)
			addEmployee(empIT[0]);
	}
	static void refill_all() {
		refilladmins();
		refillclients();
		refillemployees();
	}
};