#include <ctime>
#include <iostream>
using namespace std;

int main()
{
	srand(time(0));
	int a[30];
	int *p = a;
	for (int i = 0; i < 30; i++)
		*(p + i) = rand() % (10 - 1 + 1) + 1;
	for (int i = 0; i < 30; i++)
		cout << *(p + i) << " ";
	cout << endl;
	return 0;
}
