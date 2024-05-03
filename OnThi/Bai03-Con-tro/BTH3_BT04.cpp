#include <ctime>
#include <iostream>
using namespace std;

int main()
{
	int n;
	do
	{
		cout << "Nhap kich thuoc cua mang: ";
		cin >> n;
		if (n < 0 || n > 30)
			cout << "Nhap lai\n";
	} while (n < 0 || n > 30);
	int *arr = new int[n];

	for (int i = 0; i < n; i++)
		*(arr + i) = rand() % (100 - 1 + 1) + 1;

	cout << "Mang: ";
	for (int i = 0; i < n; i++)
		cout << *(arr + i) << " ";
	cout << endl;
	cout << "Cac phan tu la so le: ";
	int max = *(arr), *index = NULL;
	for (int i = 0; i < n; i++)
	{
		if (*(arr + i) % 2 != 0)
			cout << *(arr + i) << " ";
		if (max < *(arr + i))
		{
			max = *(arr + i);
			index = (arr + i);
		}
	}
	cout << "\nPhan tu lon nhat trong mang la: " << max << ", tai o nho: " << index << endl;
	cout << endl;
	delete[] arr;
	return 0;
}
