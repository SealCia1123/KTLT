// Nhan ma tran
#include <iostream>
#define MAX_ROW 10
#define MAX_COL 10

using namespace std;

int main()
{
	int a[MAX_ROW][MAX_COL], b[MAX_ROW][MAX_COL];
	int r1, c1, r2, c2;
	cin >> r1 >> c1;
	for (int i = 0; i < r1; i++)
	{
		for (int j = 0; j < c1; j++)
			cin >> a[i][j];
	}
	for (int i = 0; i < r1; i++)
	{
		for (int j = 0; j < c1; j++)
			cout << a[i][j] << "\t";
		cout << "\n";
	}

	cin >> r2 >> c2;
	for (int i = 0; i < r2; i++)
	{
		for (int j = 0; j < c2; j++)
			cin >> b[i][j];
	}
	for (int i = 0; i < r2; i++)
	{
		for (int j = 0; j < c2; j++)
			cout << b[i][j] << "\t";
		cout << "\n";
	}

	if (c1 != r2)
	{
		cout << "Error\n";
		return 0;
	}
	int c[MAX_ROW][MAX_COL] = {{0}};
	int r3 = r1, c3 = c2;
	for (int i = 0; i < r3; i++)
	{
		for (int j = 0; j < c3; j++)
		{
			for (int k = 0; k < c1; k++)
				c[i][j] += a[i][k] * b[k][j];
		}
	}

	for (int i = 0; i < r3; i++)
	{
		for (int j = 0; j < c3; j++)
			cout << c[i][j] << "\t";
		cout << "\n";
	}
	return 0;
}
