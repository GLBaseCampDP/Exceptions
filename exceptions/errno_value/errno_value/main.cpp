#include <iostream>
#include <cstring>
//#include <string>
#include <cerrno>
#include <fstream>
#define MES(S) std::cout << S << ": " << \
    std::strerror(errno) << std::endl;

// errno і поширення винятків
void OpenFile(const std::string & filename) {
  errno = 0;
  std::ofstream file;
  file.exceptions(std::ifstream::goodbit); // Don't throw
  file.open(filename,
   (std::fstream::in | std::fstream::binary));

  if (!file.is_open() || !file.good()) {
//const char * error = strerror(errno);
    MES("Open File (string)");
    throw errno;
  }
}
void OpenFile() {
  try {
    std::ofstream file;
    file.exceptions(std::ios::badbit |
      std::ios::failbit);
    file.open("C:\\A.txt");
  }
  catch (const std::ios_base::failure& e) {
    MES("Open File ()");
  }
}

// errno і блок try
int main() {
  try {
    OpenFile("C:\\A.txt");
  }
  catch (char*) {}

  errno = 0;
  OpenFile();
}
