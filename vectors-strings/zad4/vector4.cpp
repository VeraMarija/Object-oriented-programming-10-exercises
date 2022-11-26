#include<iostream>
#include "vector.h"
#include<vector>
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

void remove_vect(vector<int>& v, int i) {
	v[i - 1] = v[v.size() - 1];
	v.pop_back();
}

void output_vect(vector<int>& v) {
	int i;
	for (i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;

}

