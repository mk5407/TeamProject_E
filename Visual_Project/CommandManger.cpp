#include "CommandManager.h"
#include <iostream>
#include <string>

using namespace std;

CommandManager::CommandManager()
{
    IDatabase<Employee>* db_pointer = (IDatabase<Employee>*)(&db_);
    
    iAdd_ = static_cast<IAdd*>(new Add(db_pointer));
    iSch_ = static_cast<ISch*>(new Sch(db_pointer));
    iMod_ = static_cast<IMod*>(new Mod(db_pointer));
    iDel_ = static_cast<IDel*>(new Del(db_pointer));
}

CommandManager::~CommandManager()
{
    delete iAdd_,iSch_,iMod_,iDel_,db_;
}

void CommandManager::parsingCMD(vector<string> str_list)
{

    cmd_ = str_list[(int)InputType::CMD_Type];
    option1_ = str_list[(int)InputType::Option1];
    option2_ = str_list[(int)InputType::Option2];

    int type = (int)Type::EmployeeNum;

    vector<string> mod_type = { "employeeNum", "name", "cl", "phoneNum", "birthday", "certi" };

    for (string mod_select : mod_type)
    {
        if (!mod_select.compare(str_list[(int)InputType::Search_type]))
        {
            find_.type_ = static_cast<Type>(type);
            find_.content_ = str_list[(int)InputType::Search_content];
        }

        if (!mod_select.compare(str_list[(int)InputType::Modify_type]))
        {
            modify_.type_ = static_cast<Type>(type);
            modify_.content_ = str_list[(int)InputType::Modify_content];
        }
        type++;
    }
}

void CommandManager::executeCmd(vector<string> cmdStr)
{
    parsingCMD(cmdStr);

    if (cmd_ == "ADD") 
    {
        iAdd_->add(cmdStr);
    }
    else
    {
        vector<int> sch_list = iSch_->search(option2_, find_.type_, find_.content_);

        if (cmd_ == "MOD") iMod_->modify(modify_.type_,modify_.content_, sch_list);
        if (cmd_ == "DEL") iDel_->del(sch_list);
    }
}