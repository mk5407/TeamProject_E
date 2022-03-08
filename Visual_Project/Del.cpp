#include "Del.h"
#include <algorithm>
#include <functional>

Del::Del(IDatabase<Employee>* database) {
    m_pEmployee_database = database;
}

void Del::del(vector<int> delete_list) {
    int size = delete_list.size();
    if (size <= 0) return;

    sort(delete_list.begin(), delete_list.end(), greater<int>());

    for (int index = 0; index < size; index++) {
        m_pEmployee_database->delData(delete_list[index]);
    }
}