#include <iostream>
#include <stack>
using namespace std;
int main()
{
    string s, t;
    cin >> s >> t;
    stack<pair<char, int>> ans;
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (!ans.empty())
        {
            if (s[i] == t[ans.top().second])
                ans.push({s[i], ans.top().second + 1});
            else
            {
                if (s[i] == t[0])
                    ans.push({s[i], 1});
                else
                    ans.push({s[i], 0});
            }
        }
        else
        {
            if (s[i] == t[0])
                ans.push({s[i], 1});
            else
                ans.push({s[i], 0});
        }
        if (!ans.empty() && ans.top().second == t.length())
        {
            for (int j = 0; j < t.length(); j++)
            {
                ans.pop();
            }
        }
    }
    if (ans.empty())
    {
        cout << "FRULA";
    }
    else
    {
        stack<char> ansout;
        while (!ans.empty())
        {
            ansout.push(ans.top().first);
            ans.pop();
        }
        while (!ansout.empty())
        {
            cout << ansout.top();
            ansout.pop();
        }
    }
}