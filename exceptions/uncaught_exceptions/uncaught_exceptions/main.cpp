#include <iostream>
#include <exception>
struct A {
  int i;
  ~A(){
      if (std::uncaught_exception())
         std::cout << "Yes\n";
  }
};

int main() {
  try{
    A a;
    throw 1;
  }
  catch (...){
    std::cout << "Universal soldier";
  }
}
