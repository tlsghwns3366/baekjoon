#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int nn[n];
    int dpp[n];
    int dpm[n];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
        dpp[i] = 1;
        dpm[i] = 1;
        if (0 < i)
        {
            if (nn[i - 1] <= nn[i])
                dpp[i] = dpp[i - 1] + 1;
            if (nn[i - 1] >= nn[i])
                dpm[i] = dpm[i - 1] + 1;
        }
        ans = ans < dpp[i] ? dpp[i] : ans;
        ans = ans < dpm[i] ? dpm[i] : ans;
    }
    cout << ans;
}