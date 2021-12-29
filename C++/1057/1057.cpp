#include <iostream>
using namespace std;
int main()
{
    int n, k, l;
    cin >> n >> k >> l;
    int ans = 0;
    while (n != 0)
    {
        n = n / 2;
        if (k % 2 == 1)
            k = k / 2 + 1;
        else
            k = k / 2;
        if (l % 2 == 1)
            l = l / 2 + 1;
        else
            l = l / 2;

        ans++;
        if (l == k)
        {
            cout << ans;
            break;
        }
    }
}