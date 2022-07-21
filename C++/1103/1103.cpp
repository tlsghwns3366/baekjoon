#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int ans = 1;
bool cy = false;
char nm[50][50];
bool nmb[50][50];
int nmc[50][50];
void f(int x, int y)
{
    if (nmb[x][y])
    {
        cy = true;
        return;
    }
    nmb[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int tempx = x + (dx[i] * (nm[x][y] - '0'));
        int tempy = y + (dy[i] * (nm[x][y] - '0'));
        if (tempx < n && tempx >= 0 && tempy < m && tempy >= 0)
        {
            if (nm[tempx][tempy] != 'H')
            {
                if (nmc[x][y] + 1 > nmc[tempx][tempy])
                {
                    nmc[tempx][tempy] = nmc[x][y] + 1;
                    if (ans < nmc[tempx][tempy])
                        ans = nmc[tempx][tempy];
                    f(tempx, tempy);
                    if (cy)
                        return;
                }
            }
        }
    }
    nmb[x][y] = false;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            nm[i][j] = s[j];
            nmb[i][j] = false;
            nmc[i][j] = 1;
        }
    }
    f(0, 0);
    if (cy)
        cout << "-1";
    else
        cout << ans;
}