#include <string>
#include <iostream>
#include "Employee.h"

using namespace std;

#define OLDEST_EMP_NUM   (69000000)
#define YOUNGEST_EMP_NUM (21999999) 

#define MAX_LEN_NAME (15)
#define EMPLOYEE_NUM_LENGTH (8)

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
		if (emp.getName().length() > MAX_LEN_NAME)
			return false;

		if (!IsUpperCase(emp.getName()))
			return false;
		
		return true;
	}
};

class ColumnEmployeeNum : public Column
{
	virtual bool IsValidColumn(Employee emp)
	{
		string employeeNum = emp.getEmployeeNum();
		if (employeeNum.length() != EMPLOYEE_NUM_LENGTH)
			return false;

		try 
		{
			if ((stoi(employeeNum) < YOUNGEST_EMP_NUM) || (stoi(employeeNum) > OLDEST_EMP_NUM))
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
		unsigned int number = 0;
		string fullPhoneNumber = emp.getPhoneNum();
		if (!(fullPhoneNumber[0] == '0') || !(fullPhoneNumber[1] == '1') || !(fullPhoneNumber[2] == '0'))
		{
			return false;
		}

		for (int i = 3; i < 11; i++)
		{
			if ((i == 3) || (i == 8))
			{
				if (fullPhoneNumber[i] != '-')
					return false;
				continue;
			}
			number = fullPhoneNumber[i] - '0';
			if (number > 9)
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
		if (emp.getBirthday().length() != 8)
			return false;

		try
		{
			birthday = stoi(emp.getBirthday());
			month = stoi(emp.getBirthday().substr(4,2));
			day = stoi(emp.getBirthday().substr(6, 2));

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