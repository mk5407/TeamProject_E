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
    delete iAdd_,iSch_,iMod_,iDel_;
}

void CommandManager::parsingCMD(vector<string> str_list)
{

    cmd_ = str_list[(int)InputType::CMD_Type];
    option1_ = str_list[(int)InputType::Option1];
    option2_ = str_list[(int)InputType::Option2];

    int type_index = (int)Type::EmployeeNum;

    vector<string> employee_info = { "employeeNum", "name", "cl", "phoneNum", "birthday", "certi" };

    for (string info : employee_info)
    {
        if (!info.compare(str_list[(int)InputType::Search_type]))
        {
            find_.type_ = static_cast<Type>(type_index);
            find_.content_ = str_list[(int)InputType::Search_content];
        }

        type_index++;
    }

    if(cmd_=="MOD")
    { 
        type_index = (int)Type::EmployeeNum;

        for (string info : employee_info)
        {
            if (!info.compare(str_list[(int)InputType::Modify_type]))
            {
                modify_.type_ = static_cast<Type>(type_index);
                modify_.content_ = str_list[(int)InputType::Modify_content];
            }
            type_index++;
        }
    }
}

void CommandManager::sortEmployee(vector<int>& emp_list, int left, int right)
{
    if (left >= right) return;
    int pivot = left;
    int tempLeft = left + 1;
    int tempRight = right;

    while (tempLeft <= tempRight)
    {
        int leftEmployeeNum = stoi(db_.getData(emp_list[tempLeft])->getEmployeeNum());
        int rightEmployeeNum = stoi(db_.getData(emp_list[tempRight])->getEmployeeNum());
        int pivotEmployeeNum = stoi(db_.getData(emp_list[pivot])->getEmployeeNum());

        if (leftEmployeeNum >= OLDEST_EMP_NUM)
            leftEmployeeNum += 1900000000;
        if (rightEmployeeNum >= OLDEST_EMP_NUM)
            rightEmployeeNum += 1900000000;
        if (pivotEmployeeNum >= OLDEST_EMP_NUM)
            pivotEmployeeNum += 1900000000;
        if (leftEmployeeNum <= YOUNGEST_EMP_NUM)
            leftEmployeeNum += 2000000000;
        if (rightEmployeeNum <= YOUNGEST_EMP_NUM)
            rightEmployeeNum += 2000000000;
        if (pivotEmployeeNum <= YOUNGEST_EMP_NUM)
            pivotEmployeeNum += 2000000000;

        while ((leftEmployeeNum < pivotEmployeeNum) && (tempLeft <= right))
        {
            tempLeft++;
            leftEmployeeNum = stoi(db_.getData(emp_list[tempLeft])->getEmployeeNum());
            if (leftEmployeeNum >= OLDEST_EMP_NUM)
                leftEmployeeNum += 1900000000;
            if (leftEmployeeNum <= YOUNGEST_EMP_NUM)
                leftEmployeeNum += 2000000000;
        }
        while ((rightEmployeeNum > pivotEmployeeNum) && (tempRight > left))
        {
            tempRight--;
            rightEmployeeNum = stoi(db_.getData(emp_list[tempRight])->getEmployeeNum());
            if (rightEmployeeNum >= OLDEST_EMP_NUM)
                rightEmployeeNum += 1900000000;
            if (rightEmployeeNum <= YOUNGEST_EMP_NUM)
                rightEmployeeNum += 2000000000;
        }

        if (tempLeft < tempRight)
        {
            swap(emp_list[tempLeft], emp_list[tempRight]);
        }
        else break;
    }
    swap(emp_list[tempRight], emp_list[pivot]);
    sortEmployee(emp_list, left, tempRight - 1);
    sortEmployee(emp_list, tempRight + 1, right);
}

vector<string> CommandManager::executeCmd(vector<string> cmdStr)
{   
    vector<string> outputStrAll;
    

    if (cmd_ == "ADD") 
    {
        iAdd_->add(cmdStr);
    }
    else
    {
        parsingCMD(cmdStr);

        vector<int> sch_list = iSch_->search(option2_, find_.type_, find_.content_);
        outputStrAll = printOutputString(sch_list);

        if (option1_ == "-p")
            sortEmployee(sch_list, 0, sch_list.size() - 1);

        if (cmd_ == "MOD") 
        { 
            if (modify_.type_ == Type::EmployeeNum)
            {
                cout << "Invalid Modify Type: The Employee number cannot be changed. " << endl;
            }
            else
            {
                iMod_->modify(modify_.type_, modify_.content_, sch_list);
            }
        }
        if (cmd_ == "DEL") iDel_->del(sch_list);
    }

    return outputStrAll;
}


vector<string> CommandManager::printOutputString(vector<int> sch_list)
{
    vector<string> outputStrAll;
    int sch_size = sch_list.size();

    if (sch_size == 0)
    {
        outputStrAll.push_back(cmd_ + "," + "NONE");
    }
    else
    {
        if (option1_ != "-p")
        {
            string size_str = to_string(sch_size);
            outputStrAll.push_back(cmd_ + "," + size_str);
        }
        else
        {
            for (int index = 0; index < sch_size; index++)
            {
                Employee* e = db_.getData(sch_list[index]);

                string output = cmd_ + ",";

                for (int i = EMPLOYEE_INFO_START; i <= EMPLOYEE_INFO_END; i++)
                {
                    Type type = static_cast<Type>(i);

                    output += getEmployeeInfo(e, type);
                    output += ",";
                }

                outputStrAll.push_back(output);
            }
        }
    }
   

    return outputStrAll;
}

string CommandManager::getEmployeeInfo(Employee * e, Type type)
{
    string employeeInfo[] = { e->getEmployeeNum(), e->getName(), e->getCL(), e->getPhoneNum(),e->getBirthday(), e->getCerti() };

    int index = (int)type - (int)Type::EmployeeNum;

    return employeeInfo[index];
}