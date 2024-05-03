#include <iostream>
#define MAX_SIZE 10
using namespace std;

void printPascalTriagle(int h);

/* int ctToHop(int n, int k); */
/**/
/* void inTamGiac(int h); */

int main()
{
	int h;
	cin >> h;
	printPascalTriagle(h);
	return 0;
}

void printPascalTriagle(int h)
{
	int triagle[MAX_SIZE][MAX_SIZE] = {{0}};
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (i == 0 || j == i || j == 0)
				triagle[i][j] = 1;
			else
				triagle[i][j] = triagle[i - 1][j - 1] + triagle[i - 1][j];
			cout << triagle[i][j] << "\t";
		}
		cout << "\n";
	}
}

/* int ctToHop(int n, int k) */
/* { */
/* 	if (k == 0 || n == k) */
/* 		return 1; */
/* 	return ctToHop(n - 1, k - 1) + ctToHop(n - 1, k); */
/* } */
/**/
/* void inTamGiac(int h) */
/* { */
/* 	for (int i = 0; i < h; i++) */
/* 	{ */
/* 		for (int j = 0; j <= i; j++) */
/* 			cout << ctToHop(i, j) << "\t"; */
/* 		cout << "\n"; */
/* 	} */
/* } */
