#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;



class OutputManager {
public:
    void setOutputName(string name) {
        outputName_ = name;
    }

    bool writeFile(vector<string> outputStrAll) {
        ofstream fout(outputName_);

        if (fout.fail()) {
            return false;
        }

        for (auto str : outputStrAll) {
           fout << str << endl;
        }
        return true;
    }

private:
    string outputName_;
};


