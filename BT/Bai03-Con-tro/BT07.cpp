#include <iostream>
using namespace std;

int *find(int *arr, int n, int value);

int main()
{
	int n, arr[20], x;
	cout << "Nhap kich thuoc cua mang: ";
	cin >> n;
	cout << "Nhap vao phan tu cua mang: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << "Nhap gia tri can tim: ";
	cin >> x;
	if (find(arr, n, x) == NULL)
		cout << "Khong tim thay gia tri trong mang\n";
	else
		cout << "Tim thay gia tri tai vi tri " << find(arr, n, x) << " trong mang\n";
	return 0;
}

int *find(int *arr, int n, int value)
{
	int *p = NULL;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == value)
			return (p = arr + i);
	}
	return p;
}
