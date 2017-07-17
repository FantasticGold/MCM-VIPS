#include <iostream>
#include <fstream>
#include <iomanip>

int main(void) {
  std::ifstream data;
  std::ofstream predict_data;

  data.open("../../NewData/build2/pu.txt");
  predict_data.open("../../Prediction/p2.txt");
  double user;
  while (1) {
    data >> user;
    if (!data) {
      break;
    }
    predict_data << std::fixed << std::setprecision(3) << user << std::endl;
  }
  data.close();
  predict_data.close();

  return 0;
}