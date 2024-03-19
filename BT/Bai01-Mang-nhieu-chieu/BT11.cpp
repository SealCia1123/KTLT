#include <iostream>
using namespace std;

void printAvailableSeat(const int seat[13][6]);

void input(char userSeat[]);

void bookBusinessClass(int seat[13][6], char userSeat[]);

void bookEconomyClass(int seat[13][6], char userSeat[]);

void bookCheapClass(int seat[13][6], char userSeat[]);

int main()
{
	int seat[13][6] = {
		{0, 0, 1, 0, 1, 1},
		{0, 1, 0, 1, 0, 1},
		{0, 0, 1, 1, 0, 1},
		{1, 1, 1, 0, 1, 1},
		{0, 1, 0, 1, 0, 0},
		{0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1, 1},
		{0, 1, 0, 1, 1, 0},
		{1, 0, 1, 1, 0, 0},
		{0, 1, 0, 1, 1, 1},
		{0, 0, 1, 0, 1, 0},
		{0, 0, 1, 1, 0, 1},
		{0, 0, 0, 0, 1, 0}};

	int choice, row, col;
	char userSeat[2];
	while (true)
	{
		printAvailableSeat(seat);
		cout << "Ban muon dat ve loai nao (1. Hang thuong gia, 2. Pho thong, 3. Tiet kiem): ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			input(userSeat);
			bookBusinessClass(seat, userSeat);
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		default:
			cout << "Lua chon khong hop le\n";
		}
		char isContinue;
		cout << "Ban co muon tiep tuc chuong trinh (Nhan K de dung): ";
		cin >> isContinue;
		if (isContinue == 'k' || isContinue == 'K')
		{
			cout << "Ket thuc chuong trinh\n";
			return 0;
		}
		system("clear");
	}
}

void printAvailableSeat(const int seat[13][6])
{
	char col = 'A';
	cout << "So do cho ngoi hien tai:\n";
	cout << "\t";
	for (int i = 0; i < 6; i++)
		cout << col++ << "\t";
	cout << endl;
	for (int i = 0; i < 13; i++)
	{
		cout << "Hang " << i + 1 << "\t";
		for (int j = 0; j < 6; j++)
			cout << (seat[i][j] == 0 ? "*\t" : "X\t");
		cout << endl;
	}
}

void input(char userSeat[])
{
	do
	{
		cout << "Nhap vao vi tri ghe ban muon chon: ";
		cin >> userSeat;
		if ((userSeat[0] < '0' || userSeat[0] > '9') || (userSeat[1] < 'A' || userSeat[1] > 'Z'))
			cout << "Nhap lai vi tri ghe can chon."
				 << "\nChon theo cu phap [Hang thu ...][Cot chu ...]"
				 << "\nVi du: 1B, 2C, 4F\n";
	} while ((userSeat[0] < '1' || userSeat[0] > '9') || (userSeat[1] < 'A' || userSeat[1] > 'Z'));
}

void bookBusinessClass(int seat[13][6], char userSeat[])
{
	while (userSeat[0] < '1' || userSeat[0] > '2')
	{
		cout << "Ghe hang thuong gia chi gom hang thu 1 va hang thu 2\n";
		input(userSeat);
	}
}

void bookEconomyClass(int seat[13][6], char userSeat[])
{

	while (userSeat[0] < '3' || userSeat[0] > '7')
	{
		cout << "Ghe hang thuong gia chi gom hang thu 1 va hang thu 2\n";
		input(userSeat);
	}
}

void bookCheapClass(int seat[13][6], char userSeat[])
{
	while (userSeat[0] < '8')
	{
		cout << "Ghe hang thuong gia chi gom hang thu 1 va hang thu 2\n";
		input(userSeat);
	}
}
