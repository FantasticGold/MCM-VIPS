#include <iostream>
#include <fstream>
using std::endl;
using std::string;

int main(void) {
  std::ofstream ofstm;
  std::ifstream ifstm;
  
  //Initialize
  ifstm.open("../../Data/user_action_train.txt");
  ofstm.open("../../NewData/buy_data.txt");
  int buy;
  while (ifstm) {
    ifstm.ignore(1024, '\t');
    ifstm.ignore(1024, '\t');
    ifstm >> buy;
    ofstm << buy << ' ';
    ifstm.ignore(1024, '\n');
  }
  ifstm.close();
  ofstm.close();

  // Count
  std::ifstream buys;
  std::ifstream users;
  //int buy;
  char c;
  int u_id, spu_id;
  buys.open("../../NewData/buy_data.txt");
  users.open("../../Data/user_action_train.txt");
  ofstm.open("../../NewData/user_buy.txt");
  while (buys) {
    buys >> buy;
    if (buy) {
      do {
        users.get(c);
        ofstm << c;
      } while (c != '\t');
      do {
        users.get(c);
        ofstm << c;
      } while (c != '\t');
      users.ignore(1024, '\t');
      do {
        users.get(c);
        ofstm << c;
      } while (c != '\n');
    }
  }
  buys.close();
  users.close();
  ofstm.close();

  return 0;
}