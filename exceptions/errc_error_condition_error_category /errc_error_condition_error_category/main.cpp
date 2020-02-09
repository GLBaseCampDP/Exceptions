#include <iostream>
#include <system_error>
#include <iostream>
#include <string>

#define DIVIDE_BY_ZERO -3
using namespace std;

#define OUT(catg, er) my_cond = \
   catg().default_error_condition(er);\
   cout << "Category: " << \
   my_cond.category().name() << '\n'\
   << "Value: " << my_cond.value() << '\n'\
   << "Message: " << my_cond.message() << '\n';

int main() {
  error_condition my_cond;
  OUT(system_category, DIVIDE_BY_ZERO);
  OUT(system_category, E2BIG);
  OUT(generic_category, E2BIG);

  error_condition a(errc::file_exists);
  error_condition b(EEXIST,
      generic_category());

  if (a == b)
    cout << "Yes message - " << a.message();
}
