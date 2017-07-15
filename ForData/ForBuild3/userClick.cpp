#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int usersAndCategery[700000][50];
map<int, int> users[700000];

int categeries[100000];
int indexOfCtgr[55];

int brands[100000];
int indexOfBrnd[7000];

int goodInfo[2500000][2];

int main() {
	int idOfUser, idOfGood, categery, brand, action;
	string date;

	ifstream ctgrIn("../../../NewData/build3/categ0ries_count.txt");
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

	ifstream buy("../../../Data/user_action_train.txt");
	while (buy >> idOfUser) {
		buy >> idOfGood >> action >> date;
		if (!action) {
			usersAndCategery[ idOfUser ][0] = 1;
			usersAndCategery[ idOfUser ][ categeries[goodInfo[idOfGood][1]] ] ++;
			
			brand = brands[ goodInfo[idOfGood][0] ];
			if (!users[idOfUser].count(brand))	
				users[idOfUser].insert(pair<int, int>(brand, 1));
			else
				(users[idOfUser])[brand] += 1;


		}
		cout << "reading file four..." << endl;	
	}
	buy.close();

	ofstream usrAndCtgr("users_category_click.txt");
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

	ofstream usrAndBrnd("users_brand_click.txt");
	for (int i = 0; i < 700000; ++ i) {
		if (!users[i].empty()) {
			usrAndBrnd << i << endl;
			map<int, int>::iterator iter;
			for (iter = users[i].begin(); iter != users[i].end(); iter ++) {
				usrAndBrnd << indexOfBrnd[iter->first] + 10000000 << ' ' <<
					iter->second << "  ";
			}
			usrAndBrnd << endl;
		}
	}

	cout << "done!" << endl;
}