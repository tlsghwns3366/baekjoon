#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *m = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
    }
    sort(m, m + n);
    long long time = 0;
    long long count = 0;
    for (int i = 0; i < n; i++)
    {
        count = count + m[i];
        time += count;
    }
    cout << time;
}