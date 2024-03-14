#include <cstring>
#include <iostream>
#define MAX_SIZE 30
using namespace std;

int main()
{
	char *name = new char[MAX_SIZE];
	cout << "Nhap vao ho va ten: ";
	cin.getline(name, 30);

	char *p = strtok(name, ", ");
	while (p != NULL)
	{
		cout << p << " ";
		p = strtok(NULL, ", ");
	}
	delete[] name;
	delete[] p;
	return 0;
}
