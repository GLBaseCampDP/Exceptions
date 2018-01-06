// ErrnoInC++.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#include <cstring> 
#include <cerrno>
#include <fstream>
#define MES(S) char error[256];\
strerror_s(error, 255, errno);\
std::cout << S << ": " << error << std::endl;

// errno і поширення винятків
void OpenFile(const std::string & filename)
{
	
	errno = 0;
	std::ofstream file;
	file.exceptions(0); // Don't throw
	file.open(filename, (std::fstream::in | std::fstream::binary));

		if (!file.is_open() || !file.good())
		{
			//const char * error = strerror(errno);
			MES("Open File (string)");
			throw error;

		}
	
}

void OpenFile()
{
	try {
		std::ofstream file;
		file.exceptions(std::ios::badbit | std::ios::failbit);
		file.open("C:\\A.txt");
	}
	catch (const std::ios_base::failure& e) {
		MES("Open File ()");
	}
}

// errno і блок try
void main() {

	try
	{
		OpenFile("C:\\A.txt");
	}
	catch (char*) {}

	errno = 0;
	OpenFile();

	system("pause");
}