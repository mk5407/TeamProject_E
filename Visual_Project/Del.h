#pragma once
#include <vector>

#include "employee.h"
#include "database.h"

using namespace std;

class IDel {
public:
	virtual void del(vector<int> delete_list) = 0;
};

class Del : public IDel
{
public:
	Del(IDatabase<Employee>* database);
	void del(vector<int> delete_list) override;

private:
	IDatabase<Employee>* m_pEmployee_database;
};
