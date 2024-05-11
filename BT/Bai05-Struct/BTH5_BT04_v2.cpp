#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

struct SinhVien
{
	string MSSV, hoTen, diaChi;
	int namSinh;
	double diemToan, diemVan, diemNN, diemTB;

	void nhapSV()
	{
		cout << "Nhap MSSV: ";
		cin >> MSSV;
		cin.ignore();
		cout << "Nhap ho ten: ";
		getline(cin, hoTen);
		cout << "Nhap dia chi: ";
		getline(cin, diaChi);
		cout << "Nhap nam sinh: ";
		cin >> namSinh;
		cout << "Nhap diem toan, van, ngoai ngu: ";
		cin >> diemToan >> diemVan >> diemNN;
		diemTB = ((diemToan + diemVan) * 2 + diemNN) / 5;
	}

	void ranking()
	{
		if (diemTB >= 8)
			cout << "Xep loai: Gioi\n";
		else if (diemTB >= 6.5)
			cout << "Xep loai: Kha\n";
		else if (diemTB >= 5)
			cout << "Xep loai: Trung binh\n";
		else
			cout << "Xep loai: Duoi trung binh\n";
	}

	void xuatSV()
	{
		cout << "MSSV: " << MSSV << endl;
		cout << "Ho ten: " << hoTen << endl;
		cout << "Dia chi: " << diaChi << endl;
		cout << "Nam sinh: " << namSinh << endl;
		cout << "Diem toan, van, ngoai ngu: " << diemToan << "\t" << diemVan << "\t" << diemNN << endl;
		cout << "Diem trung binh: " << diemTB << endl;
		this->ranking();
	}
};

int main()
{
	SinhVien *dsSinhVien = new SinhVien[45];
	int choice, size = 0;
	while (true)
	{
		system("clear");
		cout << "====================Menu====================\n";
		cout << "1. Nhap thong tin sinh vien\n";
		cout << "2. In danh sach sinh vien\n";
		cout << "3. Tim thong tin sinh vien\n";
		cout << "0. Thoat chuong trinh\n";
		cout << "Nhap vao lua chon: ";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
		{
			cout << "=================NHAP THONG TIN=================\n";
			if (size >= 45)
				cout << "So luong sinh vien vuot qua kich thuoc toi da\n";
			else
				dsSinhVien[size++].nhapSV();
			/* getInfo(dsSinhVien[size++]); */
			break;
		}

		case 2:
		{
			if (size == 0)
				cout << "Danh sach sinh vien hien dang trong\n";
			else
			{
				for (int i = 0; i < size; i++)
				{
					cout << "\n=====Sinh vien thu " << i + 1 << "=====\n";
					dsSinhVien[i].xuatSV();
				}
			}
			break;
		}

		case 3:
		{
			if (size == 0)
				cout << "Danh sach sinh vien hien dang trong\n";
			else
			{
				int index;
				do
				{
					cout << "Nhap vao so thu tu sinh vien can tim: ";
					cin >> index;
					if ((index < 1 || index > 45) || (index > size))
						cout << "Khong tim thay sinh vien, nhap lai\n";
				} while ((index < 1 || index > 45) || (index > size));
				cout << "=================THONG TIN SINH VIEN=================\n";
				dsSinhVien[--index].xuatSV();
			}
			break;
		}
		case 0:
		{
			cout << "Ket thuc chuong trinh\n";
			delete[] dsSinhVien;
			return 0;
		}
		default:
			cout << "Lua chon khong hop le\n";
		}
		bool isContinue;
		cout << "Tiep tuc chuong trinh (1/0): ";
		cin >> isContinue;
		if (!isContinue)
		{
			cout << "Ket thuc chuong trinh\n";
			delete[] dsSinhVien;
			return 0;
		}
	}
}
