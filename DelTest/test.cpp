#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include "../Visual_Project/Sch.cpp"
#include "../Visual_Project/Del.cpp"
#include "../Visual_Project/Employee.h"
using namespace std;

TEST(DelTestCaseName, DelTest) {
	vector<Employee> employeeList;
	employeeList.push_back({ "15123099", "VXIHXOTH JHOP", CareerLevel::CL3, "010-3112-2609", "19771211", CertiLevel::ADV });
	employeeList.push_back({ "17112609", "FB NTAWR", CareerLevel::CL4, "010-5645-6122", "19861203", CertiLevel::PRO });
	employeeList.push_back({ "18115040", "TTETHU HBO", CareerLevel::CL3, "010-4581-2050", "20080718", CertiLevel::ADV });
	employeeList.push_back({ "88114052", "NQ LVARW", CareerLevel::CL4, "010-4528-3059", "19911021", CertiLevel::PRO });
	employeeList.push_back({ "19129568", "SRERLALH HMEF", CareerLevel::CL2, "010-3091-9521", "19640910", CertiLevel::PRO });
	employeeList.push_back({ "17111236", "VSID TVO", CareerLevel::CL1, "010-3669-1077", "20120718", CertiLevel::PRO });
	employeeList.push_back({ "18117906", "TWU QSOLT", CareerLevel::CL4, "010-6672-7186", "20030413", CertiLevel::PRO });
	employeeList.push_back({ "08123556", "WN XV", CareerLevel::CL1, "010-7986-5047", "20100614", CertiLevel::PRO });
	employeeList.push_back({ "02117175", "SBILHUT LDEXRI", CareerLevel::CL4, "010-2814-1699", "19950704", CertiLevel::ADV });
	employeeList.push_back({ "03113260", "HH LTUPF", CareerLevel::CL2, "010-5798-5383", "19791018", CertiLevel::PRO });
	employeeList.push_back({ "14130827", "RPO JK", CareerLevel::CL4, "010-3231-1698", "20090201", CertiLevel::ADV });
	employeeList.push_back({ "01122329", "DN WD", CareerLevel::CL4, "010-7174-5680", "20071117", CertiLevel::PRO });
	employeeList.push_back({ "08108827", "RTAH VNUP", CareerLevel::CL4, "010-9031-2726", "19780417", CertiLevel::ADV });
	employeeList.push_back({ "85125741", "FBAH RTIJ", CareerLevel::CL1, "010-8900-1478", "19780228", CertiLevel::ADV });
	employeeList.push_back({ "08117441", "BMU MPOSXU", CareerLevel::CL3, "010-2703-3153", "20010215", CertiLevel::ADV });
	employeeList.push_back({ "10127115", "KBU MHU", CareerLevel::CL3, "010-3284-4054", "19660814", CertiLevel::ADV });
	employeeList.push_back({ "12117017", "LFIS JJIVL", CareerLevel::CL1, "010-7914-4067", "20120812", CertiLevel::PRO });
	employeeList.push_back({ "11125777", "TKOQKIS HC", CareerLevel::CL1, "010-6734-2289", "19991001", CertiLevel::PRO });
	employeeList.push_back({ "11109136", "QKAHCEX LTODDO", CareerLevel::CL4, "010-2627-8566", "19640130", CertiLevel::PRO });
	employeeList.push_back({ "05101762", "VCUHLE HMU", CareerLevel::CL4, "010-3988-9289", "20030819", CertiLevel::PRO });

	vector<string> inputs;
	inputs.push_back("DEL, , , ,employeeNum,18115040");
	inputs.push_back("DEL,-p,-l, ,name,MPOSXU");

	Sch* sch = new Sch();
	vector<Employee> found;
	found = sch->sreach(employeeList, inputs[0]);
	EXPECT_EQ(1, found.size());

	Del* del = new Del();
	del->del(employeeList, found);

	found = sch->sreach(employeeList, inputs[0]);
	EXPECT_EQ(0, found.size());
}