#pragma once

#include "Mod.h"
#include <sstream>

using namespace std;

Mod::Mod(string cmd) 
{
	option1_ = 0;
	option2_ = 0;
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

	int type = 0;

	vector<string> mod_type = { "employeeNum", "name", "cl", "phoneNum", "birthday", "certi" };

	// [TO DO] Refactoring 
	for (string mod_select : mod_type)
	{
		if (!mod_select.compare(str_list[4]))
		{
			find_.type_ = static_cast<Type>(type);
			find_.content_ = str_list[5];
		}

		if (!mod_select.compare(str_list[6]))
		{
			modify_.type_ = static_cast<Type>(type);;
			modify_.content_ = str_list[7];
		}
		type++;
	}
	
}

vector<Employee*> Mod::getModifyList(vector<Employee>& employee_list)
{
	// [TO DO] Refactoring 
	CareerLevel find_cl;
	vector<string> cl_type = { "CL1", "CL2", "CL3", "CL4" };
	CertiLevel find_certi;
	vector<string> certi_type = { "ADV", "PRO", "EX" };

	int cl_num = 0;
	int certi_num = 0;

	for (string cl_str : cl_type)
	{
		if (cl_str == find_.content_)
		{
			find_cl = static_cast<CareerLevel>(cl_num);
		}
		cl_num++;
	}

	for (string certi_str : certi_type)
	{
		if (certi_str == find_.content_)
		{
			find_certi = static_cast<CertiLevel>(certi_num);
		}
		certi_num++;
	}

	int vector_size = employee_list.size();

	// [TO DO] Refactoring 
	switch (find_.type_)
	{
	case Type::EmployeeNum:

		for (int i = 0; i< vector_size; i++)
		{
			Employee* e = &employee_list[i];

			if (e->employeeNum == find_.content_)
			{
				find_list_.push_back(e);
			}
		}

		break;
	case Type::Name:
		
		for (int i = 0; i < vector_size; i++)
		{
			Employee* e = &employee_list[i];

			if (e->name == find_.content_)
			{
				find_list_.push_back(e);
			}
		}
		break;

	case Type::CL:

		for (int i = 0; i < vector_size; i++)
		{
			Employee* e = &employee_list[i];

			if (e->cl == find_cl)
			{
				find_list_.push_back(e);
			}
		}

		break;

	case Type::PhoneNum:

		for (int i = 0; i < vector_size; i++)
		{
			Employee* e = &employee_list[i];

			if (e->phoneNum == find_.content_)
			{
				find_list_.push_back(e);
			}
		}

		break;
	case Type::BirthDay:

		for (int i = 0; i < vector_size; i++)
		{
			Employee* e = &employee_list[i];

			if (e->birthday == find_.content_)
			{
				find_list_.push_back(e);
			}
		}

		break;
	case Type::Certi:

		for (int i = 0; i < vector_size; i++)
		{
			Employee* e = &employee_list[i];

			if (e->certi == find_certi)
			{
				find_list_.push_back(e);
			}
		}

		break;
	}

	return find_list_;
}

void Mod::modifyEmployeeInfo(vector<Employee*> modify_list)
{
	// [TO DO] Refactoring 
	CareerLevel modify_cl;
	vector<string> cl_type = { "CL1", "CL2", "CL3", "CL4" };
	CertiLevel modify_certi;
	vector<string> certi_type = { "ADV", "PRO", "EX" };

	int cl_num = 0;
	int certi_num = 0;

	for (string cl_str : cl_type)
	{
		if (cl_str == modify_.content_)
		{
			modify_cl = static_cast<CareerLevel>(cl_num);
		}
		cl_num++;
	}

	for (string certi_str : certi_type)
	{
		if (certi_str == modify_.content_)
		{
			modify_certi = static_cast<CertiLevel>(certi_num);
		}
		certi_num++;
	}


	for (Employee* e : modify_list)
	{
		switch (modify_.type_)
		{
		case Type::EmployeeNum:
			e->employeeNum = modify_.content_;
			break;
		case Type::Name:
			e->name = modify_.content_;
			break;
		case Type::CL:
			e->cl = modify_cl;
			break;
		case Type::PhoneNum:
			e->phoneNum = modify_.content_;
			break;
		case Type::BirthDay:
			e->birthday = modify_.content_;
			break;
		case Type::Certi:
			e->certi = modify_certi;
			break;
		}
	}

}