#include <iomanip>
#include <iostream>

using namespace std;

int sum1(int n);

int sum2(int n);

double sum3(int n);

int factorial(int n);

int sum4(int n);

int main()
{
	int choice, n;
	cout << "1. S1 = 1 + 2 + 3 + ... + n\n";
	cout << "2. S2 = 1^2 + 2^2 + 3^2 + .. + n^2\n";
	cout << "3. S3 = 1 + 1/3 + 1/5 + ... + 1/n\n";
	cout << "4. S4 = 1! + 2! + 3! + ... + n!\n";
	cout << "Nhap vao lua chon: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		do
		{
			cout << "Nhap n (n > 0): ";
			cin >> n;
			if (n <= 0)
				cout << "Nhap n la so nguyen duong\n";
		} while (n <= 0);
		cout << "S = " << sum1(n) << endl;
		break;
	}
	case 2:
	{
		do
		{
			cout << "Nhap n (n > 0): ";
			cin >> n;
			if (n <= 0)
				cout << "Nhap n la so nguyen duong\n";
		} while (n <= 0);
		cout << "S = " << sum2(n) << endl;
		break;
	}
	case 3:
	{
		do
		{
			cout << "Nhap n (n > 0 & n % 2 == 1): ";
			cin >> n;
			if (n <= 0 && n % 2 == 1)
				cout << "Nhap n la so nguyen duong va n la so le\n";
		} while (n <= 0 && n % 2 == 1);
		cout << "S = " << fixed << setprecision(2) << sum3(n) << endl;
		break;
	}
	case 4:
	{
		do
		{
			cout << "Nhap n (n > 0): ";
			cin >> n;
			if (n <= 0)
				cout << "Nhap n la so nguyen duong\n";
		} while (n <= 0);
		cout << "S = " << sum4(n) << endl;
		break;
	}
	default:
		cout << "Lua chon khong hop le\n";
	}
	return 0;
}

int sum1(int n)
{
	if (n == 1)
		return 1;
	return n + sum1(n - 1);
}

int sum2(int n)
{
	if (n == 1)
		return 1;
	return n * n + sum2(n - 1);
}

double sum3(int n)
{
	if (n == 1)
		return (double)1;
	return (double)1 / n + sum3(n - 2);
}

int factorial(int n)
{
	if (n == 0 || n == 1)
		return 1;
	return n * factorial(n - 1);
}

int sum4(int n)
{
	if (n == 1)
		return 1;
	return factorial(n) + sum4(n - 1);
}
