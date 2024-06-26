#include <iostream>

using namespace std;

double myPow(int x, int y);

int main()
{
	int x, y;
	cout << "Nhap vao x, y: ";
	cin >> x >> y;
	cout << "Ket qua cua " << x << " mu " << y << " la: " << myPow(x, y) << endl;
	return 0;
}

double myPow(int x, int y)
{
	if (y == 0)
		return 1;
	else if (y == 1)
		return x;

	if (y > 0)
		return (double)x * myPow(x, y - 1);
	else
		return 1.0 / myPow(x, -y);
}
