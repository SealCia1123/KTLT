// Tinh ham mu
#include <iostream>
using namespace std;

double myPow(int x, int y);

int main()
{
	int x, y;
	cout << "Nhap vao x mu y: ";
	cin >> x >> y;
	cout << "x mu y la: " << myPow(x, y) << "\n";
	return 0;
}

double myPow(int x, int y)
{
	if (y == 0)
		return 1;
	if (y < 0)
		return (1 / myPow(x, -y));
	return x * myPow(x, y - 1);
}
