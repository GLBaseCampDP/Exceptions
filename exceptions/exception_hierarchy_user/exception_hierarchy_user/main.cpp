#include<iostream>
struct errBase {   int i;
  errBase() { i = 0; message(); }
  errBase(int j) : i(j){}
  void message() {
    std::cout << " Base Exception with value: "
      << i << "\n";
  }
};
struct errDer : public errBase {   int i;
  errDer() :errBase() { i = 0; message(); }
  errDer(int j1, int j2) :errBase(j1), i(j2){}
  void message() {
    std::cout << " Derivate Exception with value:"
      << i << "\n";
  }
};

struct A {
    A(int i, int j){
      if (i) throw errBase(i);
      if (j) throw errDer(i, j);
    }
  };

int main(){
    try {
      A a(0, 2);
    }
    catch (errBase& er){
      er.message();
    }
    catch (errDer& er){
      er.message();
    }
}
