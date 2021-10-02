#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    long long int nn[n];
    fill(nn, nn + n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    for (int i = 0; i < m; i++)
    {
        sort(nn, nn + n);
        long long int temp = nn[0] + nn[1];
        nn[0] = temp;
        nn[1] = temp;
    }
    long long int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += nn[i];
    }
    cout << s;
}