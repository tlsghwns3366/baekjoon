#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int main()
{
    int r, c;
    cin >> r >> c;
    char rc[r][c];
    bool brc[r][c];
    for (int i = 0; i < r; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++)
        {
            rc[i][j] = s[j];
            brc[i][j] = false;
        }
    }
    int anso = 0;
    int ansv = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (rc[i][j] == 'v' || rc[i][j] == 'o')
            {
                if (brc[i][j])
                    continue;
                queue<pair<int, int>> q;
                q.push({i, j});
                brc[i][j] = true;
                int countv = 0;
                int counto = 0;
                if (rc[i][j] == 'v')
                    countv++;
                if (rc[i][j] == 'o')
                    counto++;
                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        if (x + dx[k] < 0 || x + dx[k] >= r || y + dy[k] < 0 || y + dy[k] >= c)
                            continue;
                        if (rc[x + dx[k]][y + dy[k]] != '#' && !brc[x + dx[k]][y + dy[k]])
                        {
                            brc[x + dx[k]][y + dy[k]] = true;
                            if (rc[x + dx[k]][y + dy[k]] == 'v')
                                countv++;
                            if (rc[x + dx[k]][y + dy[k]] == 'o')
                                counto++;
                            q.push({x + dx[k], y + dy[k]});
                        }
                    }
                }
                if (counto > countv)
                    anso += counto;
                else
                    ansv += countv;
            }
        }
    }
    cout << anso << " " << ansv;
}