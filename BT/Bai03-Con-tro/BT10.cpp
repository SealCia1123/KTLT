#include <iostream>
using namespace std;

void allocate_mem(int ***mt, int row, int col);

void free_mem(int **mt, int row, int col);

void generateRandomArr(int **arr, int row, int col);

void print(int **arr, int row, int col);

int **addMatrix(int **mt1, int **mt2, int row, int col);

int main()
{
    int row, col;
    cout << "Nhap so hang va so cot: ";
    cin >> row >> col;
    int **mt1, **mt2;
    allocate_mem(&mt1, row, col);
    allocate_mem(&mt2, row, col);
    generateRandomArr(mt1, row, col);
    generateRandomArr(mt2, row, col);
    print(mt1, row, col);
    print(mt2, row, col);
    free_mem(mt1, row, col);
    free_mem(mt2, row, col);
}

void allocate_mem(int ***mt, int row, int col)
{
    *mt = new int *[row];
    for (int i = 0; i < row; i++)
        (*mt)[i] = new int[col];
}

void generateRandomArr(int **arr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            arr[i][j] = rand() % (10 - 1 + 1) + 1;
    }
}

void print(int **arr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}

int **addMatrix(int **mt1, int **mt2, int n)
{
    int **mt = new int *[n];
    for (int i = 0; i < n; i++)
        mt[i] = new int[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            mt[i][j] = mt1[i][j] + mt2[i][j];
    }
    return mt;
}

void free_mem(int **mt, int row, int col)
{
    for (int i = 0; i < row; i++)
        delete[] mt[i];
    delete[] mt;
}
