#include <iostream>
#include <fstream>
#include <map>

int main(void) {

  std::cerr << "Waiting good data......\n";
  std::ifstream data_good("../../../Data/goods_train.txt");

  std::map<int, int> m_brand;
  std::map<int, int> m_category;
  int good, brand, category;
  while (true) {
    data_good >> good >> brand >> category;
    if (!data_good) {
      break;
    }
    m_brand[good] = brand;
    m_category[good] = category;
  }

  data_good.close();
  std::cerr << std::endl;

  std::cerr << "Waiting brand and category weight......\n";
  std::ifstream data_brand_number("../../../NewData/build4/brand_number.txt");
  std::ifstream data_category_number("../../../NewData/build4/category_number.txt");
  std::ofstream data_brand_weight("../../../NewData/build4/brand_weight.txt");
  std::ofstream data_category_weight("../../../NewData/build4/category_weight.txt");

  int number, n, high;
  while (true) {
    data_brand_number >> brand >> number;
    if (!data_brand_number) {
      break;
    }
    n = 0;
    for (; number > 0; number /= 10, ++n) {
      high = number % 10;
    }
    data_brand_weight << brand << ' ' << ((9*n + high - 1)*2) << std::endl;
  }
  while (true) {
    data_category_number >> category >> number;
    if (!data_category_number) {
      break;
    }
    n = 0;
    for (; number > 0; number /= 10, ++n) {
      high = number % 10;
    }
    data_category_weight << category << ' ' << (9*n + high - 1) << std::endl;
  }

  data_brand_number.close();
  data_category_number.close();
  data_brand_weight.close();
  data_category_weight.close();
  std::cerr << std::endl;

  std::cerr << "Waiting basic user weight......\n";
  std::ifstream data_user_test("../../../Data/user_action_test_items.txt");
  std::ifstream data_user_bought("../../../NewData/build4/user_bought.txt");
  std::ifstream data_user_clicked("../../../NewData/build4/user_clicked.txt");
  std::ifstream data_user_bought_brand("../../../NewData/build4/user_bought_brand.txt");
  std::ifstream data_user_bought_category("../../../NewData/build4/user_bought_category.txt");
  std::ofstream data_user_basic_weight("../../../NewData/build4/user_basic_weight.txt");

  std::map<int, int> m_user_bought;
  std::map<int, int> m_user_clicked;
  int user;
  while (true) {
    data_user_bought >> user >> number;
    if (!data_user_bought) {
      break;
    }
    m_user_bought[user] = number;
  }
  while (true) {
    data_user_clicked >> user >> number;
    if (!data_user_clicked) {
      break;
    }
    n = 0;
    for (; number > 0; number /= 10, ++n) {
      high = number % 10;
    }
    m_user_clicked[user] = (9*n + high - 1);
  }
  int bought_brand, bought_category;
  int basic_user;
  while (true) {
    data_user_test >> user >> good;
    data_user_bought_brand >> bought_brand;
    data_user_bought_category >> bought_category;
    if (!data_user_test) {
      break;
    }
    basic_user = m_user_bought[user] + m_user_clicked[user] + bought_category;
    if (bought_brand) {
      basic_user += m_user_bought[user] / bought_brand;
    }
    data_user_basic_weight << basic_user << std::endl;
  }

  data_user_test.close();
  data_user_bought.close();
  data_user_clicked.close();
  data_user_bought_brand.close();
  data_user_bought_category.close();
  data_user_basic_weight.close();
  std::cerr << std::endl;

  std::cerr << "Waiting basic good weight......\n";
  std::ifstream data_good_test("../../../Data/user_action_test_items.txt");
  std::ifstream data_good_bought("../../../NewData/build4/good_bought.txt");
  std::ifstream data_good_clicked("../../../NewData/build4/good_clicked.txt");
  std::ifstream data_w_brand("../../../NewData/build4/brand_weight.txt");
  std::ifstream data_w_category("../../../NewData/build4/category_weight.txt");
  std::ofstream data_good_basic_weight("../../../NewData/build4/good_basic_weight.txt");

  std::map<int, int> m_good_bought;
  std::map<int, int> m_good_clicked;
  std::map<int, int> m_w_brand;
  std::map<int, int> m_w_category;
  while (true) {
    data_good_bought >> good >> number;
    if (!data_good_bought) {
      break;
    }
    m_good_bought[good] = number;
  }
  while (true) {
    data_good_clicked >> good >> number;
    if (!data_good_clicked) {
      break;
    }
    n = 0;
    for (; number > 0; number /= 10, ++n) {
      high = number % 10;
    }
    m_good_clicked[good] = (9*n + high - 1);
  }
  while (true) {
    data_w_brand >> brand >> number;
    if (!data_w_brand) {
      break;
    }
    m_w_brand[brand] = number;
  }
  while (true) {
    data_w_category >> category >> number;
    if (!data_w_category) {
      break;
    }
    m_w_category[category] = number;
  }
  int basic_good;
  while (true) {
    data_good_test >> user >> good;
    if (!data_good_test) {
      break;
    }
    basic_good = m_good_bought[good] + m_good_clicked[good];
    basic_good += m_w_brand[m_brand[good]] + m_w_category[m_category[good]];
    data_good_basic_weight << basic_good << std::endl;
  }

  data_good_bought.close();
  data_good_bought.close();
  data_good_test.close();
  data_w_brand.close();
  data_w_category.close();
  data_good_basic_weight.close();
  std::cerr << std::endl;

  return 0;
}