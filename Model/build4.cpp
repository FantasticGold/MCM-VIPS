#include <iostream>
#include <fstream>

int main(void) {
  std::ofstream test("../../Prediction/p3.txt");

  int n = 5761092;
  while (n--) {
    test << "0.000\n";
  }

  return 0;
}