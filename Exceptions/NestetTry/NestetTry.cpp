// NestetTry.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
using namespace  std;
// ��������� ���������
void F(int i) {
	switch (i) {
	case 0: throw "string Exeption"; break;
	case 1: throw double(i); break;
	case 2: throw i; break;
	}
}

void main() {
	try {
		try {
			F(2);
		}
		// �������� ���������� ����� try
		catch (const char *c) {
			cout << "inside TRY-Blok " << "\n" <<
				c << "\n";
		}
		// ��������� �� � ���������� �����
		throw 1;
	}
	// ��������� ���������� ����� try
	catch (double) {
		cout << "outside TRY-Blok " << "\n" <<
			"double Exeption" << "\n";
	}
	catch (int) {
		cout << "outside TRY-Blok " << "\n " <<
			"int Exeption" << "\n";
	}
	catch (...) {
		cout << "outside TRY-Blok " << "\n " <<
			"ALL Exeption" << "\n";
	}
}



