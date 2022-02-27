#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int nn[n];
    int nn2[8001];
    fill(nn2, nn2 + 8001, 0);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
        sum += nn[i];
        nn2[nn[i] + 4000]++;
    }
    sort(nn, nn + n);
    int temp = 0;
    int c = 0;
    int ans = 0;
    for (int i = 0; i < 8001; i++)
    {
        if (nn2[i] > temp)
            temp = nn2[i];
    }
    for (int i = 0; i < 8001; i++)
    {
        if (c == 2)
            break;
        if (nn2[i] == temp)
        {
            ans = i;
            c++;
        }
    }
    cout << (int)round(((double)sum / n)) << "\n";
    cout << nn[n / 2] << "\n";
    cout << ans - 4000 << "\n";
    cout << nn[n - 1] - nn[0];
}