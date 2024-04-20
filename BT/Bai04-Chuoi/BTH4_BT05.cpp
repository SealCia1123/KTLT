#include <conio.h>
#include <iostream>
using namespace std;
int main()
{
	char password[11];
	char temp;
	int i = 0;
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
	cout << endl
		 << password;
}
