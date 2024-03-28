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

void input(SanPham *sp, int start, int end);

void print(const SanPham *sp, int size);

void changeProduct(SanPham &sp);

int currentSize = 0;

int main()
{
	SanPham *listProducts = new SanPham[MAX_PRODUCTS];
	int choice, inputSize = 0, modifiedIndex = 0, inputIndex = 0;
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
			{
				cout << "Nhap so luong san pham can them: ";
				cin >> inputSize;
				cin.ignore();
			}
			if (currentSize != 0)
				inputIndex = currentSize - 1;
			currentSize += inputIndex;
			input(listProducts, inputIndex, currentSize);
			break;
		}
		case 2:
		{
			cout << "=========Thong tin san pham=========\n";
			print(listProducts, currentSize);
			break;
		}
		case 3:
		{
			cout << "=========Chinh sua thong tin san pham=========\n";
			if (currentSize == 0)
			{
				cout << "Danh sach san pham hien dang trong\n";
				break;
			}
			do
			{
				cout << "Nhap so thu tu san pham can chinh sua: ";
				cin >> modifiedIndex;
				if (modifiedIndex < 0 || modifiedIndex > currentSize)
					cout << "Vui long nhap lai so thu tu cua san pham\n";
			} while (modifiedIndex < 0 || modifiedIndex > currentSize);
			changeProduct(listProducts[--modifiedIndex]);
			break;
		}
		case 0:
		{
			cout << "Ket thuc chuong trinh\n";
			delete[] listProducts;
			listProducts = NULL;
			return 0;
		}
		}
		int isContinue;
		cout << "Tiep tuc chuong trinh (1/0): ";
		cin >> isContinue;
		cin.ignore();
		if (!isContinue)
		{
			cout << "Ket thuc chuong trinh\n";
			delete[] listProducts;
			listProducts = NULL;
			return 0;
		}
	}
}

void input(SanPham *sp, int start, int size)
{
	for (int i = start; i < size; i++)
	{
		cout << "\n=========Nhap thong tin san pham thu " << currentSize << "=========\n";
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
	cout << "=========================================\n";
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
		cout << "=========================================\n";
		cout << "San pham thu " << i + 1 << "\n";
		cout << "Ma san pham: " << sp[i].maSP << endl;
		cout << "Ten san pham: " << sp[i].tenSP << endl;
		cout << "Don gia: " << fixed << setprecision(0) << sp[i].donGia << endl;
		cout << "So luong ton kho: " << sp[i].slTonKho << endl;
	}
	cout << "=========================================\n";
}

void changeProduct(SanPham &sp)
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
	{
		cout << "Nhap ma san pham moi: ";
		char maSPMoi[10];
		cin.getline(sp.maSP, 10);
		break;
	}
	case 2:
	{
		cout << "Nhap ten san pham moi: ";
		getline(cin, sp.tenSP);
		break;
	}
	case 3:
	{
		cout << "Nhap don gia moi: ";
		cin >> sp.donGia;
		break;
	}
	case 4:
	{
		cout << "Nhap don gia moi: ";
		cin >> sp.slTonKho;
		break;
	}
	default:
		cout << "Lua chon khong hop le\n";
	}
	cout << "=========================================\n";
}
