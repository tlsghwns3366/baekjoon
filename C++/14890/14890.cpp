#include <iostream>
using namespace std;
int main()
{
    int n, l;
    cin >> n >> l;
    int ans = 2 * n;
    int nn[n][n];
    bool k[n][n][2];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> nn[i][j];
            k[i][j][0] = false;
            k[i][j][1] = false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (nn[i][j - 1] != nn[i][j])
            {
                if (nn[i][j - 1] > nn[i][j] && nn[i][j - 1] - nn[i][j] == 1)
                {
                    int templ = 0;
                    for (int ii = j; ii < n; ii++)
                    {
                        if (nn[i][j] != nn[i][ii] || k[i][ii][0])
                            break;
                        templ++;
                    }
                    if (templ >= l)
                    {
                        for (int ii = 0; ii < l; ii++)
                        {
                            k[i][j + ii][0] = true;
                        }
                    }
                    else
                    {
                        ans--;
                        break;
                    }
                }
                else if (nn[i][j] > nn[i][j - 1] && nn[i][j] - nn[i][j - 1] == 1)
                {
                    int templ = 0;
                    for (int ii = j - 1; ii >= 0; ii--)
                    {
                        if (nn[i][j - 1] != nn[i][ii] || k[i][ii][0])
                            break;
                        templ++;
                    }
                    if (templ >= l)
                    {
                        for (int ii = 0; ii < l; ii++)
                        {
                            k[i][j - 1 - ii][0] = true;
                        }
                    }
                    else
                    {
                        ans--;
                        break;
                    }
                }
                else
                {
                    ans--;
                    break;
                }
            }
        }
        for (int j = 1; j < n; j++)
        {
            if (nn[j - 1][i] != nn[j][i])
            {
                if (nn[j - 1][i] > nn[j][i] && nn[j - 1][i] - nn[j][i] == 1)
                {
                    int templ = 0;
                    for (int ii = j; ii < n; ii++)
                    {
                        if (nn[j][i] != nn[ii][i] || k[ii][i][1])
                            break;
                        templ++;
                    }
                    if (templ >= l)
                    {
                        for (int ii = 0; ii < l; ii++)
                        {
                            k[j + ii][i][1] = true;
                        }
                    }
                    else
                    {
                        ans--;
                        break;
                    }
                }
                else if (nn[j][i] > nn[j - 1][i] && nn[j][i] - nn[j - 1][i] == 1)
                {
                    int templ = 0;
                    for (int ii = j - 1; ii >= 0; ii--)
                    {
                        if (nn[j - 1][i] != nn[ii][i] || k[ii][i][1])
                            break;
                        templ++;
                    }
                    if (templ >= l)
                    {
                        for (int ii = 0; ii < l; ii++)
                        {
                            k[j - 1 - ii][i][1] = true;
                        }
                    }
                    else
                    {
                        ans--;
                        break;
                    }
                }
                else
                {
                    ans--;
                    break;
                }
            }
        }
    }
    cout << ans;
}