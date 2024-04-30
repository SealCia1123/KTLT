// Dem chu so
#include <iostream>
using namespace std;

int countDigit(int n);

int main()
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	cout << "n co " << countDigit(n) << " chu so\n";
	return 0;
}

int countDigit(int n)
{
	if (n < 10)
		return 1;
	return 1 + countDigit(n / 10);
}
