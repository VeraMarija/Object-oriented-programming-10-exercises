#include "human.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include "player.h"
using namespace std;

Human::Human(string s) {
	set_name(s);
	set_handSum(0);
	set_allSum(0);
	set_points(0);
}

int Human::selectCoins() {
	int n, cnt = 0;
	cout << "i will ask you which coins of 1,2 and 5 you wanna take, if you want coin enter 1 if not enter 0!" << endl;
	do {
		cout << "ONE KUNA?" << endl;
		cin >> n;
	} while (n != 0 && n != 1);
	if (n) { 
		cnt += 1; 
	}
	do {
		cout << "TWO KUNAS?" << endl;
		cin >> n;
	} while (n != 0 && n != 1);
	if (n) { 
		cnt += 2;
	}
	do {
		cout << "FIVE KUNAS?" << endl;
		cin >> n;
	} while (n != 0 && n != 1);
	if (n) {
		cnt += 5; 
	}
	return cnt;
}

int Human::guess_allSum(int num_players) {
	int max = num_players * 8;
	int sum = 0;
	do {
		cout << "guess what the total amount is " << endl;
		cin >> sum;
	} while (sum<0 || sum > max);
	return sum;
}