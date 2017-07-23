#include <iostream>
#include <fstream>
#include <cmath>

int main(void) {
  char ch;
  double m, s, p;
  do {
    std::cout << "-> s = ((1 - p) * m^2 + p * (1 - m)^2)^0.5\n";
    std::cout << "Please enter [1] to calculate p, "
      << "[2] to calculate s, [q] to quit\n";
    std::cin.get(ch);
    switch (ch) {
      case '1':
        std::cout << "Please enter m:\n";
        std::cin >> m;
        std::cout << "Please enter s:\n";
        std::cin >> s;
        if (m >= 0.5 || s <= m) {
          std::cout << "It is impossible.\n";
        }
        std::cout << "m = " << m << ", s = " << s
          << ", p = " << (s*s - m*m)/((1 - m)*(1 - m) - m*m);
        break;
      case '2':
        std::cout << "Please enter m:\n";
        std::cin >> m;
        std::cout << "Please enter p:\n";
        std::cin >> p;
        std::cout << "m = " << m << ", p = " << p
          << ", s = " << sqrt((1 - p) * m*m + p * (1 - m)*(1 - m));
        break;
      default:
        break;
    }
    std::cin.get();
    std::cout << std::endl;
  } while (ch != 'q');
  data.close();

  return 0;
}