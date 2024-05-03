#include <iostream>
#define MAX_SIZE 10
using namespace std;

int sumOfArr(const int arr[], int n);

int main()
{
	int arr[MAX_SIZE];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << sumOfArr(arr, n) << "\n";
	return 0;
}

int sumOfArr(const int arr[], int n)
{
	if (n - 1 == 0)
		return arr[0];
	return arr[n - 1] + sumOfArr(arr, n - 1);
}
