#include <cstring>
#include <iostream>
#define MAX_SIZE 30
using namespace std;

void loweringCase(char *c);

bool isPalindrome(char *c);

int main()
{
	char *s = new char[MAX_SIZE];
	cout << "Nhap vao chuoi: ";
	cin.getline(s, MAX_SIZE);
	cout << s << endl;

	if (isPalindrome(s))
		cout << "Chuoi " << s << " la chuoi Palindrome\n";
	else
		cout << "Chuoi " << s << " khong phai la chuoi Palindrome\n";
	delete[] s;
	return 0;
}

void loweringCase(char *c)
{
	for (int i = 0; i < strlen(c); i++)
	{
		if (c[i] >= 'A' && c[i] <= 'Z')
			c[i] += 32;
	}
}

bool isPalindrome(char *c)
{
	char *temp = new char[MAX_SIZE];
	for (int j = strlen(c) - 1, i = 0; i >= 0; i++, j--)
		temp[i] = c[j];

	for (int i = 0; i < strlen(c); i++)
	{
		if (c[i] != temp[i])
		{
			/* delete[] temp; */
			return false;
		}
	}
	/* delete[] temp; */
	return true;
}
