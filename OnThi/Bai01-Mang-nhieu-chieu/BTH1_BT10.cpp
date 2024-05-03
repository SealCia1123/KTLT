#include <iostream>
using namespace std;

int main()
{
	int n, count = 1;
	cin >> n;
	int arr[10][10];
	int r1 = 0, c1 = 0, r2 = n - 1, c2 = n - 1;
	while (r1 <= r2 && c1 <= c2)
	{
		for (int i = c1; i <= c2; i++)
			arr[r1][i] = count++;
		++r1;
		for (int i = r1; i <= r2; i++)
			arr[i][c2] = count++;
		--c2;
		for (int i = c2; i >= c1; i--)
			arr[r2][i] = count++;
		--r2;
		for (int i = r2; i >= r1; i--)
			arr[i][c1] = count++;
		++c1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}
	return 0;
}
