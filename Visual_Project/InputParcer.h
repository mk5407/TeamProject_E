#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "ColumnChecker.h"
using namespace std;


class InputParcer {
public:
    vector<string> split(string str) {
        vector<string> result;
        stringstream ss(str);
        string word;

        while (getline(ss, word, ',')) {
            result.push_back(word);
        }

        //ColumnChecker checker;
        //if (checker.columnCheck(result) == false) {
        //    result.clear();
        //}

        return result;
    }

    bool isValidFileName(string name) {
        if (name.length() <= 4) return false;
        if (name.find("/") != string::npos) return false;
        if (name.find("\\") != string::npos) return false;

        int dotCnt = 0;
        for (auto element : name) {
            if (element == '.') dotCnt++;
        }
        if (dotCnt > 1) return false;

        string txtExt = ".txt";
        if(txtExt != name.substr(name.size() - 4, 4)) return false;

        return true;
    }

    bool isValidArg(int argc, char* argv[]) {
        if (argc != 3) {
            cout << "Input argc failure" << endl;
            return false;
        }

        string inputFile(argv[1]);
        string outputFile(argv[2]);
        if ((isValidFileName(inputFile)==false) || (isValidFileName(outputFile)==false)) return false;

        return true;
    }
};
