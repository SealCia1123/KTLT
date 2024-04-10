#include "BTH5_BT10.h"

#include <iostream>
using namespace std;

int main()
{
	GPG t1, t2, res;
	cout << "Nhap vao khoang thoi gian thu nhat:\n";
	t1.setTime();
	t1.printGPG();
	cout << "Nhap vao khoang thoi gian thu hai:\n";
	t2.setTime();
	t2.printGPG();
	res = res.cal(t1, t2);
	cout << "Khoang cach giua hai khoang thoi gian la: ";
	res.printGPG();
	return 0;
}
