#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int a1 = 1;
    int a2 = 2;
    int a3 = 0;
    for (int i = 2; i < n; i++)
    {
        a3 = (a1 + a2) % 15746;
        a1 = a2;
        a2 = a3;
    }
    if (n == 1)
        cout << 1;
    else if (n == 2)
        cout << 2;
    else
        cout << a3;
}