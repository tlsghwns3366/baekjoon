#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int x = 0; x < t; x++)
    {
        int n, m;
        cin >> n >> m;
        int nn[n];
        pair<int, int> mm[m];
        for (int i = 0; i < m; i++)
        {
            cin >> mm[i].first >> mm[i].second;
        }
        cout << n - 1 << endl;
    }
}