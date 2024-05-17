#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

void capitalizeStr(char *c)
{
	for (int i = 0; i < strlen(c); i++)
	{
		if (c[i] >= 'a' && c[i] <= 'z')
			c[i] -= 32;
	}
}

int main()
{
	char str[20];
	ofstream outStr;
	cout << "Nhap vao chuoi ky tu: ";
	cin.getline(str, 20);
	outStr.open("BT4.txt", ios::out);
	if (!outStr.is_open())
		cout << "Mo file khong thanh cong\n";
	else
	{
		capitalizeStr(str);
		outStr << str << endl;
	}
	outStr.close();
	return 0;
}
