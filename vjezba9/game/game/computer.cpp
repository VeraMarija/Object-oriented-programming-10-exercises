#include "computer.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<random>
#include "player.h"

using namespace std;

Computer::Computer(string s) {
	set_name(s);
	set_handSum(0);
	set_allSum(0);
	set_points(0);
}

int Computer::selectCoins() {
	int sum = 0;
	sum += (rand() % 2) * 1; //izabrana ili ne 1 kuna
	sum += (rand() % 2) * 2;
	sum += (rand() % 2) * 5;
	
	return sum;
}

int Computer::guess_allSum(int num_players) {
	int max = num_players * 8;
	int sum = 0 + (rand() % max+1);
	
	return sum;
}
