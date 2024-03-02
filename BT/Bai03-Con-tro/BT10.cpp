#include <iostream>
using namespace std;

void allocate_mem(int ***mt, int n);

void generateRandomArr(int **arr, int n);

void print(int **arr, int n);

int **addMatrix(int **mt1, int **mt2, int n);

int main()
{
    int n;
    cout << "Nhap vao kich thuoc ma tran: ";
    cin >> n;
    int **mt1 = new int *[n];
    for (int i = 0; i < n; i++)
        mt1[i] = new int[n];

    int **mt2 = new int *[n];
    for (int i = 0; i < n; i++)
        mt2[i] = new int[n];
    generateRandomArr(mt1, n);
    generateRandomArr(mt2, n);
    print(mt1, n);
    print(mt1, n);
    int **sumMatrix = addMatrix(mt1, mt2, n);
    print(sumMatrix, n);

    for (int i = 0; i < n; i++)
        delete[] mt1[i];
    delete[] mt1;
    for (int i = 0; i < n; i++)
        delete[] mt2[i];
    delete[] mt2;
    for (int i = 0; i < n; i++)
        delete[] sumMatrix[i];
    delete[] sumMatrix;
}

void allocate_mem(int ***mt, int n)
{
    int **res = new int *[n];
    for (int i = 0; i < n; i++)
        (*res)[i] = *new int[n];
}

void generateRandomArr(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            arr[i][j] = rand() % (10 - 1 + 1) + 1;
    }
}

void print(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
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
