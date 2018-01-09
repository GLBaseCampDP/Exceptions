// ErrorCode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

// custom error_category example
#include <iostream>       
#include <system_error>   
#include <iostream>
#include <string>

#define DIVIDE_BY_ZERO -3
using namespace std;

#define OUT(catg, er) my_cond = catg().default_error_condition(er);\
   std::cout << "Category: " << my_cond.category().name() << '\n'\
   << "Value: " << my_cond.value() << '\n'\
   << "Message: " << my_cond.message() << '\n';

int main() {
	error_condition my_cond;
	my_cond = OUT(system_category, DIVIDE_BY_ZERO);
	my_cond = OUT(system_category, E2BIG);
	my_cond = OUT(generic_category, E2BIG);

	std::error_condition a(std::errc::file_exists);
	std::error_condition b(EEXIST, std::generic_category());

	if (a == b) std::cout << "Yes message - " << a.message();

		system("pause");
	return 0;
}
