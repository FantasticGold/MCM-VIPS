#include "ForBuild2PUF.cpp"
#include <cstdio>

int main(void) {
  // std::cout << "Waiting: preprocess\n";
  // preprocess();
  
  std::cout << "Waiting: judge\n";
  judge();

  char ch;
  do {
    std::cout << "Please press [Enter] to continue:\n";
  } while ((ch = getchar()) != '\n');

  return 0;
}