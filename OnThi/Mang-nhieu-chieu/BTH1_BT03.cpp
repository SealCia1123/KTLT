// Dung while nhap xuat, tinh tong, max, min
#include <iostream>
#define MAX_ROW 10
#define MAX_COL 15
using namespace std;

int main()
{
	int arr[MAX_COL][MAX_ROW];
	int i = 0, j = 0, row, col;
	do
	{
		cout << "Nhap so dong va so cot: ";
		cin >> row >> col;
		if (row > 10 || row < 0 || col > 15 || col < 0)
			cout << "Nhap lai\n";
	} while (row > 10 || row < 0 || col > 15 || col < 0);

	cout << "Nhap phan tu vao mang: ";
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			cin >> arr[i][j];
			j++;
		}
		i++;
	}

	i = 0, j = 0;
	cout << "Mang vua nhap:\n";
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			cout << arr[i][j] << "\t";
			j++;
		}
		cout << "\n";
		i++;
	}

	i = 0, j = 0;
	int sum = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			sum += arr[i][j];
			j++;
		}
		i++;
	}
	cout << "Tong cac phan tu trong mang: " << sum << "\n";

	i = 0, j = 0;
	int max = arr[0][0], min = arr[0][0];
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if (arr[i][j] > max)
				max = arr[i][j];
			if (arr[i][j] < min)
				min = arr[i][j];
			j++;
		}
		i++;
	}
	cout << "Max: " << max << "\n"
		 << "Min: " << min << "\n";
	return 0;
}
