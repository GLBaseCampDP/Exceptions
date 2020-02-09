struct A { int i; };

// обмеження генерації виключень лише типом A
// усі спроби згенерувати виключення не типу А
// приведуть до аварійного завершення
int F(int i) throw (A){
  switch (i)
  {
    case 0: throw " exception char* "; break;
    case 1: throw A(); break;
   default: throw i;
}
}

int main() {
// спроба згенерується недопустиме виключення
int i = F(0);
}
