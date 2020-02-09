#include<iostream>
int main() {
  try  {
    try {
      throw 1;
    }
    catch (int i) {
      std::cout << "Exception";
    // Поширення виключення
    // через генерацію нового
      throw i;
      // Поширення існуючого виключення
             throw ;
         }
       }
       catch (double i) {
         std::cout << "Double Exception ";
       }
       catch (int i) {
         std::cout << "Int Exception ";
       }
}
