#include <iostream>
using namespace std;

int *find(const int arr[], int n, int value);

int main()
{
    int n, arr[20], x;
    cout << "Nhap kich thuoc cua mang: ";
    cin >> n;
    cout << "Nhap vao phan tu cua mang: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Nhap gia tri can tim: ";
    cin >> x;
    if (find(arr, n, x) == NULL)
        cout << "Khong tim thay gia tri trong mang\n";
    else
        cout << "Tim thay gia tri tai vi tri thu " << find(arr, n, x) + 1 << " trong mang\n";
    return 0;
}

int *find(const int arr[], int n, int value)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == value)
            return (int *)i;
    }
    return NULL;
}
