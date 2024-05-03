#include <iostream>
using namespace std;

int main()
{
	int n, count = 1;
	int arr[10][10];
	cin >> n;
	for (int j = 0; j < n; j++)
	{
		if (j % 2 != 0)
		{
			for (int i = n - 1; i >= 0; i--)
				arr[i][j] = count++;
		}
		else
		{
			for (int i = 0; i < n; i++)
				arr[i][j] = count++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << arr[i][j] << "\t";
		cout << "\n";
	}
	return 0;
}
