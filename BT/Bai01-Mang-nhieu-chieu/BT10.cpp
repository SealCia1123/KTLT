#include <iostream>
#define MAX_SIZE 10
using namespace std;

void input(int arr[MAX_SIZE][MAX_SIZE], int n);

void output(const int arr[MAX_SIZE][MAX_SIZE], int n);

int main()
{
    int arr[MAX_SIZE][MAX_SIZE];
    int n;
    cout << "Nhap vao kich thuoc cua mang: ";
    cin >> n;
    input(arr, n);
    output(arr, n);
    return 0;
}

void input(int arr[MAX_SIZE][MAX_SIZE], int n)
{
    int row1 = 0, row2 = n - 1, col1 = 0, col2 = n - 1;
    int count = 1;
    while (row1 <= row2 && col1 <= col2)
    {
        for (int i = col1; i <= col2; i++)
            arr[row1][i] = count++;
        ++row1;
        for (int i = row1; i <= row2; i++)
            arr[i][col2] = count++;
        --col2;
        if (col1 <= col2)
        {
            for (int i = col2; i >= col1; i--)
                arr[row2][i] = count++;
            --row2;
        }
        if (row1 <= row2)
        {
            for (int i = row2; i >= row1; i--)
                arr[i][col1] = count++;
            ++col1;
        }
    }
}

void output(const int arr[MAX_SIZE][MAX_SIZE], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }
}
