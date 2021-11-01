#include <iostream>
#include <queue>
#include <climits>
using namespace std;
int n;
int nx[4] = {-1, 0, 1, 0};
int ny[4] = {0, 1, 0, -1};

int f()
{
    cin >> n;
    return n;
}
int main()
{
    int a = 1;
    while (f() != 0)
    {
        int nn[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> nn[i][j];
            }
        }
        int v[n][n];
        fill(&v[0][0], &v[n - 1][n], INT_MAX);
        v[0][0] = nn[0][0];
        priority_queue<pair<int, pair<int, int>>> q;
        q.push(make_pair(-nn[0][0], make_pair(0, 0)));
        while (!q.empty())
        {
            int t = q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                if (x + nx[i] >= 0 && x + nx[i] < n && y + ny[i] >= 0 && y + ny[i] < n)
                {
                    if (v[x + nx[i]][y + ny[i]] > v[x][y] + nn[x + nx[i]][y + ny[i]])
                    {
                        v[x + nx[i]][y + ny[i]] = v[x][y] + nn[x + nx[i]][y + ny[i]];
                        q.push(make_pair(-nn[x + nx[i]][y + ny[i]], make_pair(x + nx[i], y + ny[i])));
                    }
                }
            }
        }
        cout << "Problem " << a << ": " << v[n - 1][n - 1] << endl;
        a++;
    }
}