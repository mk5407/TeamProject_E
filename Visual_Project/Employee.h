#pragma once
#include <string>
#include <vector>
using namespace std;

enum class Type
{
	EmployeeNum = 4,
	Name,
	CL,
	PhoneNum,
	BirthDay,
	Certi
};

class Employee
{
public:
	Employee(string empNum, string empName, string empCl, string empPhoneNum, string empBirthday, string empCerti) :
		employeeNum(empNum), name(empName), cl(empCl), phoneNum(empPhoneNum), birthday(empBirthday), certi(empCerti)
	{}
	Employee(vector<string> vec) : employeeNum(vec[(int)Type::EmployeeNum]), name(vec[(int)Type::Name]), cl(vec[(int)Type::CL]),
		                           phoneNum(vec[(int)Type::PhoneNum]), birthday(vec[(int)Type::BirthDay]), certi(vec[(int)Type::Certi])
	{}

	string getEmployeeNum()
	{
		return employeeNum;
	}
	string getName()
	{
		return name;
	}
	string getFirstName()
	{
		return name.substr(0, name.rfind(' '));
	}
	string getLastName()
	{
		return name.substr(name.rfind(' ') + 1);
	}
	string getCL()
	{
		return cl;
	}
	string getPhoneNum()
	{
		return phoneNum;
	}
	string getMiddlePhoneNum()
	{
		return phoneNum.substr(4, 4);
	}
	string getLastPhoneNum()
	{
		return phoneNum.substr(9, 4);
	}
	string getBirthday()
	{
		return birthday;
	}
	string getCerti()
	{
		return certi;
	}

private:
	string employeeNum;
	string name;
	string cl;
	string phoneNum;
	string birthday;
	string certi;
};
