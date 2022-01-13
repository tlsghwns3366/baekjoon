#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int nm[n][m];
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            nm[i][j] = s[j] - '0';
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp = nm[i][j];
            for (int k = 0; k < 50; k++)
            {
                if (i + k < n && j + k < m)
                {
                    if (temp == nm[i + k][j] && temp == nm[i][j + k] && temp == nm[i + k][j + k])
                    {
                        if (ans < (k + 1) * (k + 1))
                            ans = (k + 1) * (k + 1);
                    }
                }
                else
                    break;
            }
        }
    }
    cout << ans;
}