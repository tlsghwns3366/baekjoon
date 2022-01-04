#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct Robot
{
    int num;
    int x;
    int y;
    int v;
    double s;
};
bool cmp(Robot a, Robot b)
{
    if (a.s == b.s)
        return a.num < b.num;
    else
        return a.s < b.s;
}
int main()
{
    int n;
    cin >> n;
    Robot r[n];
    for (int i = 0; i < n; i++)
    {
        int x, y, v;
        r[i].num = i + 1;
        cin >> r[i].x >> r[i].y >> r[i].v;
        r[i].s = sqrt((0 - r[i].x) * (0 - r[i].x) + (0 - r[i].y) * (0 - r[i].y)) / r[i].v;
    }
    sort(r, r + n, cmp);
    for (int i = 0; i < n; i++)
    {
        cout << r[i].num << "\n";
    }
}