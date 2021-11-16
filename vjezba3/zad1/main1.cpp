#include<iomanip>
#include<iostream>
#include<vector>
#include "vector.h"
using namespace std;

int main() {
	
	int n, x, y;
	cout << "enter how much elements you want: " << endl;
	cin >> n;
	vector <int> v1;
	input_vect1(v1, n);
	output_vect(v1);
	cout << endl;
	cout << "enter the limits of the interval(first number must be smaller than the second!)  " << endl;
	cin >> x;
	cin >> y;
	while (x >= y) {
		cout << "error!enter again!" << endl;
		cin >> x;
		cin >> y;
	}
	vector <int> v2;
	input_vect2(v2, x, y);
	output_vect(v2);


}