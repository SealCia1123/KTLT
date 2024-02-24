#include <iostream>
#define MAX_ROW 5
#define MAX_COL 6
using namespace std;

int main()
{
    int row, col;
    int arr[MAX_ROW][MAX_COL];
    do
    {
        cout << "Nhap vao so hang va so cot: ";
        cin >> row >> col;
        if (row > MAX_ROW || col > MAX_COL)
            cout << "Chi nhap so hang nho hon 5 va so cot nho hon 6\n";
    } while (row > MAX_ROW || col > MAX_COL);

    cout << "Nhap phan tu vao mang: ";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cin >> arr[i][j];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }

    int indexRow, indexCol;
    cout << "Nhap vao hang can tinh tong: ";
    cin >> indexRow;
    --indexRow;
    cout << "Nhap vao cot can tinh tong: ";
    cin >> indexCol;
    --indexCol;

    int sumRow = 0, sumCol = 0;
    for (int i = 0; i < col; i++)
        sumRow += arr[indexRow][i];

    for (int i = 0; i < row; i++)
        sumCol += arr[i][indexCol];
    cout << "Tong hang can tinh: " << sumRow << endl;
    cout << "Tong cot can tinh: " << sumCol << endl;

    int value, count = 0;
    cout << "Nhap gia tri can tim vao mang: ";
    cin >> value;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (value == arr[i][j])
                ++count;
        }
    }
    return 0;
}
