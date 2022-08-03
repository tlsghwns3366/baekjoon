#include <iostream>
#include <algorithm>
using namespace std;
int nn[500000];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    sort(nn, nn + n);
    long long int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += abs(nn[i - 1] - i);
    }
    cout << ans;
}