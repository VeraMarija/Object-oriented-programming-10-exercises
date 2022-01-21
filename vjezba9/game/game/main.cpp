#include "game.h"
#include<iostream>
#include<iomanip>
#include<vector>
#include <string>
using namespace std;

int main() {
	Game japaneza;
	if (!japaneza.GameStart()) {
		cout << "THE GAME IS OVER!!! " << endl;
	}
}