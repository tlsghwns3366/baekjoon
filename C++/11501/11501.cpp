#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tk = 0; tk < t; tk++)
    {
        int n;
        cin >> n;
        int nn[n];
        long long ans = 0;
        int max = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> nn[i];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (max < nn[i])
                max = nn[i];
            ans += max - nn[i];
        }
        cout << ans << "\n";
    }
}