#include <iostream>
#include <fstream>
//#include <map>
using namespace std;

int usersAndCategery[700000][50];
int brandAndCategery[10000][50];
//int usersAndBrand[200000][7000];
//std::map<int, int> users[200000];


int categeries[100000];
int indexOfCtgr[55];

int brands[100000];
int indexOfBrnd[7000];

int goodInfo[2500000][2];

int main() {
	int idOfUser, idOfGood, categery, brand;
	string date;

	ifstream ctgrIn("../../../NewData/build3/categories_count.txt");
	for (int i = 0; i < 49; ++ i) {
		ctgrIn >> categery;
		categeries[categery] = i + 1;
		indexOfCtgr[i + 1] = categery;
		ctgrIn >> categery;

		cout << "reading file one..." << endl;
	}
	ctgrIn.close();

	ifstream brndIn("../../../NewData/build3/brands_count.txt");
	for (int i = 0; i < 6955; ++ i) {
		brndIn >> brand;
		brands[brand % 10000000] = i + 1;
		indexOfBrnd[i + 1] = brand % 10000000;
		brndIn >> brand;

		cout << "reading file two..." << endl;
	}
	brndIn.close();

	ifstream goodIn("../../../NewData/build3/goods_train_sorted.txt");
	while (goodIn >> idOfGood) {
		goodIn >> brand >> goodInfo[idOfGood][1];
		goodInfo[idOfGood][0] = brand % 10000000;
	}
	goodIn.close();

	ifstream buy("../../../NewData/user_buy.txt");
	while (buy >> idOfUser) {
		buy >> idOfGood >> date;
		usersAndCategery[ idOfUser ][0] = 1;
		//usersAndBrand[ idOfUser ][0] = 1;
		brandAndCategery[ brands[ goodInfo[idOfGood][0] ] ][0] = 1;
		usersAndCategery[ idOfUser ][ categeries[goodInfo[idOfGood][1]] ] ++;
		brandAndCategery[ brands[ goodInfo[idOfGood][0] ] ][ categeries[goodInfo[idOfGood][1]] ] ++;
		//usersAndBrand[ idOfUser ][ brands[ goodInfo[idOfGood][0] ] ] ++;
	
		cout << "reading file four..." << endl;	
	}
	buy.close();

	ofstream usrAndCtgr("../../../NewData/build3/users_category.txt");
	for (int i = 1; i < 700000; ++ i) {
		if (usersAndCategery[i][0]) {
			usrAndCtgr << i << endl;
			for (int j = 1; j < 50; ++ j) {
				if (usersAndCategery[i][j]) {
					usrAndCtgr << indexOfCtgr[j] << ' ' <<
						usersAndCategery[i][j] << "  ";
				}
			}
			usrAndCtgr << endl;
		}
		cout << "outputing file one..." << endl;
	}
	usrAndCtgr.close();

	ofstream brndAndCtgr("../../../NewData/build3/brands_category.txt");
	for (int i = 1; i < 10000; ++ i) {
		if (brandAndCategery[i][0]) {
			brndAndCtgr << indexOfBrnd[i] + 10000000 << endl;
			for (int j = 1; j < 50; ++ j) {
				if (brandAndCategery[i][j]) {
					brndAndCtgr << indexOfCtgr[j] << ' ' <<
						brandAndCategery[i][j] << "  ";
				}
			}
			brndAndCtgr << endl;
		}
		cout << "outputing file two..." << endl;
	}
	brndAndCtgr.close();
/*
	ofstream usrAndBrnd("users_brand.txt");
	for (int i = 0; i < 200000; ++ i) {
		if (usersAndBrand[i][0]) {
			usrAndBrnd << i << endl;
			for (int j = 1; j < 10000; ++ j) {
				if (usersAndBrand[i][j]) {
					usrAndBrnd << indexOfBrnd[j] << ' ' <<
						usersAndBrand[i][j] << "  ";
				}
			}
			usrAndBrnd << endl;
		}
		cout << "outputing file three..." << endl;
	}
	usrAndBrnd.close();
*/
	cout << "done!" << endl;
}