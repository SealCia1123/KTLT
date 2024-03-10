#include <iostream>
using namespace std;

int binToDec(int n);

int main()
{
    int n;
    cin >> n;
    cout << binToDec(n) << endl;
    return 0;
}

int binToDec(int n)
{
    if (n == 0)
        return 0;
    return n % 10 + 2 * binToDec(n / 10);
}
