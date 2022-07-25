#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, x;
    cin >> n;
    int nn[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    cin >> x;
    sort(nn, nn + n);
    int p1 = 0;
    int p2 = n-1;
    int ans = 0;
    while (p1 < p2)
    {
        if (x == nn[p1] + nn[p2])
        {
            ans++;
            p1++;
            p2--;
        }
        else if (x > nn[p1] + nn[p2])
            p1++;
        else
            p2--;
    }
    cout << ans;
}