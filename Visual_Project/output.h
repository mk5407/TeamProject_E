#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;



class OutputData {
public:
	void setOutputName(string name) {
		outputName_ = name;
	}

	bool writeFile(vector<string> vectorStr) {
		ofstream fout(outputName_);

		vector<string> outputStr;
		if (fout.fail()) {
			return false;
		}

		for (auto str : vectorStr) {
			fout << str << endl;
		}
		return true;
	}

private:
	string outputName_;
};


