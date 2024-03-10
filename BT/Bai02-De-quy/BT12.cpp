#include <iostream>
using namespace std;

int findMin(const int arr[], int first, int last);

int main()
{
    int n, arr[10];
    cout << "Nhap kich thuoc cua mang: ";
    cin >> n;

    cout << "Nhap phan tu vao mang: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Mang da nhap la: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl
         << "Phan tu nho nhat trong mang la: " << findMin(arr, 0, n - 1) << endl;

    return 0;
}

int findMin(const int arr[], int start, int end)
{
    if (start == end)
        return arr[start];
    int min = findMin(arr, start + 1, end);
    if (arr[start] < min)
        min = arr[start];
    return min;
}
