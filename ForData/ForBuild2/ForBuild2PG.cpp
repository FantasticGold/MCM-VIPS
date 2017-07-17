#include "ForBuild2PGF.cpp"

int main(void) {
  
  // std::cerr << "Waiting: preprocess\n";
  // preprocess();
  
  // std::cerr << "Waiting: count\n";
  // count();
  
  // std::cerr << "Waiting: weight\n";
  // weight();
  
  std::cerr << "Waiting: PG\n";
  PG();

  char ch;
  do {
    std::cout << "Please press [Enter] to continue:\n";
  } while ((ch = getchar()) != '\n');

  return 0;
}