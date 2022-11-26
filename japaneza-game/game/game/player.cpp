#include "player.h"
#include<iostream>
#include<iomanip>
#include <string>

Player::Player() {
	handSum = 0;
	allSum = 0;
	points = 0;
}

void Player::set_name(string s) {
	name = s;
}

string Player::get_name() {
	return name;
}

void Player::set_handSum(int n) {
	handSum = n;
}

int Player::get_handSum() {
	return handSum;
}

void Player::set_allSum(int n) {
	allSum = n;
}

int Player::get_allSum() {
	return allSum;
}

void Player::set_points(int n) {
	points = n;
}

void Player::add_point() {
	points++;
}

int Player::get_points() {
	return points;
}

Player::~Player() {}