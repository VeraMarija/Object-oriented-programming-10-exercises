#ifndef TIMER_H 
#define TIMER_H

using namespace std;
/*Napi�ite klasu timer koja sadr�i privatne �lanove h, m tipa int i s tipa double,
koja predstavlja rezultat u trci Formule 1. Napi�ite potrebne konstruktore
i operatore kako bi za grupu voza�a izra�unali:
� prosje�nu brzinu svih voza�a,
� postignuto vrijeme najbr�eg voza�a,
� razliku vremena do vremena najbr�eg voza�a (u sekundama),
� ispisati postignuta vremena u obliku stringa "h:m:s"
Klasa treba imati operatore: +=, -=, +, -, /=, /, <<, operator double*/

class timer {
	int h, m;
	double s;
public:
	timer():h(0),m(0),s(0){}
	timer(int h,int m,double s):h(h),m(m),s(s){}
	friend ostream& operator<<(ostream& os, const timer& t);
	friend timer operator+(timer a, timer b);
	friend timer operator-(timer a, timer b);
	
	timer& operator+=(const timer& other);
	timer& operator-=(const timer& other);
	timer& operator/=(int size);
	operator double();
	void change_s();
	void change_m();
	~timer() {}
	friend class penalty;
};


class penalty {
	double extra_sek;
public:
	penalty(int sek) :extra_sek(sek) {}
	void operator()(timer& t) {
		t.s += extra_sek;
		t.change_s();
		t.change_m();
	}
	
};



#endif
