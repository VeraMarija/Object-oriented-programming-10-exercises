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

int sum_fun(vector<int>& v) {
	int i, cnt = 0;
	for (i = 0;i < v.size();++i) {
		cnt += v[i];
	}
	return cnt;
}


void output_vect(vector<int>& v) {
	int i;
	for (i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;

}
