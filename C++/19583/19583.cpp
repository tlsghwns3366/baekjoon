#include <iostream>
#include <map>
using namespace std;
int main()
{
    string s, e, q;
    cin >> s >> e >> q;
    map<string, int> m;
    int ans = 0;
    while (true)
    {
        string a, b;
        cin >> a >> b;
        if (a == "" && b == "")
            break;
        if (a <= s)
        {
            m[b] = 1;
            continue;
        }
        if (a >= e && a <= q)
        {
            if(m[b] == 1)
            {
                m[b]--;
                ans++;
            }
        }
    }
    cout<<ans;
}