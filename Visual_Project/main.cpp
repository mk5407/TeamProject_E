#include <iostream>
#include "input.h"
#include "output.h"
using namespace std;


int main(int argc, char* argv[])
{
    InputData input;
    OutputData output;

    // Visual_Project 속성 > 디버깅 > 명령인수 > input_20_20.txt output_20_20.txt
    // 이렇게 입력하면 됩니다.
    // 
    // 수동 test를 원하시면 아래의 블럭을 enable 해주세요
    //string inputFile = "input_20_20.txt";
    //string outputFile = "output_20_20.txt";

    if (!input.isValidArg(argc, argv))   exit(1);

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

        vector<string> lineStr = input.split(str, ',');
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

    return 0;
}


