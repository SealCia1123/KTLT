#include <cstring>
#include <iostream>
#define MAX_SIZE 30
using namespace std;

void removeSpace(char *c);

int countSpace(char *c);

int countChar(char *c, char choice);

int countUpperCase(char *c);

int countLowerCase(char *c);

void upperCase(char *c);

void lowerCase(char *c);

void upperCaseEachWord(char *c);

int main()
{
    char *c = new char[MAX_SIZE];
    char choice;
    cout << "a. Loai bo khoang trang dau vao cuoi chuoi\n";
    cout << "b. Dem so khoang trang cua chuoi\n";
    cout << "c. Dem chuoi co bao nhieu chu hoac so\n";
    cout << "d. Dem chuoi co bao nhieu ky tu in hoa\n";
    cout << "e. Dem chuoi co bao nhieu ky tu in thuong\n";
    cout << "f. Chuyen toan bo chuoi sang in hoa\n";
    cout << "g. Chuyen toan bo chuoi sang in thuong\n";
    cout << "h. Chuyen chuoi sang in hoa moi tu\n";
    cout << "i. Dem chuoi co bao nhieu tu\n";
    cout << "Nhap vao lua chon: ";
    cin >> choice;
    cin.ignore();
    cout << "Nhap vao chuoi: ";
    cin.getline(c, MAX_SIZE);

    switch (choice)
    {
    case 'a':
    {
        removeSpace(c);
        cout << "Chuoi da loai bo khoang trang dau cuoi: " << c << endl;
        break;
    }
    case 'b':
    {
        cout << "So luong khoang trang cua chuoi la: " << countSpace(c) << endl;
        break;
    }
    case 'c':
    {

        char temp;
        cout << "Ban muon kiem tra so luong chu hay so (C/S): ";
        cin >> temp;
        if (temp == 'c' || temp == 'C')
            cout << "Chuoi co " << countChar(c, temp) << " chu\n";
        else
            cout << "Chuoi co " << countChar(c, temp) << " chu so\n";
        break;
    }
    case 'd':
    {
        cout << "Chuoi co " << countUpperCase(c) << " ky tu in hoa\n";
        break;
    }
    case 'e':
    {
        cout << "Chuoi co " << countLowerCase(c) << " ky tu in thuong\n";
        break;
    }
    case 'f':
    {
        upperCase(c);
        cout << "Chuoi sau khi in hoa: " << c << endl;
        break;
    }
    case 'g':
    {
        lowerCase(c);
        cout << "Chuoi sau khi in thuong: " << c << endl;
        break;
    }
    case 'h':
    {
        upperCaseEachWord(c);
        cout << "Chuoi khi in hoa moi tu: " << c << endl;
        break;
    }
    default:
        cout << "Lua chon khong hop le\n";
    }
    delete[] c;
    return 0;
}

void removeSpace(char *c)
{
    while (c[0] == ' ')
    {
        for (int i = 0; i < strlen(c); i++)
            c[i] = c[i + 1];
    }

    int index = strlen(c) - 1;
    while (c[index] == ' ')
    {
        c[strlen(c) - 1] = '\0';
        --index;
    }
}

int countSpace(char *c)
{
    int count = 0;
    for (int i = 0; i < strlen(c); i++)
    {
        if (c[i] == ' ')
            ++count;
    }
    return count;
}

int countChar(char *c, char choice)
{
    int count = 0;
    if (choice == 'C' || choice == 'c')
    {
        for (int i = 0; i < strlen(c); i++)
        {
            if ((c[i] >= 97 && c[i] <= 122) || (c[i] >= 65 && c[i] <= 90))
                ++count;
        }
    }
    else
    {
        for (int i = 0; i < strlen(c); i++)
        {
            if (c[i] >= 48 && c[i] <= 57)
                ++count;
        }
    }
    return count;
}

int countUpperCase(char *c)
{
    int count = 0;
    for (int i = 0; i < strlen(c); i++)
    {
        if (c[i] >= 65 && c[i] <= 90)
            ++count;
    }
    return count;
}

int countLowerCase(char *c)
{
    int count = 0;
    for (int i = 0; i < strlen(c); i++)
    {
        if (c[i] >= 97 && c[i] <= 122)
            ++count;
    }
    return count;
}

void upperCase(char *c)
{
    for (int i = 0; i < strlen(c); i++)
    {
        if (c[i] >= 97 && c[i] <= 122)
            c[i] -= 32;
    }
}

void lowerCase(char *c)
{

    for (int i = 0; i < strlen(c); i++)
    {
        if (c[i] >= 65 && c[i] <= 90)
            c[i] += 32;
    }
}

void upperCaseEachWord(char *c)
{
    if (c[0] >= 97 && c[0] <= 122)
        c[0] -= 32;
    for (int i = 0; i < strlen(c) - 1; i++)
    {
        if (c[i] == ' ' && (c[i + 1] >= 97 && c[i + 1] <= 122))
            c[i + 1] -= 32;
    }
}
