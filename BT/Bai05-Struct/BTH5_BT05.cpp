#include <cstring>
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

void printInfo(const Sach *sach, int size, char *name);

int main()
{
	Sach listBooks[50];
	char author[20];
	int index = 0, isContinue;
	do
	{
		cout << "=====Nhap vao thong tin sach=====\n";
		getInfo(listBooks[index++]);
		cout << "Tiep tuc nhap sach (1/0): ";
		cin >> isContinue;
		if (!isContinue)
			cout << "=====Ket thuc nhap sach=====\n";
		cin.ignore();
	} while (isContinue);
	cout << "Nhap ten tac gia can tim: ";
	cin.getline(author, 20);
	printInfo(listBooks, ++index, author);
	return 0;
}

void getInfo(Sach &sach)
{
	cout << "Nhap ten sach: ";
	cin.getline(sach.tenSach, 20);
	cout << "Nhap ten tac gia: ";
	cin.getline(sach.tenTacGia, 20);
	cout << "Nhap ngay thang nam xuat ban: ";
	cin >> sach.ngayXuatBan.ngay;
	cin.ignore();
	cin >> sach.ngayXuatBan.thang;
	cin.ignore();
	cin >> sach.ngayXuatBan.nam;
	cin.ignore();
}

void printInfo(const Sach *sach, int size, char *name)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(sach[i].tenTacGia, name) == 0)
		{
			cout << "Sach cua tac gia " << sach[i].tenTacGia << "\n";
			cout << "Ten: " << sach[i].tenSach << endl;
			cout << "Ten tac gia: " << sach[i].tenTacGia << endl;
			cout << "Ngay thang nam xuat ban: " << sach[i].ngayXuatBan.ngay << "/" << sach[i].ngayXuatBan.thang << "/" << sach[i].ngayXuatBan.nam << endl;
			return;
		}
	}
	cout << "Khong tim thay sach cua tac gia " << name << endl;
}
