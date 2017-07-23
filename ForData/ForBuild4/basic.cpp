#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <utility>

int main(void) {

  std::cerr << "Waiting good data......\n";
  std::ifstream data_good("../../../Data/goods_train.txt");
  std::ofstream data_brand_number("../../../NewData/build4/brand_number.txt");
  std::ofstream data_category_number("../../../NewData/build4/category_number.txt");

  std::map<int, int> m_brand;
  std::map<int, int> m_category;
  std::map<int, int> m_brand_number;
  std::map<int, int> m_category_number;
  int good, brand, category;
  while (true) {
    data_good >> good >> brand >> category;
    if (!data_good) {
      break;
    }
    ++m_brand_number[brand];
    ++m_category_number[category];
    m_brand[good] = brand;
    m_category[good] = category;
  }
  for (auto i: m_brand_number) {
    data_brand_number << i.first << ' ' << i.second << std::endl;
  }
  for (auto i: m_category_number) {
    data_category_number << i.first << ' ' << i.second << std::endl;
  }

  data_good.close();
  data_brand_number.close();
  data_category_number.close();
  std::cerr << std::endl;

  std::cerr << "Waiting user data......\n";
  std::ifstream data_user("../../../Data/user_action_train.txt");
  std::ofstream data_user_bought("../../../NewData/build4/user_bought.txt");
  std::ofstream data_user_clicked("../../../NewData/build4/user_clicked.txt");
  std::ofstream data_good_bought("../../../NewData/build4/good_bought.txt");
  std::ofstream data_good_clicked("../../../NewData/build4/good_clicked.txt");
  
  std::map<int, int> m_user_bought;
  std::map<int, int> m_user_clicked;
  std::map<int, int> m_good_bought;
  std::map<int, int> m_good_clicked;
  std::map<int, std::set<int> > m_user_bought_brand;
  std::map<int, std::set<int> > m_user_bought_category;
  int user, action;
  std::string date;
  while (true) {
    data_user >> user >> good >> action >> date;
    if (!data_user) {
      break;
    }
    ++m_user_clicked[user];
    ++m_good_clicked[good];
    if (action) {
      ++m_user_bought[user];
      ++m_good_bought[good];
      m_user_bought_brand[user].insert(m_brand[good]);
      m_user_bought_category[user].insert(m_category[good]);
    }
  }
  for (auto i: m_user_clicked) {
    data_user_clicked << i.first << ' ' << i.second << std::endl;
  }
  for (auto i: m_good_clicked) {
    data_good_clicked << i.first << ' ' << i.second << std::endl;
  }
  for (auto i: m_user_bought) {
    data_user_bought << i.first << ' ' << i.second << std::endl;
  }
  for (auto i: m_good_bought) {
    data_good_bought << i.first << ' ' << i.second << std::endl;
  }

  data_user.close();
  data_user_bought.close();
  data_user_clicked.close();
  data_good_bought.close();
  data_good_clicked.close();
  std::cerr << std::endl;

  std::cerr << "Waiting test data......\n";
  std::ifstream data_test("../../../Data/user_action_test_items.txt");
  std::ofstream data_user_bought_brand("../../../NewData/build4/user_bought_brand.txt");
  std::ofstream data_user_bought_category("../../../NewData/build4/user_bought_category.txt");

  while (true) {
    data_test >> user >> good;
    if (!data_test) {
      break;
    }
    data_user_bought_brand << m_user_bought_brand[user].size() << std::endl;
    data_user_bought_category << m_user_bought_category[user].size() << std::endl;
  }

  data_user_bought_brand.close();
  data_user_bought_category.close();
  std::cerr << std::endl;

  return 0;
}