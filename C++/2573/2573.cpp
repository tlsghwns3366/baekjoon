#include <iostream>
using namespace std;
int nx[4] = {-1, 0, 1, 0};
int ny[4] = {0, 1, 0, -1};
int **nn;
bool **bb;
int n, m;

int ans;
void f(int a, int b)
{
    bb[a][b] = false;
    for (int x = 0; x < 4; x++)
    {
        if (a + nx[x] >= 0 && a + nx[x] < n && b + ny[x] >= 0 && b + ny[x] < m)
        {
            if (bb[a + nx[x]][b + ny[x]] == true)
            {
                f(a + nx[x], b + ny[x]);
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    nn = new int *[n];
    bb = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        nn[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> nn[i][j];
        }
    }
    ans = 0;
    int temp;
    do
    {
        temp = 0;
        bb = new bool *[n];
        for (int i = 0; i < n; i++)
        {
            bb[i] = new bool[m];
            for (int j = 0; j < m; j++)
            {
                if (nn[i][j] == 0)
                    bb[i][j] = false;
                else
                    bb[i][j] = true;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (bb[i][j])
                {
                    temp++;
                    f(i, j);
                }
            }
        }

        if (temp == 0)
        {
            ans = 0;
            break;
        }
        else if (temp > 1)
        {
            break;
        }
        ans++;
        int count[n][m];
        fill(&count[0][0], &count[n - 1][m], 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (nn[i][j] != 0)
                {
                    for (int x = 0; x < 4; x++)
                    {
                        if (i + nx[x] >= 0 && i + nx[x] < n && j + ny[x] >= 0 && j + ny[x] < m)
                        {
                            if (nn[i + nx[x]][j + ny[x]] == 0)
                            {
                                count[i][j]++;
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                nn[i][j] -= count[i][j];
                if (nn[i][j] < 0)
                    nn[i][j] = 0;
            }
        }
    } while (temp < 2);
    cout << ans;
}