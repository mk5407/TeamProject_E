#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


class InputData {
public:
	void setInputName(string name) {
		inputName_ = name;
	}

	vector<string> readFile() {
		ifstream fin(inputName_);
		vector<string> inputStr;
		if (fin.fail()) {
			return inputStr;
		}

		string line;
		while (!fin.eof()) {
			getline(fin, line);
			inputStr.push_back(line);
		}
		fin.close();
		return inputStr;
	}

private:
	string inputName_;
};


