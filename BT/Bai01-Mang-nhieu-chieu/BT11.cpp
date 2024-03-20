#include <cstdlib>
#include <iostream>
using namespace std;

void printAvailableSeat(const int seat[13][6]);

void input(char *userRow, char &userCol);

void bookBusinessClass(int seat[13][6], char *userRow, char userCol);

void bookEconomyClass(int seat[13][6], char *userRow, char userCol);

void bookCheapClass(int seat[13][6], char *userRow, char userCol);

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
	char userCol, userRow[2];
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

void input(char *userRow, char &userCol)
{
	do
	{
		cout << "Nhap vao ghe o hang thu: ";
		cin >> userRow;
		cout << "Nhap vao ghe o cot chu: ";
		cin >> userCol;
		if (!(atoi(userRow) >= 1 && atoi(userRow) <= 13) || !((userCol >= 'A' && userCol <= 'F') || (userCol >= 'a' && userCol <= 'f')))
			cout << "Chon lai ghe, chon theo cu phap: Hang thu, Cot chu\n"
				 << "Vi du: Ghe o hang hang thu: 1, 2, 3,..., 13\n"
				 << "       Ghe o cot chu: A, B, C,..., F\n";
	} while (!(atoi(userRow) >= 1 && atoi(userRow) <= 13) || !((userCol >= 'A' && userCol <= 'F') || (userCol >= 'a' && userCol <= 'f')));
}

void bookBusinessClass(int seat[13][6], char *userRow, char userCol)
{
	while (atoi(userRow) < 1 || atoi(userRow) > 2)
	{
		cout << "Ghe hang THUONG GIA chi gom ghe tu hang 1 den hang 2 va cot tu A den F\n";
		input(userRow, userCol);
	}
	int row = atoi(userRow) - 1;
	int col = ((userCol >= 'A' && userCol <= 'F') ? (int)userCol - 65 : (int)userCol - 97);

	while (seat[row][col] == 1)
	{
		cout << "Cho quy khach chon da co nguoi dat, quy khach vui long chon cho moi\n";
		input(userRow, userCol);
		row = atoi(userRow) - 1;
		col = ((userCol >= 'A' && userCol <= 'F') ? (int)userCol - 65 : (int)userCol - 97);
	}
	seat[row][col] = 1;
	cout << "Dat ve thanh cong\n";
}

void bookEconomyClass(int seat[13][6], char *userRow, char userCol)
{

	while (atoi(userRow) < 3 || atoi(userRow) > 7)
	{
		cout << "Ghe hang PHO THONG chi gom ghe tu hang 3 den hang 7 va cot tu A den F\n";
		input(userRow, userCol);
	}
	int row = atoi(userRow) - 1;
	int col = ((userCol >= 'A' && userCol <= 'F') ? (int)userCol - 65 : (int)userCol - 97);

	while (seat[row][col] == 1)
	{
		cout << "Cho quy khach chon da co nguoi dat, quy khach vui long chon cho moi\n";
		input(userRow, userCol);
		row = atoi(userRow) - 1;
		col = ((userCol >= 'A' && userCol <= 'F') ? (int)userCol - 65 : (int)userCol - 97);
	}
	seat[row][col] = 1;
	cout << "Dat ve thanh cong\n";
}

void bookCheapClass(int seat[13][6], char *userRow, char userCol)
{
	while (atoi(userRow) < 8)
	{
		cout << "Ghe hang TIET KIEM chi gom ghe tu hang 8 den hang 13 va cot tu A den F\n";
		input(userRow, userCol);
	}
	int row = atoi(userRow) - 1;
	int col = ((userCol >= 'A' && userCol <= 'F') ? (int)userCol - 65 : (int)userCol - 97);

	while (seat[row][col] == 1)
	{
		cout << "Cho quy khach chon da co nguoi dat, quy khach vui long chon cho moi\n";
		input(userRow, userCol);
		row = atoi(userRow) - 1;
		col = ((userCol >= 'A' && userCol <= 'F') ? (int)userCol - 65 : (int)userCol - 97);
	}
	seat[row][col] = 1;
	cout << "Dat ve thanh cong\n";
}
