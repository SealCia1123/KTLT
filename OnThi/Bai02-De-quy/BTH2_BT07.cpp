// Tong so chan/le
#include <iostream>
using namespace std;

int sumEvenDigit(int n);
int sumOddDigit(int n);

int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	cout << "Tong so chu so chan: " << sumEvenDigit(n) << "\n";
	cout << "Tong so chu so le: " << sumOddDigit(n) << "\n";

	return 0;
}

int sumEvenDigit(int n)
{
	if (n < 10)
	{
		if (n % 2 == 0)
			return n;
	}
	if ((n % 10) % 2 == 0)
		return (n % 10) + sumEvenDigit(n / 10);
	return sumEvenDigit(n / 10);
}

int sumOddDigit(int n)
{
	if (n < 10)
	{
		if (n % 2 != 0)
			return n;
	}
	if ((n % 10) % 2 != 0)
		return (n % 10) + sumOddDigit(n / 10);
	return sumOddDigit(n / 10);
}
