#include<iostream>
#include "vector.h"
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector <int > v4;
	input_vect1(v4, 5);
	cout << "vector before sorting: " << endl;
	output_vect(v4);
	sort(v4.begin(), v4.end());
	cout << "vector after sorting: " << endl;
	output_vect(v4);
	int sum = sum_fun(v4);
	vector<int>::iterator it = v4.begin();
	v4.insert(it, 0);
	v4.insert(v4.end(), sum);
	output_vect(v4);
	
}