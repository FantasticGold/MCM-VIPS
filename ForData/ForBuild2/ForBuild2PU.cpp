#include "ForBuild2PUF.cpp"
#include <cstdio>

int main(void) {
  // std::cerr << "Waiting: preprocess\n";
  // preprocess();
  
  // std::cerr << "Waiting: judge\n";
  // judge();
  
  std::cerr << "Waiting: count\n";
  count();

  char ch;
  do {
    std::cout << "Please press [Enter] to continue:\n";
  } while ((ch = getchar()) != '\n');

  return 0;
}