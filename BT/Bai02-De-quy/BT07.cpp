#include <iostream>

using namespace std;

int sumEvenNum(int n);

int main()
{
	int n;
	cout << "Nhap vao so n: ";
	cin >> n;
	cout << "Tong cac chu so chan cua " << n << " la: " << sumEvenNum(n) << endl;
	return 0;
}

int sumEvenNum(int n)
{
	if (n == 0)
		return 0;

	if ((n % 10) % 2 == 0)
		return (n % 10) + sumEvenNum(n / 10);
	return sumEvenNum(n / 10);
}
