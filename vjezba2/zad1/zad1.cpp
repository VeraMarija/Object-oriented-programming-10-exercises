#include<iostream>
using namespace std;

void min_max(int& min, int& max, int* arr, int len)
{
	int i;
	for (i = 1;i < len;++i) {
		if (arr[i] < min) {
			min = arr[i];
		}
		if (arr[i] > max) {
			max = arr[i];
		}
	}
}
int main()
{
	int arr[] = { 1,2,5,6,7,9,-5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int min = arr[0], max = arr[0];
	min_max(min, max, arr, len);
	cout << "the smallest element of array is:  " << min << endl;
	cout << "the biggest element of array is:  " << max << endl;
	return 0;
}