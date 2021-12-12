#include "Board.h"
#include<iostream>
#include<iomanip>
#include<algorithm>


int main() {
	Board def;
	Board cpy(def);
	Board mov = std::move(def);
	if (def.get_matrix() == nullptr)
		std::cout << std::endl << "maneged to take ownership with move constructor" << std::endl;
	else
		std::cout << std::endl << "failed to take ownership using the move constructor" << std::endl;
	std::cout << std::endl;
	Board b(5, 10);
	return 0;

}