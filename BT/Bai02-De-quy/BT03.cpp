#include <cmath>
#include <iostream>
using namespace std;

double normalPow(int x, int y)
{
    double result = 1.0;
    if (y >= 0)
    {
        for (int i = 1; i <= y; i++)
            result *= x;
    }
    else
    {
        for (int i = 1; i <= abs(y); i++)
            result /= x;
    }
    return result;
}

double myPow(int x, int y);

int main()
{
    int x, y;
    cout << "Nhap vao x, y: ";
    cin >> x >> y;
    cout << "Ket qua cua " << x << " mu " << y << " la: " << myPow(x, y) << endl;
    return 0;
}

double myPow(int x, int y)
{
    if (y == 0)
        return 1;
    else if (y > 0)
        return x * myPow(x, y - 1);
    else
        return 1.0 / x * myPow(x, y + 1);
}
