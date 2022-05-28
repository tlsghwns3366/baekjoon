#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int n;
    cin >> n;
    int da;
    cin >> da;
    int nn[49];
    fill(nn,nn+49,0);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> nn[i];
    }

    sort(nn, nn + n - 1, cmp);
    int ans = 0;
    while (nn[0] >= da)
    {
        da++;
        ans++;
        nn[0]--;
        sort(nn, nn + n - 1, cmp);
    }
    cout << ans;
}