#include <iostream>
#include <fstream>
#include <iomanip>
using std::endl;
using std::string;

int main(void) {
  std::ofstream predict;
  std::ifstream records;
  std::ifstream users;

  records.open("../../NewData/user_buy_data.txt");
  users.open("../../Data/user_action_test_items.txt");
  predict.open("../../Prediction/p1.txt");
  int u_id, spu_id;
  double nums[100000] = {0};
  int n = 10000000;
  while (n--) {
    records >> u_id;
    records.ignore(1024, '\n');
    nums[u_id / 100] += 0.01;
  }
  int m = 10000;
  while (users) {
    users >> u_id >> spu_id;
    predict << std::fixed << std::setprecision(3) << nums[u_id / 100] << ' ';
  }
  records.close();
  users.close();
  predict.close();

  return 0;
}