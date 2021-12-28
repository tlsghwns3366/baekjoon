#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int nn[1001];
    fill(nn, nn + 1001, 0);
    int ans = 0;
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        nn[a] = b;
        if (b > nn[start])
            start = a;
    }
    int temp = 0;
    for (int i = 0; i <= start; i++)
    {
        if (nn[i] != 0)
        {
            if (temp < nn[i])
                temp = nn[i];
        }
        if (temp != 0)
        {
            ans += temp;
        }
    }
    temp = 0;
    for (int i = 1001; i > start; i--)
    {
        if (nn[i] != 0)
        {
            if (temp < nn[i])
                temp = nn[i];
        }
        if (temp != 0)
        {
            ans += temp;
        }
    }
    cout << ans;
}