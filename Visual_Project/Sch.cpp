#include "Sch.h"

Sch::Sch(IDatabase<Employee>* database) {
    m_pEmployee_database = database;
}

vector<int> Sch::search(string op2, Type type, string value) {
    vector<int> result;
    int dbSize = m_pEmployee_database->getDbSize();

    for (int i = 0; i < dbSize; i++) {
        Employee* emp = m_pEmployee_database->getData(i);
        string tmp;
        switch (type) {
        case (Type::BirthDay):
            tmp = emp->getBirthday();
            if (op2 == "-y") tmp = tmp.substr(0, 4);
            if (op2 == "-m") tmp = tmp.substr(4, 2);
            if (op2 == "-d") tmp = tmp.substr(6, 2);
            break;
        case (Type::Certi):
            tmp = emp->getCerti();
            break;
        case (Type::CL):
            tmp = emp->getCL();
            break;
        case (Type::EmployeeNum):
            tmp = emp->getEmployeeNum();
            break;
        case (Type::Name):
            tmp = emp->getName();
            if (op2 == "-f") tmp = emp->getFirstName();
            if (op2 == "-l") tmp = emp->getLastName();
            break;
        case (Type::PhoneNum):
            tmp = emp->getPhoneNum();
            if (op2 == "-m") tmp = emp->getMiddlePhoneNum();
            if (op2 == "-l") tmp = emp->getLastPhoneNum();
            break;
        default:
            break;
        }

        if (value == tmp)
            result.push_back(i);
    }

    return result;
}