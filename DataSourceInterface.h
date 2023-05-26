#pragma once
#include "Admin.h"
using namespace std;

class datasourceinterface {
public:
	virtual void addClient(client c) = 0;
	virtual void addEmployee(Employee e) = 0;
	virtual void addAdmin(Admin a) = 0;
	virtual void getAllClients() = 0;
	virtual void getAllEmployees() = 0;
	virtual void getAllAdmins() = 0;
	virtual void removeAllClients() = 0;
	virtual void removeAllEmployees() = 0;
	virtual void removeAllAdmins() = 0;
};