#include <iostream>
using namespace std;

int main()
{
	int arr[4][3];
	int i = 0, j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 3)
		{
			cin >> arr[i][j];
			++j;
		}
		++i;
	}

	i = 0, j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 3)
		{
			cout << arr[i][j] << "\t";
			++j;
		}
		cout << "\n";
		++i;
	}
	return 0;
}
