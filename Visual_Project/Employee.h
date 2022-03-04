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

	string getEmployeeNum() const
	{
		return employeeNum;
	}
	string getName() const
	{
		return name;
	}
	string getFirstName() const
	{
		return name.substr(0, name.rfind(' '));
	}
	string getLastName() const
	{
		return name.substr(name.rfind(' ') + 1);
	}
	string getCL() const
	{
		return cl;
	}
	string getPhoneNum() const
	{
		return phoneNum;
	}
	string getMiddlePhoneNum() const
	{
		return phoneNum.substr(4, 4);
	}
	string getLastPhoneNum() const
	{
		return phoneNum.substr(9, 4);
	}
	string getBirthday() const
	{
		return birthday;
	}
	string getCerti() const
	{
		return certi;
	}

	bool operator== (const Employee& emp)
	{
		bool isEqual = true;

		isEqual &= (emp.getEmployeeNum() == employeeNum);
		isEqual &= (emp.getName() == name);
		isEqual &= (emp.getCL() == cl);
		isEqual &= (emp.getPhoneNum() == phoneNum);
		isEqual &= (emp.getBirthday() == birthday);
		isEqual &= (emp.getCerti() == certi);

		return isEqual;
	}

	void setColumnData(Type colType, string data)
	{
		if (colType == Type::EmployeeNum)
			employeeNum = data;

		if (colType == Type::Name)
			name = data;

		if (colType == Type::CL)
			cl = data;

		if (colType == Type::PhoneNum)
			phoneNum = data;

		if (colType == Type::BirthDay)
			birthday = data;

		if (colType == Type::Certi)
			certi = data;
	}

private:
	string employeeNum;
	string name;
	string cl;
	string phoneNum;
	string birthday;
	string certi;
};
