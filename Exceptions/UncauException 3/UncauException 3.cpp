// UncauException 3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#include <exception>

struct A {
	int i;
	~A()	{
		if (std::uncaught_exception()) 
			std::cout << "Yes\n";
	}
};

void main() {
	try	{
		A a;
		throw 1;

	}
	catch (...){
			std::cout << "Universal soldier";
	}
	
	
	system("pause");
}


