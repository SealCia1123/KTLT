#include <iostream>
using namespace std;

int sumOfArr(int arr[], int n);

int main()
{
    int arr[10], n;
    cout << "Nhap kich thuoc cua mang: ";
    cin >> n;
    cout << "Nhap phan tu vao mang: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Tong phan tu cua mang: " << sumOfArr(arr, n) << endl;
    return 0;
}

int sumOfArr(int arr[], int n)
{
    if (n == 0)
        return arr[0];
    return arr[n - 1] + sumOfArr(arr, n - 1);
}
