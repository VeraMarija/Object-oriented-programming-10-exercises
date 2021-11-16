#include<iostream>
#include "vector.h"
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	vector <int> v4;
	input_vect1(v4, 5);
	int position = v4.size() / 2;
	remove_vect(v4, position);
	cout << "removing " << position << ".element  ";
	output_vect(v4);
	return 0;
}

