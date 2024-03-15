#include <iostream>
using namespace std;

int UCLN(int a, int b);

int main()
{
	int x, y;
	int *ptr1 = &x, *ptr2 = &y;
	cout << "Nhap vao 2 so: ";
	cin >> *ptr1 >> *ptr2;
	cout << "Uoc chung lon nhat cua hai so vua nhap la: " << UCLN(*ptr1, *ptr2) << endl;
	return 0;
}

int UCLN(int a, int b)
{
	if (b == 0)
		return a;
	int d = a % b;
	return UCLN(b, d);
}
