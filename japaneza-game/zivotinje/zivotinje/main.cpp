#include "animals.h"
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main() {
	animal* array[] = { new Bee, new Ladybugs, new Centipede , new Tarantule, new Scorpion , new Eagle, new Owl };
	int n = sizeof(array) / sizeof(animal);
	Brojac b;
	b.print_species_and_legs(array, n);
	for (auto el : array) {
		delete el;
	}
}