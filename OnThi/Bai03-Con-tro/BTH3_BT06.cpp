#include <ctime>
#include <iostream>
using namespace std;

void reverseArr(int *arr, int n)
{
	int left = 0, right = n - 1;
	while (left < right)
	{
		swap(arr[left], arr[right]);
		++left;
		--right;
	}
}

int main()
{
	srand(time(0));
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = rand() % (10 - 1 + 1) + 1;

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	reverseArr(arr, n);
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	delete[] arr;
	return 0;
}
