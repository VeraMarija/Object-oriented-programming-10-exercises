#include "animals.h"
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

animal::~animal() {}

void Brojac::print_species_and_legs(animal** array,int n) {
	
	for (int i = 0;i < n;++i) {
		cout << "dodan: " << array[i]->return_species() << endl;
		number_of_legs += array[i]->return_legs();
	}
	cout << "sum of legs: " << number_of_legs;
}


