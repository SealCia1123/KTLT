#include <cstring>
#include <iostream>
#define MAX_SIZE 20
using namespace std;

void printName(char *s);

int main()
{
	char s[MAX_SIZE];
	cout << "Nhap ho va ten: ";
	cin.getline(s, MAX_SIZE);
	printName(s);
	return 0;
}

void printName(char *s)
{
	char *p = strtok(s, " ");
	while (p != NULL)
	{
		cout << p << "\n";
		p = strtok(NULL, " ");
	}
}
