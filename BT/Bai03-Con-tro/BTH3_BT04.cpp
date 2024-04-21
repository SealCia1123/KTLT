#include <ctime>
#include <iostream>
using namespace std;

int main()
{
	srand(time(0));
	int *p = new int[30];
	for (int i = 0; i < 30; i++)
		p[i] = rand() % (10 - 1 + 1) + 1;

	cout << "Cac phan tu la so le trong mang: ";
	for (int i = 0; i < 30; i++)
	{
		if (*(p + i) % 2 == 1)
			cout << *(p + i) << " ";
	}
	cout << endl;

	int max = p[0], *maxIndex = p;
	for (int i = 0; i < 30; i++)
	{
		if (*(p + i) > max)
		{
			max = *(p + i);
			maxIndex = p + i;
		}
	}
	cout << "Dia chi cua phan tu lon nhat trong mang: " << maxIndex << endl;
	delete[] p;
	return 0;
}
