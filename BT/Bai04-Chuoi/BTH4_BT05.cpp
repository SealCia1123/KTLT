#include <conio.h>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
	char correctPassword[11] = "SinhVienCQ";
	char password[11];
	char temp;
	int i = 0;
	do
	{
		while (true)
		{
			temp = getch();
			if (temp == ' ')
				continue;
			if (temp == '\r')
			{
				password[i] = '\0';
				break;
			}
			cout << "X ";
			password[i++] = temp;
		}
		if (strcmp(password, correctPassword) != 0)
			cout << "Nhap sai, nhap lai\n";
		else
			cout << "Dang nhap thanh cong\n";
	} while (strcmp(password, correctPassword) == 0);
}
