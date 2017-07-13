#include <iostream>
#include <fstream>
#include <map>

void countGoods();
void initializeGoods();
void predictGoods();

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

void initializeGoods() {
  std::ifstream data;
  std::ifstream brand_data;
  std::ifstream category_data;
  std::ofstream good_data;

  brand_data.open("../../../NewData/build2/build2_brand_number");
  category_data.open("../../../NewData/build2/build2_category_number");
  std::map<int, int> num_brand;
  std::map<int, int> num_category;
  int brand, category, num;
  while (brand_data) {
    brand_data >> brand >> num;
    num_brand[brand] = num;
  }
  while (category_data) {
    category_data >> category >> num;
    num_category[category] = num;
  }
  brand_data.close();
  category_data.close();
  
  data.open("../../../Data/goods_train.txt");
  good_data.open("../../../NewData/build2/build2_good");
  std::map<int, int> good_brand;
  std::map<int, int> good_category;
  int n, b, c;
  while (data) {
    data >> n >> b >> c;
    good_data << n << ' ' << num_brand[b] << ' ' << num_category[c] << std::endl;
  }
  data.close();
  good_data.close();

  return;
}

void predictGoods() {
  std::ifstream good_data;
  std::ifstream data;
  std::ofstream predict_data;
  
  std::map<int, int> brand, category;
  good_data.open("../../../NewData/build2/build2_good");
  int n, b, c;
  while (good_data) {
    good_data >> n >> b >> c;
    brand[n] = b;
    category[n] = c;
  }
  good_data.close();

  int user, good;
  data.open("../../../Data/user_action_test_items.txt");
  predict_data.open("../../../NewData/build2/build2_user_brand");
  while (data) {
    data >> user >> good;
    predict_data << user << ' ' << brand[good] << std::endl;
  }
  predict_data.close();
  data.close();

  data.open("../../../Data/user_action_test_items.txt");
  predict_data.open("../../../NewData/build2/build2_user_category");
  while (data) {
    data >> user >> good;
    predict_data << user << ' ' << category[good] << std::endl;
  }
  predict_data.close();
  data.close();

  return;
}

