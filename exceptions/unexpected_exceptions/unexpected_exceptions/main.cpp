#include <iostream>
#include <exception>

struct A { };
void ExceptThrow() throw (A) {
  throw 1;
}
void my_unexpected() {
  std::cout << "Uncaught Exception \n";
  throw 'a';
}
int main() {
  std::set_unexpected(my_unexpected);
  try {
    ExceptThrow();
  }
  catch (A&) {}
  catch (char) {
     std::cout << "Char Exception\n";
  }
catch (...) {}
}
