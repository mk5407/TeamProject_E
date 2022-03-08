#include "Del.h"

Del::Del(IDatabase<Employee>* database) {
    m_pEmployee_database = database;
}

void Del::del(vector<int> delete_list) {
    int size = delete_list.size();
    if (size <= 0) return;
    for (int index = size - 1; index >= 0; index--) {
        m_pEmployee_database->delData(delete_list[index]);
    }
}