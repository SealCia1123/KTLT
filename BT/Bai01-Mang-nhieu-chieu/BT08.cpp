#include <iostream>
#define MAX_SIZE 10
using namespace std;

void generateRandomArr(int arr[MAX_SIZE][MAX_SIZE], int n);

void output(const int arr[MAX_SIZE][MAX_SIZE], int n);

void sum(const int firstArr[MAX_SIZE][MAX_SIZE], const int secondArr[MAX_SIZE][MAX_SIZE], int n);

void multiply(const int firstArr[MAX_SIZE][MAX_SIZE], const int secondArr[MAX_SIZE][MAX_SIZE], int n);

int main()
{
	int n;
	int firstArr[MAX_SIZE][MAX_SIZE], secondArr[MAX_SIZE][MAX_SIZE];
	cout << "Nhap kich thuoc cua mang: ";
	cin >> n;
	generateRandomArr(firstArr, n);
	output(firstArr, n);
	cout << endl;
	generateRandomArr(secondArr, n);
	output(secondArr, n);

	sum(firstArr, secondArr, n);
	multiply(firstArr, secondArr, n);
	return 0;
}

void generateRandomArr(int arr[MAX_SIZE][MAX_SIZE], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			arr[i][j] = rand() % (100 - 1 + 1) + 1;
	}
}

void output(const int arr[MAX_SIZE][MAX_SIZE], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}
}

void sum(const int firstArr[MAX_SIZE][MAX_SIZE], const int secondArr[MAX_SIZE][MAX_SIZE], int n)
{
	cout << "TONG hai ma tran:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << firstArr[i][j] + secondArr[i][j] << "\t";
		cout << endl;
	}
}

void multiply(const int firstArr[MAX_SIZE][MAX_SIZE], const int secondArr[MAX_SIZE][MAX_SIZE], int n)
{
	cout << "TICH hai ma tran:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << firstArr[i][j] * secondArr[i][j] << "\t";
		cout << endl;
	}
}
