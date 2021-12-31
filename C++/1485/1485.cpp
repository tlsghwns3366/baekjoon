#include <iostream>
#include <algorithm>
using namespace std;
struct XY
{
    int x;
    int y;
};
int f(XY a, XY b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
bool cmp(XY a, XY b)
{
    if (a.x == b.x)
        return a.y < b.y;
    else
        return a.x < b.x;
}
int main()
{
    int t;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        XY xy[4];
        int ans = 0;
        for (int i = 0; i < 4; i++)
        {
            cin >> xy[i].x >> xy[i].y;
        }
        sort(xy, xy + 4, cmp);
        if (f(xy[0], xy[1]) == f(xy[0], xy[2]) && f(xy[3], xy[2]) == f(xy[3], xy[1]) && f(xy[0], xy[3]) == f(xy[1], xy[2]))
        {
            ans = 1;
        }

        cout << ans << "\n";
    }
}