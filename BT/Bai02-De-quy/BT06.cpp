#include <iostream>

using namespace std;

int myReverse(int n);

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
	int res = 0;
	if (n == 0)
		return n;
	int temp = n % 10;
	res = res * 10 + temp;
	myReverse(n / 10);
	return res;
}
