#include <cstring>
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
			if (currentSize > MAX_PRODUCTS)
				cout << "So luong san pham vuot qua muc toi da\n";
			else
				input(listProducts[currentSize++]);
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
			cout << "XOA SAN PHAM\n";
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
				cin.ignore();
				if (deleteIndex < 0 || deleteIndex > currentSize)
					cout << "Nhap lai so thu tu cua san pham\n";
			} while (deleteIndex < 0 || deleteIndex > currentSize);
			deleteProduct(listProducts, --deleteIndex, currentSize);
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
	cout << "Nhap thong tin san pham\n";
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

void modify(SanPham &sp)
{
	int choice;
	cout << "1. Sua ma san pham\n";
	cout << "2. Sua ten san pham\n";
	cout << "3. Sua don gia\n";
	cout << "4. Sua so luong ton kho\n";
	cout << "Nhap lua chon: ";
	cin >> choice;
	cin.ignore();
	switch (choice)
	{
	case 1:
		cout << "Nhap ma san pham moi: ";
		cin.getline(sp.maSP, 10);
		break;
	case 2:
		cout << "Nhap ten san pham moi: ";
		getline(cin, sp.tenSP);
		break;
	case 3:
		cout << "Nhap don gia moi: ";
		cin >> sp.donGia;
		break;
	case 4:
		cout << "Nhap so luong ton kho moi: ";
		cin >> sp.slTonKho;
		break;
	default:
		cout << "Lua chon khong hop le\n";
	}
}

void deleteProduct(SanPham *sp, int index, int &size)
{
	for (int i = index + 1; i < size; i++)
	{
		strcpy(sp[i - 1].maSP, sp[i].maSP);
		sp[i - 1].tenSP = sp[i].tenSP;
		sp[i - 1].donGia = sp[i].donGia;
		sp[i - 1].slTonKho = sp[i].slTonKho;
	}
	--size;
	cout << "XOA SAN PHAM THANH CONG!\n";
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
