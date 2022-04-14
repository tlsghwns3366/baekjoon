#include <iostream>
#include <stack>
using namespace std;
int main()
{
    string s;
    cin >> s;
    stack<char> t;
    int ans = 0;
    int temp = 1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            temp = temp * 2;
            t.push('(');
        }
        else if (s[i] == ')')
        {
            if (t.empty() || t.top() != '(')
            {
                ans = 0;
                break;
            }
            if (s[i - 1] == '(')
            {
                ans += temp;
                temp = temp / 2;
                t.pop();
            }
            else
            {
                temp = temp / 2;
                t.pop();
            }
        }
        else if (s[i] == '[')
        {
            temp = temp * 3;
            t.push('[');
        }
        else if (s[i] == ']')
        {
            if (t.empty() || t.top() != '[')
            {
                ans = 0;
                break;
            }
            if (s[i - 1] == '[')
            {
                ans += temp;
                temp = temp / 3;
                t.pop();
            }
            else
            {
                temp = temp / 3;
                t.pop();
            }
        }
    }
    if (!t.empty())
        ans = 0;
    cout << ans;
}