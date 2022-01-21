#ifndef PLAYER_H
#define PLAYER_H
#include<string>
#include<vector>
using namespace std;


class Player {
protected:
	string name;
	int handSum;
	int allSum;
	int points;
public:
	Player();
	void set_name(string s);
	string get_name();
	void set_handSum(int n);
	int get_handSum();
	void set_allSum(int n);
	int get_allSum();
	void set_points(int n);
	void add_point();
	int get_points();
	virtual int selectCoins() { return handSum; }
	virtual int guess_allSum(int num_players) { return allSum; }
	virtual ~Player();

};

#endif