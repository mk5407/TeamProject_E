#include "pch.h"
#include "../Visual_Project/Column.cpp"

TEST(ColumnValidTest, NameTest)
{
	Employee emp0;
	emp0.name = "BRIAN JUNG";
	Employee emp1;
	emp1.name = "Steve Jobs";
	Employee emp2;
	emp2.name = "IT IS NOT NAME HAHA";

	Column *name = new ColumnName();
	EXPECT_EQ(true, name->IsValidColumn(emp0));
	EXPECT_EQ(false, name->IsValidColumn(emp1));
	EXPECT_EQ(false, name->IsValidColumn(emp2));
}

TEST(ColumnValidTest, EmployeeNumTest)
{
	Employee emp0;
	emp0.employeeNum = "12345678";
	Employee emp1;
	emp1.employeeNum = "00000000";
	Employee emp2;
	emp2.employeeNum = "08271948";
	Employee emp3;
	emp3.employeeNum = "172839";
	Employee emp4;
	emp4.employeeNum = "1234123172";

	Column* employeeNum = new ColumnEmployeeNum();
	EXPECT_EQ(true, employeeNum->IsValidColumn(emp0));
	EXPECT_EQ(true, employeeNum->IsValidColumn(emp1));
	EXPECT_EQ(true, employeeNum->IsValidColumn(emp2));
	EXPECT_EQ(false, employeeNum->IsValidColumn(emp3));
	EXPECT_EQ(false, employeeNum->IsValidColumn(emp4));
}

TEST(ColumnValidTest, PhoneNumTest)
{
	Employee emp0;
	emp0.phoneNum = "010-1234-5678";
	Employee emp1;
	emp1.phoneNum = "010-0000-0000";
	Employee emp2;
	emp2.phoneNum = "010-000-0000";
	Employee emp3;
	emp3.phoneNum = "011-1234-4212";
	Employee emp4;
	emp4.phoneNum = "0111-234-4212";
	Employee emp5;
	emp5.phoneNum = "010-a134-4212";

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
	Employee emp0;
	emp0.birthday = "19991201";
	Employee emp1;
	emp1.birthday = "1923014";
	Employee emp2;
	emp2.birthday = "20001301";
	Employee emp3;
	emp3.birthday = "20001200";
	Employee emp4;
	emp4.birthday = "20191067";
	Employee emp5;
	emp5.birthday = "20170019";
	Employee emp6;
	emp6.birthday = "2017-a19";

	Column* name = new ColumnBirthday();
	EXPECT_EQ(true, name->IsValidColumn(emp0));
	EXPECT_EQ(false, name->IsValidColumn(emp1));
	EXPECT_EQ(false, name->IsValidColumn(emp2));
	EXPECT_EQ(false, name->IsValidColumn(emp3));
	EXPECT_EQ(false, name->IsValidColumn(emp4));
	EXPECT_EQ(false, name->IsValidColumn(emp5));
	EXPECT_EQ(false, name->IsValidColumn(emp6));
}