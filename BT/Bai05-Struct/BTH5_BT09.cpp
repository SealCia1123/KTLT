#include "BT09.h"

#include <iostream>
using namespace std;

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
	case 3:
	{
		res = res.mulFractions(p1, p2);
		cout << "Tich hai phan so la: ";
		res.getFraction();
		break;
	}
	case 4:
	{
		res = res.divFractions(p1, p2);
		cout << "Thuong hai phan so la: ";
		res.getFraction();
		break;
	}

	default:
		cout << "Lua chon khong hop le\n";
	}
	return 0;
}
