#include <iostream>
#include <fstream>
#include <cstdio>
#include <map>

void preprocess();
void judge();
void count();

void preprocess() {
  std::ifstream data;
  std::ofstream user_data;
  std::ofstream good_data;

  data.open("../../../Data/user_action_test_items.txt");
  user_data.open("../../../NewData/build2/user.txt");
  good_data.open("../../../NewData/build2/good.txt");

  int user, good;
  while (1) {
    data >> user >> good;
    if (!data) {
      break;
    }
    user_data << user << std::endl;
    good_data << good << std::endl;
  }

  data.close();
  user_data.close();
  good_data.close();

  return;
}
void judge() {
  std::ifstream data;
  std::ofstream brand_data;
  std::ofstream category_data;

  data.open("../../../Data/goods_train.txt");
  std::map<int, int> m_brand;
  std::map<int, int> m_category;
  int good, brand, category;
  while (data) {
    data >> good >> brand >> category;
    m_brand[good] = brand;
    m_category[good] = category;
  }
  data.close();

  data.open("../../../NewData/build2/good.txt");
  data.seekg(0, std::ios::end);
  int len = data.tellg();
  data.close();

  brand_data.open("../../../NewData/build2/brand.txt");
  category_data.open("../../../NewData/build2/category.txt");

  char* str = new char[len + 1];
  FILE* fp = fopen("../../../NewData/build2/good.txt", "r");
  fread(str, 1, len, fp);
  int num = 0;
  int sum = 0;
  for (int i = 0; i < len; ++i) {
    if (str[i] == '\n') {
      ++sum;
      if (sum == 5761093) {
        break;
      }
      brand_data << m_brand[num] << std::endl;
      category_data << m_category[num] << std::endl;
      num = 0;
    } else {
      num = 10 * num + str[i] - '0';
    }
  }
  fclose(fp);
  
  brand_data.close();
  category_data.close();

  return;
}
void count() {
  std::ifstream data;
  std::ofstream brand_number;
  std::ofstream category_number;
  std::ofstream good_number;

  data.open("../../../Data/goods_train.txt");
  std::map<int, int> m_brand;
  std::map<int, int> m_category;
  int good, brand, category;
  int sum = 0;
  while (1) {
    data >> good >> brand >> category;
    if (!data) {
      break;
    }
    ++m_brand[brand];
    ++m_category[category];
    ++sum;
  } 
  data.close();

  good_number.open("../../../NewData/build2/good_number.txt");
  good_number << sum << std::endl;
  good_number.close();

  brand_number.open("../../../NewData/build2/brand_number.txt");
  category_number.open("../../../NewData/build2/category_number.txt");

  for (auto i: m_brand) {
    brand_number << i.first << ' ' << i.second << std::endl;
  }
  for (auto i: m_category) {
    category_number << i.first << ' ' << i.second << std::endl;
  }

  brand_number.close();
  category_number.close();

  return;
}
