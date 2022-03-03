#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Employee.h"

using namespace std;

enum class Type
{
	EmployeeNum,
	Name,
	CL,
	PhoneNum,
	BirthDay,
	Certi
};

struct FindType {
	Type type_;
	string content_;
};

struct ModifyType {
	Type type_;
	string content_;
};

class Mod
{
public:
	Mod(string cmd);
	void parsingCMD(string cmd);
	vector<Employee*> getModifyList(vector<Employee>& employee_list);
	void modifyEmployeeInfo(vector<Employee*> modify_list);

private:
	int option1_;
	int option2_;
	FindType find_;
	ModifyType modify_;

	//[TO DO] pointer
	vector <Employee*> find_list_; 
};