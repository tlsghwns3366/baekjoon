#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    int nn[1001];
    for (int i = 1; i <= k; i++)
    {
        ans += i;
    }
    n -= ans;
    if (n < 0)
    {
        cout<<"-1";
    }
    else
    {
        nn[0] = n / k;
        n -= (n / k) * k;
        for (int i = 1; i <= k; i++)
        {
            nn[i] = nn[i - 1] + 1;
        }
        if(n != 0)
            nn[k]++;
        cout << nn[k] - nn[1];
    }
}