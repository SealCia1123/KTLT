#include <cstring>
#include <iostream>
#include <string>
#define MAX_PRODUCTS 30
#define MAX_CHAR_SIZE 11
using namespace std;

struct SanPham
{
	char maSP[MAX_CHAR_SIZE];
	string tenSP;
	double donGia;
	int slTonKho;
};

void input(SanPham &sp);

void inputProducts(SanPham *dsSanPham, int index, int size);

void print(const SanPham *sp, int size);

void modify(SanPham *dsSP, int size, char *maSPCanTim);

void deleteProduct(SanPham *dsSP, int &size, char *maSPCanXoa);

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
		cout << "1. Nhap san pham\n";
		cout << "2. Xuat danh sach san pham\n";
		cout << "3. Sua san pham\n";
		cout << "4. Xoa san pham\n";
		cout << "5. Sap xep san pham theo so luong ton kho\n";
		cout << "0. Thoat chuong trinh\n";
		cout << "Nhap lua chon: ";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
		{
			int temp;
			do
			{
				cout << "Nhap so luong san pham can them: ";
				cin >> temp;
				cin.ignore();
				if (temp < 0 || temp + currentSize > MAX_PRODUCTS)
					cout << "So luong nhap khong hop le, nhap lai\n";
			} while (temp < 0 || temp + currentSize > MAX_PRODUCTS);
			inputProducts(listProducts, currentSize, currentSize + temp);
			currentSize += temp;
			break;
		}

		case 2:
		{
			cout << "THONG TIN SAN PHAM\n";
			print(listProducts, currentSize);
			break;
		}

		case 3:
		{
			cout << "CHINH SUA SAN PHAM\n";
			if (currentSize == 0)
			{
				cout << "Danh sach san pham hien dang trong\n";
				break;
			}
			char maSPCanTim[MAX_CHAR_SIZE];
			cout << "Nhap vao ma san pham can tim: ";
			cin.getline(maSPCanTim, MAX_CHAR_SIZE);
			modify(listProducts, currentSize, maSPCanTim);
			break;
		}

		case 4:
		{
			cout << "XOA SAN PHAM\n";
			if (currentSize == 0)
			{
				cout << "Danh sach san pham hien dang trong\n";
				break;
			}
			char maSPCanXoa[MAX_CHAR_SIZE];
			cout << "Nhap vao ma san pham can xoa: ";
			cin.getline(maSPCanXoa, MAX_CHAR_SIZE);
			deleteProduct(listProducts, currentSize, maSPCanXoa);
			break;
		}

		case 5:
		{
			cout << "SAP XEP THEO SO LUONG TON KHO\n";
			sortProducts(listProducts, currentSize);
			break;
		}
		case 0:
		{
			delete[] listProducts;
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
			cout << "Ket thuc chuong trinh\n";
			return 0;
		}
	}
}

void input(SanPham &sp)
{
	cout << "Nhap vao ma san pham: ";
	cin.getline(sp.maSP, MAX_CHAR_SIZE);
	cout << "Nhap vao ten san pham: ";
	getline(cin, sp.tenSP);
	cout << "Nhap don gia: ";
	cin >> sp.donGia;
	cout << "Nhap so luong ton kho: ";
	cin >> sp.slTonKho;
	cin.ignore();
}

void inputProducts(SanPham *dsSanPham, int index, int size)
{
	for (int i = index; i < size; i++)
	{
		cout << "==== NHAP SAN PHAM THU " << i + 1 << " ====\n";
		input(dsSanPham[i]);
	}
}

void print(const SanPham *sp, int size)
{
	if (size == 0)
	{
		cout << "Danh sach san pham hien dang trong\n";
		return;
	}
	cout << "=========================================\n";
	for (int i = 0; i < size; i++)
	{
		cout << "San pham thu " << i + 1 << "\n";
		cout << "Ma san pham: " << sp[i].maSP << endl;
		cout << "Ten san pham: " << sp[i].tenSP << endl;
		cout << "Don gia: " << sp[i].donGia << endl;
		cout << "So luong ton kho: " << sp[i].slTonKho << endl;
		cout << "=========================================\n";
	}
}

void modify(SanPham *dsSP, int size, char *maSPCanTim)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(dsSP[i].maSP, maSPCanTim) == 0)
		{
			cout << "1. Sua ten san pham\n";
			cout << "2. Sua don gia\n";
			cout << "3. Sua so luong ton kho\n";
			cout << "Nhap lua chon: ";
			int choice;
			cin >> choice;
			cin.ignore();
			switch (choice)
			{
			case 1:
				cout << "Nhap ten san pham: ";
				getline(cin, dsSP[i].tenSP);
				break;
			case 2:
				cout << "Nhap don gia: ";
				cin >> dsSP[i].donGia;
				break;
			case 3:
				cout << "Nhap so luong ton kho: ";
				cin >> dsSP[i].slTonKho;
				break;
			default:
				cout << "Lua chon khong hop le!\n";
			}
			return;
		}
	}
	cout << "KHONG TIM THAY!\n";
}

void deleteProduct(SanPham *dsSP, int &size, char *maSPCanXoa)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(dsSP[i].maSP, maSPCanXoa) == 0)
		{
			for (int j = i + 1; j < size; j++)
			{
				strcpy(dsSP[j - 1].maSP, dsSP[j].maSP);
				dsSP[j - 1].tenSP = dsSP[j].tenSP;
				dsSP[j - 1].donGia = dsSP[j].donGia;
				dsSP[j - 1].slTonKho = dsSP[j].slTonKho;
			}
			cout << "XOA SAN PHAM THANH CONG!\n";
			--size;
			return;
		}
	}
	cout << "KHONG TIM THAY!\n";
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
		}
	}
}
