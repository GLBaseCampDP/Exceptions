// ThrowControl.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
struct A {
int i;
};
// ��������� ��������� ��������� ���� ����� A
int F(int) throw (A); 

main()
{
	int i = F(0); // ������ ����������� ����������� ����������
}
// �� ������ ����������� ���������� �� ���� �
// ��������� �� ��������� ����������
int F(int i) throw (A)	{      			
	switch (i)
	{
	case 0: throw " exception char* "; break;
	case 1: throw A(); break;
	default: throw i;
	}
}


