#include "pch.h"
#include <iostream>
#include <string>

#include "MockDatabase.h"
#include "../Visual_Project/Database.h"
#include "../Visual_Project/Del.cpp"

using namespace std;

TEST(DelTestCaseName, DelTest) {
	testing::NiceMock<MockDatabase> database;
	database.DelegatetoFake();

	Employee* emp0 = new Employee("12345678", "BRIAN JUNG", "CL1", "010-1234-5678", "19991201", "PRO");
	Employee* emp1 = new Employee("12345679", "STEVE JOBS", "CL2", "010-8274-2988", "20001230", "ADV");
	Employee* emp2 = new Employee("12345670", "JOHN DOE", "CL3", "010-1244-6432", "19961208", "EX");
	Employee* emp3 = new Employee("12345671", "BILL GATES", "CL4", "010-1234-1225", "19000574", "EX");
	Employee* emp4 = new Employee("12345672", "JAMES CHOI", "CL3", "010-1241-9880", "19201231", "ADV");
	Employee* emp5 = new Employee("12345673", "GILDONG HONG", "CL2", "010-7247-1123", "19550208", "PRO");
	Employee* emp6 = new Employee("12345674", "BAB KIM", "CL1", "010-1554-8964", "19701106", "EX");
	Employee* emp7 = new Employee("12345675", "TIM COOK", "CL3", "010-7659-0757", "19470524", "PRO");

	database.addData(emp0);
	database.addData(emp1);
	database.addData(emp2);
	database.addData(emp3);
	database.addData(emp4);
	database.addData(emp5);
	database.addData(emp6);
	database.addData(emp7);

	EXPECT_EQ(8, database.getDbSize());
	EXPECT_EQ(emp0, database.getData(0));
	EXPECT_EQ(emp1, database.getData(1));
	EXPECT_EQ(emp2, database.getData(2));
	EXPECT_EQ(emp3, database.getData(3));
	EXPECT_EQ(emp4, database.getData(4));
	EXPECT_EQ(emp5, database.getData(5));
	EXPECT_EQ(emp6, database.getData(6));
	EXPECT_EQ(emp7, database.getData(7));

	Del* del = new Del(&database);
	del->del({ 1, 2 });
	EXPECT_EQ(6, database.getDbSize());
	del->del({ 0 });
	EXPECT_EQ(5, database.getDbSize());
}