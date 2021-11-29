#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    bool b[n + 1];
    fill(b, b + n + 1, true);
    map<string, int> m;
    for (int i = 1; i <= n; i++)
    {
        string temp;
        cin >> temp;
        m[temp] = i;
    }
    int ans = 0;
    int p = 1;
    for (int i = 1; i <= n; i++)
    {
        string temp;
        cin >> temp;
        b[m[temp]] = false;
        if (m[temp] == p)
        {
            for (int j = p; j <= n; j++)
            {
                if (b[j])
                {
                    p = j;
                    break;
                }
            }
        }
        else
            ans++;
    }
    cout << ans;
}