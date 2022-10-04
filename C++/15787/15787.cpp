#include <iostream>
using namespace std;
int t[100001];
bool tb[1 << 21];
int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b;
        if (a == 1)
        {
            cin >> c;
            t[b] |= (1 << c);
        }
        else if (a == 2)
        {
            cin >> c;
            t[b] &= ~(1 << c);
        }
        else if (a == 3)
        {
            t[b] = t[b] << 1;
            t[b] &= ((1 << 21) - 1);
        }
        else if (a == 4)
        {
            t[b] = t[b] >> 1;
            t[b] &= ~1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!tb[t[i]])
            ans++;
        tb[t[i]] = true;
    }
    cout << ans;
}