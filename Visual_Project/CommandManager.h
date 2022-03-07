#pragma once

#include <vector>
#include "OutputManager.h" 
#include "database.h"

#include "Sch.h"
#include "Del.h"
#include "Mod.h"
#include "add.h"

using namespace std;

const int EMPLOYEE_INFO_START = 4;
const int EMPLOYEE_INFO_END = 9;

enum class InputType
{
    CMD_Type = 0,
    Option1,
    Option2, 
    Search_type = 4,
    Search_content,
    Modify_type,
    Modify_content
};

struct SchType {
    Type type_;
    string content_;
};

struct ModType {
    Type type_;
    string content_;
};

class CommandManager
{
public:
    CommandManager();
    ~CommandManager();

    vector<string> executeCmd(vector<string> cmdStr);
    void parsingCMD(vector<string> str_list);

    vector<string> printOutputString(vector<int> sch_list);
    string getEmployeeInfo(Employee* e, Type type);
    void sortEmployee(vector<int>& emp_list, int left, int right);

private:
    EmployeeDatabase db_;
    IAdd* iAdd_;
    ISch* iSch_;
    IMod* iMod_;
    IDel* iDel_;

    string cmd_;
    string option1_;
    string option2_;
    SchType find_;
    ModType modify_;
};