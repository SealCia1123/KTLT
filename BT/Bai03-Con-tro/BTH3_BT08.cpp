#include <iostream>

using namespace std;

int main()
{
	int h;
	cout << "Nhap kich thuoc ma tran: ";
	cin >> h;
	int **mt = new int *[h];
	for (int i = 0; i < h; i++)
		mt[i] = new int[h];

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (i == 0 || j == 0)
				mt[i][j] = 1;
			else
				mt[i][j] = mt[i - 1][j - 1] + mt[i - 1][j];
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j <= i; j++)
			cout << mt[i][j] << " ";
		cout << endl;
	}

	for (int i = 0; i < h; i++)
		delete[] mt[i];
	delete[] mt;
	return 0;
}
