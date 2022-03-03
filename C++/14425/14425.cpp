#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n, m;
    int ans = 0;
    cin >> n >> m;
    map<string, int> m1;

    for (int q = 0; q < n; q++)
    {
        string temp;
        cin >> temp;
        m1[temp] = 1;
    }
    for (int q = 0; q < m; q++)
    {
        string temp;
        cin >> temp;
        if (m1[temp] == 1)
            ans++;
    }
    cout << ans;
}