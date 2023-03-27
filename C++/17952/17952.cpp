#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if (t == 0)
        {
            if (s.empty())
                continue;
            int a, b;
            a = s.top().first;
            b = s.top().second;
            s.pop();
            b--;
            if (b == 0)
                ans += a;
            else
                s.push({a, b});
            continue;
        }
        else
        {
            int a, b;
            cin >> a >> b;
            b--;
            if (b == 0)
                ans += a;
            else
                s.push({a, b});
        }
    }
    cout << ans;
}