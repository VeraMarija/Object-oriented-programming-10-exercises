#ifndef COMPUTER_H
#define COMPUTER_H
#include<string>
#include<vector>
#include "player.h"


class Computer : public Player {
public:
	Computer(string s);
	int selectCoins();
	int guess_allSum(int num_player);
	~Computer() {}
};


#endif