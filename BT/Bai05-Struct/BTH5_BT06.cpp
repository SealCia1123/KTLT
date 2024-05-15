#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
#define MAX_PRODUCTS 30
using namespace std;

struct SanPham
{
	char maSP[10];
	string tenSP;
	double donGia;
	int slTonKho;
};

void input(SanPham &sp);

void print(const SanPham *sp, int size);

void modify(SanPham &sp);

void deleteProduct(SanPham *sp, int index, int &size);

void mySwap(SanPham &a, SanPham &b);

void sortProducts(SanPham *sp, int currentSize);

int main()
{
	int currentSize = 0;
	SanPham *listProducts = new SanPham[MAX_PRODUCTS];
	int choice;
	while (true)
	{
		system("clear");
		cout << "1. Nhap thong tin san pham\n";
		cout << "2. Xuat thong tin san pham\n";
		cout << "3. Sua thong tin san pham\n";
		cout << "4. Xoa thong tin san pham\n";
		cout << "5. Sap xep lai san pham theo so luong ton kho\n";
		cout << "0. Thoat chuong trinh\n";
		cout << "Nhap lua chon: ";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
		{
			if (currentSize > MAX_PRODUCTS)
				cout << "So luong san pham vuot qua muc toi da\n";
			else
				input(listProducts[currentSize++]);
			break;
		}

		case 2:
		{
			cout << "====Thong tin san pham====\n";
			print(listProducts, currentSize);
			break;
		}

		case 3:
		{
			cout << "====Chinh sua thong tin san pham====\n";
			if (currentSize == 0)
			{
				cout << "Danh sach san pham hien dang trong\n";
				break;
			}
			int modifiedIndex = 0;
			do
			{
				cout << "Nhap so thu tu san pham can chinh sua: ";
				cin >> modifiedIndex;
				cin.ignore();
				if (modifiedIndex < 0 || modifiedIndex > currentSize)
					cout << "Nhap lai so thu tu cua san pham\n";
			} while (modifiedIndex < 0 || modifiedIndex > currentSize);
			modify(listProducts[--modifiedIndex]);
			break;
		}

		case 4:
		{
			cout << "====Xoa san pham====\n";
			if (currentSize == 0)
			{
				cout << "Danh sach san pham hien dang trong\n";
				break;
			}
			int deleteIndex = 0;
			do
			{
				cout << "Nhap so thu tu san pham can xoa: ";
				cin >> deleteIndex;
				if (deleteIndex < 0 || deleteIndex > currentSize)
					cout << "Nhap lai so thu tu cua san pham\n";
			} while (deleteIndex < 0 || deleteIndex > currentSize);
			deleteProduct(listProducts, --deleteIndex, currentSize);
			print(listProducts, currentSize);
			break;
		}

		case 5:
		{
			cout << "Sap xep thu tu san pham theo so luong ton kho\n";
			sortProducts(listProducts, currentSize);
			print(listProducts, currentSize);
			break;
		}
		case 0:
		{
			delete[] listProducts;
			listProducts = NULL;
			cout << "Ket thuc chuong trinh\n";
			return 0;
		}
		}
		int isContinue;
		cout << "Tiep tuc chuong trinh (1/0): ";
		cin >> isContinue;
		cin.ignore();
		if (!isContinue)
		{
			delete[] listProducts;
			listProducts = NULL;
			cout << "Ket thuc chuong trinh\n";
			return 0;
		}
	}
}

void input(SanPham &sp)
{
	cout << "====Nhap thong tin san pham====\n";
	cout << "Nhap vao ma san pham: ";
	cin.getline(sp.maSP, 10);
	cout << "Nhap vao ten san pham: ";
	getline(cin, sp.tenSP);
	cout << "Nhap don gia: ";
	cin >> sp.donGia;
	cout << "Nhap so luong ton kho: ";
	cin >> sp.slTonKho;
	cin.ignore();
}

void print(const SanPham *sp, int size)
{
	if (size == 0)
	{
		cout << "Danh sach san pham hien dang trong\n";
		return;
	}
	for (int i = 0; i < size; i++)
	{
		cout << "===San pham thu " << i + 1 << "===\n";
		cout << "Ma san pham: " << sp[i].maSP << endl;
		cout << "Ten san pham: " << sp[i].tenSP << endl;
		cout << "Don gia: " << fixed << setprecision(0) << sp[i].donGia << endl;
		cout << "So luong ton kho: " << sp[i].slTonKho << endl;
	}
	cout << "=========================================\n";
}

void modify(SanPham &sp)
{
	cout << "Nhap vao ma san pham: ";
	cin.getline(sp.maSP, 10);
	cout << "Nhap vao ten san pham: ";
	getline(cin, sp.tenSP);
	cout << "Nhap don gia: ";
	cin >> sp.donGia;
	cout << "Nhap so luong ton kho: ";
	cin >> sp.slTonKho;
	cin.ignore();
}

void deleteProduct(SanPham *sp, int index, int &size)
{
	if (index < size - 1)
	{
		for (int i = index + 1; i < size; i++)
		{
			strcpy(sp[i - 1].maSP, sp[i].maSP);
			sp[i - 1].tenSP = sp[i].tenSP;
			sp[i - 1].donGia = sp[i].donGia;
			sp[i - 1].slTonKho = sp[i].slTonKho;
		}
	}
	--size;
	cout << "=========Xoa san pham thanh cong=========\n";
}

void mySwap(SanPham &a, SanPham &b)
{
	SanPham temp = a;
	a = b;
	b = temp;
}

void sortProducts(SanPham *sp, int currentSize)
{
	for (int i = 0; i < currentSize; i++)
	{
		for (int j = 0; j < currentSize - i - 1; j++)
		{
			if (sp[j].slTonKho > sp[j + 1].slTonKho)
				mySwap(sp[j], sp[j + 1]);
			// mySwap(sp[j].maSP, sp[j + 1].maSP);
			// mySwap(sp[j].tenSP, sp[j + 1].tenSP);
			// mySwap(sp[j].donGia, sp[j + 1].donGia);
			// mySwap(sp[j].slTonKho, sp[j + 1].slTonKho);
		}
	}
}
