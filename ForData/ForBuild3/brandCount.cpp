#include <iostream>
#include <fstream>
using namespace std;

int brands[100000];

int main() {
	int idOfGood, behaviour, bought, click, brand, categery;

	ifstream fin("../../../NewData/build3/good_statistic.txt");
	ifstream in("../../../NewData/goods_train_sorted.txt");
	if (fin.fail()) return 0;
	while (fin >> idOfGood) {
		fin >> behaviour >> bought >> click;
		in >> idOfGood >> brand >> categery;
		brands[brand % 10000000] += bought;
		cout << "reading..." << endl;
	}

	fin.close();
	in.close();

	ofstream fout("../../../NewData/build3/brands_count.txt");
	for (int i = 0; i < 100000; ++ i) {
		if (brands[i]) {
			fout << i  + 10000000 << ' ' << brands[i] << endl;
		}
	}
	fout.close();
	cout << "done!" << endl;
}