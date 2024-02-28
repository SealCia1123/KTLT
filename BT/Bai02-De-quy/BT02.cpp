#include <iostream>
using namespace std;

int factorial(int n);

int main()
{
    int n;
    do
    {
        cout << "Nhap vao so nguyen duong n (n > 0): ";
        cin >> n;
        if (n <= 0)
            cout << "Nhap sai, nhap lai n\n";
    } while (n <= 0);

    cout << "Giai thua cua " << n << " la: " << factorial(n) << endl;
    return 0;
}

int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}
