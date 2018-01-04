// OperatorCatch.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
using namespace std;

struct A{
	int i;
};
// ф-я генерує і обробляє виключення
int F(int i) {
	try
	{
		switch (i)
		{
		case 0: throw " exception char* "; break;
		case 1: throw A(); break;
		case 2: throw i; break;
		default: throw 3.14;
		}
	}
	// обробник рядк. виключень разом зі значенням
	catch (const char *c)	{
		cout << c;
	}
	// обробник усіх виключень класу А 
	catch (A) 
	{
		cout << "exception A";
	}
	// обробник усіх виключень цілого типу
	catch (int) 
	{
		cout << "exception int";
	}
}
void main() {
	F(0);
}

