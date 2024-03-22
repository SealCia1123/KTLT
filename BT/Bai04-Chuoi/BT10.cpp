#include <cstring>
#include <iostream>
#define MAX_SIZE 20
using namespace std;

void printDate(char *date);

int main()
{
	char date[MAX_SIZE];
	cin >> date;
	printDate(date);
	return 0;
}

void printDate(char *date)
{
	char month[12][10] = {"January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	char *dates = new char[MAX_SIZE];
	char *p = strtok(date, "/");
	while (p != NULL)
	{
		p = strtok(NULL, "/");
		cout << p << " ";
	}
	cout << dates;
	delete[] dates;
	dates = NULL;
}
