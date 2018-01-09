// ErrnoException.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#include <iostream>
#include <cfenv>
#include <cmath>
#include <cerrno>
#include <cstring>

#pragma STDC FENV_ACCESS ON
#pragma warning( disable : 4996 )  
using namespace std;

#define DETECT(Exc) if (e & Exc) cout << #Exc << " ";


double THROW(int x) {
	if (x == 0) feraiseexcept(FE_INVALID | FE_OVERFLOW);
	return x*x;
}

int main() {
	// �������� ������������ ������� ������ �������
	std::cout << "MATH_ERRNO is "
		<< (math_errhandling & MATH_ERRNO ? "on" : "of") << '\n'
		<< "MATH_ERREXCEPT is "
		<< (math_errhandling & MATH_ERREXCEPT ? "on" : "of") << '\n';
	// ������� �������
	std::feclearexcept(FE_ALL_EXCEPT);
	errno = 0;
	// ������� �������� ������ �������
	cout << "log(0) = " << log(0) << '\n';
	// ����� errno

	if (errno == ERANGE)
		std::cout << "errno = ERANGE (" << strerror (errno) << ")\n";
	// ����� ������� ������ ��� �������
	if (fetestexcept(FE_DIVBYZERO))
		cout << "FE_DIVBYZERO (pole error) is generated\n";


	
	feclearexcept(FE_ALL_EXCEPT);
	// ������������� ��������� �������
	THROW(0);
	if (fetestexcept(FE_OVERFLOW)) cout <<"FE_OVERFLOW is on \n";

	// ����������� ����� ��� ���������
	int e = fetestexcept(FE_ALL_EXCEPT);

	cout << "The following exceptions are set: ";
	DETECT(FE_DIVBYZERO); DETECT(FE_INEXACT); DETECT(FE_INVALID);
	DETECT(FE_OVERFLOW); DETECT(FE_UNDERFLOW);
	/*if (e & FE_DIVBYZERO) cout << "FE_DIVBYZERO ";
	if (e & FE_INEXACT)   cout << "FE_INEXACT ";
	if (e & FE_INVALID)   cout << "FE_INVALID ";
	if (e & FE_OVERFLOW)  cout << "FE_OVERFLOW ";
	if (e & FE_UNDERFLOW) cout << "FE_UNDERFLOW ";*/


	system("pause");
}
