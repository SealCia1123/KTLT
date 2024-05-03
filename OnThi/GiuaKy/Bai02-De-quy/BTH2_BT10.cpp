#include <cstdlib>
#include <iostream>
using namespace std;

int UCLN(int a, int b);

int main()
{
	int a, b;
	cout << "Nhap 2 so: ";
	cin >> a >> b;
	cout << "UCLN cua 2 so: " << UCLN(a, b) << "\n";
	return 0;
}

int UCLN(int a, int b)
{
	a = abs(a);
	b = abs(b);
	if (b == 0)
		return a;
	int d = a % b;
	return UCLN(b, d);
}
