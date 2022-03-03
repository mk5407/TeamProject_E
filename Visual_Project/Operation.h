#pragma once

enum class OPCode {
	OP_ADD,
	OP_DEL,
	OP_SCH,
	OP_MOD,
};

enum class OPOption1 {
	OP1_PRINT,
	OP1_NONE,
};

enum class OPOption2 {
	OP2_NAME_FIRSTNAME,		// -f
	OP2_NAME_LASTNAME,		// -l
	OP2_PHONE_MIDDLE,		// -m
	OP2_PHONE_LAST,			// -l
	OP2_BIRTH_YEAR,			// -y
	OP2_BIRTH_MONTH,		// -m
	OP2_BIRTH_DAY,			// -d
	OP2_NONE,
};

enum class ColummType {
	CLM_EMPLOYEE_NUM,
	CLM_NAME,
	CLM_CL,
	CLM_PHONE_NUM,
	CLM_BIRTYDAY,
	CLM_CERTI,
};
