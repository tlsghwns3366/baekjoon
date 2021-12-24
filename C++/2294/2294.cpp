#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int kk[k + 1];
    int nn[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    fill(kk, kk + k + 1, INT_MAX);
    kk[0] = 0;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - nn[j] >= 0)
            {
                if (kk[i - nn[j]] != INT_MAX && kk[i - nn[j]] + 1 < kk[i])
                {
                    kk[i] = kk[i - nn[j]] + 1;
                }
            }
        }
    }
    if (kk[k] == INT_MAX)
        cout << -1;
    else
        cout << kk[k];
}