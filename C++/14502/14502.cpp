#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int **nn;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int **> v;
void f(int a, int b, int c, int **tnn)
{
    if (c == 3)
    {
        int **tnn2 = new int *[n];
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            tnn2[i] = new int[m];
            for (int j = 0; j < m; j++)
            {
                tnn2[i][j] = tnn[i][j];
                if (tnn2[i][j] == 2)
                    q.push({i, j});
            }
        }

        while (!q.empty())
        {
            int ta = q.front().first;
            int tb = q.front().second;
            q.pop();
            for (int x = 0; x < 4; x++)
            {
                if (ta + dx[x] < n && tb + dy[x] < m && ta + dx[x] >= 0 && tb + dy[x] >= 0)
                {
                    if (tnn2[ta + dx[x]][tb + dy[x]] == 0)
                    {
                        tnn2[ta + dx[x]][tb + dy[x]] = 2;
                        q.push({ta + dx[x], tb + dy[x]});
                    }
                }
            }
        }
        v.push_back(tnn2);
        return;
    }
    for (int i = a; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (tnn[i][j] == 0)
            {
                if (i == a && j < b)
                    continue;
                tnn[i][j] = 1;
                f(i, j, c + 1, tnn);
                tnn[i][j] = 0;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    nn = new int *[n];
    for (int i = 0; i < n; i++)
    {
        nn[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> nn[i][j];
        }
    }
    int **tnn = new int *[n];
    for (int ii = 0; ii < n; ii++)
    {
        tnn[ii] = new int[m];
        for (int jj = 0; jj < m; jj++)
        {
            tnn[ii][jj] = nn[ii][jj];
        }
    }
    f(0, 0, 0, tnn);
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int count = 0;
        for (int ii = 0; ii < n; ii++)
        {
            for (int jj = 0; jj < m; jj++)
            {
                if (v[i][ii][jj] == 0)
                    count++;
            }
        }
        if (ans < count)
            ans = count;
    }
    cout << ans;
}