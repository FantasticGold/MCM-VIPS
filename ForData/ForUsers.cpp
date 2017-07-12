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
  int n = 100;
  while (ifstm) {
    if (--n) {
      ifstm >> u_id >> spu_id >> action_type >> date;
      ++click[u_id];
      if (action_type == 1) {
        ++buy[u_id];
      }
      n = 100000000;
    }
    ifstm.ignore(1024, '\n');
  }
  ifstm.close();

  ofstm.open("../NewData/users_click_data.txt");
  for (auto iter: click) {
    ofstm << "User: " << iter.first << "   Click: " << iter.second << endl;
  } 
  ofstm.close();

  
  ofstm.open("../NewData/users_buy_data.txt");
  for (auto iter: buy) {
    ofstm << "User: " << iter.first << "   Buy: " << iter.second << endl;
  } 
  ofstm.close();

  return 0;
}