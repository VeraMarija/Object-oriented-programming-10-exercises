//3.Napisati iterativnu funkciju za traženje najveæeg i najmanjeg broja u nizu.

#include<iostream>
using namespace std;

void min_max(int* arr, int n, int* min, int* max)
{
	*min = arr[0];
	*max = arr[0];
	for (int i = 0;i < n;++i)
	{
		if (arr[i] <= *min)
			*min = arr[i];
		if (arr[i] >= *max)
			*max = arr[i];
	}
}
int main()
{
	int arr[] = { 1,2,34,5,6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int min, max;
	min_max(arr, n, &min, &max);
	cout << "smallest number is: " << min << endl;
	cout << "biggest number is: " << max << endl;
}
