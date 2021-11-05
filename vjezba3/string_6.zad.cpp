//Napišite funkciju koja stringove, koje korisnik unosi, sprema u vektor stingova,
//2svaki string preokrene te sortira vektor po preokrenutim stringovima.
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void reverse_str(string& s) {
	int i = s.size() - 1;
	int j;
	string s2;
	s2.resize(s.size());
	for (i, j = 0;i>=0 ;--i, ++j) {
		s2[j] = s[i];
	}
	s = s2;
}

void input_vect_of_str(vector<string>& v, int n) {
	int i = 1;
	for (i;i <= n;++i) {
		string s;
		cout << i << ".string: ";
		getline(cin,s);
		reverse_str(s);
		v.push_back(s);
	}
}

void output_vect_of_str(vector<string>& v) {
	int i;
	for (i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main() {
	int n = 3;
	vector <string > v;
	input_vect_of_str(v, n);
	output_vect_of_str(v);
	sort(v.begin(), v.end());
	output_vect_of_str(v);
	return 0;
}