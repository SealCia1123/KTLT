#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ifstream read;
	read.open("BT1.txt", ios::in);
	if (!read.is_open())
		cout << "Khong the mo file de doc\n";
	else
	{
		int m;
		cout << "Mo file thanh cong! Co the tiep tuc doc file\n";
		read >> m;
		cout << "Noi dung trong file: " << m << endl;
	}
	read.close();
	return 0;
}
