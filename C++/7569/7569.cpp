#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int n, m, h;
int d;
queue<tuple<int, int, int>> q;
void f(int ***nn, int a, int b, int c, int temp)
{
    while (!q.empty())
    {
        int size = 0;
        for (int i = 0; i < temp; i++)
        {
            a = get<0>(q.front());
            b = get<1>(q.front());
            c = get<2>(q.front());
            q.pop();
            if (nn[a][b][c] >= 1)
            {
                if (a - 1 >= 0 && nn[a - 1][b][c] == 0)
                {
                    nn[a - 1][b][c] = nn[a][b][c] + 1;
                    q.push(make_tuple(a - 1, b, c));
                    size++;
                }
                if (a + 1 < h && nn[a + 1][b][c] == 0)
                {
                    nn[a + 1][b][c] = nn[a][b][c] + 1;
                    q.push(make_tuple(a + 1, b, c));
                    size++;
                }
                if (b - 1 >= 0 && nn[a][b - 1][c] == 0)
                {
                    nn[a][b - 1][c] = nn[a][b][c] + 1;
                    q.push(make_tuple(a, b - 1, c));
                    size++;
                }
                if (b + 1 < n && nn[a][b + 1][c] == 0)
                {
                    nn[a][b + 1][c] = nn[a][b][c] + 1;
                    q.push(make_tuple(a, b + 1, c));
                    size++;
                }
                if (c - 1 >= 0 && nn[a][b][c - 1] == 0)
                {
                    nn[a][b][c - 1] = nn[a][b][c] + 1;
                    q.push(make_tuple(a, b, c - 1));
                    size++;
                }
                if (c + 1 < m && nn[a][b][c + 1] == 0)
                {
                    nn[a][b][c + 1] = nn[a][b][c] + 1;
                    q.push(make_tuple(a, b, c + 1));
                    size++;
                }
            }
        }
        temp = size;
        d++;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> h;
    int ***nn = new int **[h];
    for (int i = 0; i < h; i++)
    {
        nn[i] = new int *[n];
        for (int j = 0; j < n; j++)
        {
            nn[i][j] = new int[m];
            for (int k = 0; k < m; k++)
            {
                cin >> nn[i][j][k];
            }
        }
    }
    int size = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (nn[i][j][k] == 1)
                {
                    q.push(make_tuple(i, j, k));
                    size++;
                }
            }
        }
    }
    f(nn, get<0>(q.front()), get<1>(q.front()), get<2>(q.front()), size);

    bool temp = false;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (nn[i][j][k] == 0)
                {
                    temp = true;
                    break;
                }
            }
        }
    }
    if (temp)
        cout << -1;
    else
        cout << d - 1;
}