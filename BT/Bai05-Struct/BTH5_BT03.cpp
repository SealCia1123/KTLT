#include <ctime>
#include <iostream>
#include <string>
using namespace std;

struct NhanVien
{
	string maNhanVien, hoTen;
	int namVaoLam, namSinh;
};

void input(NhanVien &nv)
{
	cout << "Nhap ho ten: ";
	getline(cin, nv.hoTen);
	cout << "Nhap ma nhan vien: ";
	getline(cin, nv.maNhanVien);
	cout << "Nhap vao nam sinh: ";
	cin >> nv.namSinh;
	cout << "Nhap vao nam vao lam: ";
	cin >> nv.namVaoLam;
}

int calYears(const int currentYear, const int countYear)
{
	return currentYear - countYear;
}

void printNV(const NhanVien nv)
{
	cout << "=====Thong tin nhan vien=====\n";
	time_t t = time(nullptr);
	tm *const currentYear = localtime(&t);
	cout << "Ho ten: " << nv.hoTen << endl;
	cout << "Ma nhan vien: " << nv.maNhanVien << endl;
	cout << "Nam sinh: " << nv.namSinh << endl;
	cout << "Nam vao lam: " << nv.namVaoLam << endl;
	cout << "Tuoi: " << calYears(1900 + currentYear->tm_year, nv.namSinh) << endl;
	cout << "Tham nien: " << calYears(1900 + currentYear->tm_year, nv.namVaoLam) << endl;
}

int main()
{
	NhanVien nv1;
	input(nv1);
	printNV(nv1);
	return 0;
}
