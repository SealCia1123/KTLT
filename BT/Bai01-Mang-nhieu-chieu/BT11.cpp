#include <cstdlib>
#include <iostream>
using namespace std;

void printAvailableSeat(const int seat[13][6]);

void input(char *userRow, char &userCol);

void bookTicket(int seat[13][6], char *userRow, char userCol, int ticketType);

int main()
{
	// Khai bao san mang 2 chieu vi tri cho ngoi hien tai
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
		system("clear");
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
		// Neu dat ve hang THUONG GIA -> truyen ticketType = 1
		case 1:
		{
			input(userRow, userCol);
			bookTicket(seat, userRow, userCol, 1);
			break;
		}

		// Neu dat ve hang PHO THONG -> truyen ticketType = 2
		case 2:
		{
			input(userRow, userCol);
			bookTicket(seat, userRow, userCol, 2);
			break;
		}

		// Neu dat ve hang TIET KIEM -> truyen ticketType = 3
		case 3:
		{
			input(userRow, userCol);
			bookTicket(seat, userRow, userCol, 3);
			break;
		}

		// Neu chon 0 -> thoat chuong trinh
		case 0:
		{
			cout << "Ket thuc chuong trinh\n";
			return 0;
		}

		// Neu chon khac 1,2,3,0 -> in ra lua chon ko hop le
		default:
			cout << "Lua chon khong hop le\n";
		}

		// Cho nguoi dung lua chon tiep tuc su dung chuong trinh
		char isContinue;
		cout << "Ban co muon tiep tuc chuong trinh (Nhan K de dung): ";
		cin >> isContinue;
		if (isContinue == 'k' || isContinue == 'K')
		{
			cout << "Ket thuc chuong trinh\n";
			return 0;
		}
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

	// In ra cho ngoi hien tai, neu trong thi in '*', neu co nguoi dat roi thi in 'X'
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
		// Nhap vao hang ghe va cot ghe
		cout << "Nhap vao ghe o hang thu: ";
		cin >> userRow;
		cout << "Nhap vao ghe o cot chu: ";
		cin >> userCol;

		// Neu so ghe < 1 hoac so ghe > 13 thi in ra loi
		// Neu cot ghe khac A,B,C,D,E,F thi in ra loi, cho phep nhap ca chu thuong va chu in hoa
		// Lap lai cho toi khi nguoi dung nhap vao dung format
		if ((atoi(userRow) < 1 || atoi(userRow) > 13) || !((userCol >= 'A' && userCol <= 'F') || (userCol >= 'a' && userCol <= 'f')))
			cout << "Chon lai ghe, chon theo cu phap: Hang thu, Cot chu\n"
				 << "Vi du: Ghe o hang hang thu: 1, 2, 3,..., 13\n"
				 << "       Ghe o cot chu: A, B, C,..., F\n";
	} while ((atoi(userRow) < 1 || atoi(userRow) > 13) || !((userCol >= 'A' && userCol <= 'F') || (userCol >= 'a' && userCol <= 'f')));
}

void bookTicket(int seat[13][6], char *userRow, char userCol, int ticketType)
{
	// KT ticketType va cho vao TH tuong ung
	int checkRow = atoi(userRow);
	if (ticketType == 1)
	{
		while (checkRow < 1 || checkRow > 2)
		{
			cout << "Ghe hang THUONG GIA chi gom ghe tu hang 1 den hang 2 va cot tu A den F\n";
			input(userRow, userCol);
			checkRow = atoi(userRow);
		}
	}

	else if (ticketType == 2)
	{
		while (checkRow < 3 || checkRow > 7)
		{
			cout << "Ghe hang PHO THONG chi gom ghe tu hang 3 den hang 7 va cot tu A den F\n";
			input(userRow, userCol);
			checkRow = atoi(userRow);
		}
	}

	else
	{
		while (checkRow < 8)
		{
			cout << "Ghe hang TIET KIEM chi gom ghe tu hang 8 den hang 13 va cot tu A den F\n";
			input(userRow, userCol);
			checkRow = atoi(userRow);
		}
	}

	// Gan hang = hang nguoi dung nhap - 1
	// Neu nguoi dung nhap chu in hoa: cot = cotNguoiDung - 65; khong thi cot = cotNguoiDung - 97 de cot co index cua mang
	int row = checkRow - 1;
	int col = ((userCol >= 'A' && userCol <= 'F') ? (int)userCol - 65 : (int)userCol - 97);

	// KT neu vi tri do co nguoi da dat thi in ra loi
	while (seat[row][col] == 1)
	{
		cout << "Cho quy khach chon da co nguoi dat, quy khach vui long chon cho moi\n";

		// Cho phep nguoi dung nhap lai, gan lai bien hang, cot
		input(userRow, userCol);
		row = checkRow - 1;
		col = ((userCol >= 'A' && userCol <= 'F') ? (int)userCol - 65 : (int)userCol - 97);
	}
	// Neu vi tri ghe kha dung -> gan vi tri ghe = 1, in ra dat ve thanh cong
	seat[row][col] = 1;
	cout << "Dat ve thanh cong\n";
}
