/*
  Suppose p
  Suppose all the value is as follow: 0, 0.001, 0.002, ... , 0.998, 0.999, 1
  Suppose the error lead to the difference that is <p>
  s = ((1 - p) * ((1 - p) / 2)^2 + p * p^2)^0.5
*/
#include <iostream>
#include <fstream>
#include <cmath>

int main(void) {
  std::ofstream data("../../../NewData/build4/analysis2.txt");
  data << "For each <p> the <s> is as follow:\n";
  for (double p = 0; p <= 1; p += 0.001) {
    data << "For p = " << p << ", s = "
      << sqrt((1 - p)*(1 - p)*(1 - p) / 4 + p*p*p) << std::endl;
  }
  return 0;
}