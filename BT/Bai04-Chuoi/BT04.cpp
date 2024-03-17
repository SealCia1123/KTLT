#include <cstring>
#include <iostream>
#define MAX_SIZE 20
using namespace std;

char *loweringCase(char *const c);

bool isPalindrome(char *const c);

int main()
{
	char *s = new char[MAX_SIZE];
	cout << "Nhap vao chuoi: ";
	cin.getline(s, MAX_SIZE);

	if (isPalindrome(s))
		cout << "Chuoi " << s << " la chuoi Palindrome\n";
	else
		cout << "Chuoi " << s << " khong phai la chuoi Palindrome\n";

	delete[] s;
	s = NULL;
	return 0;
}

char *loweringCase(char *const c)
{
	char *res = new char[strlen(c)];
	for (int i = 0; i < strlen(c); i++)
		res[i] = c[i];

	for (int i = 0; i < strlen(res); i++)
	{
		if (res[i] >= 'A' && res[i] <= 'Z')
			res[i] += 32;
	}
	return res;
}

bool isPalindrome(char *const c)
{
	char *originStr = new char[strlen(c)];
	char *reversedStr = new char[strlen(c)];

	for (int i = 0; i < strlen(c); i++)
		originStr[i] = c[i];

	// Nhap chuoi reversedStr nguoc tu chuoi goc
	for (int i = 0, j = strlen(c) - 1; i < strlen(c); i++, j--)
		reversedStr[i] = c[j];

	reversedStr = loweringCase(reversedStr);
	originStr = loweringCase(originStr);

	for (int i = 0; i < strlen(c); i++)
	{
		if (originStr[i] != reversedStr[i])
		{
			delete[] originStr;
			delete[] reversedStr;
			originStr = NULL;
			reversedStr = NULL;
			return false;
		}
	}
	delete[] originStr;
	delete[] reversedStr;
	originStr = NULL;
	reversedStr = NULL;
	return true;
}
