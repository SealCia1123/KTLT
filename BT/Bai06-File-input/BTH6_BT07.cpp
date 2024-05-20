#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ofstream outData;
	outData.open("test.txt", ios::out);
	while (true)
	{
		int temp;
		cin >> temp;
		if (temp == -1)
			break;
		outData << temp << " ";
	}
	outData.close();
	return 0;
}
