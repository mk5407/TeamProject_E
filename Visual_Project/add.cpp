#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "add.h"

using namespace std;

Add::Add(IDatabase<Employee>* db)
{
	this->db = db;
}

void Add::add(vector<string>& strVector)
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