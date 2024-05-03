// Nhi phan -> thap phan
#include <iostream>
using namespace std;

int binToDec(int bin);

int main()
{
	int n;
	cout << "Nhap vao so he nhi phan: ";
	cin >> n;
	cout << "So o he thap phan: " << binToDec(n) << "\n";
	return 0;
}

int binToDec(int n)
{
	if (n < 10)
		return n;
	return (n % 10) + 2 * binToDec(n / 10);
}
