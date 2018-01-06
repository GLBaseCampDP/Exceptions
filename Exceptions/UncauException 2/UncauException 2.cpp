// UncauException 2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

//Новий обробник неперухопленої КС
#include <iostream>
#include <stdexcept>

void my_terminate() {
	if (!std::uncaught_exception())
	{
		std::cout << "Є непередбачені КС";
	}
	std::cout << "Program will be terminate";
	exit(1);
}
void ExceptThrow(bool yes) {
	if (yes) throw;
}
void main()
{
	set_terminate(my_terminate);
	ExceptThrow(true);
}

