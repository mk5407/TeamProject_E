#include <iostream>
#include "input.h"
#include "output.h"
using namespace std;


int main(int argc, char* argv[])
{
    if (argc != 3) return 0;

	//string inputFile = "input_20_20.txt";
	//string outputFile = "output_20_20.txt";

    string inputFile = argv[1];
    string outputFile = argv[2];

	InputData input;
	input.setInputName(inputFile);

	vector<string> inStrAll = input.readFile();
	if (inStrAll.size() == 0){
		cout << "file open fail" << endl;
		exit(1);
	}	

    vector<string> outStrAll;
    vector<string> result;
    for (auto str : inStrAll) {
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
            outStrAll.push_back(lineResult);
        }

    }

    OutputData output;
    output.setOutputName(outputFile);
    output.writeFile(inStrAll);

	return 0;
} 