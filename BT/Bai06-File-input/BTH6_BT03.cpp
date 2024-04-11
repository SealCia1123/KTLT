#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	srand(time(0));
	ofstream write;
	write.open("BT3.txt", ios::out);
	if (!write.is_open())
		cout << "Khong the mo file de ghi\n";
	else
	{
		int MAX, MIN;
		ifstream read;
		cout << "Nhap vao khoang MAX va MIN: ";
		cin >> MAX >> MIN;
		write << rand() % (MAX - MIN + 1) + MIN << "#" << rand() % (MAX - MIN + 1) + MIN << "#" << rand() % (MAX - MIN + 1) + MIN << endl;

		read.open("BT3.txt", ios::in);
		if (!read.is_open())
			cout << "Khong the mo file de doc\n";
		else
		{
			int a, b, c;
			read >> a;
			read.ignore(1);
			read >> b;
			read.ignore(1);
			read >> c;
			read.ignore(1);
			float tbCong = (a + b + c) / 3.0;
			cout << "Trung binh cong cua a, b va c la: " << tbCong << endl;
		}
		read.close();
	}
	write.close();
	return 0;
}
