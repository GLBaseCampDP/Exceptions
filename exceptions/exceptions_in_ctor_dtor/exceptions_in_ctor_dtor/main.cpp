#include<iostream>

struct A {
  class B {};
  enum { max = 2000 };
  A(int i) {
    if ((i<0) || (i> max))
      throw A::B();
  }
};

int main() {

  try {
    A* a = new A(300);
  }
  catch (A::B ) {
    std::cout << "Error";
  }
}
