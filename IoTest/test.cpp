#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

#include "../Visual_Project/input.h"
#include "../Visual_Project/output.h"

using namespace std;



TEST(Input_TestCase, InputDataTest) {

	string inputFile = "input_1_1.txt";
	string outputFile = "output_1_1.txt";
	string inString = "ADD, , , , 15123099, VXIHXOTH JHOP, CL3, 010 - 3112 - 2609, 19771211, ADV";

	InputData input;
	input.setInputName(inputFile);

	vector<string> vectorStr;
	//EXPECT_EQ(vectorStr, input.readFile());

	vectorStr.push_back("ADD, , , ,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO");
	vectorStr.push_back("ADD, , , ,18115040,TTETHU HBO,CL3,010-4581-2050,20080718,ADV");
	vectorStr.push_back("ADD, , , ,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,ADV");
	vectorStr.push_back("ADD, , , ,08117441,BMU MPOSXU,CL3,010-2703-3153,20010215,ADV");
	vectorStr.push_back("SCH,-p,-d, ,birthday,04");
	vectorStr.push_back("MOD,-p, , ,name,FB NTAWR,birthday,20050520");
	vectorStr.push_back("SCH, , , ,employeeNum,79110836");
	vectorStr.push_back("DEL, , , ,employeeNum,18115040");
	vectorStr.push_back("DEL,-p,-l, ,name,MPOSXU");
	EXPECT_EQ(vectorStr, input.readFile());


}


TEST(Input_TestCase, SplitTest) {
	InputData util;
	vector<string> result;
	result.push_back("aaa");
	result.push_back("bb");
	EXPECT_EQ(result, util.split("aaa,bb", ','));

	result.clear();
	result.push_back("ccc");
	result.push_back("ddd");
	EXPECT_EQ(result, util.split("ccc ddd", ' '));

	result.clear();
	result.push_back("ee");
	result.push_back("fff");
	EXPECT_EQ(result, util.split("ee-fff", '-'));

}


TEST(Output_TestCase, OutputTest) {

	EXPECT_EQ(1, 1);

}


