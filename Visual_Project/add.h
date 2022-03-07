#pragma once
#include "Employee.h"
#include "Database.h"

class IAdd
{
public:
	virtual ~IAdd() {};
	virtual void add(vector<string>& strVector) = 0;
};

class Add : public IAdd
{
public:
	Add(IDatabase<Employee>* db);
	void add(vector<string>& strVector);

private:
	IDatabase<Employee>* db;
};