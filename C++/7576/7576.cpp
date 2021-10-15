#include <iostream>
#include <queue>
using namespace std;
int n, m;
int c;
queue<pair<int, int>> q;
void f(int **nn, int a, int b, int temp)
{
    while (!q.empty())
    {
        int size = 0;
        for (int i = 0; i < temp; i++)
        {
            a = q.front().first;
            b = q.front().second;
            q.pop();
            if (nn[a][b] >= 1)
            {
                if (a - 1 >= 0 && nn[a - 1][b] == 0)
                {
                    nn[a - 1][b] = nn[a][b] + 1;
                    q.push(make_pair(a - 1, b));
                    size++;
                }
                if (a + 1 < n && nn[a + 1][b] == 0)
                {
                    nn[a + 1][b] = nn[a][b] + 1;
                    q.push(make_pair(a + 1, b));
                    size++;
                }
                if (b - 1 >= 0 && nn[a][b - 1] == 0)
                {
                    nn[a][b - 1] = nn[a][b] + 1;
                    q.push(make_pair(a, b - 1));
                    size++;
                }
                if (b + 1 < m && nn[a][b + 1] == 0)
                {
                    nn[a][b + 1] = nn[a][b] + 1;
                    q.push(make_pair(a, b + 1));
                    size++;
                }
            }
        }
        temp = size;
        c++;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    int **nn = new int *[n];
    for (int i = 0; i < n; i++)
    {
        nn[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> nn[i][j];
        }
    }
    int size = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (nn[i][j] == 1)
            {
                q.push(make_pair(i, j));
                size++;
            }
        }
    }
    f(nn, q.front().first, q.front().second, size);
    bool temp = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (nn[i][j] == 0)
            {
                temp = true;
                break;
            }
        }
    }
    if (temp)
        cout << -1;
    else
        cout << c - 1;
}