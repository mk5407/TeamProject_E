#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
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

	vector<string> split(string str, char delimiter) {
		vector<string> result;
		stringstream ss(str);
		string word;

		while (getline(ss, word, delimiter)) {
			result.push_back(word);
		}
		return result;
	}

private:
	string inputName_;
};


