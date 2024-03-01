#include <iostream>
#define MAX_SIZE 10
using namespace std;

void input(int arr[MAX_SIZE][MAX_SIZE], int n);
void output(const int arr[MAX_SIZE][MAX_SIZE], int n);

int main()
{

    return 0;
}

void input(int arr[MAX_SIZE][MAX_SIZE], int n)
{
    int row1 = 0, row2 = n - 1;
    int col1 = 0, col2 = n - 1;
    while (row1 <= row2 && col1 <= col2)
    {
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
