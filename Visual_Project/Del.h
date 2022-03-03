#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Employee.h"

using namespace std;

class Del
{
public:
	bool compareEmployee(struct Employee s1, struct Employee s2) {
		return (s1.employeeNum == s2.employeeNum) &&
			(s1.name == s2.name) &&
			(s1.cl == s2.cl) &&
			(s1.phoneNum == s2.phoneNum) &&
			(s1.birthday == s2.birthday) &&
			(s1.certi == s2.certi);
	}

	int del(std::vector<Employee>& list, std::vector<Employee> foundList) {

		for (int i = 0; i < foundList.size(); i++) {
			for (int j = 0; j < list.size(); j++) {
				if (compareEmployee(foundList[i], list[j])) list.erase(list.begin() + j);
			}
		}

		return 0;
	}
};

