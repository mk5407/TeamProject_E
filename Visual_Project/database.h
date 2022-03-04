#pragma once
#include "Employee.h"

template <typename T>
class IDatabase
{
public:
    virtual ~IDatabase() {};
    virtual T* getData(int index) = 0;
    virtual int getDbSize() = 0;
    virtual void addData(T* emp) = 0;
    virtual void delData(int index) = 0;
};

class EmployeeDatabase : public IDatabase<Employee>
{
public:
    virtual ~EmployeeDatabase() 
    {
        for (auto p : emp_arr)
        {
            if (p)
                delete p;
        }
    };
    virtual Employee* getData(int index)
    {
        if (emp_arr.size() <= index)
            return nullptr;
        return emp_arr[index];
    }
    virtual int getDbSize()
    {
        return emp_arr.size();
    }
    virtual void addData(Employee* emp)
    {
        if (emp)
            emp_arr.push_back(emp);
    }
    virtual void delData(int index)
    {
        if (emp_arr.size() <= index)
            return;

        delete emp_arr[index];
        emp_arr.erase(emp_arr.begin() + index);
    }

private:
    vector<Employee*> emp_arr;
};