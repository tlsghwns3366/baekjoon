#include <iostream>
using namespace std;
int w, h;
int nx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int ny[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
void f(int **wh, int a, int b)
{
    for (int i = 0; i < 8; i++)
    {
        if (a + ny[i] >= 0 && a + ny[i] < h && b + nx[i] >= 0 && b + nx[i] < w)
        {
            if (wh[a + ny[i]][b + nx[i]] == 1)
            {
                wh[a + ny[i]][b + nx[i]] = 0;
                f(wh, a + ny[i], b + nx[i]);
            }
        }
    }
}
bool in()
{
    cin >> w >> h;
    if (w == 0 && h == 0)
        return false;
    else
        return true;
}
int main()
{
    while (in())
    {
        int **hw = new int *[h];
        for (int i = 0; i < h; i++)
        {
            hw[i] = new int[w];
            for (int j = 0; j < w; j++)
            {
                cin >> hw[i][j];
            }
        }
        int count = 0;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (hw[i][j] == 1)
                {
                    hw[i][j] = 0;
                    f(hw, i, j);
                    count++;
                }
            }
        }
        cout << count << "\n";
    }
}