#ifndef ANIMALS_H
#define ANIMALS_H
#include <iostream>
#include <cstdlib>
#include<string>
using namespace std;

class animal {
public:
	virtual int return_legs() = 0;
	virtual string return_species() = 0;
	virtual ~animal() = 0;
};

class insect:public animal{
protected:
	string species = "insect";
public:
	virtual int return_legs() { return 0; }
	virtual string return_species() { return species; }
	virtual ~insect() {};
};

class Bee : public insect {
protected:
	int legs=6;
	string name = "Bee";
public:
	int return_legs() { return legs; }
	string return_species() { return name; }
	~Bee() {}
};

class Ladybugs : public insect {
protected:
	int legs = 6;
	string name = "Ladybugs";
public:
	int return_legs() { return legs; }
	string return_species() { return name; }
	~Ladybugs() {}
};

class Centipede : public insect {
protected:
	int legs = 100;
	string name = "Centipede";
public:
	int return_legs() { return legs; }
	string return_species() { return name; }
	 ~Centipede() {}
};

class spider:public animal{
protected:
	string species = "spider";
public:
	virtual int return_legs() { return 0; }
	virtual string return_species() { return species; }
	virtual ~spider() {}
};

class Tarantule:public spider{
protected:
	int legs = 8;
	string name = "Tarantule";
public:
	int return_legs() { return legs; }
	string return_species() { return name; }
	~Tarantule() {}
};

class Scorpion: public spider{
protected:
	int legs = 8;
	string name = "Scorpion";
public:
	int return_legs() { return legs; }
	string return_species() { return name; }
	~Scorpion() {}
};

class bird:public animal {
protected:
	string spicies = "bird";
public:
	virtual int return_legs() { return 0; }
	virtual string return_species() {return spicies; }
	virtual ~bird() {}
};

class Eagle: public bird {
protected:
	int legs = 2;
	string name = "Eagle";
public:
	int return_legs() { return legs; }
	string return_species() { return name; }
	~Eagle() {}
};
class Owl : public bird {
protected:
	int legs = 2;
	string name = "Owl";
public:
	int return_legs() { return legs; }
	string return_species() { return name; }
	~Owl() {}
};

class Brojac {
private:
	int number_of_legs;
public:
	Brojac(): number_of_legs(0) {}
	void print_species_and_legs(animal ** array,int n);
};

#endif
