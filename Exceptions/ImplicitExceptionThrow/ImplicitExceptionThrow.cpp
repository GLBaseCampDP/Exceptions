// ImplicitExceptionThrow.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

int F(int);

void main() {
	// ����������� ���������� "exception int"
	F(10);
}

int F(int i) {
	// ��������� ��������� ���� char* 
	if (i)  throw "exeption int";
	else throw "exeption zero";
	// ��������� ��������� ���� int 
	throw i;
	return 10;
}

