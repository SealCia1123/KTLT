#include <iostream>
using namespace std;

void decToBin(int n);

int main()
{
    int n;
    cout << "Nhap so o he thap phan: ";
    cin >> n;
    cout << "So o he nhi phan la: ";
    decToBin(n);
    return 0;
}

void decToBin(int n)
{
    int temp = n % 2;
    if (n == 0)
        return;
    decToBin(n / 2);
    cout << temp;
}
