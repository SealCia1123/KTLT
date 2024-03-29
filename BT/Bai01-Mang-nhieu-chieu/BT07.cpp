#include <climits>
#include <iostream>
#define MAX_COL 10
#define MAX_ROW 10
using namespace std;

void inputArr(int arr[MAX_ROW][MAX_COL], int row, int col);

void output(const int arr[MAX_ROW][MAX_COL], int row, int col);

double averangeValue(const int arr[MAX_ROW][MAX_COL], int row, int col);

int findValue(const int arr[MAX_ROW][MAX_COL], int row, int col, int &value);

void swapTwoElements(int arr[MAX_ROW][MAX_COL], int row, int col, int &x, int &y);

int multiply(const int arr[MAX_ROW][MAX_COL], int row, int col, int &x);

int main()
{
	int row, col;
	int arr[MAX_ROW][MAX_COL];
	cout << "Nhap vao so hang va cot: ";
	cin >> row >> col;
	inputArr(arr, row, col);
	output(arr, row, col);
	cout << "Gia tri trung binh cua ma tran: " << averangeValue(arr, row, col) << endl;

	int value;
	if (findValue(arr, row, col, value) == INT_MIN)
		cout << "Khong tim thay " << value << endl;
	else
		cout << "Tim thay " << value << " trong mang\n";

	int x, y;
	swapTwoElements(arr, row, col, x, y);
	output(arr, row, col);

	int mulCol;
	cout << "Tich cot can tinh: " << multiply(arr, row, col, mulCol) << endl;
	return 0;
}

void inputArr(int arr[MAX_ROW][MAX_ROW], int row, int col)
{
	cout << "Nhap phan tu vao mang: ";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cin >> arr[i][j];
	}
}

void output(const int arr[MAX_ROW][MAX_COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}
}

double averangeValue(const int arr[MAX_ROW][MAX_COL], int row, int col)
{
	double result = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			result += arr[i][j];
	}
	result /= row * col;
	return result;
}

int findValue(const int arr[MAX_ROW][MAX_COL], int row, int col, int &value)
{
	cout << "Nhap vao gia tri can tim: ";
	cin >> value;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (value == arr[i][j])
				return arr[i][j];
		}
	}
	return INT_MIN;
}

void swapTwoElements(int arr[MAX_ROW][MAX_COL], int row, int col, int &x, int &y)
{
	int rX = -1, rY = -1, cX, cY;
	cout << "Nhap vao hai gia tri muon hoan doi: ";
	cin >> x >> y;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] == x)
			{
				rX = i;
				cX = j;
			}
			if (arr[i][j] == y)
			{
				rY = i;
				cY = j;
			}
		}
	}

	if (rX == -1 || rY == -1)
		cout << "Phan tu khong co trong mang\n";
	else
	{
		int temp = arr[rX][cX];
		arr[rX][cX] = arr[rY][cY];
		arr[rY][cY] = temp;
	}
}

int multiply(const int arr[MAX_ROW][MAX_COL], int row, int col, int &x)
{
	cout << "Nhap vao cot can tinh tich: ";
	cin >> x;
	--x;
	int result = 1;
	for (int i = 0; i < row; i++)
		result *= arr[i][x];
	return result;
}
