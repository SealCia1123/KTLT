#include <ctime>
#include <iostream>
#include <string>
using namespace std;

struct NhanVien
{
	string maNhanVien, hoTen;
	int namVaoLam, namSinh;
};

void input(NhanVien &nv);

void printNV(const NhanVien nv);

int tinhNam(const int currentYear, const int countYear);

int main()
{
	time_t t = time(nullptr);
	tm *const pTInfo = localtime(&t);
	cout << "Current year: " << 1900 + pTInfo->tm_year << '\n';
	NhanVien nv1;
	input(nv1);
	printNV(nv1);
	cout << "Tuoi: " << tinhNam(1900 + pTInfo->tm_year, nv1.namSinh);
	cout << "Tham nien: " << tinhNam(1900 + pTInfo->tm_year, nv1.namVaoLam);
	return 0;
}

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

void printNV(const NhanVien nv)
{
	cout << "Ho ten: " << nv.hoTen << endl;
	cout << "Ma nhan vien: " << nv.maNhanVien << endl;
	cout << "Nam sinh: " << nv.namSinh << endl;
	cout << "Nam vao lam: " << nv.namVaoLam << endl;
}

int tinhNam(const int currentYear, const int countYear)
{
	return currentYear - countYear;
}
