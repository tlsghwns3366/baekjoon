#include <iostream>
using namespace std;

int a, b, c;
bool bb[201][201][201];
bool ans[201];
int tmin(int x, int y)
{
    if (x < y)
        return x;
    else
        return y;
}
void f(int x, int y, int z)
{
    int tx = tmin(a, x + z);
    int ty = y;
    int tz = z + x - tx;
    if (!bb[tx][ty][tz])
    {
        bb[tx][ty][tz] = true;
        if (tx == 0)
            ans[tz] = true;
        f(tx, ty, tz);
    }
    tx = x;
    ty = tmin(b, y + z);
    tz = z + y - ty;
    if (!bb[tx][ty][tz])
    {
        bb[tx][ty][tz] = true;
        if (tx == 0)
            ans[tz] = true;
        f(tx, ty, tz);
    }
    tx = tmin(a, y + x);
    ty = y + x - tx;
    tz = z;
    if (!bb[tx][ty][tz])
    {
        bb[tx][ty][tz] = true;
        if (tx == 0)
            ans[tz] = true;
        f(tx, ty, tz);
    }
    tz = tmin(c, z + y);
    tx = x;
    ty = z + y - tz;
    if (!bb[tx][ty][tz])
    {
        bb[tx][ty][tz] = true;
        if (tx == 0)
            ans[tz] = true;
        f(tx, ty, tz);
    }
    ty = min(b, y + x);
    tx = y + x - ty;
    tz = z;
    if (!bb[tx][ty][tz])
    {
        bb[tx][ty][tz] = true;
        if (tx == 0)
            ans[tz] = true;
        f(tx, ty, tz);
    }
    tz = min(c, z + x);
    tx = z + x - tz;
    ty = y;
    if (!bb[tx][ty][tz])
    {
        bb[tx][ty][tz] = true;
        if (tx == 0)
            ans[tz] = true;
        f(tx, ty, tz);
    }
}
int main()
{
    cin >> a >> b >> c;
    ans[c] = true;
    f(0, 0, c);
    for (int i = 0; i <= c; i++)
    {
        if (ans[i])
            cout << i << " ";
    }
}