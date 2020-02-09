//Новий обробник неперухопленого виключення
#include <iostream>
#include <stdexcept>

void my_terminate() {
  std::cout << "Program will be terminate";
  exit(1);
}

void ExceptThrow(bool yes) {
  if (yes) throw;
}

int main() {
 std::set_terminate(my_terminate);
 ExceptThrow(true);
}
