#include <iostream>
using namespace std;

struct PhanSo
{
	int tuSo;
	int mauSo;
};

int UCLN(int a, int b);

PhanSo simplify(PhanSo &p);

void inputFraction(PhanSo &p);

void printFraction(const PhanSo p);

PhanSo sumOfFraction(const PhanSo p1, const PhanSo p2);

int main()
{
	PhanSo p1, p2;
	int choice;
	cout << "1. Tinh TONG hai phan so\n";
	cout << "2. Tinh HIEU hai phan so\n";
	cout << "3. Tinh TICH hai phan so\n";
	cout << "4. Tinh THUONG hai phan so\n";
	cout << "Nhap lua chon: ";
	cin >> choice;
	inputFraction(p1);
	inputFraction(p2);
	switch (choice)
	{
	case 1:
	{
		cout << "Tong cua hai phan so la: ";
		PhanSo p3 = sumOfFraction(p1, p2);
		printFraction(simplify(p3));
		break;
	}
	default:
		cout << "Lua chon khong hop le\n";
	}
	return 0;
}

int UCLN(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}

void inputFraction(PhanSo &p)
{
	do
	{
		cout << "Nhap vao tu so: ";
		cin >> p.tuSo;
		cout << "Nhap vao mau so: ";
		cin >> p.mauSo;
		if (p.mauSo == 0)
			cout << "Khong nhap mau so bang 0\n";
	} while (p.mauSo == 0);
}

void printFraction(const PhanSo p)
{
	cout << p.tuSo << "/" << p.mauSo << endl;
}

PhanSo simplify(PhanSo &p)
{
	int UC = UCLN(p.tuSo, p.mauSo);
	p.tuSo /= UC;
	p.mauSo /= UC;
	return p;
}

PhanSo sumOfFraction(const PhanSo p1, const PhanSo p2)
{
	PhanSo result;
	if (p1.mauSo == p2.mauSo)
	{
		result.tuSo = p1.tuSo + p2.tuSo;
		result.mauSo = p1.mauSo;
		return simplify(result);
	}

	int UC = UCLN(p1.mauSo, p2.mauSo);
	result.tuSo = p1.tuSo * UC + p2.tuSo * UC;
	result.mauSo = p1.mauSo * UC;
	return simplify(result);
}
