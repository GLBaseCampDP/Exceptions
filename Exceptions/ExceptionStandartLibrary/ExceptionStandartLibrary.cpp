#include "stdafx.h"

#include <iostream>
#include <exception>
#include <string>
using namespace std;
unsigned cnt = 0;
#define HANDLER_Creator(NAme) void NAme (exception_ptr e){\
  try {\
    if (e) {\
      ::cnt++;\
     rethrow_exception(e);\
   } }

HANDLER_Creator(handler)
catch (...) {
	cerr << "Exception (" << cnt << "): " << "\n";
}
}

HANDLER_Creator(handler2)
catch (exception e) {
	cerr << "Exception (" << cnt << "): " << e.what() << "\n";
}
}
void main() {
	exception_ptr e, e2;
	// обгортання звичайного виключення
	try {
		cnt++;
		throw 1;
	}
	catch (int& i) {
		cout << "Exception (" << cnt << "): " << "\n";
		e = current_exception();
		e2 = make_exception_ptr(e);
	}
	handler(e);   handler(e2);

	// створення копії існуючого
	try {
		cnt++;
		string("abcd").substr(42); // генериться виключення
	}
	catch (exception &ex) {
		cerr << "Exception (" << cnt << "): " << ex.what() << "\n";
		e = current_exception();
		e2 = make_exception_ptr(ex);
	}
	handler2(e);   handler2(e2);
}
