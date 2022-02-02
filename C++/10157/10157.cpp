#include <iostream>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main()
{
    int x, y;
    cin >> y >> x;
    int k;
    cin >> k;
    int xy[x + 1][y + 1];
    fill(&xy[0][0], &xy[x][y], 0);
    int tx = 0;
    int ty = 0;
    int i = 2;
    int z = 0;
    xy[0][0] = 1;
    int ans = 0;
    int ansx = 0;
    int ansy = 0;
    while (i <= x * y)
    {
        if (tx + dx[z] < x && tx + dx[z] >= 0 && ty + dy[z] < y && ty + dy[z] >= 0 && xy[tx + dx[z]][ty + dy[z]] == 0)
        {
            tx += dx[z];
            ty += dy[z];
            xy[tx][ty] = i;

            if (i == k)
            {
                ans = i;
                ansx = tx;
                ansy = ty;
            }
            i++;
        }
        else
        {
            z++;
            if (z > 4)
                z = 0;
        }
    }
    if (k == 1)
    {
        ans = 1;
        ansx = 0;
        ansy = 0;
    }
    if (ans == 0)
        cout << 0;
    else
        cout << ansy + 1 << " " << ansx + 1;
}