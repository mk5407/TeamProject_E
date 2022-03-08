#include "Del.h"

Del::Del(IDatabase<Employee>* database) {
    m_pEmployee_database = database;
}

void Del::del(vector<int> delete_list) {
    int size = delete_list.size();
    for (int index = size - 1; index >= 0; index--) {
        m_pEmployee_database->delData(index);
    }
}