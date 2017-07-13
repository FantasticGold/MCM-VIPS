#include <iostream>
#include <fstream>
#include <map>

void countGoods();
void countGoods() {
  std::ifstream data;
  std::ofstream new_data;

  data.open("../../../Data/goods_train.txt");
  std::map<int, int> num_brand;
  std::map<int, int> num_category;
  int brand, category;
  int sum = 0;
  while (data) {
    data.ignore(1024, '\t');
    data >> brand >> category;
    ++num_brand[brand];
    ++num_category[category];
    ++sum;
  }
  data.close();

  new_data.open("../../../NewData/build2/build2_brand_number");
  for (auto iter: num_brand) {
    new_data << iter.first << ' ' << iter.second << std::endl;
  }
  new_data.close();
  
  new_data.open("../../../NewData/build2/build2_category_number");
  for (auto iter: num_category) {
    new_data << iter.first << ' ' << iter.second << std::endl;
  }
  new_data.close();
  
  new_data.open("../../../NewData/build2/build2_goods_number");
  new_data << sum << std::endl;
  new_data.close();

  return;
}