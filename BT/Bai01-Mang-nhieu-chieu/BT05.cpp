#include <iostream>
#define MAX_SIZE 10
using namespace std;

int main()
{
    int n;
    int arr[MAX_SIZE][MAX_SIZE];
    cout << "Nhap kich thuoc cua ma tran: ";
    cin >> n;

    cout << "Nhap phan tu vao mang: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }

    int tongDuongCheoChinh = 0, tongDuongCheoPhu = 0;
    for (int i = 0, j = 0; i < n; i++, j++)
        tongDuongCheoChinh += arr[i][j];
    cout << "Tong duong cheo chinh: " << tongDuongCheoChinh << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j == n - 1)
                tongDuongCheoPhu += arr[i][j];
        }
    }

    cout << "Tong duong cheo phu: " << tongDuongCheoPhu << endl;
    return 0;
}
