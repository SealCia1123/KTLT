#include <cstdlib>
#include <iostream>
using namespace std;

int UCLN(int a, int b);

class PhanSo
{
  private:
	int tuSo, mauSo;

  public:
	int getTS();
	int getMS();
	void setFraction();
	void getFraction();
	void simplify(PhanSo &p);
	PhanSo sumFractions(const PhanSo p1, const PhanSo p2);
	PhanSo subFractions(const PhanSo p1, const PhanSo p2);
};

int PhanSo::getTS()
{
	return this->tuSo;
}

int PhanSo::getMS()
{
	return this->mauSo;
}

void PhanSo::setFraction()
{
	do
	{
		cout << "Nhap vao tu so va mau so: ";
		cin >> tuSo >> mauSo;
		if (mauSo == 0)
			cout << "Nhap mau so khac 0\n";
	} while (mauSo == 0);
}

void PhanSo::getFraction()
{
	if (mauSo == 1)
		cout << tuSo << endl;
	else
		cout << tuSo << "/" << mauSo << endl;
}

void PhanSo::simplify(PhanSo &p)
{
	if (p.mauSo < 0)
	{
		p.tuSo *= -1;
		p.mauSo *= -1;
	}
	int UC = UCLN(p.tuSo, p.mauSo);
	p.tuSo /= UC;
	p.mauSo /= UC;
}

PhanSo PhanSo::sumFractions(const PhanSo p1, const PhanSo p2)
{
	PhanSo result;
	if (p1.mauSo == p2.mauSo)
	{
		result.tuSo = p1.tuSo + p2.tuSo;
		result.mauSo = p1.mauSo;
	}
	else
	{
		result.tuSo = p1.tuSo * p2.mauSo + p2.tuSo * p1.mauSo;
		result.mauSo = p1.mauSo * p2.mauSo;
	}
	simplify(result);
	return result;
}

PhanSo PhanSo::subFractions(const PhanSo p1, const PhanSo p2)
{
	PhanSo result;
	if (p1.mauSo == p2.mauSo)
	{
		result.tuSo = p1.tuSo - p2.tuSo;
		result.mauSo = p1.mauSo;
	}
	else
	{
		result.tuSo = (p1.tuSo * p2.mauSo) - (p2.tuSo * p1.mauSo);
		result.mauSo = p1.mauSo * p2.mauSo;
	}
	simplify(result);
	return result;
}

int main()
{
	PhanSo p1, p2, res;
	int choice;
	cout << "1. Tinh TONG hai phan so\n";
	cout << "2. Tinh HIEU hai phan so\n";
	cout << "3. Tinh TICH hai phan so\n";
	cout << "4. Tinh THUONG hai phan so\n";
	cout << "Nhap lua chon: ";
	cin >> choice;
	cout << "Nhap phan so thu nhat\n";
	p1.setFraction();
	cout << "Nhap phan so thu hai\n";
	p2.setFraction();
	switch (choice)
	{
	case 1:
	{
		res = res.sumFractions(p1, p2);
		cout << "Tong hai phan so la: ";
		res.getFraction();
		break;
	}
	case 2:
	{
		res = res.subFractions(p1, p2);
		cout << "Hieu hai phan so la: ";
		res.getFraction();
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
