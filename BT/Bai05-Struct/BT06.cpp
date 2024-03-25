#include <iostream>
#include <string>
using namespace std;

struct SanPham
{
	char maSP[10];
	string tenSP;
	double donGia;
	int slTonKho;
};

void input(SanPham *sp, int size);

void print(const SanPham *sp, int size);

int main()
{
	int size;
	cout << "Nhap so luong san pham: ";
	cin >> size;
	cin.ignore();
	SanPham *listProducts = new SanPham[size];
	input(listProducts, size);
	print(listProducts, size);

	delete[] listProducts;
	listProducts = NULL;
	return 0;
}

void input(SanPham *sp, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "================Nhap thong tin san pham================\n";
		cout << "Nhap vao ma san pham: ";
		cin.getline(sp[i].maSP, 10);
		cout << "Nhap vao ten san pham: ";
		getline(cin, sp[i].tenSP);
		cout << "Nhap don gia: ";
		cin >> sp[i].donGia;
		cout << "Nhap so luong ton kho: ";
		cin >> sp[i].slTonKho;
		cin.ignore();
	}
}

void print(const SanPham *sp, int size)
{
	if (size == 0)
		cout << "Khong co san pham\n";
	else
	{
		for (int i = 0; i < size; i++)
		{
			cout << "============San pham thu " << i + 1 << "============\n";
			cout << "Ma san pham: " << sp[i].maSP << endl;
			cout << "Ten san pham: " << sp[i].tenSP << endl;
			cout << "Don gia: " << sp[i].donGia << endl;
			cout << "So luong ton kho: " << sp[i].slTonKho << endl;
		}
	}
}
