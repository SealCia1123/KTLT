#include <iostream>
using namespace std;

int *reversedArr(const int arr[], int n);

int main()
{
    int n, arr[20];
    cout << "Nhap kich thuoc cua mang: ";
    cin >> n;
    cout << "Nhap vao phan tu cua mang: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Mang dao nguoc la: ";
    int *newArr = reversedArr(arr, n);
    for (int i = 0; i < n; i++)
        cout << newArr[i] << " ";
    cout << endl;

    delete[] newArr;
    newArr = nullptr;
    return 0;
}

int *reversedArr(const int arr[], int n)
{
    int *newArr = new int[n];
    for (int i = 0, j = n - 1; i < n; i++, j--)
        newArr[i] = arr[j];
    return newArr;
}
