#include "ForBuild2PUF.cpp"
#include <cstdio>

int main(void) {
  std::cerr << "Waiting: simplify\n";
  simplify();

  std::cerr << "Waiting: preprocess\n";
  preprocess();
  
  std::cerr << "Waiting: judge\n";
  judge();
  
  std::cerr << "Waiting: count\n";
  count();

  std::cerr << "Waiting: weight\n";
  weight();
  
  std::cerr << "Waiting: PU\n";
  PU();

  char ch;
  do {
    std::cout << "Please press [Enter] to continue:\n";
  } while ((ch = getchar()) != '\n');

  return 0;
}