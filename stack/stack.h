#ifndef STACK_H
#define STACK_H
#include<iostream>
/*push, pop i is_empty
zadnji koji ulazi - prvi izlazi*/

template <typename T>
class Stack {
private:
	int capacity;
	int size;
	T* array;
public:
	Stack() { size = 0; array = new T[10]; }
	int get_size() { return size; }
	void push_element(T e) { array[size] = e; size++; }
	void pop_element() { size--; }
	bool is_empty();
	T* get_array() { return array; }
	~Stack() { delete [] array; std::cout << "delete"; }
};

template<typename T> bool Stack<T>::is_empty() {
	if (size)
		return 1;
	return 0;
}

#endif