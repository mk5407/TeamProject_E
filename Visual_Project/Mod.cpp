#pragma once

#include "Mod.h"
#include <sstream>

using namespace std;

Mod::Mod(string cmd) 
{
	parsingCMD(cmd);
}

void Mod::parsingCMD(string cmd)
{
	istringstream ss(cmd);
	string str_buf;

	vector<string> str_list;

	while (getline(ss, str_buf, ','))
	{
		str_list.push_back(str_buf);
	}

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
string Mod::getEmployeeInfo(Employee* e, Type type)
{
	//[TO DO] Refactoring
	string Option2Check[] = {"-f","-l","-m","-l"};
	Type ModifyCheck[] = { Type::Name,Type::Name,Type::PhoneNum,Type::PhoneNum };

	string option2_employeeInfo[] = { e->getFirstName(), e->getLastName(),e->getMiddlePhoneNum(),e->getLastPhoneNum() };

	for (int i = 0; i < MAX_OPTION2_SIZE; i++)
	{
		string option2_check = Option2Check[i];
		Type modify_check = ModifyCheck[i];

		if ((option2_check == option2_) && (modify_check == modify_.type_))
		{
			return option2_employeeInfo[i];
		}
	}
	
	string employeeInfo[] = {e->getEmployeeNum(), e->getName(), e->getCL(), e->getPhoneNum(),e->getBirthday(), e->getCerti() };
	
	int index = (int)type - (int)Type::EmployeeNum;

	return employeeInfo[index];
}

vector<Employee*> Mod::getModifyList(vector<Employee>& employee_list)
{
	int vector_size = employee_list.size();

	for (int i = 0; i < vector_size; i++)
	{
		Employee* e = &employee_list[i];

		if (getEmployeeInfo(e, find_.type_) == find_.content_)
		{
			find_list_.push_back(e);
		}
	}

	//[TO DO] Refactoring
	if (option1_ != "-p")
	{
		result_string_.push_back("MOD,"+to_string(find_list_.size()));
	}
	else
	{
		int find_size = find_list_.size();

		for (Employee *e : find_list_)
		{
			string output="MOD,";

			for (int i = EMPLOYEE_INFO_START; i<= EMPLOYEE_INFO_END; i++)
			{
				Type type = static_cast<Type>(i);

				output += getEmployeeInfo(e, type);
				output += ",";
			}

			result_string_.push_back(output);
		}
	}

	return find_list_;
}

void Mod::modifyEmployeeInfo(vector<Employee*> modify_list)
{
	for (Employee* e : modify_list)
	{
		e->setColumnData(modify_.type_, modify_.content_);
	}
}