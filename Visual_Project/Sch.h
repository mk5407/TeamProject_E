#pragma once
#include <vector>
#include <string>
#include "employee.h"
#include "database.h"

using namespace std;

class ISch {
public:
	virtual vector<int> search(string op2, Type type, string value) = 0;
};

class Sch : public ISch
{
public:
	Sch(IDatabase<Employee>* database);
	vector<int> search(string op2, Type type, string value) override;

private:
	IDatabase<Employee>* m_pEmployee_database;
};
