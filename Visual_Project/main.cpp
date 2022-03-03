#include <iostream>
#include <vector>
#include <string>
#include "input.h"
#include "output.h"
#include "utils.h"
using namespace std;


int main(int argc, char* argv[])
{
    //if (argc != 3) return 0;
    //if (!isNum(argv[1]))return 0;
    //if (!isNum(argv[2]))return 0;
    //int a = atoi(argv[1]);
    //int b = atoi(argv[2]);
    //if (!(a >= 0 && a < MAXSIZE)) return 0;
    //if (!(b >= 0 && b < MAXSIZE)) return 0;
    //if (!isFloat(argv[3])) return 0;
    //float c = atof(argv[3]);



	string inputFile = "input_20_20.txt";
	string outputFile = "output_20_20.txt";

	InputData input;
	input.setInputName(inputFile);

	vector<string> inStrAll = input.readFile();
	if (inStrAll.size() == 0){
		cout << "file open fail" << endl;
		exit(1);
	}	

    vector<string> outStrAll;
    Utils util;
    vector<string> result;
    for (auto str : inStrAll) {
        if (str.length() == 0) break;

        vector<string> lineStr = util.split(str, ',');
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
            outStrAll.push_back(lineResult);
        }

    }

    OutputData output;
    output.setOutputName(outputFile);
    output.writeFile(inStrAll);

	return 0;
} 