#pragma once
#include "pch.h"
#include "../Visual_Project/add.cpp"

class FixtureAdd : public ::testing::Test
{
protected:
    void SetUp() override
    {
        db = new EmployeeDatabase();
        if (!db)
            return;

        add = new Add(db);

        // 1st Data
        vec.push_back("ADD");
        vec.push_back(" ");
        vec.push_back(" ");
        vec.push_back(" ");
        vec.push_back("17112609");
        vec.push_back("FB NTAWR");
        vec.push_back("CL4");
        vec.push_back("010-5645-6122");
        vec.push_back("19861203");
        vec.push_back("PRO");

        add->add(vec);
    }

    void TearDown() override
    {
        if (db)
            delete db;
        if (add)
            delete add;
    }

public:
    vector<string> vec;
    Add* add;
    EmployeeDatabase* db;
};