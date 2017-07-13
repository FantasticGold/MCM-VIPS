#include "ForBuild2PUF.cpp"

int main(void) {
  char ch;
  do {
    std::cout << "Please press [Enter] to continue: ";
    std::cin.get(ch);
    std::cout << std::endl;
  } while (ch != '\n');

  return 0;
}