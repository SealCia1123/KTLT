#include <iostream>
#include <ncurses.h>
using namespace std;

int main()
{
	int i = 0;
	char password[11];
	char a;
	cout << "Nhap mat khau: ";
	while (true)
	{
		a = getch();
		if (a == '\n')
		{
			password[i] = '\0';
			break;
		}
		if (a == ' ')
			continue;
		cout << "*";
		password[i++] = a;
	}
	cout << endl
		 << password << endl;

	return 0;
}
