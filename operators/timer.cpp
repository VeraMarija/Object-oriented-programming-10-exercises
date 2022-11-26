#include<iostream>
#include<vector>
#include<algorithm>
#include "timer.h"


//friendovi
ostream& operator<<(ostream& os, const timer& t) {
	return os << t.h << ":" << t.m << ":" << t.s;
}

timer operator+(timer a, timer b) {
	return timer(a.h + b.h, a.m + b.m, a.s + b.s);
}

timer operator-(timer a, timer b) {
	return timer(a.h - b.h, a.m - b.m, a.s - b.s);
}

//operatori kao funkcije clanovi klase

timer& timer::operator+=(const timer& other) {
	s += other.s;
	m += other.m;
	h += other.h;
	return *this;
}

timer& timer::operator-=(const timer& other) {
	h -= other.h;
	m -= other.m;
	
	s -= other.s;
	
	return *this;
}

timer& timer::operator/=(int size) {
	h /= size;
	int rest = m % size;
	m /= size;
	s += rest * 60;
	s /= size;
	return *this;
}


timer::operator double() {
	return double(3600 * h + 60 * m + s);
}

void timer::change_s() {
	if (s > 59) {
		double difference = s - 60;
		s = difference;
		m += 1;
	}
}
void timer::change_m() {
	if (m > 59) {
		double difference = m - 60;
		m = difference;
		h += 1;
	}
}

