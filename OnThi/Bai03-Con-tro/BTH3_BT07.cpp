#include <iostream>
using namespace std;

int *searchElement(int *arr, int n, int value)
{
	for (int i = 0; i < n; i++)
	{
		if (*(arr + i) == value)
			return (arr + i);
	}
	return NULL;
}

int main()
{
	int arr[4] = {1, 2, 3, 4};
	cout << "Test: " << (arr + 2) << endl;
	cout << "Result: " << searchElement(arr, 4, 3) << endl;
	return 0;
}
