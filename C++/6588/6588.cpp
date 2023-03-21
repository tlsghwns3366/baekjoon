#include <iostream>
using namespace std;
bool dp[1000000];
bool f(int a)
{
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
            return dp[a] = false;
    }
    return dp[a] = true;
}
int main()
{
    cin.tie(NULL);
    for (int i = 3; i <= 1000000; i += 2)
    {
        f(i);
    }
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        for (int i = 3; i <= 1000000; i += 2)
        {
            if (dp[i] && dp[n - i])
            {
                cout << n << " = " << i << " + " << n - i << "\n";
                break;
            }
        }
    }
}