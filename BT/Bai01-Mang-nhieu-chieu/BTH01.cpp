#include <iostream>
using namespace std;

int main()
{
    int arr[3][4];

    arr[0][0] = 8;
    arr[0][1] = 4;
    arr[0][2] = -1;
    arr[0][3] = 5;
    arr[1][0] = 2;
    arr[1][1] = 2;
    arr[1][2] = 6;
    arr[1][3] = 9;
    arr[2][0] = 11;
    arr[2][1] = 2;
    arr[2][2] = 5;
    arr[2][3] = 4;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }
    return 0;
}
