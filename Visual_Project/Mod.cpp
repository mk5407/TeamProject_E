#pragma once

#include "Mod.h"

using namespace std;

Mod::Mod(IDatabase<Employee>* database)
{
    m_pEmployee_database = database;
}

void Mod::modify(Type type, string value, vector<int> modify_list)
{
    for (int index : modify_list)
    {
        Employee* employee = m_pEmployee_database->getData(index);
        employee->setColumnData(type, value);
    }
}