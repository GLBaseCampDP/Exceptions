// DisiminationException 2.cpp: ���������� ����� ����� ��� ����������� ����������.
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
			// ��������� ����������
			throw i;   
		}
	}
	catch (double i) { std::cout << "Double Exception "; }
	catch (int i) { std::cout << "Int Exception "; }
}

