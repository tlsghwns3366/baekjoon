#include <iostream>
#include <vector>
using namespace std;
int n, m, h;
int nn[10][10];
int ans = 0;
int homex = 0;
int homey = 0;
vector<pair<int, int>> v;
bool mintb[10];
void f(int x, int y, int hp, int mint)
{
    if (ans < mint)
    {
        if (hp >= abs(homex - x) + abs(homey - y))
            ans = mint;
    }
    if (hp <= 0)
        return;
    for (int i = 0; i < v.size(); i++)
    {
        int dx = v[i].first;
        int dy = v[i].second;
        if (abs(dx - x) + abs(dy - y) <= hp && !mintb[i])
        {
            mintb[i] = true;
            f(dx, dy, hp - (abs(dx - x) + abs(dy - y)) + h, mint + 1);
            mintb[i] = false;
        }
    }
}
int main()
{
    cin >> n >> m >> h;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> nn[i][j];
            if (nn[i][j] == 1)
            {
                homex = i;
                homey = j;
            }
            if (nn[i][j] == 2)
            {
                v.push_back({i, j});
            }
        }
    }
    f(homex, homey, m, 0);
    cout << ans;
}