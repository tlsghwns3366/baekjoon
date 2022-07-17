#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int nn[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    int sum = 0;
    int p1 = 0;
    int p2 = k;
    for (int i = 0; i < k; i++)
    {
        sum += nn[i];
    }
    int ans = sum;
    for (int i = 0; i + k < n; i++)
    {
        sum -= nn[p1];
        sum += nn[p2];
        if (ans < sum)
            ans = sum;
        p1++;
        p2++;
    }
    cout << ans;
}