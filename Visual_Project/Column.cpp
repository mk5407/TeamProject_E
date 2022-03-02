#include <string>
#include <iostream>
#include "Employee.h"

using namespace std;

#define OLDEST_EMP_NUM   (69000000)
#define YOUNGEST_EMP_NUM (21999999) 

bool IsUpperCase(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
			continue;

		if ((str[i] < 'A') || (str[i] > 'Z'))
		{
			return false;
		}
	}
	return true;
}

class Column
{
public:
	virtual bool IsValidColumn(Employee emp) = 0;
};

class ColumnName : public Column
{
	virtual bool IsValidColumn(Employee emp)
	{
		if (emp.name.length() > 15)
			return false;

		if (!IsUpperCase(emp.name))
			return false;
		
		return true;
	}
};

class ColumnEmployeeNum : public Column
{
	virtual bool IsValidColumn(Employee emp)
	{
		if (emp.employeeNum.length() != 8)
			return false;

		try 
		{
			if ((stoi(emp.employeeNum) < YOUNGEST_EMP_NUM) || (stoi(emp.employeeNum) > OLDEST_EMP_NUM))
				return true;
		}
		catch (invalid_argument)
		{
			return false;
		}

		return false;
	}
};

// TODO: Refactoring 진행 예정입니다. (Eunkak 220302)
class ColumnPhoneNum : public Column
{
	virtual bool IsValidColumn(Employee emp)
	{
		unsigned int phoneNum = 0;
		if (!(emp.phoneNum[0] == '0') || !(emp.phoneNum[1] == '1') || !(emp.phoneNum[2] == '0'))
		{
			return false;
		}

		for (int i = 3; i < 11; i++)
		{
			if ((i == 3) || (i == 8))
			{
				if (emp.phoneNum[i] != '-')
					return false;
				continue;
			}
			phoneNum = emp.phoneNum[i] - '0';
			if (phoneNum > 9)
			{
				return false;
			}
		}
		return true;
	}
};

// TODO: Refactoring 진행 예정입니다. (Eunkak 220302)
class ColumnBirthday : public Column
{
	virtual bool IsValidColumn(Employee emp)
	{
		unsigned int birthday = 0;
		unsigned int month = 0;
		unsigned int day = 0;
		if (emp.birthday.length() != 8)
			return false;

		try
		{
			birthday = stoi(emp.birthday);
			month = stoi(emp.birthday.substr(4,2));
			day = stoi(emp.birthday.substr(6, 2));

			if ((month > 12) || (day > 31) || (month * day == 0))
			{
				return false;
			}
		}
		catch (invalid_argument)
		{
			return false;
		}
		return true;
	}
};