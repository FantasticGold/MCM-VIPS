//这个程序将goods_train.txt的数据按照商品ID从小到大排列
//maxCategory 记录品类ID的最大值


#include <iostream>
#include <fstream>
using namespace std;

int goods[3000000][2];

int maxCategory;

int main() {
	int idOfGood, brand, category;
	ifstream fin("../../../Data/goods_train.txt");
	while (fin >> idOfGood) {
		fin >> brand >> category;
		maxCategory = max(maxCategory, category);
		goods[idOfGood][0] = brand;
		goods[idOfGood][1] = category;
	}
	fin.close();

	ofstream fout("../../../NewData/build3/goods_train_sorted.txt");
	for (int i = 0; i < 3000000; ++ i) {
		if (goods[i][0]) {
			fout << i << ' ' << goods[i][0] << ' ' << goods[i][1] << endl;
		}
	}
	fout.close();
	cout << maxCategory << endl;
}

//
//maxCategery: 75799