#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, k, b;
    cin >> n >> k >> b;
    int nn[n + 1];
    int sum[n + 1];
    int ans = 987654321;
    for (int i = 1; i <= n; i++)
    {
        nn[i] = 1;
    }
    for (int i = 0; i < b; i++)
    {
        int temp;
        cin >> temp;
        nn[temp] = 0;
    }
    sum[1] = k;
    for (int j = 0; j < k; j++)
    {
        sum[1] -= nn[1 + j];
    }
    for (int i = 2; i + k - 1 <= n; i++)
    {
        sum[i] = sum[i - 1] + nn[i - 1] - nn[i + k-1];
        if (ans > sum[i])
            ans = sum[i];
    }
    cout << ans;
}