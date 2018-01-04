// ThrowControl.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
struct A {
int i;
};
// обмеження генерації виключень лише типом A
int F(int) throw (A); 

main()
{
	int i = F(0); // спроба згенерується недопустиме виключення
}
// усі спроби згенерувати виключення не типу А
// приведуть до аварійного завершення
int F(int i) throw (A)	{      			
	switch (i)
	{
	case 0: throw " exception char* "; break;
	case 1: throw A(); break;
	default: throw i;
	}
}


