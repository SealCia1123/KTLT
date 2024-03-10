#include <iostream>
using namespace std;

int decToBin(int n);

int main()
{
    int n;
    cout << "Nhap so o he thap phan: ";
    cin >> n;
    cout << "So o he nhi phan la: " << decToBin(n);
    cout << endl;
    return 0;
}

int decToBin(int n)
{
    if (n == 0)
        return 0;
    else
    {
        int temp = n % 2;
        return decToBin(n / 2) * 10 + temp;
    }
}
