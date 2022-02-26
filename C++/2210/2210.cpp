#include <iostream>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int nn[5][5];
bool bb[1000000];
int ans = 0;
void f(int a, int b, int s, int c)
{
    if (c == 5)
    {
        if (!bb[s])
        {
            bb[s] = true;
            ans++;
        }
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (a + dx[i] >= 0 && b + dy[i] >= 0 && a + dx[i] < 5 && b + dy[i] < 5)
        {
            f(a + dx[i], b + dy[i], s * 10 + nn[a + dx[i]][b + dy[i]], c + 1);
        }
    }
}
int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> nn[i][j];
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            f(i, j, nn[i][j], 0);
        }
    }
    cout << ans;
}