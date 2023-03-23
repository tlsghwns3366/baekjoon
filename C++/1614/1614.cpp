#include <iostream>
using namespace std;
int main()
{
    long long n, m;
    long long ans = 0;
    cin >> n >> m;
    if (n == 1)
    {
        ans = m * 8;
    }
    else if (n == 2)
    {
        if (m % 2 == 0)
            ans += (m / 2) * 8 + 1;
        else
            ans += (m / 2) * 8 + 7;
    }
    else if (n == 3)
    {
        if (m % 2 == 0)
            ans += (m / 2) * 8 + 2;
        else
            ans += (m / 2) * 8 + 6;
    }
    else if (n == 4)
    {
        if (m % 2 == 0)
            ans += (m / 2) * 8 + 3;
        else
            ans += (m / 2) * 8 + 5;
    }
    else if (n == 5)
    {
        ans += m * 8 + 4;
    }
    cout << ans;
}