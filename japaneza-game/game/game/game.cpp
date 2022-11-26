#include "game.h"
#include "computer.h"
#include "human.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<random>
using namespace std;

void Game::set_num_players(int n) {
	num_players = n;
}

int Game::get_num_players() {
	return num_players;
}

void Game::set_players(int num_humans,int num_comp) {
	for (int i = 0;i < num_humans;++i) {
		string name;
		cout << "enter " << i+1 << ".human name: " << endl;
		cin >> name;
		players.push_back(new Human(name));
	}
	for (int i = 0;i < num_comp;++i) {
		string name;
		cout << "enter " << i+1 << ".computer name: " << endl;
		cin >> name;
		players.push_back(new Computer(name));
	}
}

vector <Player*> Game::get_players() {
	return players;
}

void Game::set_gameGoal(int n) {
	gameGoal = n;
}

int Game::get_gameGoal() {
	return gameGoal;
}

int Game::GameStart() {
	int num_humans,num_comp,n,counter=0;
	cout << "how many humans are in the game? " << endl;
	cin >> num_humans;
	cout << "how many computers are in the game? " << endl;
	cin >> num_comp;
	set_num_players(num_humans + num_comp);
	set_players(num_humans,num_comp);
	do {
		cout << "up to how many points the game will be played? " << endl;
		cin >> n;
	} while (!n);
	set_gameGoal(n);
	cout << "LETS START THE GAME JAPANEZA ! :) " << endl;
	int size = players.size();
	
	while (1) {
		for (int i = 0; i < size;++i) {
			if (players[i]->get_points() == get_gameGoal()) {
				cout << "THE WINNER IS:  " << players[i]->get_name() << endl;
				for (int i = 0;i < size;++i) {
					delete players[i];
				}
				return 0;
			}
			players[i]->set_handSum(players[i]->selectCoins());
			
			counter += players[i]->get_handSum();
			players[i]->set_allSum(players[i]->guess_allSum(get_num_players()));
		}
		for (int i = 0;i < size;++i) {
			if (players[i]->get_allSum() == counter) {
				players[i]->add_point();
				cout << "the name of the player who guessed well total sum is " << players[i]->get_name() << endl;
			}
		}
		counter = 0;
	}


	return 1;

}