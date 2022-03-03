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
	bool compareEmployee(Employee s1, Employee s2) {
		return (s1.getEmployeeNum() == s2.getEmployeeNum()) &&
			(s1.getName() == s2.getName()) &&
			(s1.getCL() == s2.getCL()) &&
			(s1.getPhoneNum() == s2.getPhoneNum()) &&
			(s1.getBirthday() == s2.getBirthday()) &&
			(s1.getCerti() == s2.getCerti());
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

