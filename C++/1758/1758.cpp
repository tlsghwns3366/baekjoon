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
    long long ncount[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ncount[i];
    }
    sort(&ncount[0], &ncount[n], cmp);
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ncount[i - 1] - (i - 1) < 0)
            break;
        ans += ncount[i - 1] - (i - 1);
    }
    cout << ans;
}