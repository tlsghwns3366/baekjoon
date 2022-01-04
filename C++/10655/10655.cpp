#include <iostream>
#include <algorithm>
using namespace std;
struct XY
{
    int x;
    int y;
};
int main()
{
    int n;
    cin >> n;
    XY nn[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i].x >> nn[i].y;
    }
    int sum[n];
    fill(sum, sum + n, 0);
    for (int i = 0; i < n - 1; i++)
    {
        sum[i + 1] = sum[i] + abs(nn[i].x - nn[i + 1].x) + abs(nn[i].y - nn[i + 1].y);
    }
    int ans = sum[n - 1];
    for (int i = 1; i < n - 1; i++)
    {
        if (ans > sum[i - 1] + abs(nn[i - 1].x - nn[i + 1].x) + abs(nn[i - 1].y - nn[i + 1].y) + (sum[n - 1] - sum[i + 1]))
        {
            ans = sum[i - 1] + abs(nn[i - 1].x - nn[i + 1].x) + abs(nn[i - 1].y - nn[i + 1].y) + (sum[n - 1] - sum[i + 1]);
        }
    }
    cout << ans;
}