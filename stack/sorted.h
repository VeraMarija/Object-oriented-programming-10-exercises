#ifndef SORTED_H
#define SORTED_H
#include<iostream>

template <typename T>
T* returnSorted(T* array, int n) {
	for (int i = 0;i < n - 1;i++) {
		for (int j = i + 1;j < n;++j) {
			if (array[i] > array[j]) {
				int b = array[i];
				array[i] = array[j];
				array[j] = b;
			}
		}
	}
	return array;
}

template <>
char* returnSorted(char* array, int n) {
	for (int i = 0;i < n - 1;i++) {
		for (int j = i + 1;j < n;++j) {
			if (toupper(array[i]) > toupper(array[j])) {
				int b = array[i];
				array[i] = array[j];
				array[j] = b;
			}
		}
	}
	return array;
}


#endif