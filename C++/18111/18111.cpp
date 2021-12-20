#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int n, m, b;
    int **nm;
    pair<int, int> ans;
    cin >> n >> m >> b;
    nm = new int *[n];
    ans.first = INT_MAX;
    ans.second = 0;
    for (int i = 0; i < n; i++)
    {
        nm[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> nm[i][j];
        }
    }
    for (int x = 0; x <= 256; x++)
    {
        int sum = 0;
        int tempb = b;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (nm[i][j] < x)
                {
                    tempb -= (x - nm[i][j]);
                    sum += (x - nm[i][j]);
                }
                else if (nm[i][j] > x)
                {
                    tempb += (nm[i][j] - x);
                    sum += (nm[i][j] - x) * 2;
                }
            }
        }
        if (tempb >= 0 && ans.first >= sum)
        {
            ans.first = sum;
            ans.second = x;
        }
    }
    cout << ans.first << " " << ans.second;
}