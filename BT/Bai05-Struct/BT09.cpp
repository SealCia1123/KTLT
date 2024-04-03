#include <iostream>
using namespace std;

int UCLN(const int a, const int b);

class PhanSo
{
  private:
	int tuSo, mauSo;

  public:
	int getTS();
	int getMS();
	void setFraction();
	void printFraction();
	void simplify();
};

int PhanSo::getTS()
{
	return tuSo;
}

int PhanSo::getMS()
{
	return mauSo;
}

void PhanSo::setFraction()
{
	int a, b;
	do
	{
		cout << "Nhap vao tu so va mau so: ";
		cin >> a >> b;
		if (b == 0)
			cout << "Nhap mau khac 0\n";
	} while (b == 0);
}

void PhanSo::printFraction()
{
	if (mauSo == 1)
		cout << tuSo << endl;
	else
		cout << tuSo << "/" << mauSo << endl;
}

void PhanSo::simplify()
{
	int UC = UCLN(tuSo, mauSo);
	tuSo = tuSo / UC;
	mauSo = mauSo / UC;
}

int main()
{
	PhanSo p;
	/* PhanSo p1, p2; */
	/* int choice; */
	/* cout << "1. Tinh TONG hai phan so\n"; */
	/* cout << "2. Tinh HIEU hai phan so\n"; */
	/* cout << "3. Tinh TICH hai phan so\n"; */
	/* cout << "4. Tinh THUONG hai phan so\n"; */
	/* cout << "Nhap lua chon: "; */
	/* cin >> choice; */
	/* cout << "Nhap vao phan so thu nhat\n"; */
	/* cout << "Nhap vao phan so thu hai\n"; */
	/* switch (choice) */
	/* { */
	/* case 1: */
	/* { */
	/* 	cout << "Tong cua hai phan so la: "; */
	/* 	break; */
	/* } */
	/* case 2: */
	/* { */
	/* 	cout << "Hieu cua hai phan so la: "; */
	/* 	break; */
	/* } */
	/* case 3: */
	/* { */
	/* 	cout << "Tich cua hai phan so la: "; */
	/* 	break; */
	/* } */
	/* case 4: */
	/* { */
	/* 	cout << "Thuong cua hai phan so la: "; */
	/* 	break; */
	/* } */
	/* default: */
	/* 	cout << "Lua chon khong hop le\n"; */
	/* } */
	return 0;
}

int UCLN(const int a, const int b)
{
	if (b == 0)
		return a;
	int d = a % b;
	return UCLN(b, d);
}
