#ifndef GAME_H
#define GAME_H
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include "player.h"
 

class Game {
private:
	int num_players;
	vector <Player*> players;
	int gameGoal;

public:
	int GameStart();
	void set_num_players(int n);
	int get_num_players();
	void set_players(int n1,int n2);
	vector <Player*> get_players();
	void set_gameGoal(int n);
	int get_gameGoal();

};




#endif