#include <iostream>
using namespace std;
bool sosu[1000001];
bool f(int a)
{
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}
int main()
{
    cin.tie(NULL);
    int t;
    cin >> t;
    sosu[1] = true;
    sosu[2] = true;
    for (int i = 3; i <= 1000000; i += 2)
    {
        sosu[i] = f(i);
    }
    for (int q = 0; q < t; q++)
    {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 2; i < n; i++)
        {
            if (n - i < 0)
                break;
            if (sosu[i] && sosu[n - i])
            {
                ans++;
                if (i == n - i)
                    ans++;
            }
        }
        cout << ans / 2 << "\n";
    }
}