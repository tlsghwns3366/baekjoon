#include <iostream>
#include <queue>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

char lrc[31][31][31];
int lrccount[31][31][31];
bool lrcb[31][31][31];
int main()
{
    int L, R, C;
    while (cin >> L >> R >> C)
    {
        if (L == 0 && R == 0 && C == 0)
            break;
        queue<pair<pair<int, int>, int>> q;
        for (int i = L; i > 0; i--)
        {
            for (int j = 1; j <= R; j++)
            {
                for (int k = 1; k <= C; k++)
                {
                    cin >> lrc[i][j][k];
                    lrccount[i][j][k] = 987654321;
                    lrcb[i][j][k] = false;
                    if (lrc[i][j][k] == 'S')
                    {
                        q.push({{i, j}, k});
                        lrccount[i][j][k] = 0;
                        lrcb[i][j][k] = true;
                    }
                }
            }
        }
        while (!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int z = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                if (y + dx[i] > 0 && y + dx[i] <= R && z + dy[i] > 0 && z + dy[i] <= C)
                {
                    if (lrc[x][y + dx[i]][z + dy[i]] != '#' && !lrcb[x][y + dx[i]][z + dy[i]] && lrccount[x][y + dx[i]][z + dy[i]] > lrccount[x][y][z] + 1)
                    {
                        lrcb[x][y + dx[i]][z + dy[i]] = true;
                        lrccount[x][y + dx[i]][z + dy[i]] = lrccount[x][y][z] + 1;
                        q.push({{x, y + dx[i]}, z + dy[i]});
                    }
                }
            }
            if (x + 1 <= L)
            {
                if (lrc[x + 1][y][z] != '#' && !lrcb[x + 1][y][z] && lrccount[x + 1][y][z] > lrccount[x][y][z] + 1)
                {
                    lrcb[x + 1][y][z] = true;
                    lrccount[x + 1][y][z] = lrccount[x][y][z] + 1;
                    q.push({{x + 1, y}, z});
                }
            }
            if (x - 1 > 0)
            {
                if (lrc[x - 1][y][z] != '#' && !lrcb[x - 1][y][z] && lrccount[x - 1][y][z] > lrccount[x][y][z] + 1)
                {
                    lrcb[x - 1][y][z] = true;
                    lrccount[x - 1][y][z] = lrccount[x][y][z] + 1;
                    q.push({{x - 1, y}, z});
                }
            }
        }

        for (int j = 1; j <= R; j++)
        {
            for (int k = 1; k <= C; k++)
            {
                if (lrc[1][j][k] == 'E')
                {
                    if (lrccount[1][j][k] == 987654321)
                        cout << "Trapped!\n";
                    else
                        cout << "Escaped in " << lrccount[1][j][k] << " minute(s).\n";
                }
            }
        }
    }
}