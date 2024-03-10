#include <iostream>
#define MAX_ROW 10
#define MAX_COL 10
using namespace std;

void inputArr(int arr[MAX_ROW][MAX_COL], int &row, int &col);

void printArr(const int arr[MAX_ROW][MAX_COL], int row, int col);

void sumMatrix(const int arr1[MAX_ROW][MAX_COL], int firstRow, int firstCol, const int arr2[MAX_ROW][MAX_COL], int secondRow, int secondCol);

void mulMatrix(const int arr1[MAX_ROW][MAX_COL], int firstRow, int firstCol, const int arr2[MAX_ROW][MAX_COL], int secondRow, int secondCol);

int main()
{
    int firstRow, firstCol, secondRow, secondCol;
    int firstArr[MAX_ROW][MAX_COL];
    int secondArr[MAX_ROW][MAX_COL];
    inputArr(firstArr, firstRow, firstCol);
    inputArr(secondArr, secondRow, secondCol);
    printArr(firstArr, firstRow, firstCol);
    printArr(secondArr, secondRow, secondCol);
    int choice;
    cout << "1. Tinh tong hai ma tran\n";
    cout << "2. Tinh tich hai ma tran\n";
    switch (choice)
    {
    case 1:
    {
        sumMatrix(firstArr, firstRow, firstCol, secondArr, secondRow, secondCol);
        break;
    }
    case 2:
    {
    }
    default:
        cout << "Lua chon khong hop le\n";
    }
    return 0;
}

void inputArr(int arr[MAX_ROW][MAX_COL], int &row, int &col)
{
    cout << "Nhap vao so hang va so cot: ";
    cin >> row >> col;
    cout << "Nhap phan tu vao mang: ";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cin >> arr[i][j];
    }
}

void printArr(const int arr[MAX_ROW][MAX_COL], int row, int col)
{
    cout << "Mang dang luu: \n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }
}

void sumMatrix(const int arr1[MAX_ROW][MAX_COL], int firstRow, int firstCol, const int arr2[MAX_ROW][MAX_COL], int secondRow, int secondCol)
{
    if (firstCol != secondCol || firstRow != secondRow)
        cout << "Khong the cong hai ma tran khac kich thuoc\n";
    else
    {
        for (int i = 0; i < firstRow; i++)
        {
            for (int j = 0; j < firstCol; j++)
                cout << arr1[i][j] + arr2[i][j] << "\t";
            cout << endl;
        }
    }
}

void mulMatrix(const int arr1[MAX_ROW][MAX_COL], int firstRow, int firstCol, const int arr2[MAX_ROW][MAX_COL], int secondRow, int secondCol)
{
    if (firstRow != secondCol)
        cout << "Khong the nhan hai ma tran\n";
    else
    {
        int newMatrix[firstCol][secondRow];
        for (int i = 0; i < firstCol; i++)
        {
            for (int j = 0; j < secondCol; j++)
                newMatrix[i][j] =
        }
    }
}
