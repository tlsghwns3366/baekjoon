#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int nn[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    sort(nn, nn + n);
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        if (nn[i] * (n - i) > m)
            m = nn[i] * (n - i);
    }
    cout<<m;
}