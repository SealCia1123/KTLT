#include <iostream>
#define MAX_SIZE 10
using namespace std;

int sumOfArr(const int arr[], int n);

int main()
{
	int n, arr[MAX_SIZE];
	cout << "Nhap kich thuoc cua mang: ";
	cin >> n;
	cout << "Nhap phan tu vao mang: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << "Tong cac phan tu trong mang: " << sumOfArr(arr, n - 1) << endl;
	return 0;
}

int sumOfArr(const int arr[], int n)
{
	if (n == 0)
		return arr[0];
	return arr[n] + sumOfArr(arr, n - 1);
}
