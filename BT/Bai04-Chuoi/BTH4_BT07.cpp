#include <cstring>
#include <iostream>
#define MAX_SIZE 20
using namespace std;

int *checkSubString(char *s1, char *s2);

char *replaceStr(const char *s1, const char *s2, const char *s3);

int main()
{
	char s1[MAX_SIZE], s2[MAX_SIZE], s3[MAX_SIZE];
	cout << "Nhap vao chuoi thu nhat: ";
	cin.getline(s1, MAX_SIZE);
	cout << "Nhap vao chuoi thu hai: ";
	cin.getline(s2, MAX_SIZE);

	if (checkSubString(s1, s2) == NULL)
		cout << "Chuoi thu hai khong xuat hien trong chuoi thu nhat\n";
	else
	{
		cout << "Chuoi thu hai xuat hien tai dia chi: " << checkSubString(s1, s2) << endl;
		cout << "Nhap chuoi thu ba: ";
		cin.getline(s3, MAX_SIZE);
		replaceStr(s1, s2, s3);
		cout << "Chuoi sau khi thay the chuoi thu ba: " << s1 << endl;
	}
	return 0;
}

int *checkSubString(char *s1, char *s2)
{
	int count = 0, *index;
	for (int i = strlen(s1) - 1; i >= 0; i--)
	{
		if (s1[i] == s2[i])
		{
			++count;
			index = (int *)(s1 + i);
		}
	}
	return (count == 0 ? NULL : index);
}

char *replaceStr(const char *s1, const char *s2, const char *s3)
{
	char *newStr = new char[strlen(s1)];
	return newStr;
}
