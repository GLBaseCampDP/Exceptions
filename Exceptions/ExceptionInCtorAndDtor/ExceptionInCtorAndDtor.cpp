// ExceptionInCtorAndDtor.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include<iostream>
struct A {
	class B {};
	enum { max = 2000 };
	A(int i) 	{
		if ((i<0) || (i> max))
			throw A::B();
	}
};

void main() {

	try
	{
		A* a = new A(300);
	}
	catch (A::B ) { std::cout << "Error"; }
}

