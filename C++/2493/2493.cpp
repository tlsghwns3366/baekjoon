#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ans[n];
    fill(ans, ans + n, 0);
    stack<pair<int, int>> s;
    stack<pair<int, int>> s2;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        s.push({temp, i + 1});
    }
    for (int i = 1; i <= n; i++)
    {
        s2.push(s.top());
        s.pop();
        if (s.empty())
            continue;

        while (!s2.empty() && s.top().first >= s2.top().first)
        {
            ans[s2.top().second - 1] = s.top().second;
            s2.pop();
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}