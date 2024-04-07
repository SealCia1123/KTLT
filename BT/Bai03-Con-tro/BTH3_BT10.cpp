#include <iostream>
#define MAX 10
#define MIN 1
using namespace std;

void allocate_mem(int ***mt, int row, int col);

void free_mem(int **mt, int row, int col);

void generateRandomArr(int **arr, int row, int col);

void print(int **arr, int row, int col);

int main()
{
	int row, col;
	cout << "Nhap so hang va so cot: ";
	cin >> row >> col;
	int **mt1, **mt2;

	allocate_mem(&mt1, row, col);
	allocate_mem(&mt2, row, col);

	generateRandomArr(mt1, row, col);
	generateRandomArr(mt2, row, col);

	print(mt1, row, col);
	print(mt2, row, col);

	free_mem(mt1, row, col);
	free_mem(mt2, row, col);
	return 0;
}

void allocate_mem(int ***mt, int row, int col)
{
	*mt = new int *[row];
	for (int i = 0; i < row; i++)
		(*mt)[i] = new int[col];
}

void generateRandomArr(int **arr, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			arr[i][j] = rand() % (MAX - MIN + 1) + MIN;
	}
}

void print(int **arr, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}
	cout << endl;
}

void free_mem(int **mt, int row, int col)
{
	for (int i = 0; i < row; i++)
		delete[] mt[i];
	delete[] mt;
}
