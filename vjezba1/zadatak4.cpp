//4. Napisati rekurzivnu funkciju za traženje najveæeg i najmanjeg broja u nizu.
#include<iostream>
int funkcija(int* arr, int l, int* min, int* max)
{
	if (l <= 0)
		return 0;
	if (arr[l] <= *min)
		*min = arr[l];
	if (arr[l] >= *max)
		*max = arr[l];
	funkcija(arr, l - 1, min, max);

}
int main()
{
	int arr[] = { 1,5,6,7,-2,10 };
	int l = sizeof(arr) / sizeof(arr[0]);
	int min=0, max=0;
	funkcija(arr,l-1, &min, &max);
	std::cout << "najmanji broj je-- >" << min << std::endl;
	std::cout << "najveci broj je --> " << max;
}