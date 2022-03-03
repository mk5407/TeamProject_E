#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Employee.h"
#include "Operation.h"
#include <sstream>

using namespace std;

struct cmd_arg {
	OPCode oper;
	OPOption1 op1;
	OPOption2 op2;
	ColummType columm;
	string value;
};

inline string& ltrim(string& s, const char* t)
{
	s.erase(0, s.find_first_not_of(t));
	return s;
}

inline string& rtrim(string& s, const char* t)
{
	s.erase(s.find_last_not_of(t) + 1);
	return s;
}

inline string& trim(string& s, const char* t)
{
	return ltrim(rtrim(s, t), t);
}

struct cmd_arg* parseInputString(string input) {
	struct cmd_arg* arg = new cmd_arg();

	stringstream ss(input);
	string substr;
	getline(ss, substr, ',');
	trim(substr, " ");
	if (substr == "ADD") arg->oper = OPCode::OP_ADD;
	if (substr == "DEL") arg->oper = OPCode::OP_DEL;
	if (substr == "MOD") arg->oper = OPCode::OP_MOD;
	if (substr == "SCH") arg->oper = OPCode::OP_SCH;

	getline(ss, substr, ',');
	trim(substr, " ");
	if (substr == "-p") arg->op1 = OPOption1::OP1_PRINT;
	else arg->op1 = OPOption1::OP1_NONE;

	string op2str;
	getline(ss, op2str, ',');
	trim(op2str, " ");
	getline(ss, substr, ',');
	getline(ss, substr, ',');
	trim(substr, " ");
	if (substr == "employeeNum") {
		arg->columm = ColummType::CLM_EMPLOYEE_NUM;
		arg->op2 = OPOption2::OP2_NONE;
	}
	else if (substr == "name") {
		arg->columm = ColummType::CLM_NAME;
		arg->op2 = OPOption2::OP2_NONE;
		if (op2str == "-f") arg->op2 = OPOption2::OP2_NAME_FIRSTNAME;
		if (op2str == "-l") arg->op2 = OPOption2::OP2_NAME_LASTNAME;
	}
	else if (substr == "cl") {
		arg->columm = ColummType::CLM_CL;
		arg->op2 = OPOption2::OP2_NONE;
	}
	else if (substr == "phoneNum") {
		arg->columm = ColummType::CLM_PHONE_NUM;
		arg->op2 = OPOption2::OP2_NONE;
		if (op2str == "-m") arg->op2 = OPOption2::OP2_PHONE_MIDDLE;
		if (op2str == "-l") arg->op2 = OPOption2::OP2_PHONE_LAST;
	}
	else if (substr == "birthday") {
		arg->columm = ColummType::CLM_BIRTYDAY;
		arg->op2 = OPOption2::OP2_NONE;
		if (op2str == "-y") arg->op2 = OPOption2::OP2_BIRTH_YEAR;
		if (op2str == "-m") arg->op2 = OPOption2::OP2_BIRTH_MONTH;
		if (op2str == "-d") arg->op2 = OPOption2::OP2_BIRTH_DAY;
	}
	else if (substr == "certi") {
		arg->columm = ColummType::CLM_CERTI;
		arg->op2 = OPOption2::OP2_NONE;
	}

	getline(ss, substr, ',');
	trim(substr, " ");
	arg->value = substr;

	return arg;
}

void printEmployee(Employee employee) {
	cout << "[Debug] ";
	cout << "employeeNum: " << employee.getEmployeeNum() << " ";
	cout << "name: " << employee.getName() << " \t";
	cout << "cl: " << employee.getCL() << " ";
	cout << "phoneNum: " << employee.getPhoneNum() << " ";
	cout << "birthday: " << employee.getBirthday() << " ";
	cout << "certi: " << employee.getCerti() << endl;
}

class Sch
{
public:

	vector<Employee> sreach(std::vector<Employee> list, std::string cmd) {
		struct cmd_arg *op = parseInputString(cmd);
		vector<Employee> result;

		switch (op->columm) {
		case (ColummType::CLM_EMPLOYEE_NUM):
			for (auto item : list) {
				if (item.getEmployeeNum() == op->value) result.push_back(item);
			}
			break;
		case (ColummType::CLM_NAME):
			for (auto item : list) {
				stringstream ss(item.getName());
				string firstName, lastName;
				getline(ss, firstName, ' ');
				getline(ss, lastName, ' ');

				string tmp;
				if (op->op2 == OPOption2::OP2_NONE) tmp = item.getName();
				if (op->op2 == OPOption2::OP2_NAME_FIRSTNAME) tmp = firstName;
				if (op->op2 == OPOption2::OP2_NAME_LASTNAME) tmp = lastName;

				if (tmp == op->value) result.push_back(item);
			}
			break;
		case (ColummType::CLM_CL):
			for (auto item : list) {
				if (item.getCL() == op->value) result.push_back(item);
			}
			break;
		case (ColummType::CLM_PHONE_NUM):
			for (auto item : list) {
				stringstream ss(item.getPhoneNum());
				string middleNum, lastNum;
				getline(ss, middleNum, '-');
				getline(ss, middleNum, '-');
				getline(ss, lastNum, '-');

				string tmp;
				if (op->op2 == OPOption2::OP2_NONE) tmp = item.getPhoneNum();
				if (op->op2 == OPOption2::OP2_PHONE_MIDDLE) tmp = middleNum;
				if (op->op2 == OPOption2::OP2_PHONE_LAST) tmp = lastNum;

				if (tmp == op->value) result.push_back(item);
			}
			break;
		case (ColummType::CLM_BIRTYDAY):
			for (auto item : list) {
				string year = item.getBirthday().substr(0, 4);
				string month = item.getBirthday().substr(4, 2);
				string day = item.getBirthday().substr(6, 2);

				string tmp;
				if (op->op2 == OPOption2::OP2_NONE) tmp = item.getBirthday();
				if (op->op2 == OPOption2::OP2_BIRTH_YEAR) tmp = year;
				if (op->op2 == OPOption2::OP2_BIRTH_MONTH) tmp = month;
				if (op->op2 == OPOption2::OP2_BIRTH_DAY) tmp = day;

				if (tmp == op->value) result.push_back(item);
			}
			break;
		case (ColummType::CLM_CERTI):
			for (auto item : list) {
				if (item.getCerti() == op->value) result.push_back(item);
			}
			break;
		default:
			break;
		}

		cout << result.size() << " °³ Ã£À½" << endl;
		for (auto item : result) printEmployee(item);

		return result;
	}
};

