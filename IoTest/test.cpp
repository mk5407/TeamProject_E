#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

#include "../Visual_Project/InputManager.h"
#include "../Visual_Project/InputParcer.h"
#include "../Visual_Project/OutputManager.h"

using namespace std;


TEST(InputParcerTest, SplitTest) {
    InputParcer parcer;
    vector<string> result;

    result.push_back("aaa");
    result.push_back("bb");
    EXPECT_EQ(result, parcer.split("aaa,bb"));

    result.clear();
    result.push_back("ccc");
    result.push_back("ddd");
    EXPECT_EQ(result, parcer.split("ccc,ddd"));

    result.clear();
    result.push_back("ee");
    result.push_back("fff");
    EXPECT_EQ(result, parcer.split("ee,fff"));
}

TEST(InputParcerTest, ValidFilenameTest) {
    InputParcer parcer;
    string ext;

    ext = "aaa.txt";
    EXPECT_EQ(true, parcer.isValidFileName(ext));

    ext = "txt";
    EXPECT_EQ(false, parcer.isValidFileName(ext));

    ext = ".aaa";
    EXPECT_EQ(false, parcer.isValidFileName(ext));

    ext = "abc..txt";
    EXPECT_EQ(false, parcer.isValidFileName(ext));

    ext = "/.txt";
    EXPECT_EQ(false, parcer.isValidFileName(ext));

    ext = "aa/b.txt";
    EXPECT_EQ(false, parcer.isValidFileName(ext));

    ext = "aa\\b.txt";
    EXPECT_EQ(false, parcer.isValidFileName(ext));

    ext = "filename,txt";
    EXPECT_EQ(false, parcer.isValidFileName(ext));
}

TEST(InputParcerTest, ValidArgTest) {
    InputParcer parcer;
    int argc;
    char* argv[100];

    argc = 3;
    argv[1] = "in.txt";
    argv[2] = "out.txt";
    EXPECT_EQ(true, parcer.isValidArg(argc, argv));

    argc = 2;
    EXPECT_EQ(false, parcer.isValidArg(argc, argv));

    argc = 3;
    argv[1] = "intxt";
    argv[2] = "out.txt";
    EXPECT_EQ(false, parcer.isValidArg(argc, argv));

    argc = 3;
    argv[1] = "in.txt";
    argv[2] = "outtxt";
    EXPECT_EQ(false, parcer.isValidArg(argc, argv));
}


TEST(InputManagerTest, ReadFileTest) {
    InputManager input;
    string inputFile;
    vector<string> vectorStr;

    inputFile = "input_20_20_no_file.txt";
    input.setInputName(inputFile);
    EXPECT_EQ(vectorStr, input.readFile());

    inputFile = "input_20_20.txt";
    input.setInputName(inputFile);
    vectorStr.push_back("ADD, , , ,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV");
    vectorStr.push_back("ADD, , , ,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO");
    vectorStr.push_back("ADD, , , ,18115040,TTETHU HBO,CL3,010-4581-2050,20080718,ADV");
    vectorStr.push_back("ADD, , , ,88114052,NQ LVARW,CL4,010-4528-3059,19911021,PRO");
    vectorStr.push_back("ADD, , , ,19129568,SRERLALH HMEF,CL2,010-3091-9521,19640910,PRO");
    vectorStr.push_back("ADD, , , ,17111236,VSID TVO,CL1,010-3669-1077,20120718,PRO");
    vectorStr.push_back("ADD, , , ,18117906,TWU QSOLT,CL4,010-6672-7186,20030413,PRO");
    vectorStr.push_back("ADD, , , ,08123556,WN XV,CL1,010-7986-5047,20100614,PRO");
    vectorStr.push_back("ADD, , , ,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,ADV");
    vectorStr.push_back("ADD, , , ,03113260,HH LTUPF,CL2,010-5798-5383,19791018,PRO");
    vectorStr.push_back("ADD, , , ,14130827,RPO JK,CL4,010-3231-1698,20090201,ADV");
    vectorStr.push_back("ADD, , , ,01122329,DN WD,CL4,010-7174-5680,20071117,PRO");
    vectorStr.push_back("ADD, , , ,08108827,RTAH VNUP,CL4,010-9031-2726,19780417,ADV");
    vectorStr.push_back("ADD, , , ,85125741,FBAH RTIJ,CL1,010-8900-1478,19780228,ADV");
    vectorStr.push_back("ADD, , , ,08117441,BMU MPOSXU,CL3,010-2703-3153,20010215,ADV");
    vectorStr.push_back("ADD, , , ,10127115,KBU MHU,CL3,010-3284-4054,19660814,ADV");
    vectorStr.push_back("ADD, , , ,12117017,LFIS JJIVL,CL1,010-7914-4067,20120812,PRO");
    vectorStr.push_back("ADD, , , ,11125777,TKOQKIS HC,CL1,010-6734-2289,19991001,PRO");
    vectorStr.push_back("ADD, , , ,11109136,QKAHCEX LTODDO,CL4,010-2627-8566,19640130,PRO");
    vectorStr.push_back("ADD, , , ,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,PRO");
    vectorStr.push_back("SCH,-p,-d, ,birthday,04");
    vectorStr.push_back("MOD,-p, , ,name,FB NTAWR,birthday,20050520");
    vectorStr.push_back("SCH, , , ,employeeNum,79110836");
    vectorStr.push_back("DEL, , , ,employeeNum,18115040");
    vectorStr.push_back("DEL,-p,-l, ,name,MPOSXU");
    vectorStr.push_back("SCH,-p, , ,certi,PRO");
    vectorStr.push_back("SCH, , , ,certi,ADV");
    vectorStr.push_back("SCH,-p, , ,cl,CL4");
    vectorStr.push_back("SCH, ,-m, ,birthday,09");
    vectorStr.push_back("MOD,-p, , ,name,FB NTAWR,cl,CL3");
    vectorStr.push_back("MOD,-p, , ,employeeNum,08123556,birthday,20110706");
    vectorStr.push_back("SCH,-p,-y, ,birthday,2003");
    vectorStr.push_back("SCH,-p, , ,employeeNum,05101762");
    vectorStr.push_back("SCH,-p,-m, ,phoneNum,3112");
    vectorStr.push_back("SCH,-p,-l, ,phoneNum,4605");
    vectorStr.push_back("SCH,-p, , ,employeeNum,10127115");
    vectorStr.push_back("MOD,-p, , ,phoneNum,010-8900-1478,certi,PRO");
    vectorStr.push_back("SCH, ,-f, ,name,LDEXRI");
    vectorStr.push_back("MOD, , , ,name,VCUHLE HMU,birthday,19910808");
    vectorStr.push_back("SCH, , , ,name,FB NTAWR");
    vectorStr.push_back("");
    EXPECT_EQ(vectorStr, input.readFile());
}


TEST(OutputManagerTest, WriteFileTest) {
    OutputManager output;
    string outputFile;
    vector<string> vectorStr;

    outputFile = "output_20_20_temp1.txt";
    output.setOutputName(outputFile);
    EXPECT_EQ(true, output.writeFile(vectorStr));

    outputFile = "output_20_20_temp2.txt";
    output.setOutputName(outputFile);
    vectorStr.push_back("aaa");
    vectorStr.push_back("bbb");
    EXPECT_EQ(true, output.writeFile(vectorStr));
}


TEST(OutputManagerTest, WriteReadFileTest) {
    //write file
    OutputManager output;
    string outputFile;
    vector<string> vectorStrWrite;

    outputFile = "output_20_20_temp3.txt";
    output.setOutputName(outputFile);
    vectorStrWrite.push_back("aaa");
    vectorStrWrite.push_back("bbb");
    vectorStrWrite.push_back("ccc");
    vectorStrWrite.push_back("ddd");
    EXPECT_EQ(true, output.writeFile(vectorStrWrite));
    vectorStrWrite.push_back("");

    //read file
    InputManager input;
    string inputFile;
    vector<string> vectorStrRead;
    inputFile = "output_20_20_temp3.txt";
    input.setInputName(inputFile);
    vectorStrRead = input.readFile();
    EXPECT_EQ(vectorStrWrite, vectorStrRead);
}
