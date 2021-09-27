#include <iostream>
using namespace std;
int main()
{
    long double x, y;
    cin >> x >> y;
    long long int z = (y / x) * 100;
    long long int a = x;
    long long int b = 0;
    while (a >= b)
    {
        long long int mid = (a + b) / 2;
        long long int temp = ((y + mid) / (x + mid)) * 100;
        if (temp > z)
            a = mid - 1;
        else
            b = mid + 1;
    }
    if (z < 99)
        cout << b;
    else
        cout << -1;
}