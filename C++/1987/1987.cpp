#include <iostream>
using namespace std;
int r, c;
char **rc;
bool bb[26];
int nx[4] = {0, 1, 0, -1};
int ny[4] = {1, 0, -1, 0};
int ans;
void f(int a, int b, int s)
{
    if (ans < s)
        ans = s;
    for (int i = 0; i < 4; i++)
    {
        if (a + ny[i] < r && a + ny[i] >= 0 && b + nx[i] < c && b + nx[i] >= 0)
        {
            if (!bb[rc[a + ny[i]][b + nx[i]] - 'A'])
            {
                bb[rc[a + ny[i]][b + nx[i]] - 'A'] = true;
                f(a + ny[i], b + nx[i], s + 1);
                bb[rc[a + ny[i]][b + nx[i]] - 'A'] = false;
            }
        }
    }
}
int main()
{
    ans = 1;
    fill(bb, bb + 26, false);
    cin >> r >> c;
    rc = new char *[r];
    for (int i = 0; i < r; i++)
    {
        rc[i] = new char[r];
        for (int j = 0; j < c; j++)
        {
            cin >> rc[i][j];
        }
    }
    bb[rc[0][0] - 'A'] = true;
    f(0, 0, 1);
    cout << ans;
}