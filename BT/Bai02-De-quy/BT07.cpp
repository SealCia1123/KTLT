#include <iostream>
using namespace std;

int sumEvenNum(int n);

int main()
{
<<<<<<< HEAD
    int n;
    cout << "Nhap vao so n: ";
    cin >> n;
    cout << "Tong cac chu so chan cua " << n << " la: " << sumEvenNum(n) << endl;
    return 0;
=======
	int n;
	cout << "Nhap so: ";
	cin >> n;
	cout << "Tong cac chu so chan: " << sumEvenNum(n) << endl;
	return 0;
>>>>>>> b6fc72cc7fec064b2eac1ffe80bd88e8a837f804
}

int sumEvenNum(int n)
{
<<<<<<< HEAD
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
=======
	int temp = n % 10;
	if (temp % 2 == 0)
		return temp + sumEvenNum(n / 10);
	else
		return 0;
>>>>>>> b6fc72cc7fec064b2eac1ffe80bd88e8a837f804
}
