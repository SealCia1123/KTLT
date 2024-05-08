#include <iostream>
using namespace std;

int UCLN(int a, int b)
{
	if (b == 0)
		return a;
	int d = a % b;
	return UCLN(b, d);
}

int main()
{
	int a, b;
	cin >> a >> b;
	int *p = &a, *q = &b;
	cout << UCLN(*p, *q);
	return 0;
}
