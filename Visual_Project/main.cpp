#include <iostream>
#include "InputManager.h"
#include "InputParcer.h"
#include "OutputManager.h"
using namespace std;




int employeeManagerRun(int argc, char* argv[])
{
    // Visual_Project 속성 > 디버깅 > 명령인수 > input_20_20.txt output_20_20.txt
    // 이렇게 입력하면 됩니다.
    // 
    // 수동 test를 원하시면 아래의 블럭을 enable 하면 됩니다.
    //argc = 3;
    argv[1] = (char*)"input_20_20.txt";
    argv[2] = (char*)"output_20_20.txt";

    InputParcer parcer;
    if (!parcer.isValidArg(argc, argv)) {
        cout << "Input args failure" << endl;
        exit(1);
    }


    InputManager input(argv[1]);
    OutputManager output(argv[2]);

    vector<string> inputStrAll = input.readFile();
    if (inputStrAll.size() == 0) {
        cout << "File open failure" << endl;
        exit(1);
    }

    vector<string> outputStrAll;
    vector<string> result;
    for (auto str : inputStrAll) {
        if (str.length() == 0) break;

        vector<string> lineStr = parcer.split(str);
        if (lineStr.size() == 0) {
            cout << "Column check failure" << endl;
            exit(1);
        }

        if (lineStr[0] == "ADD") {
            //callAdd(line);
        }
        else if (lineStr[0] == "SCH") {
            //result = callSch(lineStr);
        }
        else if (lineStr[0] == "MOD") {
            //result = callMod(line);
        }
        else if (lineStr[0] == "DEL") {
            //result = callDel(line);
        }
        else {
            cout << "operation error" << endl;
            exit(1);
        }

        for (auto lineResult : result) {
            outputStrAll.push_back(lineResult);
        }

    }

    output.writeFile(outputStrAll);

    return true;
}



int main(int argc, char* argv[])
{
    employeeManagerRun(argc, argv);

    return 0;
}


