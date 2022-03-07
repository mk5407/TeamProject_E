#include "pch.h"
#include "../Visual_Project/add.cpp"
#include "AddTestFixture.h"

TEST_F(FixtureAdd, AddNormalTest)
{
    EXPECT_EQ(1, db->getDbSize());
}

TEST_F(FixtureAdd, AddOneMoreTest)
{
    vec.clear();
    vec.push_back("ADD");
    vec.push_back(" ");
    vec.push_back(" ");
    vec.push_back(" ");
    vec.push_back("18115040");
    vec.push_back("TTETHU HBO");
    vec.push_back("CL3");
    vec.push_back("010-4581-2050");
    vec.push_back("20080718");
    vec.push_back("ADV");

    add->add(vec);
    EXPECT_EQ(2, db->getDbSize());
}

TEST_F(FixtureAdd, AddSameEmployeeNumTest)
{
    vec.clear();
    vec.push_back("ADD");
    vec.push_back(" ");
    vec.push_back(" ");
    vec.push_back(" ");
    vec.push_back("17112609");
    vec.push_back("TTETHU HBO");
    vec.push_back("CL3");
    vec.push_back("010-4581-2050");
    vec.push_back("20080718");
    vec.push_back("ADV");

    add->add(vec);
    EXPECT_EQ(1, db->getDbSize());
}