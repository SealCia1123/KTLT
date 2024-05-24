#include <fstream>
#include <iostream>
#define MAX_CHAR_SIZE 20
using namespace std;

void inputString(char *str)
{
	cout << "Nhap vao chuoi: ";
	cin.getline(str, MAX_CHAR_SIZE);
}

void writeData(char *str)
{
	ofstream outData;
	outData.open("BT9.txt", ios::out);
	if (!outData.is_open())
		cout << "Mo file khong thanh cong!\n";
	else
	{
		outData << str;
		cout << "Ghi file thanh cong!\n";
		outData.close();
	}
}

void readData()
{
	ifstream inData;
	inData.open("BT9.txt", ios::in);
	if (!inData.is_open())
		cout << "Mo file khong thanh cong!\n";
	else
	{
		char str[MAX_CHAR_SIZE];
		inData.getline(str, MAX_CHAR_SIZE);
		cout << "Noi dung trong file: ";
		cout << str << endl;
		inData.close();
	}
}

int main()
{
	char str[MAX_CHAR_SIZE];
	inputString(str);
	writeData(str);
	readData();
	return 0;
}
