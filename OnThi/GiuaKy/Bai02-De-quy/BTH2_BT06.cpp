// Tinh so dao nguoc
#include <iostream>
using namespace std;

int result = 0;
int reversedNum(int n);

int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	cout << "So dao nguoc: " << reversedNum(n) << "\n";
	return 0;
}

int reversedNum(int n)
{
	if (n < 10)
		return result * 10 + n;
	result = result * 10 + (n % 10);
	return reversedNum(n / 10);
}
