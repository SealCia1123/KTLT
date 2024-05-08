// Tim so nho nhat trong mang
#include <iostream>
#define MAX_SIZE 10
using namespace std;

int minOfArr(const int arr[], int start, int end);

int main()
{
	int arr[MAX_SIZE], n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << minOfArr(arr, 0, n - 1) << "\n";
	return 0;
}

int minOfArr(const int arr[], int start, int end)
{
	if (start == end)
		return arr[start];
	int min = minOfArr(arr, start + 1, end);
	if (arr[start] < min)
		min = arr[start];
	return min;
}
