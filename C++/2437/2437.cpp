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
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        if (s + 1 < nn[i])
            break;
        s += nn[i];
    }
    cout << s+1;
}