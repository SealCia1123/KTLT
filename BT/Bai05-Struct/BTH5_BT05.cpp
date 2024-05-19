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

void input(Sach &sach);

void inputBooks(Sach *dsSach, int size);

void searching(const Sach *sach, int size, char *name);

int main()
{
	Sach listBooks[50];
	char author[21];
	int size;
	do
	{
		cout << "Nhap vao so luong sach can nhap: ";
		cin >> size;
		cin.ignore();
		if (size < 0 || size > 50)
			cout << "So luong nhap khong hop le, nhap lai\n";
	} while (size < 0 || size > 50);

	inputBooks(listBooks, size);
	cout << "Nhap ten tac gia can tim: ";
	cin.getline(author, 21);
	searching(listBooks, size, author);
	return 0;
}

void input(Sach &sach)
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

void searching(const Sach *sach, int size, char *name)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(sach[i].tenTacGia, name) == 0)
		{
			cout << "==== Sach cua tac gia " << sach[i].tenTacGia << " ====\n";
			cout << "Ten: " << sach[i].tenSach << endl;
			cout << "Ten tac gia: " << sach[i].tenTacGia << endl;
			cout << "Ngay thang nam xuat ban: " << sach[i].ngayXuatBan.ngay << "/" << sach[i].ngayXuatBan.thang << "/" << sach[i].ngayXuatBan.nam << endl;
			return;
		}
	}
	cout << "Khong tim thay sach cua tac gia " << name << endl;
}

void inputBooks(Sach *dsSach, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "==== NHAP SACH THU " << i + 1 << " ====\n";
		input(dsSach[i]);
	}
}
