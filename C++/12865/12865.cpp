#include <iostream>
#include <algorithm>

using namespace std;

class WV
{
public:
    int w;
    int v;
    WV() { w = 0, v = 0; };
};

int max(int a, int b)
{
    if (a < b)
        return b;
    else
        return a;
}
int cmp(WV a, WV b)
{
    if (a.w == b.w)
    {
        return a.v < b.v;
    }
    else
    {
        return a.w < b.w;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    WV *wv = new WV[n+1];
    int **dp = new int*[n+1];

    for (int i = 1; i <= n; i++)
    {
        cin >> wv[i].w >> wv[i].v;
    }
    sort(wv + 1, wv + n + 1, cmp);

    for(int i =0;i<=n;i++)
    {
        dp[i] = new int[k+1]{0};
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (wv[i].w <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wv[i].w] + wv[i].v);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << dp[n][k];
    delete wv, dp;
}