#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
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
        return result;
    }

    bool isValidExt(string ext) {
        string txtExt = ".txt";
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
};
