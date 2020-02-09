int F(int);

int main(){
  // згенерується виключення "exception int"
  F(10);
}

int F(int i) {
    // генерація виключень типу char*
    if (i)  throw "exeption int";
    else throw "exeption zero";
    // генерація виключень типу int
    throw i;
    return 10;
}
