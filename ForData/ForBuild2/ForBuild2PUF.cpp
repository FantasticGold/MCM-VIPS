#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <map>
#include <cmath>

void simplify();
void preprocess();
void judge();
void count();
void weight();
void PU();

void simplify() {
  std::ifstream data;
  std::ofstream action_data;

  data.open("../../../Data/user_action_train.txt");
  action_data.open("../../../NewData/build2/user_action.txt");
  int user, good, action;
  while (1) {
    data >> user >> good >> action;
    data.ignore(1024, '\n');
    if (!data) {
      break;
    }
    if (action) {
      action_data << user << ' ' << good << std::endl;
    }
  }
  data.close();
  action_data.close();

  return;
}
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
  delete str;
  
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
void weight() {
  std::ifstream data;

  data.open("../../../Data/goods_train.txt");
  std::map<int, int> m_brand;
  std::map<int, int> m_category;
  int good, brand, category;
  while (1) {
    data >> good >> brand >> category;
    if (!data) {
      break;
    }
    m_brand[good] = brand;
    m_category[good] = category;
  }
  data.close();

  data.open("../../../NewData/build2/user_action.txt");
  std::map<int, std::map<int, int> > m_user_brand;
  std::map<int, std::map<int, int> > m_user_category;
  int user;
  while (1) {
    data >> user >> good;
    if (!data) {
      break;
    }
    ++m_user_brand[user][m_brand[good]];
    ++m_user_category[user][m_category[good]];
  }
  data.close();

  std::ofstream brand_data;
  std::ofstream category_data;

  data.open("../../../Data/user_action_test_items.txt");
  brand_data.open("../../../NewData/build2/user_brand_number.txt");
  category_data.open("../../../NewData/build2/user_category_number.txt");

  while (1) {
    data >> user >> good;
    if (!data) {
      break;
    }
    brand_data << m_user_brand[user][m_brand[good]] << std::endl;
    category_data << m_user_category[user][m_category[good]] << std::endl;
  }

  data.close();
  brand_data.close();
  category_data.close();

  std::ifstream category_number_data;
  category_number_data.open("../../../NewData/build2/category_number.txt");
  std::map<int, int> m_category_number;
  int number;
  while (1) {
    category_number_data >> category >> number;
    if (!category_number_data) {
      break;
    }
    m_category_number[category] = number;
  }
  category_number_data.close();

  std::ofstream weight_data;
  data.open("../../../Data/user_action_test_items.txt");
  weight_data.open("../../../NewData/build2/user_weight.txt");
  
  int sum;
  while (1) {
    data >> user >> good;
    if (!data) {
      break;
    }
    sum = 0;
    for (auto i: m_user_category[user]) {
      sum += m_category_number[i.first];
    }
    weight_data << sum << std::endl;
  }

  data.close();
  weight_data.close();

  return;
}
void PU() {
  std::ifstream data;
  std::ifstream weight_data;
  std::ifstream good_data;
  std::ifstream brand_data;
  std::ifstream category_data;
  std::ifstream user_brand_data;
  std::ifstream user_category_data;
  std::ofstream pu_data;

  data.open("../../../NewData/build2/good_number.txt");
  double w;
  data >> w;
  data.close();

  brand_data.open("../../../NewData/build2/brand_number.txt");
  category_data.open("../../../NewData/build2/category_number.txt");
  std::map<int, double> m_brand;
  std::map<int, double> m_category;
  int brand, category;
  double number;
  while (1) {
    brand_data >> brand >> number;
    if (!brand_data) {
      break;
    }
    m_brand[brand] = number;
  }
  while (1) {
    category_data >> category >> number;
    if (!category_data) {
      break;
    }
    m_category[category] = number;
  }
  brand_data.close();
  category_data.close();

  good_data.open("../../../Data/goods_train.txt");
  std::map<int, double> m_good_brand;
  std::map<int, double> m_good_category;
  int good;
  while (1) {
    good_data >> good >> brand >> category;
    if (!good_data) {
      break;
    }
    m_good_brand[good] = m_brand[brand];
    m_good_category[good] = m_category[category];
  }
  good_data.close();

  data.open("../../../Data/user_action_test_items.txt");
  weight_data.open("../../../NewData/build2/user_weight.txt");
  user_brand_data.open("../../../NewData/build2/user_brand_number.txt");
  user_category_data.open("../../../NewData/build2/user_category_number.txt");
  pu_data.open("../../../NewData/build2/pu.txt");
  int user;
  double weight, user_brand, user_category;
  double i, x, y;
  while (1) {
    data >> user >> good;
    weight_data >> weight;
    user_brand_data >> user_brand;
    user_category_data >> user_category;
    if (!data) {
      break;
    }
    i = weight / w;
    x = pow((1 + user_brand / m_good_brand[good]), user_brand);
    y = pow((user_category / m_good_category[good]), user_category);
    pu_data << std::fixed << std::setprecision(3) << (i * x * y) << std::endl;
  }
  data.close();
  weight_data.close();
  user_brand_data.close();
  user_category_data.close();
  
  return;
}