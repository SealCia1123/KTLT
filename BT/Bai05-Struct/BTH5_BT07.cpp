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

	void input()
	{
		cout << "NHAP SAN PHAM:\n";
		cout << "Nhap ma san pham: ";
		cin.getline(maSP, 10);
		cout << "Nhap ten san pham: ";
		getline(cin, tenSP);
		cout << "Nhap don gia: ";
		cin >> donGia;
		cout << "Nhap so luong ton kho: ";
		cin >> slTonKho;
		cin.ignore();
	}

	void modify()
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
			cin.getline(maSP, 10);
			break;
		case 2:
			cout << "Nhap ten san pham moi: ";
			getline(cin, tenSP);
			break;
		case 3:
			cout << "Nhap don gia moi: ";
			cin >> donGia;
			break;
		case 4:
			cout << "Nhap so luong ton kho moi: ";
			cin >> slTonKho;
			break;
		default:
			cout << "Lua chon khong hop le\n";
		}
	}
};

void swapProducts(SanPham &a, SanPham &b)
{
	SanPham temp = a;
	a = b;
	b = temp;
}

struct DsSanPham
{
	SanPham *sp = new SanPham[35];
	int currentSize = 0;

	void freeMem()
	{
		delete[] this->sp;
	}

	void print()
	{
		if (currentSize == 0)
		{
			cout << "Danh sach san pham hien dang trong\n";
			return;
		}
		cout << "=========================================\n";
		for (int i = 0; i < currentSize; i++)
		{
			cout << "San pham thu " << i + 1 << "\n";
			cout << "Ma san pham: " << sp[i].maSP << endl;
			cout << "Ten san pham: " << sp[i].tenSP << endl;
			cout << "Don gia: " << sp[i].donGia << endl;
			cout << "So luong ton kho: " << sp[i].slTonKho << endl;
			cout << "=========================================\n";
		}
	}

	void deleteProduct(int index)
	{
		for (int i = index + 1; i < currentSize; i++)
		{
			strcpy(sp[i - 1].maSP, sp[i].maSP);
			sp[i - 1].tenSP = sp[i].tenSP;
			sp[i - 1].donGia = sp[i].donGia;
			sp[i - 1].slTonKho = sp[i].slTonKho;
		}
		--currentSize;
		cout << "XOA THANH CONG!\n";
	}

	void sortProducts()
	{
		for (int i = 0; i < currentSize; i++)
		{
			for (int j = 0; j < currentSize - i - 1; j++)
			{
				if (sp[j].slTonKho > sp[j + 1].slTonKho)
					swapProducts(sp[j], sp[j + 1]);
			}
		}
		cout << "SAP XEP THANH CONG!\n";
	}
};

int main()
{
	DsSanPham ds;
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
			if (ds.currentSize > MAX_PRODUCTS)
				cout << "So luong san pham vuot qua muc toi da\n";
			else
				ds.sp[ds.currentSize++].input();
			break;
		}

		case 2:
		{
			cout << "THONG TIN SAN PHAM\n";
			ds.print();
			break;
		}

		case 3:
		{
			cout << "CHINH SUA SAN PHAM\n";
			if (ds.currentSize == 0)
			{
				cout << "Danh sach san pham hien dang trong\n";
				break;
			}
			int modifiedIndex;
			do
			{
				cout << "Nhap so thu tu san pham can chinh sua: ";
				cin >> modifiedIndex;
				cin.ignore();
				if (modifiedIndex < 0 || modifiedIndex > ds.currentSize)
					cout << "Nhap lai so thu tu cua san pham\n";
			} while (modifiedIndex < 0 || modifiedIndex > ds.currentSize);
			ds.sp[--modifiedIndex].modify();
			break;
		}

		case 4:
		{
			cout << "XOA SAN PHAM\n";
			if (ds.currentSize == 0)
			{
				cout << "Danh sach san pham hien dang trong\n";
				break;
			}
			int deleteIndex = 0;
			do
			{
				cout << "Nhap so thu tu san pham can xoa: ";
				cin >> deleteIndex;
				if (deleteIndex < 0 || deleteIndex > ds.currentSize)
					cout << "Nhap lai so thu tu cua san pham\n";
			} while (deleteIndex < 0 || deleteIndex > ds.currentSize);
			ds.deleteProduct(--deleteIndex);
			break;
		}

		case 5:
		{
			cout << "SAP XEP THEO THU TU SO LUONG TON KHO\n";
			ds.sortProducts();
			break;
		}
		case 0:
		{
			ds.freeMem();
			cout << "KET THUC CHUONG TRINH\n";
			return 0;
		}
		}
		int isContinue;
		cout << "Tiep tuc chuong trinh (1/0): ";
		cin >> isContinue;
		cin.ignore();
		if (!isContinue)
		{
			ds.freeMem();
			cout << "KET THUC CHUONG TRINH\n";
			return 0;
		}
	}
}
