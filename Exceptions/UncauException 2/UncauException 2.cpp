// UncauException 2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

//����� �������� ������������� ��
#include <iostream>
#include <stdexcept>

void my_terminate() {
	if (!std::uncaught_exception())
	{
		std::cout << "� ������������ ��";
	}
	std::cout << "Program will be terminate";
	exit(1);
}
void GenerateExcept(bool yes) {
	if (yes) throw;
}
main()
{
	set_terminate(my_terminate);
	GenerateExcept(true);
}

