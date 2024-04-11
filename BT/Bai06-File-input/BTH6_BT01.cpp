#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ofstream write;
	write.open("BT1.txt", ios::out);
	if (!write.is_open())
		cout << "Khong the mo file de ghi\n";
	else
	{
		cout << "Mo file thanh cong! Co the tiep tuc ghi file\n";
		int a, b;
		cout << "Nhap vao hai so nguyen: ";
		cin >> a >> b;
		write << a + b << endl;
	}
	write.close();
	return 0;
}
