#pragma once

#include "OutputManager.h" 
#include "database.h"

#include "Sch.h"
#include "Del.h"
#include "Mod.h"
#include "add.cpp"

using namespace std;

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

    void executeCmd(vector<string> cmdStr);
    void parsingCMD(vector<string> str_list);

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