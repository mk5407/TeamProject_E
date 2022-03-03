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

vector<Employee> Mod::getModifyList(vector<Employee> employee_list)
{
	vector <Employee> find_list;

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

	// [TO DO] Refactoring 
	switch (find_.type_)
	{
	case Type::EmployeeNum:
		for (Employee e : employee_list)
		{
			if (e.employeeNum == find_.content_)
			{
				find_list.push_back(e);
			}
		}

		break;
	case Type::Name:
		for (Employee e : employee_list)
		{
			if (e.name == find_.content_)
			{
				find_list.push_back(e);
			}
		}
		break;

	case Type::CL:
		for (Employee e : employee_list)
		{
			if (e.cl == find_cl)
			{
				find_list.push_back(e);
			}
		}

		break;

	case Type::PhoneNum:
		for (Employee e : employee_list)
		{
			if (e.phoneNum == find_.content_)
			{
				find_list.push_back(e);
			}
		}

		break;
	case Type::BirthDay:
		for (Employee e : employee_list)
		{
			if (e.birthday == find_.content_)
			{
				find_list.push_back(e);
			}
		}

		break;
	case Type::Certi:
		for (Employee e : employee_list)
		{
			if (e.certi == find_certi)
			{
				find_list.push_back(e);
			}
		}

		break;
	}

return find_list;
}

void Mod::modifyEmployeeInfo(vector<Employee> modify_list)
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


	for (Employee e : modify_list)
	{
		switch (modify_.type_)
		{
		case Type::EmployeeNum:
			e.employeeNum = modify_.content_;
			break;
		case Type::Name:
			e.name = modify_.content_;
			break;
		case Type::CL:
			e.cl = modify_cl;
			break;
		case Type::PhoneNum:
			e.phoneNum = modify_.content_;
			break;
		case Type::BirthDay:
			e.birthday = modify_.content_;
			break;
		case Type::Certi:
			e.certi = modify_certi;
			break;
		}
	}

}