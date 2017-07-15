#include <iostream>
#include <fstream>
using namespace std;

//int categerySale[50][2];

int categeries[80000];

int main() {
	int idOfGood, behaviour, bought, click, brand, categery;

	ifstream fin("../../../NewData/build3/goods_statistic.txt");
	ifstream in("../../../NewData/build3/goods_train_sorted.txt");
	if (fin.fail()) return 0;
	while (fin >> idOfGood) {
		fin >> behaviour >> bought >> click;
		in >> idOfGood >> brand >> categery;
		categeries[categery] += bought;
		cout << "reading..." << endl;
	}

	fin.close();
	in.close();

	ofstream fout("../../../NewData/build3/categories_count.txt");
	for (int i = 0; i < 80000; ++ i) {
		if (categeries[i]) {
			fout << i << ' ' << categeries[i] << endl;
		}
	}
	fout.close();
	cout << "done!" << endl;
}