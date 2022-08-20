#include <iostream>
using namespace std;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
double b[4];
bool xy[29][29];
int n;
double f(int c, int x, int y)
{
    if (c == n)
        return 1;
    double ans = 0;
    for (int i = 0; i < 4; i++)
    {
        if (!xy[x + dx[i]][y + dy[i]])
        {
            xy[x + dx[i]][y + dy[i]] = true;
            ans += f(c + 1, x + dx[i], y + dy[i]) * ((double)b[i] / (double)100);
            xy[x + dx[i]][y + dy[i]] = false;
        }
    }
    return ans;
}
int main()
{
    cin >> n >> b[0] >> b[1] >> b[2] >> b[3];
    cout.precision(11);
    cout.fixed;
    xy[14][14] = true;
    cout << f(0, 14, 14);
}