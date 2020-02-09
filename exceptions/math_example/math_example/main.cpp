#include <iostream>
#include <cfenv>
#include <cmath>
#include <cerrno>
#include <cstring>
// #pragma STDC FENV_ACCESS ON for only C++11
using namespace std;
#define DETECT(Exc) if (e & Exc) cout << #Exc << " ";

double THROW(int x) {
 if (x == 0) feraiseexcept(FE_INVALID | FE_OVERFLOW);
 return x*x;
}

int main() {
// перевірка встановлення системи оброки помилок
 cout << "MATH_ERRNO is " <<
(math_errhandling & MATH_ERRNO ? "on":"of")<<'\n'
  << "MATH_ERREXCEPT is " <<
(math_errhandling & MATH_ERREXCEPT ?"on":"of")<<'\n';
// очистка помилок
feclearexcept(FE_ALL_EXCEPT);
errno = 0;
// помилка внаслідок роботи функції
cout << "log(0) = " << log(0) << '\n';
// через errno
if (errno == ERANGE)
cout << "errno = ERANGE ("<<strerror(errno)<< ")\n";
// через систему оброки мат помилок
if (fetestexcept(FE_DIVBYZERO))
 cout << "FE_DIVBYZERO (pole error) is generated\n";
// користувацька генерація помилок
feclearexcept(FE_ALL_EXCEPT);
THROW(0);
if (fetestexcept(FE_OVERFLOW))
  cout <<"FE_OVERFLOW is on \n";
// вичитування стану усіх прапорців
int e = fetestexcept(FE_ALL_EXCEPT);
cout << "The following exceptions are set: ";
DETECT(FE_DIVBYZERO); DETECT(FE_INEXACT);
DETECT(FE_INVALID);
DETECT(FE_OVERFLOW); DETECT(FE_UNDERFLOW);
}
