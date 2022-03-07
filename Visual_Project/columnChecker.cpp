#include "ColumnChecker.h"

ColumnChecker::ColumnChecker() {
    IColumnEmployeeNum_ = new ColumnEmployeeNum();
    IColumnName_ = new ColumnName();
    IColumnPhoneNum_ = new ColumnPhoneNum();
    IColumnCL_ = new ColumnCL();
    IColumnBirthday_ = new ColumnBirthday();
    IColumnCerti_ = new ColumnCerti();
}

ColumnChecker::~ColumnChecker() {
    delete IColumnEmployeeNum_, IColumnName_, IColumnPhoneNum_,
        IColumnCL_, IColumnBirthday_, IColumnCerti_;
}

bool ColumnChecker::columnCheck(vector<string> line) {
    Employee emp(line[4], line[5], line[6], line[7], line[8], line[9]);

    return (IColumnEmployeeNum_->IsValidColumn(emp)
        && IColumnName_->IsValidColumn(emp)
        && IColumnPhoneNum_->IsValidColumn(emp)
        && IColumnCL_->IsValidColumn(emp)
        && IColumnBirthday_->IsValidColumn(emp)
        && IColumnCerti_->IsValidColumn(emp));
}