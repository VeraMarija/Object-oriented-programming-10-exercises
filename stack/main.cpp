#include "sorted.h"
#include<iostream>
#include<iomanip>
#include "stack.h"

int main() {
	int n;
	double array[]= { 1.256,2.11,5.15,6.4546,9.02 };
	double* p = array;
	n = sizeof(array) / sizeof(array[0]);
	p = returnSorted(p, n);
	for (int i = 0;i < n;++i) {
		std::cout << p[i] << std::endl;
	}
	std::cout << std::endl;
	char array2[] = { 'a','b','C','B','e'};
	char* pc = array2;
	n = sizeof(array2) / sizeof(array2[0]);
	pc = returnSorted(pc, n);
	for (int i = 0;i < n;++i) {
		std::cout << pc[i] << std::endl;
	}


	Stack<char> s;
	s.push_element('A');
	s.push_element('B');
	s.push_element('C');
	s.push_element('D');
	s.push_element('E');
	char* a=s.get_array();
	int m = s.get_size();
	std::cout << std::endl;
	for (int i = 0;i < m;++i) {
		std::cout << a[i] << std::endl;
		
	}
	s.pop_element();
	std::cout << std::endl;
	m = s.get_size();
	for (int i = 0;i < m;++i) {
		std::cout << a[i] << std::endl;

	}



}