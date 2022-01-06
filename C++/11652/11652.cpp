#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long int nn[100001];
    fill(nn, nn + 100001, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    sort(nn, nn + n);

    long long int temp = nn[0];
    int count = 1;
    int m = 1;
    long long int ans = nn[0];
    for (int i = 1; i < n; i++)
    {
        if (temp == nn[i])
            count++;
        else
        {
            count = 1;
            temp = nn[i];
        }
        if (m < count)
        {
            m = count;
            ans = nn[i];
        }
    }
    cout << ans;
}