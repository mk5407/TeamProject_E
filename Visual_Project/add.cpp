#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Employee.h"
#include "database.h"
using namespace std;

class IAdd
{
public: 
	virtual ~IAdd() {};
	virtual void add(vector<string>& strVector) = 0;
};

class Add : public IAdd
{
public:
	Add(IDatabase<Employee>* db)
	{
		this->db = db;
	}

	void add(vector<string>& strVector)
	{
		size_t dbSize = db->getDbSize();
		Employee* emp_ptr = new Employee(strVector);
		for (int i = 0; i < dbSize; i++)
		{
			if (db->getData(i)->getEmployeeNum() == strVector[(int)Type::EmployeeNum])
				return;
		}
		if(emp_ptr)
			db->addData(emp_ptr);
	}

private:
	IDatabase<Employee>* db;
};