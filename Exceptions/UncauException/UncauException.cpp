// UncauException.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

//�������� ������������� ��

#include <iostream>
#include <stdexcept>

void my_terminate()
{
	std::cout << "Program will be terminate";
	exit(1);
}
void GenerateExcept(bool yes)
{
	if (yes) throw;
}
void main() {
	set_terminate(my_terminate);
	GenerateExcept(true);
}




