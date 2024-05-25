#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Ngay
{
	int ngay, thang, nam;
};

struct SinhVien
{
	int vtCho, day;
	string hoLot, ten, queQuan, MSSV, nganhHoc;
	Ngay ngaySinh;
};

int main()
{
	while (true)
	{
		int choice;
		cin >> choice;
		switch (choice)
		{

		case 1:
			break;

		case 0:
			cout << "Ket thuc chuong trinh\n";
			return 0;
		default:
			cout << "Lua chon khong hop le!\n";
		}
	}
	return 0;
}
