#include <iostream>
using namespace std;

int fib(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return fib(n - 1) + fib(n - 2);
}

int *fibArr(int n)
{
	int *list = new int[n];
	for (int i = 0; i < n; i++)
		list[i] = fib(i);
	return list;
}

int main()
{
	int n;
	cin >> n;
	int *list = fibArr(n);
	for (int i = 0; i < n; i++)
		cout << list[i] << " ";
	cout << endl;
	delete[] list;
	return 0;
}
