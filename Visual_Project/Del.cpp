#include "Del.h"

Del::Del(IDatabase<Employee>* database) {
    m_pEmployee_database = database;
}

void Del::del(vector<int> delete_list) {
    for (int index : delete_list) {
        m_pEmployee_database->delData(index);
    }
}