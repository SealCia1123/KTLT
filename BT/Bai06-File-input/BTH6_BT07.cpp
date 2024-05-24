#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ofstream outData;
	outData.open("BT7.txt", ios::out);
	if (!outData.is_open())
		cout << "Mo file khong thanh cong!\n";
	else
	{
		while (true)
		{
			int temp;
			cin >> temp;
			if (temp == -1)
				break;
			outData << temp << " ";
		}
		outData.close();
	}
	return 0;
}
