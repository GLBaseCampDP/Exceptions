// ErrorCode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

// custom error_category example
#include <iostream>       // std::cout, std::endl
#include <system_error>   // std::is_error_condition_enum, std::error_category,
#include <iostream>
#include <string>

#define DIVIDE_BY_ZERO -3

int main()
{
	std::error_condition my_cond = std::system_category().default_error_condition(DIVIDE_BY_ZERO);
	std::cout << "Category: " << my_cond.category().name() << '\n'
		<< "Value: " << my_cond.value() << '\n'
		<< "Message: " << my_cond.message() << '\n';

	my_cond = std::system_category().default_error_condition(E2BIG);
	std::cout << "Category: " << my_cond.category().name() << '\n'
		<< "Value: " << my_cond.value() << '\n'
		<< "Message: " << my_cond.message() << '\n';

	my_cond = std::generic_category().default_error_condition(E2BIG);
	std::cout << "Category: " << my_cond.category().name() << '\n'
		<< "Value: " << my_cond.value() << '\n'
		<< "Message: " << my_cond.message() << '\n';
	

	system("pause");
	return 0;
}
