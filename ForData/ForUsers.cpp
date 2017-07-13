/*
  Input:
    user_action_train.txt  (The data of users's actions)
  Output:
    users_click_data.txt  (The number of goods that users clicked)
    users_buy_data.txt  (The number of goods that users bought)
*/
#include <iostream>
#include <fstream>
using std::endl;
using std::string;
#include <map>

int main(void) {
  std::ofstream ofstm;
  std::ifstream ifstm;

  //Initialize
  ifstm.open("../../Data/user_action_train.txt");
  std::map<int, int> click, buy;
  int u_id, spu_id, action_type;
  string date;
  int n = 10;
  while (ifstm) {
    if (--n) {
      ifstm.ignore(1024, '\n');
      continue;
    }
    ifstm >> u_id >> spu_id >> action_type;
    ++click[u_id];
    if (action_type == 1) {
      ++buy[u_id];
    }
    n = 10;
  }
  ifstm.close();

  ofstm.open("../../NewData/user_click_data.txt");
  for (auto iter: click) {
    ofstm << iter.first << ' ' << iter.second << endl;
  } 
  ofstm.close();

  
  ofstm.open("../../NewData/user_buy_data.txt");
  for (auto iter: buy) {
    ofstm << iter.first << ' ' << iter.second << endl;
  } 
  ofstm.close();

  return 0;
}