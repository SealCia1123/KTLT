#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

struct SinhVien
{
	string MSSV, hoTen, diaChi;
	int namSinh;
	double diemToan, diemVan, diemNN;

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
	}

	void xuatSV()
	{
		cout << "MSSV: " << MSSV << endl;
		cout << "Ho ten: " << hoTen << endl;
		cout << "Dia chi: " << diaChi << endl;
		cout << "Nam sinh: " << namSinh << endl;
		cout << "Diem toan: " << diemToan << "\tdiem van: " << diemVan << "\tdiem ngoai ngu: " << diemNN << endl;
	}
};

int main()
{
	SinhVien sv;
	sv.nhapSV();
	sv.xuatSV();
	return 0;
}
