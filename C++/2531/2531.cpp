#include <iostream>
using namespace std;
int n, d, k, c;
int nn[40000];
int dcount[3001];
int main()
{
    cin >> n >> d >> k >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    int stans = 1;
    dcount[c]++;
    for (int i = 0; i < k; i++)
    {
        if (dcount[nn[i]] == 0)
            stans++;
        dcount[nn[i]]++;
        nn[n + i] = nn[i];
    }
    int p1 = 0;
    int p2 = k;
    int ans = stans;
    while (p2 < n + k)
    {
        if (dcount[nn[p2]] == 0)
            stans++;
        dcount[nn[p2]]++;
        dcount[nn[p1]]--;
        if (dcount[nn[p1]] == 0)
            stans--;
        ans = ans < stans ? stans : ans;
        p1++;
        p2++;
    }
    cout << ans;
}