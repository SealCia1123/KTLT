#include "BTH5_BT10.h"

#include <iostream>
using namespace std;

int main()
{
	GPG t1, t2, res;
	t1.setTime();
	t1.printGPG();
	t2.setTime();
	t2.printGPG();
	res = res.cal(t1, t2);
	res.printGPG();
	return 0;
}
