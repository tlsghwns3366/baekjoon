#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int a[11];
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    a[3] = 4;
    for (int i = 4; i < 11; i++)
    {
        a[i] = a[i - 1] + a[i - 2] + a[i - 3];
    }
    for (int k = 0; k < t; k++)
    {
        int n;
        cin >> n;
        cout << a[n] << endl;
    }
}