#include <cstdlib>
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

void checkNegative(PhanSo &p);

PhanSo sumFractions(const PhanSo p1, const PhanSo p2);

PhanSo subFractions(const PhanSo p1, const PhanSo p2);

PhanSo mulFractions(const PhanSo p1, const PhanSo p2);

PhanSo divFractions(const PhanSo p1, const PhanSo p2);

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
		printFraction(sumFractions(p1, p2));
		break;
	}
	case 2:
	{
		cout << "Hieu cua hai phan so la: ";
		printFraction(subFractions(p1, p2));
		break;
	}
	case 3:
	{
		cout << "Tich cua hai phan so la: ";
		printFraction(mulFractions(p1, p2));
		break;
	}
	case 4:
	{
		cout << "Thuong cua hai phan so la: ";
		printFraction(divFractions(p1, p2));
		break;
	}
	default:
		cout << "Lua chon khong hop le\n";
	}
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
	if (p.mauSo == 1)
		cout << p.tuSo << endl;
	else
		cout << p.tuSo << "/" << p.mauSo << endl;
}

PhanSo simplify(PhanSo &p)
{
	int UC = UCLN(p.tuSo, p.mauSo);
	p.tuSo /= UC;
	p.mauSo /= UC;
	return p;
}

void checkNegative(PhanSo &p)
{
	// Neu ra mau am thi * -1 de ra dang (so am) / (so duong)
	if (p.mauSo < 0)
	{
		p.tuSo *= -1;
		p.mauSo *= -1;
	}
}

PhanSo sumFractions(const PhanSo p1, const PhanSo p2)
{
	PhanSo result;
	if (p1.mauSo == p2.mauSo)
	{
		result.tuSo = p1.tuSo + p2.tuSo;
		result.mauSo = p1.mauSo;
		return simplify(result);
	}

	int UC = UCLN(p1.mauSo, p2.mauSo);
	result.tuSo = p1.tuSo * p2.mauSo + p2.tuSo * p1.mauSo;
	result.mauSo = p1.mauSo * p2.mauSo;
	checkNegative(result);
	return simplify(result);
}

PhanSo subFractions(const PhanSo p1, const PhanSo p2)
{
	PhanSo result;
	if (p1.mauSo == p2.mauSo)
	{
		result.tuSo = p1.tuSo - p2.tuSo;
		result.mauSo = p1.mauSo;
		return simplify(result);
	}

	int UC = UCLN(p1.mauSo, p2.mauSo);
	result.tuSo = p1.tuSo * p2.mauSo - p2.tuSo * p1.mauSo;
	result.mauSo = p1.mauSo * p2.mauSo;
	checkNegative(result);
	return simplify(result);
}

PhanSo mulFractions(const PhanSo p1, const PhanSo p2)
{
	PhanSo result;
	result.tuSo = p1.tuSo * p2.tuSo;
	result.mauSo = p1.mauSo * p2.mauSo;
	checkNegative(result);
	return simplify(result);
}

PhanSo divFractions(const PhanSo p1, const PhanSo p2)
{
	PhanSo result;
	result.tuSo = p1.tuSo * p2.mauSo;
	result.mauSo = p1.mauSo * p2.tuSo;
	checkNegative(result);
	return simplify(result);
}
