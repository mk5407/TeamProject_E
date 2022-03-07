#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "column.h"
#include "database.h"

using namespace std;

class IMod
{
public:
    virtual void modify(Type type, string value, vector<int> modify_list) = 0;
};

class Mod : public IMod
{
public:
    Mod(IDatabase<Employee>* database);
    virtual void modify(Type type, string value, vector<int> modify_list);

private:
    IDatabase<Employee>* m_pEmployee_database;
};