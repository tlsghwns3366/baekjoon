#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int nn[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    int sum = 0;
    int ans = 0;
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nn[i];
        while (sum >= m && start <= i)
        {
            if (sum == m)
                ans++;
            sum -= nn[start];
            start++;
        }
    }
    cout << ans;
}