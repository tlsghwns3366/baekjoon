#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= i;
        ans %= 10000000;
        while (ans % 10 == 0)
        {
            ans /= 10;
        }
    }
    cout << ans % 10;
}