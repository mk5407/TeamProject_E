#include <iostream>
#include "InputManager.h"
#include "InputParcer.h"
#include "OutputManager.h"
#include "CommandManager.h"
#include "Database.h"
using namespace std;


int employeeManagerRun(string inputFile, string outputFile)
{
    InputParcer* inputPaser = new InputParcer();
    if (inputPaser->isValidFileName(inputFile) == false || inputPaser->isValidFileName(outputFile) == false)
        return false;
    InputManager* inputManager = new InputManager(inputFile);
    OutputManager* outputManager = new OutputManager(outputFile);
    CommandManager* commandManager = new CommandManager();
    IDatabase<Employee>* database = new EmployeeDatabase();

    vector<string> inputStrAll = inputManager->readFile();
    vector<string> outputStrAll;
    for (auto str : inputStrAll) {
        if (str.length() == 0) break;
        vector<string> lines = commandManager->executeCmd(inputPaser->split(str));
        for (string line : lines) outputStrAll.push_back(line);
    }
    outputManager->writeFile(outputStrAll);
    delete inputManager, inputPaser, outputManager, commandManager, database;
    return true;
}

int main(int argc, char* argv[])
{
    if (argc < 2) exit(1);
    employeeManagerRun(argv[1], argv[2]);

    return 0;
}
