#include <iostream>
using namespace std;

struct NTN
{
	int ngay, thang, nam;
};

struct Sach
{
	char tenSach[20], tenTacGia[20];
	NTN ngayXuatBan;
};

void getInfo(Sach &sach);

void printInfo(const Sach sach);

int main()
{
	return 0;
}

void getInfo(Sach &sach)
{
	cout << "Nhap ten sach: ";
	cin.getline(sach.tenSach, 20);
	cout << "Nhap ten tac gia: ";
	cin.getline(sach.tenTacGia, 20);
	cout << "Nhap ngay-thang-nam xuat ban: ";
	cin >> sach.ngayXuatBan.ngay >> sach.ngayXuatBan.thang >> sach.ngayXuatBan.nam;
}

void printInfo(const Sach sach)
{
	cout << "Ten: " << sach.tenSach << endl;
	cout << "Ten tac gia: " << sach.tenTacGia << endl;
	cout << "Ngay thang nam xuat ban: " << sach.ngayXuatBan.ngay << "/" << sach.ngayXuatBan.thang << "/" << sach.ngayXuatBan.nam << endl;
}
