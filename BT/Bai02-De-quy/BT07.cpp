#include <iostream>
using namespace std;

int sumEvenNum(int n);

int main()
{
    int n;
    cout << "Nhap vao so n: ";
    cin >> n;
    cout << "Tong cac chu so chan cua " << n << " la: " << sumEvenNum(n) << endl;
    return 0;
}

int sumEvenNum(int n)
{
    if (n < 10)
    {
        if (n % 2 == 0)
            return n;
        return 0;
    }
    int temp = n % 10;
    if (temp % 2 == 0)
        return temp + sumEvenNum(n / 10);
    return 0 + sumEvenNum(n / 10);
}
