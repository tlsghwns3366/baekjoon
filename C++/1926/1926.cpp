#include <iostream>
#include <algorithm>
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int n, m;
int **nm;
int f(int a, int b)
{
    nm[a][b] = 0;
    int temp = 1;
    for (int i = 0; i < 4; i++)
    {
        if (a + dx[i] < n && b + dy[i] < m && a + dx[i] >= 0 && b + dy[i] >= 0)
        {
            if (nm[a + dx[i]][b + dy[i]] == 1)
            {
                temp += f(a + dx[i], b + dy[i]);
            }
        }
    }
    return temp;
}

int main()
{
    cin >> n >> m;
    nm = new int *[n];
    for (int i = 0; i < n; i++)
    {
        nm[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> nm[i][j];
        }
    }
    int anscount = 0;
    int anssize = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (nm[i][j] == 1)
            {
                anscount++;
                anssize = max(f(i, j), anssize);
            }
        }
    }
    cout << anscount << "\n";
    cout << anssize;
}