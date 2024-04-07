#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ofstream textFile;
	textFile.open("BT1.txt", ios::out);
	int a, b;
	cout << "Nhap vao hai so nguyen: ";
	cin >> a >> b;
	textFile << a + b;
	textFile.close();
	return 0;
}
