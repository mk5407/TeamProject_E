#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;



class Utils {
public:
	vector<string> split(string str, char delimiter) {
		vector<string> result;
		stringstream ss(str);
		string word;

		while (getline(ss, word, delimiter)) {
			result.push_back(word);
		}
		return result;
	}

};