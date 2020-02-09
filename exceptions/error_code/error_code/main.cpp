#include <iostream>
#include <system_error>
#include <iostream>
#include <string>
using namespace std;

enum merr { continue_operation = 100,    	// крок - 1
   switching_operation = 101, break_operation = 102,
   sleep_operation = 103,     forbidden_operation = 104
};

class my_category: public error_category {	// крок - 2
public:
  virtual const char* name() const noexcept 	// крок - a
    { return "operation"; };
  string message(int code) const {		// крок - b
      switch (code) {
       case merr::continue_operation: return " Continue ";
       case merr::switching_operation: return " Switching ";
       case merr::break_operation: return " Break ";
       case merr::sleep_operation:  return " Sleep ";
       case merr::forbidden_operation: return " Forbidden ";
       default: return "Unknown operation error";
      }
  }
  virtual error_condition			 // крок - c
     default_error_condition(int code) const noexcept{
    switch (code) {
    case merr::forbidden_operation:
         return errc::permission_denied;
    default: return error_condition(code, *this);
  }
}
};

const error_category & operation_category() 	 // крок - 3
{  static my_category mct; return mct; }

#define MAKE_ERROR(s) error_##s make_error_##s(merr c) { \
return error_##s(static_cast<int>(c), operation_category());}

MAKE_ERROR(code);				 // крок - 4
MAKE_ERROR(condition);			 // крок - 4

namespace std { template <> 			 // крок - 5
struct is_error_code_enum<merr>: public true_type {}; }

void CallOperation(error_code& er)
{  er = merr::forbidden_operation;}

int main() {				 // крок - 6
error_code er;
CallOperation(er);
if (er == merr::forbidden_operation){ cout << er.message();}
}
