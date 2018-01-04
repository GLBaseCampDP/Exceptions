// ExceptionTree.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include<iostream>
struct errBase {
	int i;
	errBase() { i = 0; message(); }
	errBase(int i) { this->i = i; }
	void message() { 
		std::cout << " Base Exception with value: " << 
			i << "\n"; 
	}
};
struct errDer : public errBase {
	int i;
	errDer() :errBase() { i = 0; message(); }
	errDer(int i, int j) :errBase(j) { this->i = i; }
	void message() { 
		std::cout << " Derivate Exception with value: " << 
			i << "\n"; 
	}
};
struct A {
	A(int i, int j)	{
		if (i) throw errBase(i);
		if (j) throw errDer(i, j);
	}
};

void main(){
	try	{
		A a(0, 2);
	}
	catch (errBase& er)	{
		er.message();
	}
	catch (errDer& er)	{
		er.message();
	}
}

