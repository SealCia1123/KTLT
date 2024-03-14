#include <iostream>
using namespace std;

int sumEvenNum(int n);

int main()
{
	int n;
	cout << "Nhap so: ";
	cin >> n;
	cout << "Tong cac chu so chan: " << sumEvenNum(n) << endl;
	return 0;
}

int sumEvenNum(int n)
{
	int temp = n % 10;
	if (temp % 2 == 0)
		return temp + sumEvenNum(n / 10);
	else
		return 0;
}
