#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

void capitalizeStr(char &c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
}

int main()
{
	char str[20];
	char *c = str;
	ofstream outStr;
	cout << "Nhap vao chuoi ky tu: ";
	cin.getline(str, 20);
	outStr.open("BT4.txt", ios::out);
	if (!outStr.is_open())
		cout << "Mo file khong thanh cong\n";
	else
	{
		for (int i = 0; i < strlen(str); i++)
			capitalizeStr(*(c + i));
		outStr << str << endl;
		outStr.close();
	}
	return 0;
}
