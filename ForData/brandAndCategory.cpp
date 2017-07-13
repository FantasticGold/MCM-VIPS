// calcutlate the number of brand and category

#include <fstream>
#include <iostream>
using namespace std;

int numOfBrand;
int numOfCategory;

int brands[100000];
int categories[100000];

int main() {
	int idOfGood, brand, category;
	int OORBrand = 0, OORCategories = 0; // OOR(out of range)

	ifstream fin("goods_train.txt");
	while (fin >> idOfGood) {
		fin >> brand >> category;
		if (brand < 10000000 || brand > 10100000) {
			OORBrand ++;
			continue;
		}
		if (category > 100000) {
			OORCategories ++;
			continue;
		}
		brands[brand % 10000000] ++;
		categories[category] ++;

	}
	fin.close();
	for (int i = 0; i < 100000; ++ i) {
		if (brands[i] != 0) {
			++ numOfBrand;
		}
		if (categories[i] != 0) {
			++ numOfCategory;
		}
	}
	cout << "numOfBrand: " << numOfBrand << endl;
	cout << "numOfCategory: " << numOfCategory << endl;
	cout << "OORBrand: " << OORBrand << endl;
	cout << "OORCategories: " << OORCategories << endl;
}