#include <cstring>
#include <iostream>
using namespace std;

int main()
{
	char password[11];
	cout << "Nhap mat khau: ";
	cin >> password;
	for (int i = 0; i < strlen(password); i++)
		cout << "X ";
	return 0;
}
