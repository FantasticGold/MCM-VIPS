/*
  Suppose min, max, p
  Then s = ((1 - p) * min^2 + p * max^2)^0.5
*/
#include <iostream>
#include <fstream>

int main(void) {
  std::ofstream data("../../../NewData/build4/analysis.txt");
  for (double bound = 0.4; bound >= 0.1; bound -= 0.1) {
    data << "For each value of <min>, to satisfy s <= " << bound
      << ", the proportion of error <p> is as follow:\n";
    for (double min = 0, max; min < bound; min += 0.01) {
      max = 1 - min;
      data << "For min = " << min << ", p <= "
        << (bound*bound - min*min) / (max*max - min*min) << std::endl;
    }
    data << std::endl;
  }
  data.close();

  return 0;
}