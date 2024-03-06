#include <cmath>
#include <iostream>
using namespace std;

void input(int **arr, int row, int col);

void printArr(const int *const *const arr, int row, int col);

bool isPrime(int n);

int sumOfPrimeNumber(int **arr, int row, int col);

int main()
{
    int row, col;
    cout << "Nhap vao so hang va so cot: ";
    cin >> row >> col;
    int **arr = new int *[row];
    for (int i = 0; i < row; i++)
        arr[i] = new int[col];

    input(arr, row, col);
    printArr(arr, row, col);
    cout << "Tong cac so nguyen to trong mang: " << sumOfPrimeNumber(arr, row, col) << endl;

    for (int i = 0; i < row; i++)
        delete[] arr[i];
    delete[] arr;
    return 0;
}

void input(int **arr, int row, int col)
{
    cout << "Nhap phan tu vao mang: ";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cin >> arr[i][j];
    }
}

void printArr(const int *const *const arr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int sumOfPrimeNumber(int **arr, int row, int col)
{
    int sum = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (isPrime(arr[i][j]))
                sum += arr[i][j];
        }
    }
    return sum;
}
