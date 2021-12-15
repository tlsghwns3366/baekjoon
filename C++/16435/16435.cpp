#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, l;
    cin >> n >> l;
    int nn[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    sort(nn, nn + n);
    for (int i = 0; i < n; i++)
    {
        if (nn[i] <= l)
            l++;
        else
            break;
    }
    cout << l;
}