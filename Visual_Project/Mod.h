#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Employee.h"

using namespace std;

const int EMPLOYEE_INFO_START = 4;
const int EMPLOYEE_INFO_END = 9;

const int MAX_OPTION2_SIZE = 4;

enum class InputType
{
	Option1 = 1,
	Option2 = 2,
	Search_type = 4,
	Search_content,
	Modify_type,
	Modify_content
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
	string getEmployeeInfo(Employee* e, Type type);

	string option1_;
	string option2_;
	FindType find_;
	ModifyType modify_;

	vector <string> result_string_;
	vector <Employee*> find_list_; 
};