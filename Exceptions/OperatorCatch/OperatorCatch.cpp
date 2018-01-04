// OperatorCatch.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#include <iostream>
using namespace std;

struct A{
	int i;
};
// �-� ������ � �������� ����������
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
	// �������� ����. ��������� ����� � ���������
	catch (const char *c)	{
		cout << c;
	}
	// �������� ��� ��������� ����� � 
	catch (A) 
	{
		cout << "exception A";
	}
	// �������� ��� ��������� ������ ����
	catch (int) 
	{
		cout << "exception int";
	}
}
void main() {
	F(0);
}

