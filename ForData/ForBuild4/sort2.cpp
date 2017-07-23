#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#include <iomanip>

class Weight {
public:
  Weight() {
    //
  }
  Weight(int n1, int n2, int n3, int n4) {
    user = n1;
    good = n2;
    w_user = n3;
    w_good = n4;
  }
  Weight(const Weight& w2) {
    this->user = w2.user;
    this->good = w2.good;
    this->w_user = w2.w_user;
    this->w_good = w2.w_good;
  }
  int getUser() const {
    return user;
  }
  int getGood() const {
    return good;
  }
  int getWuser() const {
    return w_user;
  }
  int getWgood() const {
    return w_good;
  }
private:
  int user;
  int good;
  int w_user;
  int w_good;
};
struct Weightcmp {
  bool operator()(const Weight& w1, const Weight& w2) {
    int s1 = w1.getWuser() + w1.getWgood();
    int s2 = w2.getWuser() + w2.getWgood();
    if (s1 != s2) {
      return s1 < s2;
    }
    if (w1.getWuser() != w2.getWuser()) {
      return w1.getWuser() < w2.getWuser();
    }
    return w1.getWgood() < w2.getWgood();
  }
};

int main(void) {
  std::cout << "Waiting sort......\n";
  std::ifstream data_test("../../../Data/user_action_test_items.txt");
  std::ifstream data_user("../../../NewData/build4/user_basic_weight.txt");
  std::ifstream data_good("../../../NewData/build4/good_basic_weight.txt");
  std::ofstream data_weight("../../../NewData/build4/weight2.txt");

  std::priority_queue<Weight, std::vector<Weight>, Weightcmp> q;
  int user, good, w_user, w_good;
  while (true) {
    data_test >> user >> good;
    data_user >> w_user;
    data_good >> w_good;
    if (!data_test) {
      break;
    }
    q.push(Weight(user, good, w_user, w_good));
  }
  std::map<std::pair<int, int>, double> m_weight;
  for (int i = 0; i < 2880546; ++i) {
    m_weight[std::make_pair(q.top().getUser(), q.top().getGood())] = 0.8;
    q.pop();
  }
  for (int i = 0; i < 2880546; ++i) {
    m_weight[std::make_pair(q.top().getUser(), q.top().getGood())] = 0.2;
    q.pop();
  }
  data_test.close();
  data_test.open("../../../Data/user_action_test_items.txt");
  int sum = 0;
  double result;
  while (true) {
    data_test >> user >> good;
    if (!data_test) {
      break;
    }
    result = m_weight[std::make_pair(user, good)];
    data_weight << std::fixed << std::setprecision(3) << result << std::endl;
    if (result == 0) {
      ++sum;
    }
  }
  std::cout << "sum = " << sum << std::endl;

  data_test.close();
  data_user.close();
  data_good.close();
  data_weight.close();
  std::cout << std::endl;

  return 0;
}