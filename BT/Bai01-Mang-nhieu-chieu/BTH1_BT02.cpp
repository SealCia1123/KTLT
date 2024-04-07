#include <iostream>
using namespace std;

int main()
{
	int i = 0, j = 0;
	int arr[4][3];

	cout << "Nhap mang 2 chieu: ";
	while (i < 4)
	{
		j = 0;
		while (j < 3)
		{
			cin >> arr[i][j];
			j++;
		}
		i++;
	}

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 3)
		{
			cout << arr[i][j] << "\t";
			j++;
		}
		cout << endl;
		i++;
	}
	return 0;
}
