#include <cstdlib>
#include <iostream>
using namespace std;

struct PhanSo
{
	int tuSo;
	int mauSo;
};

int UCLN(int a, int b)
{
	a = abs(a);
	b = abs(b);
	if (b == 0)
		return a;
	int d = a % b;
	return UCLN(b, d);
}

PhanSo simplify(PhanSo &p)
{
	if (p.mauSo < 0)
	{
		p.tuSo *= -1;
		p.mauSo *= -1;
	}

	int UC = UCLN(p.tuSo, p.mauSo);
	p.tuSo /= UC;
	p.mauSo /= UC;
	return p;
}

void inputFraction(PhanSo &p)
{
	do
	{
		cout << "Nhap vao tu so va mau so: ";
		cin >> p.tuSo;
		cin.ignore();
		cin >> p.mauSo;
		if (p.mauSo == 0)
			cout << "Loi chia cho 0, vui long nhap lai\n";
	} while (p.mauSo == 0);
}

void printFraction(const PhanSo p)
{
	if (p.mauSo == 1)
		cout << p.tuSo;
	else
		cout << p.tuSo << "/" << p.mauSo;
}

PhanSo sumFractions(const PhanSo p1, const PhanSo p2)
{
	PhanSo result;
	result.tuSo = p1.tuSo * p2.mauSo + p2.tuSo * p1.mauSo;
	result.mauSo = p1.mauSo * p2.mauSo;
	return simplify(result);
}

PhanSo subFractions(const PhanSo p1, const PhanSo p2)
{
	PhanSo result;
	result.tuSo = p1.tuSo * p2.mauSo - p2.tuSo * p1.mauSo;
	result.mauSo = p1.mauSo * p2.mauSo;
	return simplify(result);
}

PhanSo mulFractions(const PhanSo p1, const PhanSo p2)
{
	PhanSo result;
	result.tuSo = p1.tuSo * p2.tuSo;
	result.mauSo = p1.mauSo * p2.mauSo;
	return simplify(result);
}

PhanSo divFractions(const PhanSo p1, const PhanSo p2)
{
	PhanSo result;
	result.tuSo = p1.tuSo * p2.mauSo;
	result.mauSo = p1.mauSo * p2.tuSo;
	return simplify(result);
}

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
		cout << "Tong hai phan so: ";
		printFraction(sumFractions(p1, p2));
		cout << "\n";
		break;
	}
	case 2:
	{
		cout << "Hieu hai phan so: ";
		printFraction(subFractions(p1, p2));
		cout << "\n";
		break;
	}
	case 3:
	{
		cout << "Tich hai phan so: ";
		printFraction(mulFractions(p1, p2));
		cout << "\n";
		break;
	}
	case 4:
	{
		cout << "Thuong hai phan so: ";
		printFraction(divFractions(p1, p2));
		cout << "\n";
		break;
	}
	default:
		cout << "Lua chon khong hop le\n";
	}
	return 0;
}
