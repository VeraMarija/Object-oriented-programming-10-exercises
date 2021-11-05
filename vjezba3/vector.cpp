#include<iostream>
#include "vector.hpp"
#include<algorithm>
using namespace std;

int sum_fun(vector<int>& v) {
	int i, cnt = 0;
	for (i = 0;i < v.size();++i) {
		cnt += v[i];
	}
	return cnt;
}

void remove_vect(vector<int>& v,int i) {
	v[i-1]= v[v.size() - 1];
	v.pop_back();
}

void input_vect1(vector<int>& v, int n)  {
	int i = 1,x;
	for (i;i <= n;++i) {
		cout << "enter " << i << ". element: " << endl;
		cin >> x;
		v.push_back(x);
	}
}

void input_vect2(vector<int>& v, int a, int b) {
	
	int i = 1,x;
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

int main() {
	//1.task
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

	//2.task
	vector<int> v3;
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
		cout  << "vector 3 has no elements!" << endl;
	else {
		cout  << "elements of new vector are : " << endl;
		output_vect(v3);
	}

	//3.task
	vector <int > v4 { 1,4,3,8,-3 };
	cout << "vector before sorting: " << endl;
	output_vect(v4);
	sort(v4.begin(), v4.end());
	cout  <<"vector after sorting: " << endl;
	output_vect(v4);
	int sum = sum_fun(v4);
	vector<int>::iterator it = v4.begin();
	v4.insert(it,0);
	v4.insert(v4.end(), sum);
	output_vect(v4);

	//4.task
	int position= v4.size() / 2;
	remove_vect(v4,position);
	cout << "removing " << position << ".element  ";
	output_vect(v4);
	return 0;
}