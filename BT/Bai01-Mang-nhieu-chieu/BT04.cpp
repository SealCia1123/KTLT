#include <iostream>
#define MAX_ROW 5
#define MAX_COL 6
using namespace std;

int main()
{
    int row, col;
    int arr[MAX_ROW][MAX_COL];
    do
    {
        cout << "Nhap vao so hang va so cot: ";
        cin >> row >> col;
        if (row > MAX_ROW || col > MAX_COL)
            cout << "Chi nhap so hang nho hon 5 va so cot nho hon 6\n";
    } while (row > MAX_ROW || col > MAX_COL);
    return 0;
}
