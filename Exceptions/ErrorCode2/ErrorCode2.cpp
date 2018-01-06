// ErrorCode2.cpp: определяет точку входа для консольного приложения.
//
// http://blog.think-async.com/2010/04/system-error-support-in-c0x-part-4.html

#include "stdafx.h"
#include <iostream>       
#include <system_error>   
#include <iostream>
#include <string>
using namespace std;

enum my_error {
	continue_operation = 100,
	switching_operation = 101,
	break_operation = 102, 
	sleep_operation = 103,
	forbidden_operation = 104
};


class my_category: public error_category {
public:
	virtual const char* name() const noexcept { return "operation"; };
	string message(int ev) const;
	virtual error_condition
		default_error_condition(int code) const noexcept;
};

error_condition my_category::default_error_condition(int code) const noexcept {
	switch (code)
	{
	case my_error::forbidden_operation:
		return errc::permission_denied;
	default:
		return error_condition(code, *this);
	}
}

string my_category::message(int code) const {
	switch (code) 	{
	case my_error::continue_operation:
		return " Continue ";
	case my_error::switching_operation:
		return " Switching ";
	case my_error::break_operation:
		return " Break ";
	case my_error::sleep_operation:
		return " Sleep ";
	case my_error::forbidden_operation:
		return " Forbidden "; 
	default:
		return "Unknown operation error";
	}
}

const error_category & operation_category() {
	static my_category mct;
	return mct;
}

error_code make_error_code(my_error code) {
	return error_code(
		static_cast<int>(code),
		operation_category());
}

namespace std {
	template <>
	struct is_error_code_enum<my_error>
		: public true_type {};
}


void CallOperation(error_code& er) {
	er = my_error::forbidden_operation;
}

int main() {
	error_code er;
	CallOperation(er);
	if (er == my_error::forbidden_operation)
	{
		cout << er.message();
	}
	system("pause");
    return 0;
}

