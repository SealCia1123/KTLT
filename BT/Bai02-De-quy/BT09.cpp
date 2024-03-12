#include <iostream>
using namespace std;

int binToDec(int n);

int main()
{
    int n;
    cout << "Nhap so o he nhi phan: ";
    cin >> n;
    cout << "So o he thap phan: " << binToDec(n) << endl;
    return 0;
}

int binToDec(int n)
{
    if (n == 0)
        return 0;
    return n % 10 + 2 * binToDec(n / 10);
}
