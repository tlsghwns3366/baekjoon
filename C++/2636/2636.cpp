#include <iostream>
#include <queue>
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
using namespace std;
int main()
{
    int n, m;
    int ans = 0;
    int cheesecount = 0;
    cin >> n >> m;
    int nm[n][m];
    bool cheese[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> nm[i][j];
            if (nm[i][j] == 1)
            {
                cheese[i][j] = true;
                cheesecount++;
            }
            else
                cheese[i][j] = false;
        }
    }
    while (true)
    {
        ans++;
        bool air[n][m];
        fill(&air[0][0], &air[n - 1][m], false);
        air[0][0] = true;
        queue<pair<int, int>> q;
        queue<pair<int, int>> qc;
        q.push({0, 0});
        while (!q.empty())
        {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int x = a + dx[i];
                int y = b + dy[i];
                if (x < n && x >= 0 && y < m && y >= 0)
                {
                    if (nm[x][y] != 1 && !air[x][y])
                    {
                        air[x][y] = true;
                        q.push({x, y});
                    }
                    else if (cheese[x][y])
                    {
                        cheese[x][y] = false;
                        qc.push({x, y});
                    }
                }
            }
        }
        if (cheesecount - qc.size() == 0)
            break;
        else
        {
            cheesecount -= qc.size();
            while (!qc.empty())
            {
                int a = qc.front().first;
                int b = qc.front().second;
                nm[a][b] = 0;
                qc.pop();
            }
        }
    }
    cout << ans << "\n";
    cout << cheesecount;
}