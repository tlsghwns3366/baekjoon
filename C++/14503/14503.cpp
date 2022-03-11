#include <iostream>
using namespace std;
int n, m;
int **nn;
bool **bb;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int ans;
class Robot
{
public:
    int x;
    int y;
    int c;
    int spincount;
    void cleen()
    {
        bb[x][y] = true;
        ans++;
        spincount = 0;
    }
    void spinmove()
    {
        if (!bb[x + dx[(c + 1) % 4]][y + dy[(c + 1) % 4]] && nn[x + dx[(c + 1) % 4]][y + dy[(c + 1) % 4]] != 1)
        {
            c = (c + 1) % 4;
            x = x + dx[c];
            y = y + dy[c];
            cleen();
        }
        else
        {
            c = (c + 1) % 4;
            spincount++;
        }
    }
    bool back()
    {
        if (nn[x - dx[c]][y - dy[c]] == 1)
            return false;
        x = x - dx[c];
        y = y - dy[c];
        return true;
    }
};

int main()
{
    cin >> n >> m;
    Robot r;
    int tempc;
    cin >> r.x >> r.y >> tempc;
    r.c = 3 - tempc;
    ans = 0;

    nn = new int *[n];
    bb = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        nn[i] = new int[m];
        bb[i] = new bool[m];
        for (int j = 0; j < m; j++)
        {
            cin >> nn[i][j];
            if (nn[i][j] == 1)
                bb[i][j] = true;
            else
                bb[i][j] = false;
        }
    }
    r.cleen();
    while (true)
    {
        if (r.spincount == 4)
        {
            r.spincount = 0;
            if (!r.back())
                break;
        }
        r.spinmove();
    }

    cout << ans;
}