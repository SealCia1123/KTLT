#include <iostream>
using namespace std;

int main()
{
    srand(time(0));
    int arr[30];
    for (int i = 0; i < 30; i++)
        arr[i] = rand() % (10 - 1 + 1) + 1;

    int *p = arr;
    for (int i = 0; i < 30; i++)
        cout << *(p + i) << " ";
    cout << endl;

    for (int i = 0; i < 30; i++)
        cout << p[i] << " ";
    cout << endl;
    return 0;
}
