// ErrorCode2.cpp: определяет точку входа для консольного приложения.
//
// http://blog.think-async.com/2010/04/system-error-support-in-c0x-part-5.html

#include "stdafx.h"
#include <iostream>       
#include <system_error>   
#include <iostream>
#include <string>
#include <WinError.h>
using namespace std;

enum my_error {
	continue_operation = 100,
	switching_operation = 101,
	break_operation = 102,
	sleep_operation = 103,
	forbidden_operation = 104
};


class my_category : public error_category {
public:
	virtual const char* name() const noexcept { return "operation"; };
	string message(int ev) const;
	virtual error_condition
		default_error_condition(int code) const noexcept;
	virtual bool equivalent(
		const std::error_code& code,
		int condition) const noexcept;
};

bool my_category::equivalent(
	const std::error_code& code,int condition) const noexcept
{
	switch (condition)
	{
		
	case my_error::break_operation:
#if defined(_WIN32)
		return code == std::error_code(
			ERROR_INVALID_FUNCTION, system_category());
#else
		return code = std::error_code(
			EACCES|| EAGAIN || ENOSYS, generic_category());
#endif
	case my_error::forbidden_operation:
		return code == std::errc::not_enough_memory
			|| code == std::errc::resource_unavailable_try_again;
	default:
		return false;
	}
}

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
	switch (code) {
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

#define MAKE_ERROR(s) error_##s make_error_##s(my_error code) { \
return error_##s(static_cast<int>(code),\
	operation_category());}

MAKE_ERROR(code);
MAKE_ERROR(condition);

/*error_code make_error_code(my_error code) {
return error_code(static_cast<int>(code),
operation_category());
}

error_condition make_error_condition(my_error code){
return error_condition(static_cast<int>(code),
operation_category());
}*/

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

