// 分别统计每个用户的行为，每个商品被操作次数

#include <iostream>
#include <fstream>
using namespace std;

#define maxUserNum 1000000
#define maxGoodNum 5000000

int totalBehaviour;
int totalPurchasing;
int totalClicking;

int usersBehaviour[maxUserNum];
int usersPurchasing[maxUserNum];
int usersClicking[maxUserNum];

int goodsBehaviour[maxGoodNum];
int goodsPurchased[maxGoodNum];
int goodsClicked[maxGoodNum];

int main() {
	int outOfRange = 0;

	int idOfUser, idOfGood, action;
	string date;

	ifstream fin("../../../Data/user_action_train.txt");
	ofstream userOut("../../../NewData/build3/user_action_sorted.txt");
	ofstream goodOut("../../../NewData/build3/goods_statistic.txt");
	ofstream totOut("../../../NewData/build3/total_statistic.txt");

	while(fin >> idOfUser) {
		fin >> idOfGood >> action >> date;
		if (idOfGood >= maxGoodNum) {
			outOfRange ++;
			continue;
		}

		totalBehaviour ++;
		usersBehaviour[idOfUser] ++;
		goodsBehaviour[idOfGood] ++;

		if (action) {
			totalPurchasing ++;
			usersPurchasing[idOfUser] ++;
			goodsPurchased[idOfGood] ++;
		}
		else {
			totalClicking ++;
			usersClicking[idOfUser] ++;
			goodsClicked[idOfGood] ++;
		}
		cout << "Reading... " << totalBehaviour << endl;
	}
	fin.close();

	for (int i = 0; i < maxUserNum; ++ i) {
		if (usersBehaviour[i]) {
			userOut << i << ' ' << usersBehaviour[i] << ' '
				<< usersPurchasing[i] << ' ' << usersClicking[i] << endl;
		}
	}
	userOut.close();

	for (int i = 0; i < maxGoodNum; ++ i) {
		if (goodsBehaviour[i]) {
			goodOut << i << ' ' << goodsBehaviour[i] << ' '
				<< goodsPurchased[i] << ' ' << goodsClicked[i] << endl;
		}
	}
	goodOut.close();

	totOut << totalBehaviour << endl;
	totOut << totalPurchasing << endl;
	totOut << totalClicking << endl;
	totOut.close();

	cout << outOfRange << endl;

}