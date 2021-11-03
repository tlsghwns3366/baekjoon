#include <iostream>
using namespace std;
char **rc;
bool **bb;
int nx[3] = {-1, 0, 1};
int r, c;
int ans;
bool f(int a, int b)
{
    bb[a][b] = false;
    if (b == c - 1)
    {
        ans++;
        return false;
    }
    for (int i = 0; i < 3; i++)
    {
        if (a + nx[i] >= 0 && a + nx[i] < r && b + 1 < c)
        {
            if (rc[a + nx[i]][b + 1] != 'x' && bb[a + nx[i]][b + 1])
            {
                if (!f(a + nx[i], b + 1))
                {
                    bb[a][b] = false;
                    return false;
                }
            }
        }
    }
    return true;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;
    rc = new char *[r];
    bb = new bool *[r];
    for (int i = 0; i < r; i++)
    {
        rc[i] = new char[r];
        bb[i] = new bool[c];
        string s;
        cin >> s;
        for (int j = 0; j < c; j++)
        {
            rc[i][j] = s[j];
            bb[i][j] = true;
        }
    }
    ans = 0;
    for (int i = 0; i < r; i++)
    {
        f(i, 0);
    }
    cout << ans;
}