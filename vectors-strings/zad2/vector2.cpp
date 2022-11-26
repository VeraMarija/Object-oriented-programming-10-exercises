#include<iostream>
#include "vector.h"
#include<algorithm>
using namespace std;


void input_vect1(vector<int>& v, int n) {
	int i = 1, x;
	for (i;i <= n;++i) {
		cout << "enter " << i << ". element: " << endl;
		cin >> x;
		v.push_back(x);
	}
}

void input_vect2(vector<int>& v, int a, int b) {

	int i = 1, x;
	while (i) {
		cout << "enter element:" << endl;
		cin >> x;
		if (x >= a && x <= b)
			v.push_back(x);
		else
			i = 0;
	}
	if (!v.size())
		cout << "empty vector!";
}

void output_vect(vector<int>& v) {
	int i;
	for (i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;

}
