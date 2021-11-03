#include<iostream>
using namespace std;

int& ref_to_elem(int* arr, int i)
{
	//arr[i] = arr[i] + 1;
	return ++arr[i];

}
int main()
{
	int arr[] = { 0,4,-5,2,1 };
	int i = 3;

	ref_to_elem(arr, i);
	cout << "element increased by 1 is: " << arr[i] << endl;
	return 0;
}