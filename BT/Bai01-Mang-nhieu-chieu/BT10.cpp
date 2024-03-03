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
    int count = 1;
    int h1 = 0, h2 = n - 1, c1 = 0, c2 = n - 1;
    while (h1 <= h2 && c1 <= c2)
    {
        for (int i = c1; i <= c2; i++)
            arr[h1][i] = count++;
        h1++;
        for (int i = h1; i <= h2; i++)
            arr[i][c2] = count++;
        --c2;
        if (c1 <= c2)
        {
            for (int i = c2; i >= c1; i--)
                arr[h2][i] = count++;
            --h2;
        }
        if (h1 <= h2)
        {
            for (int i = h2; i >= h1; i--)
                arr[i][c1] = count++;
            ++c1;
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
