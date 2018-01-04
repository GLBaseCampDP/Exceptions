// DisiminationException.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
void main()
{
	try
	{
		try
		{
			throw 1;
		}
		catch (int i)
		{
			std::cout << "Exception";
			// Генерація нового виключення 
			throw 3.14;   
		}
	}
	catch (double i) 
	{ std::cout << "Double Exception "; }
	catch (int i) 
	{ std::cout << "Int Exception "; }
}
