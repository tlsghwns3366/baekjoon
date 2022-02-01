#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int nn[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> nn[i];
    }
    int ans = 0;
    for (int i = n; i > 1; i--)
    {
        if (nn[i] <= nn[i - 1])
        {
            ans += nn[i - 1] - (nn[i] - 1);
            nn[i - 1] = nn[i] - 1;
        }
    }
    cout << ans;
}