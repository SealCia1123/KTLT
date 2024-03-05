#include <iostream>
using namespace std;

int fib(int n);

int *listFibonacci(int n);

int main()
{
    int n;
    cin >> n;
    int *arr = listFibonacci(n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\t";
    cout << endl;
    return 0;
}

int fib(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

int *listFibonacci(int n)
{
    int *list = new int[n];
    for (int i = 0; i <= n; i++)
        list[i] = fib(i);
    return list;
}
