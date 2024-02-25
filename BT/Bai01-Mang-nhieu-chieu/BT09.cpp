#include <iostream>
#define MAX_SIZE 10
using namespace std;

void input(int arr[MAX_SIZE][MAX_SIZE], int n);

void output(const int arr[MAX_SIZE][MAX_SIZE], int n);

int main()
{
    int n, arr[MAX_SIZE][MAX_SIZE];
    cout << "Nhap kich thuoc ma tran: ";
    cin >> n;
    input(arr, n);
    output(arr, n);
    return 0;
}

void input(int arr[MAX_SIZE][MAX_SIZE], int n)
{
    int count = 1;
    for (int j = 0; j < n; j++)
    {
        if (j % 2 == 1)
        {
            for (int i = n - 1; i >= 0; i--)
                arr[i][j] = count++;
        }
        else
        {
            for (int i = 0; i < n; i++)
                arr[i][j] = count++;
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
