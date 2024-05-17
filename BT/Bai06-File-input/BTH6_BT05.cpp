#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ifstream inData;
	inData.open("BT4.txt", ios::in);
	if (!inData.is_open())
		cout << "Doc file khong thanh cong!\n";
	else
	{
		char str[20];
		int count = 0;
		inData.getline(str, 20);
		for (int i = 0; i < strlen(str); i++)
			++count;
		cout << "Tong so ky tu cua file: " << count << "\n";
		inData.close();
	}
	return 0;
}
