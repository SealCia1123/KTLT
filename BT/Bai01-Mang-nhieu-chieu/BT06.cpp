#include <iostream>
#define MAX_ROW 10
#define MAX_COL 10
using namespace std;

int main()
{
    int row, col;
    int firstArr[MAX_ROW][MAX_COL];
    int secondArr[MAX_ROW][MAX_COL];
    cout << "Nhap so hang va so cot: ";
    cin >> row >> col;

    cout << "Nhap phan tu ma tran thu nhat: ";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cin >> firstArr[i][j];
    }
    cout << "Nhap phan tu ma tran thu hai: ";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cin >> secondArr[i][j];
    }

    cout << "Ma tran thu nhat:\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << firstArr[i][j] << "\t";
        cout << endl;
    }
    cout << "Ma tran thu hai:\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << secondArr[i][j] << "\t";
        cout << endl;
    }

    cout << "Tong hai ma tran:\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << firstArr[i][j] + secondArr[i][j] << "\t";
        cout << endl;
    }

    cout << "Tich hai ma tran:\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << firstArr[i][j] * secondArr[i][j] << "\t";
        cout << endl;
    }

    return 0;
}
