#include <iostream>
using namespace std;

int main()
{
	int h;
	cin >> h;
	int **arr = new int *[h];
	for (int i = 0; i < h; i++)
		arr[i] = new int[h];

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (i == 0 || j == 0 || j == i)
				arr[i][j] = 1;
			else
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < h; i++)
		delete[] arr[i];
	delete[] arr;
	return 0;
}
