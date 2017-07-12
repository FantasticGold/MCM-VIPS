#include <iostream>
#include <fstream>
using std::endl;
using std::string;
#include <map>
#include <set>

int main(void) {
  std::ofstream predict;
  std::ifstream records;
  std::ifstream users;

  records.open("../NewData/user_buy.txt");
  users.open("../../Data/user_action_test_items.txt");
  predict.open("../Prediction/p2.txt");

  int u_id, spu_id;
  std::map<int, std::set<int> > m;
  while (records) {
    records >> u_id >> spu_id;
    records.ignore(1024, '\n');
    m[u_id].insert(spu_id);
  }
  while (users) {
    users >> u_id >> spu_id;
    if (m[u_id].count(spu_id)) {
      predict << '0';
    } else {
      predict << "0.5";
    }
    predict << ' ';
  }

  records.close();
  users.close();
  predict.close();

  return 0;
}