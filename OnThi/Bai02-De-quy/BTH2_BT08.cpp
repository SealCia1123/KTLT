// Decimal -> Binary
#include <iostream>
using namespace std;

int decToBin(int dec);

int main()
{
	int dec;
	cout << "Nhap so he thap phan: ";
	cin >> dec;
	cout << "So o he nhi phan: " << decToBin(dec) << "\n";
	return 0;
}

int decToBin(int dec)
{
	if (dec / 2 == 0)
		return dec;
	return decToBin(dec / 2) * 10 + (dec % 2);
}
