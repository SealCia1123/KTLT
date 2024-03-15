// Viet ham tinh gia tri Fibonacci cua so nguyen khong am
#include <iostream>
using namespace std;

int fib(int n);

int main()
{
	int n;
	cout << "Nhap vao so can tinh: ";
	cin >> n;
	cout << "So Fibonacci cua " << n << " la: " << fib(n) << endl;
	return 0;
}

int fib(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	return fib(n - 1) + fib(n - 2);
}
