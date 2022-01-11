#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        int n, m;
        cin >> n >> m;
        int nn[n];
        int mm[m];
        for (int i = 0; i < n; i++)
        {
            cin >> nn[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> mm[i];
        }
        sort(nn, nn + n);
        sort(mm, mm + m);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int a = 0;
            int b = m - 1;
            while (a <= b)
            {
                int c = (a + b) / 2;
                if (nn[i] > mm[c])
                    a = c + 1;
                else
                    b = c - 1;
            }
            ans += a;
        }
        cout << ans << "\n";
    }
}