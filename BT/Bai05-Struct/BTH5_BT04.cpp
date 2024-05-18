#include <iostream>
#include <string>
using namespace std;

struct SinhVien
{
	string MSSV, hoTen, diaChi;
	int namSinh;
	double diemToan, diemVan, diemNN, diemTB;
};

void input(SinhVien &sv);

void inputListStudents(SinhVien *ds, int index, int size);

void printInfo(const SinhVien sv);

void printListSV(const SinhVien *ds, int size);

void ranking(const SinhVien sv);

void searching(const SinhVien *ds, int size, string maSV);

int main()
{
	SinhVien listStudent[45];
	int choice, currentSize = 0;
	while (true)
	{
		system("clear");
		cout << "==================== Menu ====================\n";
		cout << "1. Nhap thong tin sinh vien\n";
		cout << "2. In thong tin danh sach sinh vien\n";
		cout << "3. In thong tin sinh vien can tim\n";
		cout << "0. Thoat chuong trinh\n";
		cout << "Nhap vao lua chon: ";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
		{
			int temp;
			cout << "NHAP THONG TIN\n";
			do
			{
				cout << "Nhap so luong sinh vien can nhap: ";
				cin >> temp;
				cin.ignore();
				if (temp < 0 || temp + currentSize > 45)
					cout << "Vui long nhap lai\n";
			} while (temp < 0 || temp + currentSize > 45);
			inputListStudents(listStudent, currentSize, currentSize + temp);
			currentSize += temp;
			break;
		}
		case 2:
		{
			if (currentSize == 0)
				cout << "Danh sach sinh vien hien dang trong\n";
			else
				printListSV(listStudent, currentSize);
			break;
		}
		case 3:
		{
			if (currentSize == 0)
				cout << "Danh sach sinh vien hien dang trong\n";
			else
			{
				string maSV;
				cout << "Nhap ma sinh vien can tim: ";
				getline(cin, maSV);
				cout << "THONG TIN SINH VIEN\n";
				searching(listStudent, currentSize, maSV);
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

void input(SinhVien &sv)
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
	cin.ignore();
	sv.diemTB = ((sv.diemToan + sv.diemVan) * 2 + sv.diemNN) / 5;
}

void inputListStudents(SinhVien *ds, int index, int size)
{
	for (int i = index; i < size; i++)
	{
		cout << "==== NHAP SINH VIEN THU " << i + 1 << " ====\n";
		input(ds[i]);
	}
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

void printListSV(const SinhVien *ds, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "==== SINH VIEN THU " << i + 1 << " ====\n";
		printInfo(ds[i]);
	}
}

void searching(const SinhVien *ds, int size, string maSV)
{
	for (int i = 0; i < size; i++)
	{
		if (ds[i].MSSV == maSV)
		{
			printInfo(ds[i]);
			return;
		}
	}
	cout << "Khong tim thay sinh vien\n";
}
