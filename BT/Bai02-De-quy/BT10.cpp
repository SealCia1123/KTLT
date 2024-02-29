#include <iostream>
using namespace std;

int UCLN(int a, int b);

int main()
{
    int a, b;
    cout << "Nhap hai so nguyen: ";
    cin >> a >> b;
    cout << "Uoc chung lon nhat cua hai so nguyen " << a << " va " << b << " la: " << UCLN(a, b) << endl;
    return 0;
}

int UCLN(int a, int b)
{
    if (b == 0)
        return a;
    int d = a % b;
    return UCLN(b, d);
}
