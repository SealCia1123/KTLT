// Tong hang/cot
#include <iostream>
using namespace std;

int main()
{
	int arr[10][10];
	int r, c;
	cout << "Nhap hang, cot: ";
	cin >> r >> c;

	cout << "Nhap mang: ";
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			cout << arr[i][j] << "\t";
		cout << "\n";
	}

	int hangCanTinh, tongHang = 0, cotCanTinh, tongCot = 0;
	cout << "Nhap hang can tinh, cot can tinh: ";
	cin >> hangCanTinh >> cotCanTinh;
	hangCanTinh -= 1, cotCanTinh -= 1;
	for (int i = 0; i < c; i++)
		tongHang += arr[hangCanTinh][i];
	for (int i = 0; i < r; i++)
		tongCot += arr[i][cotCanTinh];
	cout << "Tong hang can tinh: " << tongHang << "\nTong cot can tinh: " << tongCot << "\n";
	return 0;
}
