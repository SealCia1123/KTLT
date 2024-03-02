#include <iostream>

using namespace std;

int main()
{
    int h;
    cout << "Nhap kich thuoc ma tran: ";
    cin >> h;
    int **mt = new int *[h];
    for (int i = 0; i < h; i++)
        mt[i] = new int[h];

    for (int i = 0; i < h; i++)
        delete[] mt[i];
    delete[] mt;
    return 0;
}
