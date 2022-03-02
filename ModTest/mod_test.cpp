#include "pch.h"
#include <iostream>
#include <vector>

#include "../Visual_Project/mod.cpp"
#include "../Visual_Project/Employee.h"

using namespace std;

TEST(ModInitTest, ModTest) {
  
	Employee humon1 = { 15123099, "VXIHXOTH JHOP", CareerLevel::CL3, "010 - 3112 - 2609", 19771211, CertiLevel::ADV };
	Employee humon2 = { 17112609, "FB NTAWR",      CareerLevel::CL4, "010 - 5645 - 6122", 19861203, CertiLevel::PRO};
	Employee humon3 = { 14130827, "TTETHU HBO",    CareerLevel::CL3, "010 - 4581 - 2050", 20080718, CertiLevel::ADV};

	vector<Employee> employee_list;
	employee_list.push_back(humon1);
	employee_list.push_back(humon2);
	employee_list.push_back(humon3);

	//EXPECT_EQ(15123099, humon1.employeeNum);
	//EXPECT_EQ("VXIHXOTH JHOP", humon1.name);


	//Mod modObj("MOD,-p, , ,name,FB NTAWR,cl,CL3");

//	EXPECT_EQ( 1, modObj.getSearchType("MOD, -p, , , name, FB NTAWR, cl, CL3"));
	
	//EXPECT_EQ(1, modObj.getModifyList(employee_list).size());

	//vector<Employee> find_list = modObj.getModifyList(employee_list);

	//EXPECT_EQ("FB NTAWR", find_list.front().name);


	Mod modObj2("MOD,-p, , ,employeeNum,14130827,birthday,20110706");

	vector<Employee> find_list2 = modObj2.getModifyList(employee_list);

	EXPECT_EQ("FB NTAWR", find_list2.front().name);

	

}