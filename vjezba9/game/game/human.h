#ifndef HUMAN_H
#define HUMAN_H
#include<string>
#include<vector>
#include "player.h"


class Human : public Player {
public:
	Human(string s);
	int selectCoins();
	int guess_allSum(int num_player);
	~Human() {  }
};


#endif
