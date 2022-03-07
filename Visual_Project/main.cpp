#include <iostream>
#include "inputManager.h"
#include "inputParcer.h"
#include "OutputManager.h"
#include "ColumnChecker.h"
using namespace std;




int employeeManagerRun(int argc, char* argv[])
{
    InputManager input;
    InputParcer parcer;
    OutputManager output;

    // Visual_Project 속성 > 디버깅 > 명령인수 > input_20_20.txt output_20_20.txt
    // 이렇게 입력하면 됩니다.
    // 
    // 수동 test를 원하시면 아래의 블럭을 enable 하면 됩니다.
    //argc = 3;
    //argv[1] = (char*)"input_20_20.txt";
    //argv[2] = (char*)"output_20_20.txt";

    if (!parcer.isValidArg(argc, argv)) {
        cout << "Input args failure" << endl;
        exit(1);
    }

    string inputFile(argv[1]);
    string outputFile(argv[2]);

    input.setInputName(inputFile);
    output.setOutputName(outputFile);

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


}



int main(int argc, char* argv[])
{
    employeeManagerRun(argc, argv);

    return 0;
}


