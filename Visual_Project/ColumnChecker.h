#pragma once
#include <vector>
#include <string>
#include "Column.h"

using namespace std;

class ColumnChecker
{
public:
    ColumnChecker();
    ~ColumnChecker();

    bool columnCheck(vector<string> line);

private:
    Column* IColumnEmployeeNum_;
    Column* IColumnName_;
    Column* IColumnPhoneNum_;
    Column* IColumnCL_;
    Column* IColumnBirthday_;
    Column* IColumnCerti_;
};

