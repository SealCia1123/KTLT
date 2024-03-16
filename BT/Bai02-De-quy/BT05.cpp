#include <iostream>

using namespace std;

int count(int n);

int main()
{
	int n;
	cout << "Nhap so n: ";
	cin >> n;
	cout << "So " << n << " co " << count(n) << " chu so\n";
	return 0;
}

int count(int n)
{
	if (n < 10)
		return 1;
	return 1 + count(n / 10);
}
