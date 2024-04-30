// Tinh giai thua so nguyen khong am
#include <climits>
#include <iostream>
using namespace std;

double factorial(int n);

int main()
{
	int n;
	cout << "Nhap vao n: ";
	cin >> n;
	cout << "Giai thua cua n: " << factorial(n) << "\n";
	return 0;
}

double factorial(int n)
{
	if (n < 0)
		return INT_MIN;
	if (n == 0 || n == 1)
		return 1;
	return n * factorial(n - 1);
}
