// DisiminationException 2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>

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
			// Поширення виключення
			throw i;   
		}
	}
	catch (double i) { std::cout << "Double Exception "; }
	catch (int i) { std::cout << "Int Exception "; }
}

