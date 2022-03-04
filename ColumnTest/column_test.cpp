#include "pch.h"
#include "../Visual_Project/Column.cpp"

TEST(ColumnValidTest, NameTest)
{
    Employee emp0("", "BRIAN JUNG", "", "", "", "");
    Employee emp1("", "Steve Jobs", "", "", "", "");

    Column* name = new ColumnName();
    EXPECT_EQ(true, name->IsValidColumn(emp0));
    EXPECT_EQ(false, name->IsValidColumn(emp1));
}

TEST(ColumnValidTest, EmployeeNumTest)
{
    Employee emp0("12345678", "", "", "", "", "");
    Employee emp1("00000000", "", "", "", "", "");
    Employee emp2("08271948", "", "", "", "", "");
    Employee emp3("172839", "", "", "", "", "");
    Employee emp4("1234123172", "", "", "", "", "");

    Column* employeeNum = new ColumnEmployeeNum();
    EXPECT_EQ(true, employeeNum->IsValidColumn(emp0));
    EXPECT_EQ(true, employeeNum->IsValidColumn(emp1));
    EXPECT_EQ(true, employeeNum->IsValidColumn(emp2));
    EXPECT_EQ(false, employeeNum->IsValidColumn(emp3));
    EXPECT_EQ(false, employeeNum->IsValidColumn(emp4));
}

TEST(ColumnValidTest, PhoneNumTest)
{
    Employee emp0("", "", "", "010-1234-5678", "", "");
    Employee emp1("", "", "", "010-0000-0000", "", "");
    Employee emp2("", "", "", "010-000-0000", "", "");
    Employee emp3("", "", "", "011-1234-4212", "", "");
    Employee emp4("", "", "", "0111-234-4212", "", "");
    Employee emp5("", "", "", "010-a134-4212", "", "");

    Column* name = new ColumnPhoneNum();
    EXPECT_EQ(true, name->IsValidColumn(emp0));
    EXPECT_EQ(true, name->IsValidColumn(emp1));
    EXPECT_EQ(false, name->IsValidColumn(emp2));
    EXPECT_EQ(false, name->IsValidColumn(emp3));
    EXPECT_EQ(false, name->IsValidColumn(emp4));
    EXPECT_EQ(false, name->IsValidColumn(emp5));
}

TEST(ColumnValidTest, BirthdayTest)
{
    Employee emp0("", "", "", "", "19991201", "");
    Employee emp1("", "", "", "", "1923014", "");
    Employee emp2("", "", "", "", "20001301", "");
    Employee emp3("", "", "", "", "20001200", "");
    Employee emp4("", "", "", "", "20191067", "");
    Employee emp5("", "", "", "", "20170019", "");
    Employee emp6("", "", "", "", "2017-a19", "");

    Column* name = new ColumnBirthday();
    EXPECT_EQ(true, name->IsValidColumn(emp0));
    EXPECT_EQ(false, name->IsValidColumn(emp1));
    EXPECT_EQ(false, name->IsValidColumn(emp2));
    EXPECT_EQ(false, name->IsValidColumn(emp3));
    EXPECT_EQ(false, name->IsValidColumn(emp4));
    EXPECT_EQ(false, name->IsValidColumn(emp5));
    EXPECT_EQ(false, name->IsValidColumn(emp6));
}

TEST(ColumnValidTest, CLTest)
{
    Employee emp0("", "", "CL1", "", "", "");
    Employee emp1("", "", "CL2", "", "", "");
    Employee emp2("", "", "CL3", "", "", "");
    Employee emp3("", "", "CL4", "", "", "");
    Employee emp4("", "", "DL5", "", "", "");
    Employee emp5("", "", "CL0", "", "", "");
    Employee emp6("", "", "1", "", "", "");

    Column* name = new ColumnCL();
    EXPECT_EQ(true, name->IsValidColumn(emp0));
    EXPECT_EQ(true, name->IsValidColumn(emp1));
    EXPECT_EQ(true, name->IsValidColumn(emp2));
    EXPECT_EQ(true, name->IsValidColumn(emp3));
    EXPECT_EQ(false, name->IsValidColumn(emp4));
    EXPECT_EQ(false, name->IsValidColumn(emp5));
    EXPECT_EQ(false, name->IsValidColumn(emp6));
}

TEST(ColumnValidTest, CertiTest)
{
    Employee emp0("", "", "", "", "", "ADV");
    Employee emp1("", "", "", "", "", "PRO");
    Employee emp2("", "", "", "", "", "EX");
    Employee emp3("", "", "", "", "", "IM");
    Employee emp4("", "", "", "", "", "pro");
    Employee emp5("", "", "", "", "", "EXP");
    Employee emp6("", "", "", "", "", "123");

    Column* name = new ColumnCerti();
    EXPECT_EQ(true, name->IsValidColumn(emp0));
    EXPECT_EQ(true, name->IsValidColumn(emp1));
    EXPECT_EQ(true, name->IsValidColumn(emp2));
    EXPECT_EQ(false, name->IsValidColumn(emp3));
    EXPECT_EQ(false, name->IsValidColumn(emp4));
    EXPECT_EQ(false, name->IsValidColumn(emp5));
    EXPECT_EQ(false, name->IsValidColumn(emp6));
}
