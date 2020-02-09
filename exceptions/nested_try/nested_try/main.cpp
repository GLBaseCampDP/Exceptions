#include <iostream>
using namespace  std;
// генератор виключень
void F(int i) {
  switch (i){
    case 0: throw "string Exeption"; break;
    case 1: throw double(i); break;
    case 2: throw i; break;
  }
}

int main() {
  try {
    try {
      F(2);
    }
// обробник внутрішного блока try
    catch (const char *c) {
      cout << "inside TRY-Blok " << "\n" <<
              c << "\n";
     }
 // генерація КС у зовнішньому блоці
     throw 1;
   }
 // обробники зовнішнього блока try
   catch (double) {
     cout << "outside TRY-Blok " << "\n" <<
             "double Exeption" << "\n";
   }
   catch (int) {
     cout << "outside TRY-Blok " << "\n " <<
             "int Exeption" << "\n";
   }
   catch (...) {
     cout << "outside TRY-Blok " << "\n " <<
             "ALL Exeption" << "\n";
   }
 }
