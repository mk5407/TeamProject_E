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
        vector<string> inputStrAll;
        if (fin.fail()) {
            return inputStrAll;
        }

        string line;
        while (!fin.eof()) {
            getline(fin, line);
            inputStrAll.push_back(line);
        }
        fin.close();
        return inputStrAll;
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

    bool isValidExt(string ext) {
        string txtExt(".txt");
        if (ext != txtExt)	return false;
        return true;
    }

    bool isValidArg(int argc, char* argv[]) {
        if (argc != 3) {
            cout << "Input argc failure" << endl;
            return false;
        }

        string inputFile(argv[1]);
        string outputFile(argv[2]);

        if (!isValidExt(inputFile.substr(inputFile.size() - 4, 4))) {
            cout << "Input file name failure" << endl;
            return false;
        }

        if (!isValidExt(outputFile.substr(outputFile.size() - 4, 4))) {
            cout << "output file name failure" << endl;
            return false;
        }

        return true;
    }

private:
    string inputName_;
};


