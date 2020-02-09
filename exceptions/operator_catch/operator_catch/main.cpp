#include <iostream>

struct A{
  int i;
};

// ф-я генерує і обробляє виключення
int F(int i) {
  try {
    switch (i) {
      case 0:
        throw " exception char* "; break;
      case 1: throw A(); break;
      case 2: throw i; break;
      default: throw 3.14;
    }
  }
  // обробник рядк. виключень
  catch (const char *c){
        std::cout << c;
  }
  // обробник усіх виключень класу А
  catch (A) {
        std::cout << "exception A";
  }
  // обробник усіх виключень цілого типу
  catch (int) {
        std::cout << "exception int";
  }
}

int main() {
      F(0);
}
