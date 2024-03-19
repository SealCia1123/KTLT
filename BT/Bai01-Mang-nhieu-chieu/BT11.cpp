#include <iostream>
using namespace std;

void printAvailableSeat(const int seat[13][6]);

void input(int &userRow, char &userCol);

void bookBusinessClass(int seat[13][6], int userRow, char userCol);

void bookEconomyClass(int seat[13][6], int userRow, char userCol);

void bookCheapClass(int seat[13][6], int userRow, char userCol);

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

	int choice, row, col, userRow;
	char userCol;
	while (true)
	{
		printAvailableSeat(seat);
		cout << "\n=========Menu dat ve may bay=========\n";
		cout << "1. Dat ve hang THUONG GIA\n";
		cout << "2. Dat ve hang PHO THONG\n";
		cout << "3. Dat ve hang TIET KIEM\n";
		cout << "0. Thoat chuong trinh\n";
		cout << "Nhap vao lua chon cua ban: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			input(userRow, userCol);
			bookBusinessClass(seat, userRow, userCol);
			break;
		}
		case 2:
		{
			input(userRow, userCol);
			bookEconomyClass(seat, userRow, userCol);
			break;
		}
		case 3:
		{
			input(userRow, userCol);
			bookCheapClass(seat, userRow, userCol);
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

void input(int &userRow, char &userCol)
{
	do
	{
		cout << "Nhap vao ghe o hang thu: ";
		cin >> userRow;
		cout << "Nhap vao ghe o cot chu: ";
		cin >> userCol;
		if ((userRow < 1 || userRow > 13) || !((userCol >= 'A' && userCol <= 'Z') || (userCol >= 'a' && userCol <= 'z')))
			cout << "Nhap lai vi tri ghe can chon."
				 << "\nChon theo cu phap [Hang thu ...][Cot chu ...]"
				 << "\nVi du: 1B, 2C, 3F\n";
	} while ((userRow < 1 || userRow > 13) || !((userCol >= 'A' && userCol <= 'Z') || (userCol >= 'a' && userCol <= 'z')));
}

void bookBusinessClass(int seat[13][6], int userRow, char userCol)
{
	while (userRow < 1 || userRow > 2)
	{
		cout << "Ghe hang thuong gia chi gom hang thu 1 va hang thu 2\n";
		input(userRow, userCol);
	}
	int row = --userRow, col = ((userCol >= 'A' && userCol <= 'Z') ? (int)userCol - 65 : (int)userCol - 97);
	if (seat[row][col] == 1)
	{
		cout << "Cho quy khach chon da co nguoi dat, quy khach vui long chon cho moi\n";
		input(userRow, userCol);
	}
	else
	{
		seat[row][col] = 1;
		cout << "Dat ve thanh cong\n";
	}
}

void bookEconomyClass(int seat[13][6], int userRow, char userCol)
{

	while (userRow < 3 || userRow > 7)
	{
		cout << "Ghe hang pho thong tu hang thu 3 den hang thu 7\n";
		input(userRow, userCol);
	}
	int row = --userRow, col = ((userCol >= 'A' && userCol <= 'Z') ? (int)userCol - 65 : (int)userCol - 97);
	if (seat[row][col] == 1)
	{
		cout << "Cho quy khach chon da co nguoi dat, quy khach vui long chon cho moi\n";
		input(userRow, userCol);
	}
	else
	{
		seat[row][col] = 1;
		cout << "Dat ve thanh cong\n";
	}
}

void bookCheapClass(int seat[13][6], int userRow, char userCol)
{
	while (userRow < 8 || userRow > 13)
	{
		cout << "Ghe hang tiet kiem tu hang thu 8 den hang thu 13\n";
		input(userRow, userCol);
	}
	int row = --userRow, col = ((userCol >= 'A' && userCol <= 'Z') ? (int)userCol - 65 : (int)userCol - 97);
	if (seat[row][col] == 1)
	{
		cout << "Cho quy khach chon da co nguoi dat, quy khach vui long chon cho moi\n";
		input(userRow, userCol);
	}
	else
	{
		seat[row][col] = 1;
		cout << "Dat ve thanh cong\n";
	}
}
