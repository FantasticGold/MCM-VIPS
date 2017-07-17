#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <map>
#include <set>
#include <cmath>

void preprocess();
void count();
void weight();
void PG();

void preprocess() {
  std::ifstream data;
  std::ofstream user_data;

  data.open("../../../NewData/build2/user_action.txt");
  user_data.open("../../../NewData/build2/user_number.txt");
  std::set<int> user_number;
  int user;
  while (1) {
    data >> user;
    data.ignore(1024, '\n');
    if (!data) {
      break;
    }
    user_number.insert(user);
  }
  user_data << user_number.size() << std::endl;
  data.close();
  user_data.close();

  return;
}
void count() {
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
  int user;
  std::map<int, int> m_user_brand;
  std::map<int, int> m_user_category;
  while (1) {
    data >> user >> good;
    if (!data) {
      break;
    }
    ++m_user_brand[m_brand[good]];
    ++m_user_category[m_category[good]];
  }
  data.close();

  std::ofstream brand_data;
  std::ofstream category_data;

  data.open("../../../Data/user_action_test_items.txt");
  brand_data.open("../../../NewData/build2/brand_user_number");
  category_data.open("../../../NewData/build2/category_user_number");
  while (1) {
    data >> user >> good;
    if (!data) {
      break;
    }
    brand_data << m_user_brand[m_brand[good]] << std::endl;
    category_data << m_user_category[m_category[good]] << std::endl;
  }
  data.close();
  brand_data.close();
  category_data.close();

  return;
}
void weight() {
  std::ifstream data;

  data.open("../../../NewData/build2/user_action.txt");
  std::map<int, std::set<int> > m_user;
  std::map<int, int> m_user_good;
  int user, good;
  while (1) {
    data >> user >> good;
    if (!data) {
      break;
    }
    m_user[good].insert(user);
    ++m_user_good[user];
  }
  data.close();

  std::ofstream weight_data;
  data.open("../../../Data/user_action_test_items.txt");
  weight_data.open("../../../NewData/build2/good_weight.txt");
  int sum;
  while (1) {
    data >> user >> good;
    if (!data) {
      break;
    }
    sum = 0;
    for (auto i: m_user[good]) {
      sum += m_user_good[i];
    }
    weight_data << sum << std::endl;
  }
  weight_data.close();

  return;
}
void PG() {
  std::ifstream data;
  std::ifstream weight_data;
  std::ifstream brand_data;
  std::ifstream category_data;
  std::ifstream brand_user_data;
  std::ifstream category_user_data;
  std::ofstream pg_data;

  data.open("../../../NewData/build2/good_number.txt");
  double w;
  data >> w;
  data.close();
  data.open("../../../NewData/build2/user_number.txt");
  double v;
  data >> v;
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

  data.open("../../../Data/user_action_test_items.txt");
  weight_data.open("../../../NewData/build2/good_weight.txt");
  brand_data.open("../../../NewData/build2/brand.txt");
  category_data.open("../../../NewData/build2/category.txt");
  brand_user_data.open("../../../NewData/build2/brand_user_number.txt");
  category_user_data.open("../../../NewData/build2/category_user_number.txt");
  pg_data.open("../../../NewData/build2/pg.txt");
  int user, good;
  double weight, brand_user, category_user;
  double i, x, y;
  while (1) {
    data >> user >> good;
    weight_data >> weight;
    brand_data >> brand;
    category_data >> category;
    if (!data) {
      break;
    }
    i = weight / w;
    x = pow((1 + m_brand[brand] * brand_user / v), brand_user);
    y = pow((1 + m_category[category] * category_user / v), category_user);
    pg_data << std::fixed << std::setprecision(3) << (i * x * y) << std::endl;
  }
  data.close();
  weight_data.close();
  brand_data.close();
  category_data.close();
  brand_user_data.close();
  category_user_data.close();
  pg_data.close();

  return;
}