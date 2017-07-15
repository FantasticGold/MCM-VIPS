#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <iomanip>
using namespace std;

//共七组数据
//一组输入，输入一次输出一次，运行时间约十分钟

//part one 全局数据库

int user_action[700000][2];
//int user_categery_buy[700000][50];
//int	user_categery_click[700000][50];
//int brand
int categeries_count[100000];

map<int, int> user_categery_buy[700000];
map<int, int> user_categery_click[700000];
map<int, int> user_brand_buy[700000];
map<int, int> user_brand_click[700000];
map<int, int> brand_categery[100000];

//information of good
int goodInfo[2500000][2];


int main() {
	//part two 	数据输入
	int idOfUser, idOfGood, temp, categery, brand;
	ifstream file0("../../NewData/build3/goods_train_sorted.txt");
	while (file0 >> idOfGood) {
		file0 >> brand >> goodInfo[idOfGood][1];
		goodInfo[idOfGood][0] = brand % 10000000;
	}
	file0.close();

	ifstream file1("../../NewData/build3/user_action_status.txt");
	while (file1 >> idOfUser) {
		file1 >> temp >> user_action[idOfUser][0] >> user_action[idOfUser][1];
		cout << "reading file1..." << endl;
	}
	file1.close();

	ifstream file2("../../NewData/build3/categories_count.txt");
	while (file2 >> categery) {
		file2 >> categeries_count[categery];
		cout << "reading file2..." << endl;
	}
	file2.close();

	ifstream file3("../../NewData/build3/brands_category.txt");
	while (file3 >> brand) {
		brand = brand % 10000000;
		file3.get();
		stringstream input;
		string in;
		getline(file3, in);
		input << in;
		while (input >> categery) {
			input >> temp;
			brand_categery[brand].insert(pair<int, int>(categery, temp));
		}
		cout << "reading file3..." << endl;
	}
	file3.close();

	ifstream file4("../../NewData/build3/users_category.txt");
	while (file4 >> idOfUser) {
		file4.get();
		stringstream input;
		string in;
		getline(file4, in);
		input << in;
		while (input >> categery) {
			input >> temp;
			user_categery_buy[idOfUser].insert(pair<int, int>(categery, temp));
		}
		cout << "reading file4..." << endl;
	}
	file4.close();

	ifstream file5("../../NewData/build3/users_category_click.txt");
	while (file5 >> idOfUser) {
		file5.get();
		stringstream input;
		string in;
		getline(file5, in);
		input << in;
		while (input >> categery) {
			input >> temp;
			user_categery_click[idOfUser].insert(pair<int, int>(categery, temp));
		}
		cout << "reading file5..." << endl;
	}
	file5.close();

	ifstream file6("../../NewData/build3/users_brand.txt");
	while (file6 >> idOfUser) {
		file6.get();
		stringstream input;
		string in;
		getline(file6, in);
		input << in;
		while (input >> brand) {
			brand = brand % 10000000;
			input >> temp;
			user_brand_buy[idOfUser].insert(pair<int, int>(brand, temp));
		}
		cout << "reading file6..." << endl;
	}
	file6.close();

	ifstream file7("../../NewData/build3/users_brand_click.txt");
	while (file7 >> idOfUser) {
		file7.get();
		stringstream input;
		string in;
		getline(file7, in);
		input << in;
		while (input >> brand) {
			brand = brand % 10000000;
			input >> temp;
			user_brand_click[idOfUser].insert(pair<int, int>(brand, temp));
		}
		cout << "reading file7..." << endl;
	}
	file7.close();

	int count = 0;
	double Pug, Pub, Puc, Pg;
	bool b1, b2, c1, c2;
	int n1, n2, n11, n12, n21, n22, m0, m;
	ifstream test("../../Data/user_action_test_items.txt");
	ofstream ans("result.txt");
	while(test >> idOfUser) {
		test >> idOfGood;
		b1 = user_brand_buy[idOfUser].count(goodInfo[idOfGood][0]);
		b2 = user_brand_click[idOfUser].count(goodInfo[idOfGood][0]);
		c1 = user_categery_buy[idOfUser].count(goodInfo[idOfGood][1]);
		c2 = user_categery_click[idOfUser].count(goodInfo[idOfGood][1]);
		n1 = user_action[idOfUser][0];
		n2 = user_action[idOfUser][1];
		if (n1 == 0) n1 = 1;
		if (n2 == 0) n2 = 1;
		if (b1) n11 = (user_brand_buy[idOfUser].find(goodInfo[idOfGood][0]))->second;
		if (b2) n21 = (user_brand_click[idOfUser].find(goodInfo[idOfGood][0]))->second;
		if (c1) n12 = (user_categery_buy[idOfUser].find(goodInfo[idOfGood][1]))->second;
		if (c2) n22 = (user_categery_click[idOfUser].find(goodInfo[idOfGood][1]))->second;
		m0 = categeries_count[goodInfo[idOfGood][1]];
		cout << m0;
		m = (brand_categery[goodInfo[idOfGood][0]].find(goodInfo[idOfGood][1]))->second;	
		if (m0 == 0) m0 = 1;
		Pub = 0.25 * ( b1*(1 + n11 * 1.0 /n1) + b2*(1 + n21 * 1.0 /n2) );
		Puc = 0.25 * ( c1*(1 + n12 * 1.0 /n2) + c2*(1 + n22 * 1.0 /n2) );
		Pg = m * 1.0 / m0;
		Pug = Pub * Puc + Pg;
		if (Pug > 1) Pug = 0.888;
		if (Pug < 0.8) Pug *= 1.25;
		ans << fixed << setprecision(3) << Pug << endl;
		cout << "running... " <<  m << ' ' << m0 << ' ' << Pg << endl;
	}
	cout << count << endl;
	test.close();
	ans.close();

}