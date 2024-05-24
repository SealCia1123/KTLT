#include <fstream>
#include <iostream>
using namespace std;

void readData()
{
	ifstream inData;
	inData.open("BT8.txt", ios::in);
	if (!inData.is_open())
		cout << "Mo file khong thanh cong!\n";
	else
	{
		// a b c
		int i = 1;
		while (i <= 5)
		{
			if (i % 2 == 1)
			{
				int temp;
				inData >> temp;
				cout << temp << " ";
			}
			else
				inData.ignore();
			i++;
		}
	}
}

void writeData()
{
	ofstream outData;
	outData.open("BT8.txt", ios::out);
	if (!outData.is_open())
		cout << "Mo file khong thanh cong!\n";
	else
	{
		int i = 1;
		while (i <= 3)
		{
			int num;
			cin >> num;
			outData << num << " ";
			i++;
		}
	}
}

int main()
{
	writeData();
	readData();
	return 0;
}
