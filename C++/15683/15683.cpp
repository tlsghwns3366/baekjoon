#include <iostream>
#include <vector>
using namespace std;
int n, m;
int ans;
int vsize;

int **nm;
bool **bb;
int cctv[8];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct VC
{
    int x;
    int y;
    int c;
};
VC v[8];
void f(int a)
{
    if (a == vsize)
    {
        for (int i = 0; i < vsize; i++)
        {
            int x = v[i].x;
            int y = v[i].y;
            int c = v[i].c;
            if (c == 1)
            {
                while (true)
                {
                    x += dx[cctv[i]];
                    y += dy[cctv[i]];
                    if (x < 0 || x >= n || y < 0 || y >= m)
                        break;
                    if (nm[x][y] == 6)
                        break;
                    else
                        bb[x][y] = true;
                }
            }
            else if (c == 2)
            {
                for (int j = 0; j < 3; j += 2)
                {
                    x = v[i].x;
                    y = v[i].y;
                    while (true)
                    {
                        x += dx[(cctv[i] + j) % 4];
                        y += dy[(cctv[i] + j) % 4];
                        if (x < 0 || x >= n || y < 0 || y >= m)
                            break;
                        if (nm[x][y] == 6)
                            break;
                        else
                            bb[x][y] = true;
                    }
                }
            }
            else if (c == 3)
            {
                for (int j = 0; j < 2; j++)
                {
                    x = v[i].x;
                    y = v[i].y;
                    while (true)
                    {
                        x += dx[(cctv[i] + j) % 4];
                        y += dy[(cctv[i] + j) % 4];
                        if (x < 0 || x >= n || y < 0 || y >= m)
                            break;
                        if (nm[x][y] == 6)
                            break;
                        else
                            bb[x][y] = true;
                    }
                }
            }
            else if (c == 4)
            {
                for (int j = 0; j < 3; j++)
                {
                    x = v[i].x;
                    y = v[i].y;
                    while (true)
                    {
                        x += dx[(cctv[i] + j) % 4];
                        y += dy[(cctv[i] + j) % 4];
                        if (x < 0 || x >= n || y < 0 || y >= m)
                            break;
                        if (nm[x][y] == 6)
                            break;
                        else
                            bb[x][y] = true;
                    }
                }
            }
            else
            {
                for (int j = 0; j < 4; j++)
                {
                    x = v[i].x;
                    y = v[i].y;
                    while (true)
                    {
                        x += dx[(cctv[i] + j) % 4];
                        y += dy[(cctv[i] + j) % 4];
                        if (x < 0 || x >= n || y < 0 || y >= m)
                            break;
                        if (nm[x][y] == 6)
                            break;
                        else
                            bb[x][y] = true;
                    }
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!bb[i][j])
                    sum++;
                if (nm[i][j] == 0)
                    bb[i][j] = false;
            }
        }
        if (ans > sum)
            ans = sum;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        cctv[a] = i;
        if (v[a].c == 5)
            cctv[a] = 0;
        f(a + 1);
    }
}

int main()
{
    cin >> n >> m;
    ans = n * m;
    nm = new int *[n];
    bb = new bool *[n];
    vsize = 0;
    for (int i = 0; i < n; i++)
    {
        nm[i] = new int[n];
        bb[i] = new bool[n];
        for (int j = 0; j < m; j++)
        {
            cin >> nm[i][j];
            bb[i][j] = false;
            if (nm[i][j] != 0 && nm[i][j] != 6)
            {
                v[vsize].x = i;
                v[vsize].y = j;
                v[vsize].c = nm[i][j];
                vsize++;
                bb[i][j] = true;
            }
            if (nm[i][j] == 6)
                bb[i][j] = true;
        }
    }
    f(0);
    cout << ans;
}