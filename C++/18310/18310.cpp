#include <iostream>
#include <algorithm>
#include <vector>
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
    if (n % 2 == 1)
    {
        cout << nn[n / 2];
    }
    else
    {
        cout << nn[(n / 2) - 1];
    }
}