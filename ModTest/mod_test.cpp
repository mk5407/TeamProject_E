#include "pch.h"
#include <iostream>
#include <vector>

#include "../Visual_Project/mod.cpp"
#include "../Visual_Project/Employee.h"

using namespace std;

TEST(ModInitTest, ModTest) {
  
	Employee humon1 = { "15123099", "VXIHXOTH JHOP", CareerLevel::CL3, "010 - 3112 - 2609", "19771211", CertiLevel::ADV };
	Employee humon2 = { "17112609", "FB NTAWR",      CareerLevel::CL4, "010 - 5645 - 6122", "19861203", CertiLevel::PRO};
	Employee humon3 = { "14130827", "TTETHU HBO",    CareerLevel::CL3, "010 - 4581 - 2050", "20080718", CertiLevel::ADV};

	vector<Employee> employee_list;
	employee_list.push_back(humon1);
	employee_list.push_back(humon2);
	employee_list.push_back(humon3);

	//EXPECT_EQ(15123099, humon1.employeeNum);
	//EXPECT_EQ("VXIHXOTH JHOP", humon1.name);

	// employeeNum Test
	Mod modObj2("MOD,-p, , ,employeeNum,14130827,birthday,20110706");
	vector<Employee*> find_list2 = modObj2.getModifyList(employee_list);
	string find_name = find_list2.front()->name;
	EXPECT_EQ("TTETHU HBO", find_name);

	// name Test
	Mod modObj("MOD,-p, , ,name,FB NTAWR,cl,CL3");
	vector<Employee*> find_list = modObj.getModifyList(employee_list);
	EXPECT_EQ("FB NTAWR", find_list.front()->name);

	// cl Test
	Mod modObj3("MOD,-p, , ,cl,CL3,birthday,20110706");
	vector<Employee*> find_list3 = modObj3.getModifyList(employee_list);
	EXPECT_EQ(2, find_list3.size());
	
	// phoneNum Test
	Mod modObj4("MOD,-p, , ,phoneNum,010 - 4581 - 2050,birthday,20110706");
	vector<Employee*> find_list4 = modObj4.getModifyList(employee_list);
	EXPECT_EQ("TTETHU HBO", find_list4.front()->name);

	// birthday Test
	Mod modObj5("MOD,-p, , ,birthday,19771211,birthday,20110706");
	vector<Employee*> find_list5 = modObj5.getModifyList(employee_list);
	EXPECT_EQ("VXIHXOTH JHOP", find_list5.front()->name);

	// certi Test
	Mod modObj6("MOD,-p, , ,certi,PRO,birthday,20110706");
	vector<Employee*> find_list6 = modObj6.getModifyList(employee_list);
	EXPECT_EQ("FB NTAWR", find_list6.front()->name);
}