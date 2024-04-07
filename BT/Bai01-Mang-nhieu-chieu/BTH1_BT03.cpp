#include <iostream>
#define MAX_ROW 10
#define MAX_COL 15
using namespace std;

int main()
{
	int row, col;
	int arr[MAX_ROW][MAX_COL];
	do
	{
		cout << "Nhap vao so hang va so cot: ";
		cin >> row >> col;
		if (row > MAX_ROW || col > MAX_COL)
			cout << "Nhap so dong nho hon 10 va so cot nho hon 15\n";
	} while (row > MAX_ROW || col > MAX_COL);

	cout << "Nhap phan tu vao mang: ";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cin >> arr[i][j];
	}
	cout << "Mang da nhap: \n";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}

	int sum = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			sum += arr[i][j];
	}
	cout << "Tong cac phan tu trong mang la: " << sum << endl;

	int max = arr[0][0], min = arr[0][0];
	int minIndex[2] = {0, 0}, maxIndex[2] = {0, 0};
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] > max)
			{
				max = arr[i][j];
				maxIndex[0] = i;
				maxIndex[1] = j;
			}

			if (arr[i][j] < min)
			{
				min = arr[i][j];
				minIndex[0] = i;
				minIndex[1] = j;
			}
		}
	}
	cout << "Phan tu lon nhat trong mang: " << max << endl;
	cout << "Phan tu nho nhat trong mang: " << min << endl;
	cout << "Vi tri phan tu nho nhat o hang thu " << minIndex[0] + 1 << " va cot thu " << minIndex[1] + 1 << endl;
	cout << "Vi tri phan tu lon nhat o hang thu " << maxIndex[0] + 1 << " va cot thu " << maxIndex[1] + 1 << endl;
	return 0;
}
