#include <iostream>
using namespace std;

int myReverse(int n);

int res = 0;

int main()
{
	int n;
	cout << "Nhap so nguyen duong n: ";
	cin >> n;
	cout << "So dao nguoc cua " << n << " la: " << myReverse(n) << endl;
	return 0;
}

int myReverse(int n)
{
	if (n == 0)
		return res;

	res = res * 10 + (n % 10);
	return myReverse(n / 10);
}
