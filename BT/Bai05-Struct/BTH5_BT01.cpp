#include <iostream>
#include <string>
using namespace std;

struct PhongBan
{
	string maPhongBan;
	string tenPhongBan;
};

void nhapPhongBan(PhongBan &p)
{
	cout << "Nhap ma phong ban: ";
	getline(cin, p.maPhongBan);
	cout << "Nhap ten phong ban: ";
	getline(cin, p.tenPhongBan);
}

void xuatPhongBan(const PhongBan p)
{
	cout << "Ma phong ban: " << p.maPhongBan << endl;
	cout << "Ten phong ban: " << p.tenPhongBan << endl;
}

int main()
{
	PhongBan p;
	nhapPhongBan(p);
	xuatPhongBan(p);
	return 0;
}
