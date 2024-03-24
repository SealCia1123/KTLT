#include <iostream>
#include <string>
using namespace std;

struct SinhVien
{
	string MSSV, hoTen, diaChi;
	int namSinh;
	double diemToan, diemVan, diemNN, diemTB;
};

void getInfo(SinhVien &sv);

void printInfo(const SinhVien sv);

void ranking(const SinhVien sv);

int main()
{
	SinhVien listStudent[45];
	int choice, currentStudentSize = 0;
	while (true)
	{
		system("clear");
		cout << "====================Menu====================\n";
		cout << "1. Nhap thong tin sinh vien\n";
		cout << "2. In thong tin sinh vien\n";
		cout << "0. Thoat chuong trinh\n";
		cout << "Nhap vao lua chon: ";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
		{
			cout << "=================NHAP THONG TIN=================\n";
			if (currentStudentSize >= 45)
				cout << "So luong sinh vien vuot qua kich thuoc toi da\n";
			else
				getInfo(listStudent[currentStudentSize++]);
			break;
		}
		case 2:
		{
			if (currentStudentSize == 0)
				cout << "Danh sach sinh vien hien dang trong\n";
			else
			{
				int index;
				do
				{
					cout << "Nhap vao so thu tu sinh vien can tim: ";
					cin >> index;
					if ((index < 1 || index > 45) || (index > currentStudentSize))
						cout << "Vui long nhap lai so thu tu\n";
				} while ((index < 1 || index > 45) || (index > currentStudentSize));
				cout << "=================THONG TIN SINH VIEN=================\n";
				printInfo(listStudent[--index]);
			}
			break;
		}
		case 0:
		{
			cout << "Ket thuc chuong trinh\n";
			return 0;
		}
		default:
			cout << "Lua chon khong hop le\n";
		}
		int isContinue;
		cout << "Tiep tuc chuong trinh (1/0): ";
		cin >> isContinue;
		if (!isContinue)
		{
			cout << "Ket thuc chuong trinh\n";
			return 0;
		}
	}
}

void getInfo(SinhVien &sv)
{
	cout << "Nhap MSSV: ";
	getline(cin, sv.MSSV);
	cout << "Nhap ho ten: ";
	getline(cin, sv.hoTen);
	cout << "Nhap dia chi: ";
	getline(cin, sv.diaChi);
	cout << "Nhap nam sinh: ";
	cin >> sv.namSinh;
	cout << "Nhap diem toan: ";
	cin >> sv.diemToan;
	cout << "Nhap diem van: ";
	cin >> sv.diemVan;
	cout << "Nhap diem ngoai ngu: ";
	cin >> sv.diemNN;
	sv.diemTB = ((sv.diemToan + sv.diemVan) * 2 + sv.diemNN) / 5;
}

void printInfo(const SinhVien sv)
{
	cout << "MSSV: " << sv.MSSV << endl;
	cout << "Ho ten: " << sv.hoTen << endl;
	cout << "Dia chi: " << sv.diaChi << endl;
	cout << "Nam sinh: " << sv.namSinh << endl;
	cout << "Diem toan: " << sv.diemToan << "\tDiem van: " << sv.diemVan << "\tDiem ngoai ngu: " << sv.diemNN << endl;
	cout << "Diem trung binh: " << sv.diemTB << endl;
	ranking(sv);
}

void ranking(const SinhVien sv)
{
	if (sv.diemTB >= 8)
		cout << "Xep loai: Gioi\n";
	else if (sv.diemTB >= 6.5)
		cout << "Xep loai: Kha\n";
	else if (sv.diemTB >= 5)
		cout << "Xep loai: Trung binh\n";
	else
		cout << "Xep loai: Duoi trung binh\n";
}
