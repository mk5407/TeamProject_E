#pragma once
#include <string>
enum class CareerLevel
{
	CL1,
	CL2,
	CL3,
	CL4
};

enum class CertiLevel
{
	ADV,
	PRO,
	EX
};

struct Employee
{
	unsigned int employeeNum;
	std::string name;
	CareerLevel cl;
	std::string phoneNum;
	int birthday;
	CertiLevel certi;
};