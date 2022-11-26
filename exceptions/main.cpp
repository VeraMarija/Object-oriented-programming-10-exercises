#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include <functional> 
using namespace std;
#define N 500

class greater_then{ // class for finding element greater then some value N
	int limit;
public:
	greater_then(int limit) : limit(limit) {}
	bool operator()(int n) { return n > limit; }
};
 

class e { //class for exeption
public:
	void print_exeption() { cout << "Unable to open file!"; }
};


void copyToVector(ifstream& fnum, vector<unsigned int>& v) { // copy all elements from file to the vector
	istream_iterator<unsigned int> it(fnum);
	istream_iterator<unsigned int> eos; // end of stream 
	copy(it, eos, back_inserter(v));
}


void countGreaterThenN(vector<unsigned int>& v) { // print elements greater then some N
	cout  << count_if(v.begin(), v.end(), greater_then(N)) <<" numbers are greater then " << N << endl;
}


void min_maxElement(vector<unsigned int>& v) { // print min max element
	cout << "min element is: " << *min_element(v.begin(), v.end()) << " and the max element is: " << *max_element(v.begin(), v.end()) << endl;
}


void throwSmaller(vector<unsigned int>& v) {  // throw all elements smaller then 300 from vector 
	v.erase(remove_if(v.begin(), v.end(), [](int n) { return n <300; }), v.end());
}


void sortDescending(vector<unsigned int>& v) { //sort the remaining numbers in descending order
	sort(v.begin(), v.end(), greater<unsigned int>());
}


void myFuntion(ifstream& fnum, vector<unsigned int>& v){ // main function for working on vector of natural numbers 
	fnum.open("numbers.txt");
	if (!fnum) {
		throw e();
	}
	copyToVector(fnum, v);
	countGreaterThenN(v);
	min_maxElement(v);
	throwSmaller(v);
	sortDescending(v);
}


int main() {
	vector<unsigned int> v;
	ifstream fnum;
	try {
		myFuntion(fnum,v);
	}
	catch(e exeption){
		exeption.print_exeption();
	}
}