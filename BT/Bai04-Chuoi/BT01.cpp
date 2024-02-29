#include <cstring>
#include <iostream>
#define MAX_SIZE 30
using namespace std;

void compareStr(char *s1, char *s2);

void capitalizeStr(char *s);

int main()
{
    char *s1 = new char[MAX_SIZE], *s2 = new char[MAX_SIZE];
    cout << "Nhap vao 2 chuoi: ";
    cin.getline(s1, MAX_SIZE);
    cin.getline(s2, MAX_SIZE);
    compareStr(s1, s2);

    capitalizeStr(s1);
    capitalizeStr(s2);
    cout << "Chuoi thu nhat sau khi viet hoa: " << s1 << endl;
    cout << "Chuoi thu hai sau khi viet hoa: " << s2 << endl;

    s1 = strcat(s1, s2);
    cout << "Chuoi sau khi noi: " << s1 << endl;
    return 0;
}

void compareStr(char *s1, char *s2)
{
    if (strlen(s1) == strlen(s2))
        cout << "Hai chuoi co do dai bang nhau\n";
    else if (strlen(s1) > strlen(s2))
        cout << "Chuoi thu nhat dai hon chuoi thu hai\n";
    else
        cout << "Chuoi thu hai dai hon chuoi thu nhat\n";
}

void capitalizeStr(char *s)
{
    if (s[0] >= 'a' && s[0] <= 'z')
        s[0] -= 32;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ' && (s[i + 1] >= 'a' && s[i + 1] <= 'z'))
            s[i + 1] -= 32;
    }
}
