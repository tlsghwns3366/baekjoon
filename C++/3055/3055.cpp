#include <iostream>
#include <queue>
#include <climits>
using namespace std;
int nx[4] = {-1, 0, 1, 0};
int ny[4] = {0, 1, 0, -1};

int r, c;
int **rc;
int **bb;
int **gg;
void water()
{
    queue<pair<int, int>> q;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (rc[i][j] == '*')
            {
                gg[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    while (!q.empty())
    {
        int tp1 = q.front().first;
        int tp2 = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (tp1 + nx[i] < r && tp1 + nx[i] >= 0 && tp2 + ny[i] < c && tp2 + ny[i] >= 0)
            {
                if (rc[tp1 + nx[i]][tp2 + ny[i]] != 'X' && rc[tp1 + nx[i]][tp2 + ny[i]] != 'S' && rc[tp1 + nx[i]][tp2 + ny[i]] != 'D')
                {
                    if (gg[tp1 + nx[i]][tp2 + ny[i]] > gg[tp1][tp2] + 1)
                    {
                        gg[tp1 + nx[i]][tp2 + ny[i]] = gg[tp1][tp2] + 1;
                        q.push({tp1 + nx[i], tp2 + ny[i]});
                    }
                }
            }
        }
    }
}
void go(int a, int b)
{
    queue<pair<int, int>> q;
    bb[a][b] = 0;
    q.push({a, b});
    while (!q.empty())
    {
        int tp1 = q.front().first;
        int tp2 = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (tp1 + nx[i] < r && tp1 + nx[i] >= 0 && tp2 + ny[i] < c && tp2 + ny[i] >= 0)
            {
                if (rc[tp1 + nx[i]][tp2 + ny[i]] != 'X' && rc[tp1 + nx[i]][tp2 + ny[i]] != '*' && gg[tp1 + nx[i]][tp2 + ny[i]] > bb[tp1][tp2] + 1 && bb[tp1 + nx[i]][tp2 + ny[i]] > bb[tp1][tp2] + 1)
                {
                    bb[tp1 + nx[i]][tp2 + ny[i]] = bb[tp1][tp2] + 1;
                    q.push({tp1 + nx[i], tp2 + ny[i]});
                }
            }
        }
    }
}
int main()
{
    cin >> r >> c;
    rc = new int *[r];
    bb = new int *[r];
    gg = new int *[r];
    for (int i = 0; i < r; i++)
    {
        rc[i] = new int[c];
        bb[i] = new int[c];
        gg[i] = new int[c];
        string s;
        cin >> s;
        for (int j = 0; j < c; j++)
        {
            rc[i][j] = s[j];
            bb[i][j] = INT_MAX;
            gg[i][j] = INT_MAX;
        }
    }
    water();
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (rc[i][j] == 'S')
                go(i, j);
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (rc[i][j] == 'D')
            {
                if (bb[i][j] == INT_MAX)
                    cout << "KAKTUS";
                else
                    cout << bb[i][j];
            }
        }
    }
}