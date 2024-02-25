#include <climits>
#include <iostream>
#define MAX_COL 10
#define MAX_ROW 10
using namespace std;

void inputArr(int arr[MAX_COL][MAX_ROW], int row, int col);

void output(const int arr[MAX_COL][MAX_ROW], int row, int col);

double averangeValue(const int arr[MAX_COL][MAX_ROW], int row, int col);

int findValue(const int arr[MAX_COL][MAX_ROW], int row, int col, int value);

void mySwap(int &a, int &b);

void swapTwoElements(const int arr[MAX_COL][MAX_ROW], int row, int col, int x, int y);

int main()
{
    int row, col;
    int arr[MAX_ROW][MAX_COL];
    cout << "Nhap vao so hang va cot: ";
    cin >> row >> col;
    inputArr(arr, row, col);
    output(arr, row, col);
    cout << "Gia tri trung binh cua ma tran: " << averangeValue(arr, row, col) << endl;

    int value;
    cout << "Nhap vao gia tri can tim: ";
    cin >> value;
    if (findValue(arr, row, col, value) == INT_MIN)
        cout << "Khong tim thay " << value << endl;
    else
        cout << "Tim thay " << value << " trong mang\n";
    return 0;
}

void inputArr(int arr[MAX_COL][MAX_ROW], int row, int col)
{
    cout << "Nhap phan tu vao mang: ";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cin >> arr[i][j];
    }
}

void output(const int arr[MAX_COL][MAX_ROW], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }
}

double averangeValue(const int arr[MAX_COL][MAX_ROW], int row, int col)
{
    double result = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            result += arr[i][j];
    }
    result /= row * col;
    return result;
}

int findValue(const int arr[MAX_COL][MAX_ROW], int row, int col, int value)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (value == arr[i][j])
                return arr[i][j];
        }
    }
    return INT_MIN;
}

void mySwap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swapTwoElements(const int arr[MAX_COL][MAX_ROW], int row, int col, int x, int y)
{
    mySwap(findValue(arr, row, col, x), findValue(arr, row, col, y));
}
