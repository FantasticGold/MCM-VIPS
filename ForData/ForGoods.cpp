#include <iostream>
#include <fstream>
using std::endl;
using std::string;
#include <map>
#include <utility>

int main(void) {
  std::ofstream ofstm;
  std::ifstream ifstm;

  //Initialize
  ifstm.open("../../Data/goods_train.txt");
  std::map<string, std::pair<string, string> > m;
  string spu_id, brand_id, cat_id;
  while (ifstm) {
    ifstm >> spu_id >> brand_id >> cat_id;
    m[spu_id] = std::make_pair(brand_id, cat_id);
  }
  ifstm.close();

  // // Count
  // ofstm.open("../NewData/goods_brand_data.txt");
  // std::map<string, int> m2, m3;
  // for (auto iter: m) {
  //   ++m2[iter.second.first];
  //   ++m3[iter.second.second];
  // }
  // for (auto iter: m2) {
  //   ofstm << "Brand: " << iter.first << "   Goods: " << iter.second << endl;
  // }
  // ofstm.close();
  // ofstm.open("../NewData/goods_category_data.txt");
  // for (auto iter: m3) {
  //   ofstm << "Category: " << iter.first << "   Goods: " << iter.second << endl;
  // }
  // ofstm.close();
  
  return 0;
}