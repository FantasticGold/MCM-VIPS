#include <iostream>
#include <fstream>
#include <iomanip>

int main(void) {
  std::ifstream data("../../NewData/build4/weight2.txt");
  std::ofstream data_predict("../../Prediction/p5.txt");

  double result;
  while (true) {
    data >> result;
    if (!data) {
      break;
    }
    data_predict << std::fixed << std::setprecision(3) << result << std::endl;
  }

  data.close();
  data_predict.close();

  return 0;
}