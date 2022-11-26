#include<iomanip>
#include<iostream>
#include<vector>
#include "vector.h"
using namespace std;

int main() {
	vector<int> v1,v2,v3;
	int n = 5;
	cout << "first vector: " << endl;
	input_vect1(v1, n);
	cout << "second vectro: " << endl;
	input_vect2(v2, -5, 5);
	int i, j, cnt = 0;
	for (i = 0;i < v1.size();++i) {
		for (j = 0;j < v2.size();++j) {
			if (v1[i] == v2[j])
				++cnt;
		}
		if (!cnt)
			v3.push_back(v1[i]);
		cnt = 0;
	}

	if (!v3.size())
		cout << "vector 3 has no elements!" << endl;
	else {
		cout << "elements of new vector are : " << endl;
		output_vect(v3);
	}

}
