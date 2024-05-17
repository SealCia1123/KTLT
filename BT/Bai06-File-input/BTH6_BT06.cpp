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
		char nguyenAm[11] = "ueoaiUEOAI";
		int count = 0;
		inData.getline(str, 20);
		for (int i = 0; i < strlen(str); i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (str[i] == nguyenAm[j])
					++count;
			}
		}
		cout << "So luong nguyen am trong file: " << count << "\n";
		inData.close();
	}
	return 0;
}
