#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int nn[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    int a = 0;
    int b = 10000;
    int ans = 10000;
    while (a <= b)
    {
        int c = (a + b) / 2;
        int temp = 1;
        int ma = nn[0];
        int mi = nn[0];
        for (int i = 0; i < n; i++)
        {
            if (ma < nn[i])
                ma = nn[i];
            if (mi > nn[i])
                mi = nn[i];
            if (ma - mi > c)
            {
                temp++;
                ma = mi = nn[i];
            }
        }
        if (m >= temp)
        {
            b = c - 1;
            ans = ans > c ? c : ans;
        }
        else
            a = c + 1;
    }
    cout << ans;
}