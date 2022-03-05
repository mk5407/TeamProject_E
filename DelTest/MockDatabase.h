#pragma once
#include "pch.h"
#include "../Visual_Project/database.h"
#include <vector>
using namespace std;

class FakeDatabase : public IDatabase<Employee>
{
public:
    virtual ~FakeDatabase() 
    {
        for (auto emp_ptr : emp_vector)
            if (emp_ptr)
                delete emp_ptr;
    };
    virtual Employee* getData(int index)
    {
        if (emp_vector.size() <= index)
            return nullptr;
        return emp_vector[index];
    }
    virtual int getDbSize()
    {
        return emp_vector.size();
    }
    virtual void addData(Employee* emp)
    {
        if(emp)
            emp_vector.push_back(emp);
    }
    virtual void delData(int index)
    {
        if (emp_vector.size() <= index)
            return;
        
        emp_vector.erase(emp_vector.begin() + index);
    }
private:
    vector<Employee*> emp_vector;
};

class MockDatabase : public IDatabase<Employee>
{
public:
    MOCK_METHOD(Employee*, getData, (int index), (override));
    MOCK_METHOD(int, getDbSize, (), (override));
    MOCK_METHOD(void, addData, (Employee* emp), (override));
    MOCK_METHOD(void, delData, (int index), (override));

    void DelegatetoFake()
    {
        ON_CALL(*this, getData).WillByDefault([this](int index) {return fake_db.getData(index); });
        ON_CALL(*this, getDbSize).WillByDefault([this]() {return fake_db.getDbSize(); });
        ON_CALL(*this, addData).WillByDefault([this](Employee* emp) {return fake_db.addData(emp); });
        ON_CALL(*this, delData).WillByDefault([this](int index) {return fake_db.delData(index); });
    }

private:
    FakeDatabase fake_db;
};