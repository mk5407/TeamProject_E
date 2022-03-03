#include <iostream>
#include <vector>
#include <string>
#include "input.h"
#include "output.h"
#include "utils.h"
using namespace std;


int main(int argc, char* argv[])
{
	string inputFile = "input_20_20.txt";
	string outputFile = "output_20_20.txt";

	InputData input;
	input.setInputName(inputFile);

	vector<string> inStr = input.readFile();
	if (inStr.size() == 0){
		cout << "file open fail" << endl;
		exit(1);
	}	

	Utils util;
	for (auto str : inStr) {
		vector<string> line = util.split(str, ',');
		for (auto word : line) {
			//call op func
			cout << word << "::";
		}
		cout << endl;
	}





	return 0;
} 